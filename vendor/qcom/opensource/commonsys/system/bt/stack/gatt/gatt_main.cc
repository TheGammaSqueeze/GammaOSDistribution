/******************************************************************************
 *
 *  Copyright (C) 2008-2012 Broadcom Corporation
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

/******************************************************************************
 *
 *  this file contains the main ATT functions
 *
 ******************************************************************************/

#include "bt_target.h"

#include "bt_common.h"
#include "bt_utils.h"
#include "btif_storage.h"
#include "btm_ble_int.h"
#include "btm_int.h"
#include "connection_manager.h"
#include "device/include/interop.h"
#include "gatt_int.h"
#include "l2c_api.h"
#include "l2c_int.h"
#include "osi/include/osi.h"
#include "stack/gatt/eatt_int.h"
#include "osi/include/properties.h"

using base::StringPrintf;

/* Configuration flags. */
#define GATT_L2C_CFG_IND_DONE (1 << 0)
#define GATT_L2C_CFG_CFM_DONE (1 << 1)

/* minimum GATT MTU size over BR/EDR link
 */
#define GATT_MIN_BR_MTU_SIZE 48

/******************************************************************************/
/*            L O C A L    F U N C T I O N     P R O T O T Y P E S            */
/******************************************************************************/
static void gatt_le_connect_cback(uint16_t chan, const RawAddress& bd_addr,
                                  bool connected, uint16_t reason,
                                  tBT_TRANSPORT transport);
static void gatt_le_data_ind(uint16_t chan, const RawAddress& bd_addr,
                             BT_HDR* p_buf);
static void gatt_le_cong_cback(const RawAddress& remote_bda, bool congest);

static void gatt_l2cif_connect_ind_cback(const RawAddress& bd_addr,
                                         uint16_t l2cap_cid, uint16_t psm,
                                         uint8_t l2cap_id);
static void gatt_l2cif_connect_cfm_cback(uint16_t l2cap_cid, uint16_t result);
static void gatt_l2cif_config_ind_cback(uint16_t l2cap_cid,
                                        tL2CAP_CFG_INFO* p_cfg);
static void gatt_l2cif_config_cfm_cback(uint16_t l2cap_cid,
                                        tL2CAP_CFG_INFO* p_cfg);
static void gatt_l2cif_disconnect_ind_cback(uint16_t l2cap_cid,
                                            bool ack_needed);
static void gatt_l2cif_disconnect_cfm_cback(uint16_t l2cap_cid,
                                            uint16_t result);
static void gatt_l2cif_data_ind_cback(uint16_t l2cap_cid, BT_HDR* p_msg);
static void gatt_send_conn_cback(tGATT_TCB* p_tcb, uint16_t lcid);
static void gatt_l2cif_congest_cback(uint16_t cid, bool congested);

static const tL2CAP_APPL_INFO dyn_info = {gatt_l2cif_connect_ind_cback,
                                          gatt_l2cif_connect_cfm_cback,
                                          NULL,
                                          gatt_l2cif_config_ind_cback,
                                          gatt_l2cif_config_cfm_cback,
                                          gatt_l2cif_disconnect_ind_cback,
                                          gatt_l2cif_disconnect_cfm_cback,
                                          NULL,
                                          gatt_l2cif_data_ind_cback,
                                          gatt_l2cif_congest_cback,
                                          NULL,
                                          NULL /* tL2CA_CREDITS_RECEIVED_CB */};


static void gatt_l2cif_eatt_connect_ind_cback(tL2CAP_COC_CONN_REQ *p_conn_req,
                                              uint16_t l2cap_id, uint16_t result,
                                              uint16_t status);
static void gatt_l2cif_eatt_connect_cfm_cback(RawAddress &p_bd_addr,
                                              tL2CAP_COC_CHMAP_INFO  *chmap_info,
                                              uint16_t p_mtu, uint16_t result,
                                              uint16_t status);
static void gatt_l2cif_eatt_reconfig_ind_cback(tL2CAP_COC_CHMAP_INFO* chmap_info,
                                               uint16_t p_mtu);
static void gatt_l2cif_eatt_disconnect_ind_cback(uint16_t l2cap_cid, bool ack_needed);
static void gatt_l2cif_eatt_disconnect_cfm_cback(uint16_t l2cap_cid, uint16_t result);
static void gatt_l2cif_eatt_data_ind_cback(uint16_t l2cap_cid);
static void gatt_l2cif_eatt_cong_status_cb(uint16_t cid, bool congested);
static void gatt_l2cif_eatt_credits_rcvd_cb(uint16_t cid, uint16_t credits_rcvd,
                                            uint16_t credit_count);

static const tL2CAP_COC_APPL_INFO eatt_dyn_info = {gatt_l2cif_eatt_connect_ind_cback,
                                                   gatt_l2cif_eatt_connect_cfm_cback,
                                                   gatt_l2cif_eatt_reconfig_ind_cback,
                                                   NULL,
                                                   gatt_l2cif_eatt_disconnect_ind_cback,
                                                   gatt_l2cif_eatt_disconnect_cfm_cback,
                                                   gatt_l2cif_eatt_data_ind_cback,
                                                   gatt_l2cif_eatt_cong_status_cb,
                                                   NULL,
                                                   gatt_l2cif_eatt_credits_rcvd_cb,
                                                  };

tGATT_CB gatt_cb;

/*******************************************************************************
 *
 * Function         gatt_init
 *
 * Description      This function is enable the GATT profile on the device.
 *                  It clears out the control blocks, and registers with L2CAP.
 *
 * Returns          void
 *
 ******************************************************************************/
void gatt_init(void) {
  tL2CAP_FIXED_CHNL_REG fixed_reg;
  char eatt_enabled_prop[PROPERTY_VALUE_MAX] = "false";

  VLOG(1) << __func__;

  gatt_cb = tGATT_CB();
  connection_manager::reset(true);
  memset(&fixed_reg, 0, sizeof(tL2CAP_FIXED_CHNL_REG));

  gatt_cb.def_mtu_size = GATT_DEF_BLE_MTU_SIZE;
  gatt_cb.sign_op_queue = fixed_queue_new(SIZE_MAX);
  gatt_cb.srv_chg_clt_q = fixed_queue_new(SIZE_MAX);
  /* First, register fixed L2CAP channel for ATT over BLE */
  fixed_reg.fixed_chnl_opts.mode = L2CAP_FCR_BASIC_MODE;
  fixed_reg.fixed_chnl_opts.max_transmit = 0xFF;
  fixed_reg.fixed_chnl_opts.rtrans_tout = 2000;
  fixed_reg.fixed_chnl_opts.mon_tout = 12000;
  fixed_reg.fixed_chnl_opts.mps = 670;
  fixed_reg.fixed_chnl_opts.tx_win_sz = 1;

  fixed_reg.pL2CA_FixedConn_Cb = gatt_le_connect_cback;
  fixed_reg.pL2CA_FixedData_Cb = gatt_le_data_ind;
  fixed_reg.pL2CA_FixedCong_Cb = gatt_le_cong_cback; /* congestion callback */
  fixed_reg.default_idle_tout = 0xffff; /* 0xffff default idle timeout */

  if (property_get("persist.vendor.btstack.enable.eatt", eatt_enabled_prop, "true")
      && !strcmp(eatt_enabled_prop, "true")) {
    gatt_cb.eatt_enabled = true;
  }
  else {
    gatt_cb.eatt_enabled = false;
  }

  L2CA_RegisterFixedChannel(L2CAP_ATT_CID, &fixed_reg);

  /* Now, register with L2CAP for ATT PSM over BR/EDR */
  if (!L2CA_Register(BT_PSM_ATT, (tL2CAP_APPL_INFO*)&dyn_info,
                     false /* enable_snoop */)) {
    LOG(ERROR) << "ATT Dynamic Registration failed";
  }

  BTM_SetSecurityLevel(true, "", BTM_SEC_SERVICE_ATT, BTM_SEC_NONE, BT_PSM_ATT,
                       0, 0);
  BTM_SetSecurityLevel(false, "", BTM_SEC_SERVICE_ATT, BTM_SEC_NONE, BT_PSM_ATT,
                       0, 0);

  if (gatt_cb.eatt_enabled) {
    /* Register with L2CAP for EATT PSM */
    if (!L2CA_RegisterCoc(BT_PSM_EATT, (tL2CAP_COC_APPL_INFO*)&eatt_dyn_info,
                          false /* enable_snoop */)) {
      LOG(ERROR) << "EATT Dynamic Registration failed";
    }

    BTM_SetSecurityLevel(true, "", BTM_SEC_SERVICE_EATT, BTM_SEC_OUT_ENCRYPT, BT_PSM_EATT,
                           0, 0);
    BTM_SetSecurityLevel(false, "", BTM_SEC_SERVICE_EATT, BTM_SEC_IN_ENCRYPT, BT_PSM_EATT,
                         0, 0);

    btif_storage_load_bonded_eatt_devices();
  }


  gatt_cb.hdl_cfg.gatt_start_hdl = GATT_GATT_START_HANDLE;
  gatt_cb.hdl_cfg.gap_start_hdl = GATT_GAP_START_HANDLE;
  gatt_cb.hdl_cfg.app_start_hdl = GATT_APP_START_HANDLE;

  gatt_cb.hdl_list_info = new std::list<tGATT_HDL_LIST_ELEM>();
  gatt_cb.srv_list_info = new std::list<tGATT_SRV_LIST_ELEM>();
  gatt_profile_db_init();
}

/*******************************************************************************
 *
 * Function         gatt_free
 *
 * Description      This function frees resources used by the GATT profile.
 *
 * Returns          void
 *
 ******************************************************************************/
void gatt_free(void) {
  int i;
  VLOG(1) << __func__;

  fixed_queue_free(gatt_cb.sign_op_queue, NULL);
  gatt_cb.sign_op_queue = NULL;
  fixed_queue_free(gatt_cb.srv_chg_clt_q, NULL);
  gatt_cb.srv_chg_clt_q = NULL;
  for (i = 0; i < GATT_MAX_PHY_CHANNEL; i++) {
    gatt_cb.tcb[i].pending_enc_clcb = std::queue<tGATT_CLCB*>();

    fixed_queue_free(gatt_cb.tcb[i].pending_ind_q, NULL);
    gatt_cb.tcb[i].pending_ind_q = NULL;

    alarm_free(gatt_cb.tcb[i].conf_timer);
    gatt_cb.tcb[i].conf_timer = NULL;

    alarm_free(gatt_cb.tcb[i].ind_ack_timer);
    gatt_cb.tcb[i].ind_ack_timer = NULL;

    fixed_queue_free(gatt_cb.tcb[i].sr_cmd.multi_rsp_q, NULL);
    gatt_cb.tcb[i].sr_cmd.multi_rsp_q = NULL;
  }

  for (i = 0; i < GATT_MAX_EATT_CHANNELS; i++) {
    if(gatt_cb.eatt_bcb[i].cid != L2CAP_ATT_CID) {
      fixed_queue_free(gatt_cb.eatt_bcb[i].pending_ind_q, NULL);
      alarm_free(gatt_cb.eatt_bcb[i].conf_timer);
      alarm_free(gatt_cb.eatt_bcb[i].ind_ack_timer);
    }
    gatt_cb.eatt_bcb[i].pending_ind_q = NULL;
    gatt_cb.eatt_bcb[i].conf_timer = NULL;
    gatt_cb.eatt_bcb[i].ind_ack_timer = NULL;

    fixed_queue_free(gatt_cb.eatt_bcb[i].sr_cmd.multi_rsp_q, NULL);
    gatt_cb.eatt_bcb[i].sr_cmd.multi_rsp_q = NULL;
  }

  if (gatt_cb.hdl_list_info != nullptr) {
    gatt_cb.hdl_list_info->clear();
    delete(gatt_cb.hdl_list_info);
    gatt_cb.hdl_list_info = nullptr;
  }

  if (gatt_cb.srv_list_info != nullptr) {
    gatt_cb.srv_list_info->clear();
    delete(gatt_cb.srv_list_info);
    gatt_cb.srv_list_info = nullptr;
  }
}

/*******************************************************************************
 *
 * Function         gatt_connect
 *
 * Description      This function is called to initiate a connection to a peer
 *                  device.
 *
 * Parameter        rem_bda: remote device address to connect to.
 *
 * Returns          true if connection is started, otherwise return false.
 *
 ******************************************************************************/
bool gatt_connect(const RawAddress& rem_bda, tGATT_TCB* p_tcb,
                  tBT_TRANSPORT transport, uint8_t initiating_phys,
                  tGATT_IF gatt_if) {
  VLOG(1) << __func__;
  tGATT_REG* p_reg_app = gatt_get_regcb(gatt_if);
  tBTM_SEC_DEV_REC* p_dev_rec = btm_find_dev(rem_bda);

  if (gatt_get_ch_state(p_tcb) != GATT_CH_OPEN)
    gatt_set_ch_state(p_tcb, GATT_CH_CONN);

  if (transport != BT_TRANSPORT_LE) {
    p_tcb->att_lcid = L2CA_ConnectReq(BT_PSM_ATT, rem_bda);
    return p_tcb->att_lcid != 0;
  }

  // Already connected, send the callback, mark the link as used
  if (gatt_get_ch_state(p_tcb) == GATT_CH_OPEN) {
    /*  very similar to gatt_send_conn_cback, but no good way to reuse the code
     */

    VLOG(1) << __func__ << " is_eatt_supported:" << +p_tcb->is_eatt_supported;

    if (!p_reg_app) {
      VLOG(1) << __func__ << " p_reg_app is null";
      return false;
    }

    VLOG(1) << __func__ << " p_reg eatt_support:" << +p_reg_app->eatt_support;

    if(!p_tcb->is_eatt_supported || (!p_reg_app->eatt_support)) {
      /* notifying application about the connection up event */
      for (int i = 0; i < GATT_MAX_APPS; i++) {
        tGATT_REG* p_reg = &gatt_cb.cl_rcb[i];

        if (!p_reg->in_use || p_reg->gatt_if != gatt_if) continue;

        gatt_update_app_use_link_flag(p_reg->gatt_if, p_tcb, true, true);

        if (p_reg->app_cb.p_conn_cb) {
          uint16_t conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
          (*p_reg->app_cb.p_conn_cb)(p_reg->gatt_if, p_tcb->peer_bda, conn_id,
                                     true, 0, p_tcb->transport);
        }
      }
    }
    else if (p_tcb->is_eatt_supported && p_reg_app->eatt_support) {
      std::deque<tGATT_IF>::iterator it =
          std::find(p_tcb->apps_needing_eatt.begin(), p_tcb->apps_needing_eatt.end(), gatt_if);
      if (it == p_tcb->apps_needing_eatt.end()) {
        p_tcb->apps_needing_eatt.push_back(gatt_if);
      }
      if (p_dev_rec && (p_dev_rec->sec_flags & BTM_SEC_LE_ENCRYPTED))
        gatt_establish_eatt_connect(p_tcb, 1);
    }

    return true;
  }

  p_tcb->att_lcid = L2CAP_ATT_CID;
  return connection_manager::direct_connect_add(gatt_if, rem_bda);
}

/*******************************************************************************
 *
 * Function         gatt_disconnect
 *
 * Description      This function is called to disconnect to an ATT device.
 *
 * Parameter        p_tcb: pointer to the TCB to disconnect.
 *
 * Returns          true: if connection found and to be disconnected; otherwise
 *                  return false.
 *
 ******************************************************************************/
bool gatt_disconnect(tGATT_TCB* p_tcb, uint16_t lcid) {
  VLOG(1) << __func__;

  if (!p_tcb) return false;

  uint16_t cid = p_tcb->att_lcid;
  if (p_tcb->is_eatt_supported) {
    cid = lcid;
  }

  VLOG(1) << __func__ << " cid:" << +cid;
  tGATT_CH_STATE ch_state = gatt_get_ch_state(p_tcb);
  if (ch_state == GATT_CH_CLOSING) {
    VLOG(1) << __func__ << " already in closing state";
    return true;
  }

  bool ret = true;
  if (cid == L2CAP_ATT_CID) {
    tL2C_LCB *p_lcb = l2cu_find_lcb_by_bd_addr(p_tcb->peer_bda, p_tcb->transport);
    tL2C_LINK_STATE link_state = p_lcb != NULL ? p_lcb->link_state : LST_DISCONNECTED;
    VLOG(1) << __func__ << "ch_state= " << ch_state << " link_state= " << link_state;

    if ((ch_state == GATT_CH_OPEN) ||
                ((ch_state == GATT_CH_CONN) && (link_state == LST_CONNECTED))) {
      /* only LCB exist between remote device and local */
      ret = L2CA_RemoveFixedChnl(L2CAP_ATT_CID, p_tcb->peer_bda);
    } else {
      L2CA_CancelBleConnectReq(p_tcb->peer_bda);
      gatt_cleanup_upon_disc(p_tcb->peer_bda, HCI_ERR_CONN_CAUSE_LOCAL_HOST, p_tcb->transport);
      return true;
    }
    gatt_set_ch_state(p_tcb, GATT_CH_CLOSING);
  } else {
    if ((ch_state == GATT_CH_OPEN) || (ch_state == GATT_CH_CFG)) {
      ret = L2CA_DisconnectReq(cid);
    }
    else
      VLOG(1) << __func__ << " gatt_disconnect channel not opened";
  }

  return ret;
}

/*******************************************************************************
**
** Function         gatt_is_app_holding_link
**
** Description      Checks whether the application holds the link
**
** Returns          true if the app holds the link, false otherwise.
**
*******************************************************************************/
bool gatt_is_app_holding_link(tGATT_IF gatt_if, tGATT_TCB *p_tcb)
{/*
  if(p_tcb) {
    for (int i = 0; i < GATT_MAX_APPS; i++) {
      if (p_tcb->app_hold_link[i] == gatt_if) {
        VLOG(1) << __func__ << "gatt_if " << gatt_if << "exists at idx " << +i ;);
        return true;
      }
    }
  }
*/
  VLOG(1) << __func__ << "gatt_if= " << +gatt_if << "not found;";
  return false;
}

/*******************************************************************************
 *
 * Function         gatt_update_app_hold_link_status
 *
 * Description      Update the application use link status
 *
 * Returns          true if any modifications are made or
 *                  when it already exists, false otherwise.
 *
 ******************************************************************************/
bool gatt_update_app_hold_link_status(tGATT_IF gatt_if, tGATT_TCB* p_tcb,
                                      bool is_add) {
  auto& holders = p_tcb->app_hold_link;

  VLOG(1) << __func__;
  if (is_add) {
    auto ret = holders.insert(gatt_if);
    if (ret.second) {
      VLOG(1) << "added gatt_if=" << +gatt_if;
    } else {
      VLOG(1) << "attempt to add already existing gatt_if=" << +gatt_if;
    }
    return true;
  }

  //! is_add
  if (!holders.erase(gatt_if)) {
    VLOG(1) << "attempt to remove nonexisting gatt_if=" << +gatt_if;
    return false;
  }

  VLOG(1) << "removed gatt_if=" << +gatt_if;
  return true;
}

/*******************************************************************************
 *
 * Function         gatt_update_app_use_link_flag
 *
 * Description      Update the application use link flag and optional to check
 *                  the acl link if the link is up then set the idle time out
 *                  accordingly
 *
 * Returns          void.
 *
 ******************************************************************************/
void gatt_update_app_use_link_flag(tGATT_IF gatt_if, tGATT_TCB* p_tcb,
                                   bool is_add, bool check_acl_link) {
  VLOG(1) << StringPrintf("%s: is_add=%d chk_link=%d", __func__, is_add,
                          check_acl_link);
  tGATT_EBCB* p_eatt_bcb;
  uint16_t lcid;
  uint8_t i = 0;
  tGATT_REG* p_reg = gatt_get_regcb(gatt_if);

  if (!p_tcb) return;

  lcid = p_tcb->att_lcid;
  // If we make no modification, i.e. kill app that was never connected to a
  // device, skip updating the device state.
  if (!gatt_update_app_hold_link_status(gatt_if, p_tcb, is_add)) return;

  if (!check_acl_link) {
    return;
  }

  bool is_valid_handle =
      (BTM_GetHCIConnHandle(p_tcb->peer_bda, p_tcb->transport) !=
       GATT_INVALID_ACL_HANDLE);

  if (p_tcb->is_eatt_supported) {
    p_eatt_bcb = gatt_find_eatt_bcb_by_gatt_if(gatt_if, p_tcb->peer_bda);
    if(p_eatt_bcb) {
      lcid = p_eatt_bcb->cid;
    }
  }

  if (is_add) {
    if ((lcid == L2CAP_ATT_CID) && is_valid_handle) {
      VLOG(1) << "disable link idle timer";
      /* acl link is connected disable the idle timeout */
      GATT_SetIdleTimeout(p_tcb->peer_bda, GATT_LINK_NO_IDLE_TIMEOUT,
                          p_tcb->transport, lcid);
    }
  } else {
    if (p_tcb->is_eatt_supported && (p_reg && p_reg->eatt_support) &&
        (lcid != L2CAP_ATT_CID) &&
        !gatt_remove_app_on_lcid(lcid, gatt_if)) {
      VLOG(1) << __func__ << " EATT disconnect lcid:" << +lcid;
      gatt_disconnect(p_tcb, lcid);
    }
    else {
      if (p_tcb->app_hold_link.empty()) {
        // acl link is connected but no application needs to use the link
        if (lcid == L2CAP_ATT_CID && is_valid_handle) {
          // If remote created EATT channels available, disconnect them
          if (gatt_num_eatt_bcbs(p_tcb) > 0) {
            for (i = 0; i < GATT_MAX_EATT_CHANNELS; i++) {
              if (gatt_cb.eatt_bcb[i].in_use && (gatt_cb.eatt_bcb[i].p_tcb->peer_bda == p_tcb->peer_bda)
                  && (!gatt_cb.eatt_bcb[i].create_in_prg) && (gatt_cb.eatt_bcb[i].cid != L2CAP_ATT_CID)) {
                p_eatt_bcb = &gatt_cb.eatt_bcb[i];
                L2CA_DisconnectReq(p_eatt_bcb->cid);
                break;
              }
            }
          }
          else {
            /* for fixed channel, set the timeout value to
             GATT_LINK_IDLE_TIMEOUT_WHEN_NO_APP seconds */
            VLOG(1) << " start link idle timer = "
                    << GATT_LINK_IDLE_TIMEOUT_WHEN_NO_APP << " sec";
            GATT_SetIdleTimeout(p_tcb->peer_bda, GATT_LINK_IDLE_TIMEOUT_WHEN_NO_APP,
                                p_tcb->transport, lcid);
          }
        } else
          // disconnect the dynamic channel
          gatt_disconnect(p_tcb, lcid);
      }
    }
  }
}

/** GATT connection initiation */
bool gatt_act_connect(tGATT_REG* p_reg, const RawAddress& bd_addr,
                      tBT_TRANSPORT transport, int8_t initiating_phys) {
  tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(bd_addr, transport);
  if (p_tcb != NULL) {
    /* before link down, another app try to open a GATT connection */
    uint8_t st = gatt_get_ch_state(p_tcb);
    if (st == GATT_CH_OPEN && p_tcb->app_hold_link.empty() &&
        transport == BT_TRANSPORT_LE) {
      if (!gatt_connect(bd_addr, p_tcb, transport, initiating_phys,
                        p_reg->gatt_if))
        return false;
    } else if (st == GATT_CH_CLOSING) {
      LOG(INFO) << "Must finish disconnection before new connection";
      /* need to complete the closing first */
      return false;
    } else if ((p_tcb->is_eatt_supported) && (p_reg->eatt_support)
               && (st == GATT_CH_OPEN) &&
               (transport == BT_TRANSPORT_LE)) {
      if (!gatt_connect(bd_addr, p_tcb, transport, initiating_phys,
                        p_reg->gatt_if))
        return false;
    }

    return true;
  }  // p_tcb == null

  p_tcb = gatt_allocate_tcb_by_bdaddr(bd_addr, transport);
  if (!p_tcb) {
    LOG(ERROR) << "Max TCB for gatt_if [ " << +p_reg->gatt_if << "] reached.";
    return false;
  }

  if (!gatt_connect(bd_addr, p_tcb, transport, initiating_phys,
                    p_reg->gatt_if)) {
    LOG(ERROR) << "gatt_connect failed";
    fixed_queue_free(p_tcb->pending_ind_q, NULL);
    *p_tcb = tGATT_TCB();
    return false;
  }

  return true;
}

namespace connection_manager {
void on_connection_timed_out(uint8_t app_id, const RawAddress& address) {
  tGATT_EBCB* p_eatt_bcb;
  uint16_t lcid;

  p_eatt_bcb = gatt_find_eatt_bcb_by_gatt_if(app_id, address);
  if (p_eatt_bcb)
    lcid = p_eatt_bcb->cid;
  else
    lcid = L2CAP_ATT_CID;

  gatt_le_connect_cback(lcid, address, false, 0xff, BT_TRANSPORT_LE);
}
}  // namespace connection_manager
namespace connection_manager {
void on_connection_cancelled(uint8_t app_id, const RawAddress& address) {
  gatt_le_connect_cback(L2CAP_ATT_CID, address, false, 0xff, BT_TRANSPORT_LE);
}
}  // namespace connection_manager

/** This callback function is called by L2CAP to indicate that the ATT fixed
 * channel for LE is connected (conn = true)/disconnected (conn = false).
 */
static void gatt_le_connect_cback(uint16_t chan, const RawAddress& bd_addr,
                                  bool connected, uint16_t reason,
                                  tBT_TRANSPORT transport) {
  tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(bd_addr, transport);
  bool check_srv_chg = false;
  tGATTS_SRV_CHG* p_srv_chg_clt = NULL;
  tGATT_EBCB* p_eatt_bcb = NULL;

  /* ignore all fixed channel connect/disconnect on BR/EDR link for GATT */
  if (transport == BT_TRANSPORT_BR_EDR) return;

  VLOG(1) << "GATT   ATT protocol channel with BDA: " << bd_addr << " is "
          << ((connected) ? "connected" : "disconnected");

  p_srv_chg_clt = gatt_is_bda_in_the_srv_chg_clt_list(bd_addr);
  if (p_srv_chg_clt != NULL) {
    check_srv_chg = true;
  } else {
    if (btm_sec_is_a_bonded_dev(bd_addr))
      gatt_add_a_bonded_dev_for_srv_chg(bd_addr);
  }

  if (!connected) {
    gatt_cleanup_upon_disc(bd_addr, reason, transport);
    VLOG(1) << "ATT disconnected";
    return;
  }

  /* do we have a channel initiating a connection? */
  if (p_tcb) {
    /* we are initiating connection */
    if (gatt_get_ch_state(p_tcb) == GATT_CH_CONN) {
      /* send callback */
      gatt_set_ch_state(p_tcb, GATT_CH_OPEN);
      p_tcb->payload_size = GATT_DEF_BLE_MTU_SIZE;

      gatt_send_conn_cback(p_tcb, chan);
    }
    if (check_srv_chg) gatt_chk_srv_chg(p_srv_chg_clt);
  }
  /* this is incoming connection or background connection callback */

  else {
    p_tcb = gatt_allocate_tcb_by_bdaddr(bd_addr, BT_TRANSPORT_LE);
    if (!p_tcb) {
      LOG(ERROR) << "CCB max out, no rsources";
      return;
    }

    p_tcb->att_lcid = L2CAP_ATT_CID;

    gatt_set_ch_state(p_tcb, GATT_CH_OPEN);

    p_tcb->payload_size = GATT_DEF_BLE_MTU_SIZE;

    gatt_send_conn_cback(p_tcb, chan);
    if (check_srv_chg) {
      gatt_chk_srv_chg(p_srv_chg_clt);
    }
  }

  p_tcb->mtu_for_eatt = GATT_DEF_EATT_MTU_SIZE;
  //Check whether bda supports EATT
  if (btm_sec_is_a_bonded_dev(bd_addr) && is_eatt_device(bd_addr)) {
    p_tcb->is_eatt_supported = true;

    //Allocate entry for ATT channel
    p_eatt_bcb = gatt_eatt_bcb_alloc(p_tcb, L2CAP_ATT_CID, false, false);

    if (gatt_apps_need_eatt(p_tcb)) {
      VLOG(2) << __func__ << ": Apps have requested EATT";
      GATT_Config(bd_addr, BT_TRANSPORT_LE);
    }
  }

}

/** This function is called to process the congestion callback from lcb */
static void gatt_channel_congestion(tGATT_TCB* p_tcb, bool congested, uint16_t lcid) {
  uint8_t i = 0;
  tGATT_REG* p_reg = NULL;
  uint16_t conn_id;

  /* if uncongested, check to see if there is any more pending data */
  if (p_tcb != NULL && !congested) {
    gatt_cl_send_next_cmd_inq(*p_tcb, lcid);
  }
  /* notifying all applications for the connection up event */
  for (i = 0, p_reg = gatt_cb.cl_rcb; i < GATT_MAX_APPS; i++, p_reg++) {
    if (p_reg->in_use) {
      if (p_reg->app_cb.p_congestion_cb && p_tcb) {
        conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
        (*p_reg->app_cb.p_congestion_cb)(conn_id, congested);
      }
    }
  }
}

void gatt_notify_phy_updated(uint8_t status, uint16_t handle, uint8_t tx_phy,
                             uint8_t rx_phy) {
  tBTM_SEC_DEV_REC* p_dev_rec = btm_find_dev_by_handle(handle);
  if (!p_dev_rec) {
    BTM_TRACE_WARNING("%s: No Device Found!", __func__);
    return;
  }

  tGATT_TCB* p_tcb =
      gatt_find_tcb_by_addr(p_dev_rec->ble.pseudo_addr, BT_TRANSPORT_LE);
  if (!p_tcb) return;

  for (int i = 0; i < GATT_MAX_APPS; i++) {
    tGATT_REG* p_reg = &gatt_cb.cl_rcb[i];
    if (p_reg->in_use && p_reg->app_cb.p_phy_update_cb) {
      uint16_t conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
      (*p_reg->app_cb.p_phy_update_cb)(p_reg->gatt_if, conn_id, tx_phy, rx_phy,
                                       status);
    }
  }
}

void gatt_notify_conn_update(uint16_t handle, uint16_t interval,
                             uint16_t latency, uint16_t timeout,
                             uint8_t status) {
  tBTM_SEC_DEV_REC* p_dev_rec = btm_find_dev_by_handle(handle);
  if (!p_dev_rec) return;

  tGATT_TCB* p_tcb =
      gatt_find_tcb_by_addr(p_dev_rec->ble.pseudo_addr, BT_TRANSPORT_LE);
  if (!p_tcb) return;

  for (int i = 0; i < GATT_MAX_APPS; i++) {
    tGATT_REG* p_reg = &gatt_cb.cl_rcb[i];
    if (p_reg->in_use && p_reg->app_cb.p_conn_update_cb) {
      uint16_t conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
      (*p_reg->app_cb.p_conn_update_cb)(p_reg->gatt_if, conn_id, interval,
                                        latency, timeout, status);
    }
  }
}

/** This function is called when GATT fixed channel is congested or uncongested
 */
static void gatt_le_cong_cback(const RawAddress& remote_bda, bool congested) {
  tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(remote_bda, BT_TRANSPORT_LE);
  if (!p_tcb) return;

  /* if uncongested, check to see if there is any more pending data */
    gatt_channel_congestion(p_tcb, congested, p_tcb->att_lcid);
}

/*******************************************************************************
 *
 * Function         gatt_le_data_ind
 *
 * Description      This function is called when data is received from L2CAP.
 *                  if we are the originator of the connection, we are the ATT
 *                  client, and the received message is queued up for the
 *                  client.
 *
 *                  If we are the destination of the connection, we are the ATT
 *                  server, so the message is passed to the server processing
 *                  function.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_le_data_ind(uint16_t chan, const RawAddress& bd_addr,
                             BT_HDR* p_buf) {

  /* Find CCB based on bd addr */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(bd_addr, BT_TRANSPORT_LE);
  if (p_tcb) {
    if (gatt_get_ch_state(p_tcb) < GATT_CH_OPEN) {
      LOG(WARNING) << "ATT - Ignored L2CAP data while in state: "
                   << +gatt_get_ch_state(p_tcb);
    } else
      gatt_data_process(*p_tcb, p_tcb->att_lcid, p_buf);
  }

  osi_free(p_buf);
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_connect_ind
 *
 * Description      This function handles an inbound connection indication
 *                  from L2CAP. This is the case where we are acting as a
 *                  server.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_connect_ind_cback(const RawAddress& bd_addr,
                                         uint16_t lcid,
                                         UNUSED_ATTR uint16_t psm, uint8_t id) {
  uint8_t result = L2CAP_CONN_OK;
  LOG(INFO) << "Connection indication cid = " << +lcid;

  /* new connection ? */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(bd_addr, BT_TRANSPORT_BR_EDR);
  if (p_tcb == NULL) {
    /* allocate tcb */
    p_tcb = gatt_allocate_tcb_by_bdaddr(bd_addr, BT_TRANSPORT_BR_EDR);
    if (p_tcb == NULL) {
      /* no tcb available, reject L2CAP connection */
      result = L2CAP_CONN_NO_RESOURCES;
    } else {
      p_tcb->att_lcid = lcid;
      p_tcb->is_eatt_supported = false;
    }

  } else /* existing connection , reject it */
  {
    result = L2CAP_CONN_NO_RESOURCES;
  }

  /* Send L2CAP connect rsp */
  L2CA_ConnectRsp(bd_addr, id, lcid, result, 0);

  /* if result ok, proceed with connection */
  if (result != L2CAP_CONN_OK) return;

  /* transition to configuration state */
  gatt_set_ch_state(p_tcb, GATT_CH_CFG);

  /* Send L2CAP config req */
  tL2CAP_CFG_INFO cfg;
  memset(&cfg, 0, sizeof(tL2CAP_CFG_INFO));
  cfg.mtu_present = true;
  cfg.mtu = GATT_MAX_MTU_SIZE;

  L2CA_ConfigReq(lcid, &cfg);
}

/** This is the L2CAP connect confirm callback function */
static void gatt_l2cif_connect_cfm_cback(uint16_t lcid, uint16_t result) {
  tGATT_TCB* p_tcb;
  tL2CAP_CFG_INFO cfg;

  /* look up clcb for this channel */
  p_tcb = gatt_find_tcb_by_cid(lcid);
  if (!p_tcb) return;

  VLOG(1) << __func__
          << StringPrintf(" result: %d ch_state: %d, lcid:0x%x", result,
                          gatt_get_ch_state(p_tcb), p_tcb->att_lcid);

  /* if in correct state */
  if (gatt_get_ch_state(p_tcb) == GATT_CH_CONN) {
    /* if result successful */
    if (result == L2CAP_CONN_OK) {
      /* set channel state */
      gatt_set_ch_state(p_tcb, GATT_CH_CFG);

      /* Send L2CAP config req */
      memset(&cfg, 0, sizeof(tL2CAP_CFG_INFO));
      cfg.mtu_present = true;
      cfg.mtu = GATT_MAX_MTU_SIZE;
      L2CA_ConfigReq(lcid, &cfg);
    }
    /* else initiating connection failure */
    else {
      gatt_cleanup_upon_disc(p_tcb->peer_bda, result, GATT_TRANSPORT_BR_EDR);
    }
  } else /* wrong state, disconnect it */
  {
    if (result == L2CAP_CONN_OK) {
      /* just in case the peer also accepts our connection - Send L2CAP
       * disconnect req */
      L2CA_DisconnectReq(lcid);
    }
  }
}

/** This is the L2CAP config confirm callback function */
void gatt_l2cif_config_cfm_cback(uint16_t lcid, tL2CAP_CFG_INFO* p_cfg) {

  /* look up clcb for this channel */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);
  if (!p_tcb) return;

  /* if in incorrect state */
  if (gatt_get_ch_state(p_tcb) != GATT_CH_CFG) return;

  /* if result not successful */
  if (p_cfg->result != L2CAP_CFG_OK) {
    /* Send L2CAP disconnect req */
    L2CA_DisconnectReq(lcid);
    return;
  }

  /* update flags */
  p_tcb->ch_flags |= GATT_L2C_CFG_CFM_DONE;

  /* if configuration not complete */
  if (!(p_tcb->ch_flags & GATT_L2C_CFG_IND_DONE)) return;

  gatt_set_ch_state(p_tcb, GATT_CH_OPEN);

  tGATTS_SRV_CHG* p_srv_chg_clt =
      gatt_is_bda_in_the_srv_chg_clt_list(p_tcb->peer_bda);
  if (p_srv_chg_clt != NULL) {
    gatt_chk_srv_chg(p_srv_chg_clt);
  } else {
    if (btm_sec_is_a_bonded_dev(p_tcb->peer_bda))
      gatt_add_a_bonded_dev_for_srv_chg(p_tcb->peer_bda);
  }

  /* send callback */
  gatt_send_conn_cback(p_tcb, lcid);
}

/** This is the L2CAP config indication callback function */
void gatt_l2cif_config_ind_cback(uint16_t lcid, tL2CAP_CFG_INFO* p_cfg) {
  tGATTS_SRV_CHG* p_srv_chg_clt = NULL;
  /* look up clcb for this channel */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);
  if (!p_tcb) return;

  /* GATT uses the smaller of our MTU and peer's MTU  */
  if (p_cfg->mtu_present &&
      (p_cfg->mtu >= GATT_MIN_BR_MTU_SIZE && p_cfg->mtu < L2CAP_DEFAULT_MTU))
    p_tcb->payload_size = p_cfg->mtu;
  else
    p_tcb->payload_size = L2CAP_DEFAULT_MTU;

  /* send L2CAP configure response */
  memset(p_cfg, 0, sizeof(tL2CAP_CFG_INFO));
  p_cfg->result = L2CAP_CFG_OK;
  L2CA_ConfigRsp(lcid, p_cfg);

  /* if not first config ind */
  if ((p_tcb->ch_flags & GATT_L2C_CFG_IND_DONE)) return;

  /* update flags */
  p_tcb->ch_flags |= GATT_L2C_CFG_IND_DONE;

  /* if configuration not complete */
  if ((p_tcb->ch_flags & GATT_L2C_CFG_CFM_DONE) == 0) return;

  gatt_set_ch_state(p_tcb, GATT_CH_OPEN);
  p_srv_chg_clt = gatt_is_bda_in_the_srv_chg_clt_list(p_tcb->peer_bda);
  if (p_srv_chg_clt != NULL) {
    gatt_chk_srv_chg(p_srv_chg_clt);
  } else {
    if (btm_sec_is_a_bonded_dev(p_tcb->peer_bda))
      gatt_add_a_bonded_dev_for_srv_chg(p_tcb->peer_bda);
  }

  /* send callback */
  gatt_send_conn_cback(p_tcb, lcid);
}

/** This is the L2CAP disconnect indication callback function */
void gatt_l2cif_disconnect_ind_cback(uint16_t lcid, bool ack_needed) {

  /* look up clcb for this channel */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);
  if (!p_tcb) return;

  if (ack_needed) {
    /* send L2CAP disconnect response */
    L2CA_DisconnectRsp(lcid);
  }

  if (gatt_is_bda_in_the_srv_chg_clt_list(p_tcb->peer_bda) == NULL) {
    if (btm_sec_is_a_bonded_dev(p_tcb->peer_bda))
      gatt_add_a_bonded_dev_for_srv_chg(p_tcb->peer_bda);
  }
  /* if ACL link is still up, no reason is logged, l2cap is disconnect from
   * peer */
  uint16_t reason = L2CA_GetDisconnectReason(p_tcb->peer_bda, p_tcb->transport);
  if (reason == 0) reason = GATT_CONN_TERMINATE_PEER_USER;

  /* send disconnect callback */
  gatt_cleanup_upon_disc(p_tcb->peer_bda, reason, GATT_TRANSPORT_BR_EDR);
}

/** This is the L2CAP disconnect confirm callback function */
static void gatt_l2cif_disconnect_cfm_cback(uint16_t lcid,
                                            UNUSED_ATTR uint16_t result) {

  /* look up clcb for this channel */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);
  if (!p_tcb) return;

  /* If the device is not in the service changed client list, add it... */
  if (gatt_is_bda_in_the_srv_chg_clt_list(p_tcb->peer_bda) == NULL) {
    if (btm_sec_is_a_bonded_dev(p_tcb->peer_bda))
      gatt_add_a_bonded_dev_for_srv_chg(p_tcb->peer_bda);
  }

  /* send disconnect callback */
  /* if ACL link is still up, no reason is logged, l2cap is disconnect from
   * peer */
  uint16_t reason = L2CA_GetDisconnectReason(p_tcb->peer_bda, p_tcb->transport);
  if (reason == 0) reason = GATT_CONN_TERMINATE_LOCAL_HOST;

  gatt_cleanup_upon_disc(p_tcb->peer_bda, reason, GATT_TRANSPORT_BR_EDR);
}

/** This is the L2CAP data indication callback function */
static void gatt_l2cif_data_ind_cback(uint16_t lcid, BT_HDR* p_buf) {
  /* look up clcb for this channel */
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);
  if (p_tcb && gatt_get_ch_state(p_tcb) == GATT_CH_OPEN) {
    /* process the data */
    gatt_data_process(*p_tcb, p_tcb->att_lcid, p_buf);
  }

  osi_free(p_buf);
}

/** L2CAP congestion callback */
static void gatt_l2cif_congest_cback(uint16_t lcid, bool congested) {
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(lcid);

  if (p_tcb != NULL) {
    gatt_channel_congestion(p_tcb, congested, lcid);
  }
}

/** EATT channel congestion callback */
void gatt_notify_eatt_congestion(tGATT_TCB* p_tcb, uint16_t cid, bool congested) {
  tGATT_EBCB* p_eatt_bcb = gatt_find_eatt_bcb_by_cid(p_tcb, cid);

  if (!p_eatt_bcb) {
    VLOG(1) << __func__ << " error, EATT bcb is null";
    return;
  }

  p_tcb = p_eatt_bcb->p_tcb;

  if (congested) {
    eatt_congest_notify_apps(p_tcb, cid, congested);
    return;
  }

  if (!congested && p_eatt_bcb->send_uncongestion &&
      eatt_congest_notify_apps(p_tcb, cid, congested)) {
    VLOG(1) << __func__ << " sent uncongestion cb to apps";
    return;
  }

  /* if uncongested, check to see if there is any pending GATT rsp */
  if (p_tcb != NULL && !congested && p_eatt_bcb->send_uncongestion) {
    gatt_send_pending_rsp(*(p_tcb), cid);
  }

  /* if uncongested, check to see if there is any pending GATT srvc disc rsp */
  if (p_tcb != NULL && !congested && p_eatt_bcb->send_uncongestion) {
    gatt_send_pending_disc_rsp(*(p_tcb), cid);
  }

  /* if uncongested, check to see if there is any more pending client ops */
  if (p_tcb != NULL && !congested && p_eatt_bcb->send_uncongestion) {
    gatt_cl_send_next_cmd_inq(*p_tcb, cid);
  }

  /* if uncongested, check to see if there is any more pending indications */
  if (p_tcb != NULL && !congested && p_eatt_bcb->send_uncongestion) {
    gatt_send_pending_ind(*(p_tcb), cid);
  }

  /* if uncongested, check to see if there is any more pending notifications */
  if (p_tcb != NULL && !congested && p_eatt_bcb->send_uncongestion) {
    gatt_send_pending_notif(*(p_tcb), cid);
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_cong_status_cb
 *
 * Description      This function handles congestion status callback.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_cong_status_cb(uint16_t cid, bool congested) {
  tGATT_TCB* p_tcb = gatt_find_tcb_by_cid(cid);
  if (!p_tcb) return;

  VLOG(1) << __func__;
  /* if uncongested, check to see if there is any more pending data */
  gatt_channel_congestion(p_tcb, congested, cid);
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_credits_rcvd_cb
 *
 * Description      This function handles credits received callback.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_credits_rcvd_cb(uint16_t cid, uint16_t credits_rcvd,
                                            uint16_t credit_count) {
  tGATT_TCB tcb;
  tcb.peer_bda = RawAddress::kAny;
  tGATT_EBCB* p_eatt_bcb = gatt_find_eatt_bcb_by_cid(&tcb, cid);
  VLOG(1) << __func__;

  if (p_eatt_bcb && p_eatt_bcb->no_credits && !p_eatt_bcb->send_uncongestion
      && (credit_count > 0)) {
    VLOG(1) << __func__ << " EATT channel uncongested";
    p_eatt_bcb->send_uncongestion = true;
    gatt_notify_eatt_congestion(p_eatt_bcb->p_tcb, cid, false);
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_connect_ind_cback
 *
 * Description      This function handles inbound connection indication callback
 *                  from L2CAP for EATT channel establishment. This is the case
 *                  where local device is the recipient of incoming L2CAP credit
 *                  based connection request.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_connect_ind_cback(tL2CAP_COC_CONN_REQ *p_conn_req,
                                              uint16_t l2cap_id, uint16_t result,
                                              uint16_t status) {
  uint8_t num_chnls;
  uint16_t lcid;
  tBT_TRANSPORT transport = BT_TRANSPORT_LE;
  uint16_t rsp_status = L2CAP_CONN_OK;
  tGATT_EBCB* p_eatt_bcb;
  tL2CAP_COC_CONN_REQ conn_rsp;
  tL2CAP_COC_CONN_REQ* p_conn_rsp = &conn_rsp;
  uint16_t remote_rx_mtu = 0;

  if (!p_conn_req) {
    LOG(ERROR) << " p_conn_req is null";
    return;
  }
  if (p_conn_req->transport != BT_TRANSPORT_LE) {
    LOG(ERROR) << " Unsupported transport";
    return;
  }

  for (uint8_t i=0; i< L2C_MAX_ECFC_CHNLS_PER_CONN; i++) {
    p_conn_rsp->sr_cids[i] = 0;
  }
  p_conn_rsp->num_chnls = 0;
  p_conn_rsp->transport = p_conn_req->transport;
  p_conn_rsp->p_bd_addr = p_conn_req->p_bd_addr;

  VLOG(1) << __func__ << " result:" << +result << " status:" << +status;

  if (p_conn_req) {
    tGATT_TCB* p_tcb = gatt_find_tcb_by_addr(p_conn_req->p_bd_addr, p_conn_req->transport);
    if (!p_tcb) {
      VLOG(1) << __func__ << "p_tcb is null";
      return;
    }
    transport = p_conn_req->transport;
    num_chnls = p_conn_req->num_chnls;

    for (uint8_t i=0; i< num_chnls; i++) {
      lcid = p_conn_req->sr_cids[i];
      p_eatt_bcb = gatt_eatt_bcb_alloc(p_tcb, lcid, false, true);

      if (p_eatt_bcb) {
        if (p_conn_req->mtu < GATT_DEF_EATT_MTU_SIZE)
          remote_rx_mtu = GATT_DEF_EATT_MTU_SIZE;
        else if (p_conn_req->mtu > GATT_MAX_MTU_SIZE)
          remote_rx_mtu = GATT_MAX_MTU_SIZE;
        else
          remote_rx_mtu = p_conn_req->mtu;

        if (p_eatt_bcb->p_tcb->mtu_for_eatt < GATT_DEF_EATT_MTU_SIZE) {
          p_eatt_bcb->p_tcb->mtu_for_eatt = GATT_DEF_EATT_MTU_SIZE;
        }
        p_eatt_bcb->payload_size = std::min(p_eatt_bcb->p_tcb->mtu_for_eatt, remote_rx_mtu);
        p_eatt_bcb->local_rx_mtu = p_eatt_bcb->p_tcb->mtu_for_eatt;
        p_eatt_bcb->remote_rx_mtu = remote_rx_mtu;

        p_conn_rsp->num_chnls++;
        p_conn_rsp->sr_cids[i] = lcid;
        p_conn_rsp->mtu = p_eatt_bcb->p_tcb->mtu_for_eatt;
      }
    }

    if (p_conn_rsp->num_chnls == num_chnls)
      result = L2C_COC_CONNECT_REQ_SUCCESS;
    else if (p_conn_rsp->num_chnls > 0)
      result = L2C_SOME_CONNS_ACCEPTED;
    else if (p_conn_rsp->num_chnls == 0)
      result = L2C_NO_RESOURCE_AVALIABLE;

    if (p_conn_rsp->num_chnls >= 1) {
      VLOG(1) << __func__ << " Updating EATT support";
      p_tcb->is_eatt_supported = true;
    }

    p_conn_rsp->p_bd_addr = p_conn_req->p_bd_addr;
    L2CA_ConnectCocRsp(p_conn_rsp, l2cap_id, result, rsp_status);
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_connect_cfm_cback
 *
 * Description      This function handles connection confirmation callback
 *                  from L2CAP for EATT channel establishment. This is the case
 *                  where local device is the initiator of outgoing L2CAP
 *                  credit based connection request.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_connect_cfm_cback(RawAddress &p_bd_addr,
                                              tL2CAP_COC_CHMAP_INFO *chmap_info,
                                              uint16_t p_mtu, uint16_t result,
                                              uint16_t status) {
  uint8_t num_chnls = 0;
  uint16_t lcid;
  tGATT_TCB* p_tcb = NULL;
  tGATT_IF gatt_if;
  tBT_TRANSPORT transport = BT_TRANSPORT_LE;
  tGATT_EBCB* p_eatt_bcb = NULL;
  uint16_t conn_id = 0;

  VLOG(1) << __func__ << " result:" << +result << " status:" << +status;

  if (chmap_info)
    num_chnls = chmap_info->num_chnls;

  if ((status == L2CAP_CONN_OK) && (result == L2CAP_ECFC_ALL_CONNS_SUCCESSFUL)) {
    if (num_chnls > 0) {
      for (uint8_t idx=0; idx < num_chnls; idx++) {
        lcid = chmap_info->sr_cids[idx];
        p_eatt_bcb = gatt_find_eatt_bcb_by_cid_in_progress(p_bd_addr, lcid);
        if (p_eatt_bcb) {
          transport = p_eatt_bcb->p_tcb->transport;
          p_tcb = p_eatt_bcb->p_tcb;
        }
        else {
          VLOG(1) << __func__ << " p_eatt_bcb is NULL";
          return;
        }
        if (transport == BT_TRANSPORT_BR_EDR) {
          LOG(ERROR) << " Unsupported transport";
          return;
        }
        if (!p_tcb->apps_needing_eatt.empty()) {
          gatt_if = p_tcb->apps_needing_eatt.front();
          p_tcb->apps_needing_eatt.pop_front();

          //Add mapping of conn_id and lcid
          conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, gatt_if);
          gatt_add_conn(conn_id, lcid);

          p_eatt_bcb->apps.push_back(gatt_if);
          p_eatt_bcb->create_in_prg = false;

          p_eatt_bcb->payload_size = std::min(p_eatt_bcb->p_tcb->mtu_for_eatt, p_mtu);
          p_eatt_bcb->local_rx_mtu = p_eatt_bcb->p_tcb->mtu_for_eatt;
          p_eatt_bcb->remote_rx_mtu = p_mtu;
        }
        else {
          VLOG(1) << __func__ << " None of the apps have initiated EATT connect:";
          return;
        }

        for (int i = 0; i < GATT_MAX_APPS; i++) {
          tGATT_REG* p_reg = &gatt_cb.cl_rcb[i];

          if (!p_reg->in_use || p_reg->gatt_if != gatt_if) continue;

          gatt_update_app_use_link_flag(p_reg->gatt_if, p_tcb, true, true);

          if (p_reg->app_cb.p_conn_cb) {
            uint16_t conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
            (*p_reg->app_cb.p_conn_cb)(p_reg->gatt_if, p_tcb->peer_bda, conn_id,
                                       true, 0, p_tcb->transport);
          }
        }
      }
    }
  }
  else { //Failure
    p_tcb = gatt_find_tcb_by_addr(p_bd_addr, BT_TRANSPORT_LE);

    if (!p_tcb) {
      VLOG(1) << __func__ << " p_tcb is null";
      return;
    }

    //Assign least burdened channel
    if (!p_tcb->apps_needing_eatt.empty()) {
      gatt_if = p_tcb->apps_needing_eatt.front();
      p_tcb->apps_needing_eatt.pop_front();
      p_eatt_bcb = gatt_find_best_eatt_bcb(p_tcb, gatt_if, 0, false);

      if (p_eatt_bcb) {
        for (int i = 0; i < GATT_MAX_APPS; i++) {
          tGATT_REG* p_reg = &gatt_cb.cl_rcb[i];

          if (!p_reg->in_use || p_reg->gatt_if != gatt_if) continue;

          gatt_update_app_use_link_flag(p_reg->gatt_if, p_tcb, true, true);

          if (p_reg->app_cb.p_conn_cb) {
            uint16_t conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
            (*p_reg->app_cb.p_conn_cb)(p_reg->gatt_if, p_tcb->peer_bda, conn_id,
                true, 0, p_tcb->transport);
          }
        }
      }
    }
    if (gatt_num_eatt_bcbs(p_tcb) == 0) {
      VLOG(1) << " First EATT conn attempt rejected, set eatt as not supported";
      p_tcb->is_eatt_supported = false;
    }
    gatt_eatt_bcb_in_progress_dealloc(p_bd_addr);
  }

  if (p_tcb && !p_tcb->apps_needing_eatt.empty()) {
    gatt_establish_eatt_connect(p_tcb, 1);
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_disconnect_ind_cback
 *
 * Description      This function handles disconnection indication callback
 *                  from L2CAP for EATT channel disconnection. This is the case
 *                  where local device is the recipient of incoming L2CAP
 *                  disconnection request.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_disconnect_ind_cback(uint16_t l2cap_cid, bool ack_needed) {
  tGATT_EBCB* p_eatt_bcb = gatt_find_eatt_bcb_using_all_cids(l2cap_cid);

  VLOG(1) << __func__;

  if (!p_eatt_bcb) {
    VLOG(1) << __func__ << " p_eatt_bcb is NULL for cid: " << +l2cap_cid;
    return;
  }

  tL2C_LCB *p_lcb = l2cu_find_lcb_by_bd_addr(p_eatt_bcb->p_tcb->peer_bda,
                                             p_eatt_bcb->p_tcb->transport);
  tL2C_LINK_STATE link_state = p_lcb != NULL ? p_lcb->link_state : LST_DISCONNECTED;
  if ((link_state == LST_DISCONNECTING) || (link_state == LST_DISCONNECTED)) {
    VLOG(1) << __func__ << " link_state = " << link_state;
  } else {
    //Move apps if remote disconnects an EATT channel
    gatt_move_apps(p_eatt_bcb->p_tcb, l2cap_cid);
  }

  //dealloc eatt_bcb for the lcid
  gatt_eatt_bcb_dealloc(p_eatt_bcb->p_tcb, l2cap_cid);

  if (ack_needed) {
    L2CA_DisconnectRsp(l2cap_cid);
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_disconnect_cfm_cback
 *
 * Description      This function handles disconnection confirmation callback
 *                  from L2CAP for EATT channel disconnection. This is the case
 *                  where local device is the initiator of outgoing L2CAP
 *                  disconnection request.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_disconnect_cfm_cback(uint16_t l2cap_cid, uint16_t result) {
  tGATT_TCB tcb;
  tcb.peer_bda = RawAddress::kAny;
  tGATT_EBCB* p_eatt_bcb = gatt_find_eatt_bcb_by_cid(&tcb, l2cap_cid);
  tGATT_TCB* p_tcb = NULL;
  uint8_t i = 0;

  VLOG(1) << __func__;

  if (!p_eatt_bcb) {
    VLOG(1) << __func__ << " p_eatt_bcb is NULL for cid: " << +l2cap_cid;
    return;
  }

  p_tcb = p_eatt_bcb->p_tcb;
  gatt_eatt_bcb_dealloc(p_tcb, l2cap_cid);

  // Disconnect EATT bearers
  if (p_tcb->is_eatt_supported &&
      (p_tcb->app_hold_link.empty() || p_tcb->is_att_rsp_tout)) {
    if (gatt_num_eatt_bcbs(p_tcb) > 0) {
      for (i = 0; i < GATT_MAX_EATT_CHANNELS; i++) {
        if (gatt_cb.eatt_bcb[i].in_use && gatt_cb.eatt_bcb[i].p_tcb->peer_bda == p_tcb->peer_bda
            && (!gatt_cb.eatt_bcb[i].create_in_prg) && gatt_cb.eatt_bcb[i].cid != L2CAP_ATT_CID) {
          p_eatt_bcb = &gatt_cb.eatt_bcb[i];
          L2CA_DisconnectReq(p_eatt_bcb->cid);
          break;
        }
      }
    }
    else {
      gatt_disconnect(p_tcb, L2CAP_ATT_CID);
    }
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_reconfig_ind_cback
 *
 * Description      This function handles reconfiguration indication callback
 *                  from L2CAP for EATT channel reconfiguration. This is the case
 *                  where local device is the recipient of incoming L2CAP
 *                  credit based reconfigure request.
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_reconfig_ind_cback(tL2CAP_COC_CHMAP_INFO* chmap_info,
                                               uint16_t p_mtu) {
  bool ret = false;
  uint8_t i=0;
  uint8_t num_chnls =0;
  uint16_t lcid = 0;
  tGATT_EBCB* p_eatt_bcb;
  tL2CAP_COC_CHMAP_INFO chmap_info_rsp;
  tL2CAP_COC_CHMAP_INFO* p_chmap_info_rsp = &chmap_info_rsp;
  uint16_t result = L2CAP_RCFG_OK;
  tGATTS_DATA gatts_data;
  tGATT_CL_COMPLETE cb_data;
  tGATT_TCB tcb;
  tcb.peer_bda = RawAddress::kAny;

  VLOG(1) << __func__;

  for (i=0; i< L2C_MAX_ECFC_CHNLS_PER_CONN; i++) {
    chmap_info_rsp.sr_cids[i] = 0;
  }
  chmap_info_rsp.num_chnls = 0;

  if (!chmap_info) {
    VLOG(1) << __func__ << " Invalid L2CAP EATT channels:";
    return;
  }

  num_chnls = chmap_info->num_chnls;

  if ((p_mtu < GATT_DEF_EATT_MTU_SIZE) || (p_mtu > GATT_MAX_MTU_SIZE)) {
    VLOG(1) << __func__ << " Unacceptable MTU size:";
    result = L2CAP_RCFG_UNACCEPTABLE_PARAMS;
  }

  //Update MTU size for lcids
  if (result == L2CAP_RCFG_OK) {
    VLOG(1) << __func__ << " Reconfig accepted:";
    for (i=0; i<num_chnls; i++) {
      if (chmap_info->sr_cids[i] > 0) {
        lcid = chmap_info->sr_cids[i];
        p_eatt_bcb = gatt_find_eatt_bcb_by_cid(&tcb, lcid);
        if (p_eatt_bcb) {
          p_eatt_bcb->payload_size = std::min(p_eatt_bcb->local_rx_mtu, p_mtu);
          p_eatt_bcb->remote_rx_mtu = p_mtu;
        }
      }
    }
    p_chmap_info_rsp = chmap_info;
  }

  ret = L2CA_ReconfigCocRsp(p_chmap_info_rsp, result);

  if (result == L2CAP_RCFG_OK) {
    gatts_data.mtu = p_mtu;
    /* Notify all registered applications on the cid with MTU size.*/
    for (i=0; i<num_chnls; i++) {
      if (chmap_info->sr_cids[i] > 0) {
        lcid = chmap_info->sr_cids[i];
        p_eatt_bcb = gatt_find_eatt_bcb_by_cid(&tcb, lcid);
        if (p_eatt_bcb) {
          uint8_t num_apps_on_lcid = p_eatt_bcb->apps.size();
          for (int j=0; j< num_apps_on_lcid; j++) {
            tGATT_IF gatt_if = p_eatt_bcb->apps[j];
            tGATT_REG* p_reg = gatt_get_regcb(gatt_if);
            uint16_t conn_id =
                GATT_CREATE_CONN_ID(p_eatt_bcb->p_tcb->tcb_idx, gatt_if);

            if (p_reg && !p_reg->eatt_support)
              continue;

            gatt_sr_send_req_callback(conn_id, 0, GATTS_REQ_TYPE_MTU, &gatts_data);

            tGATT_CMPL_CBACK* p_cmpl_cb = (p_reg) ? p_reg->app_cb.p_cmpl_cb : NULL;
            cb_data.mtu = p_eatt_bcb->payload_size;
            if (p_cmpl_cb) {
              (*p_cmpl_cb)(conn_id, GATTC_OPTYPE_CONFIG, GATT_SUCCESS, &cb_data, 0);
            }
          }
        }
      }
    }
  }
}

/*******************************************************************************
 *
 * Function         gatt_l2cif_eatt_data_ind_cback
 *
 * Description      This function handles data indication callback from L2CAP
 *                  for EATT channel data. This is the case where local device
 *                  is the recipient of incoming data on EATT channel.
 *
 *
 * Returns          void
 *
 ******************************************************************************/
static void gatt_l2cif_eatt_data_ind_cback(uint16_t l2cap_cid) {
  tGATT_EBCB* p_eatt_bcb;
  tGATT_TCB* p_tcb;
  BT_HDR* p_buf = NULL;
  tGATT_TCB tcb;
  tcb.peer_bda = RawAddress::kAny;

  p_eatt_bcb = gatt_find_eatt_bcb_by_cid(&tcb, l2cap_cid);
  if(p_eatt_bcb) {
    p_tcb = p_eatt_bcb->p_tcb;
    if (p_tcb && gatt_get_ch_state(p_tcb) == GATT_CH_OPEN) {
      p_buf = L2CA_ReadData(l2cap_cid);
      if (p_buf) {
        /* process the data */
        gatt_data_process(*p_tcb, l2cap_cid, p_buf);
      }
    }
  }
  else {
    VLOG(1) << __func__ << " unknown cid: " << +l2cap_cid;
    return;
  }

  osi_free(p_buf);
}

/** Callback used to notify layer above about a connection */
static void gatt_send_conn_cback(tGATT_TCB* p_tcb, uint16_t lcid) {
  uint8_t i;
  tGATT_REG* p_reg;
  uint16_t conn_id;

  VLOG(1) << __func__ << " : address " << p_tcb->peer_bda;
  std::set<tGATT_IF> apps =
      connection_manager::get_apps_connecting_to(p_tcb->peer_bda);
  std::unordered_set<uint8_t> dir_conn_apps = p_tcb->app_hold_link;
  bool is_eatt_dev = is_eatt_device(p_tcb->peer_bda);

  /* notifying all applications for the connection up event */
  for (i = 0, p_reg = gatt_cb.cl_rcb; i < GATT_MAX_APPS; i++, p_reg++) {
    bool is_app_req_eatt_conn = false;
    if (!p_reg->in_use) continue;

    if (apps.find(p_reg->gatt_if) != apps.end()) {
      gatt_update_app_use_link_flag(p_reg->gatt_if, p_tcb, true, true);
      if (p_reg->eatt_support)
        is_app_req_eatt_conn = true;
    }

    if (dir_conn_apps.find(p_reg->gatt_if) != dir_conn_apps.end()) {
      if (p_reg->eatt_support)
        is_app_req_eatt_conn = true;
    }

    if (is_eatt_dev && is_app_req_eatt_conn)
      continue;

    if (p_reg->app_cb.p_conn_cb) {
      conn_id = GATT_CREATE_CONN_ID(p_tcb->tcb_idx, p_reg->gatt_if);
      (*p_reg->app_cb.p_conn_cb)(p_reg->gatt_if, p_tcb->peer_bda, conn_id, true,
                                 0, p_tcb->transport);
    }
  }

  /* Remove the direct connection */
  connection_manager::on_connection_complete(p_tcb->peer_bda);

  if (!p_tcb->is_eatt_supported) {
    lcid = p_tcb->att_lcid;
  }

  if (!p_tcb->app_hold_link.empty() && (lcid == L2CAP_ATT_CID ||
      p_tcb->transport == BT_TRANSPORT_LE)) {
    /* disable idle timeout if one or more clients are holding the link disable
     * the idle timer */
    GATT_SetIdleTimeout(p_tcb->peer_bda, GATT_LINK_NO_IDLE_TIMEOUT,
                        p_tcb->transport, lcid);
  }
}

/*******************************************************************************
 *
 * Function         gatt_le_data_ind
 *
 * Description      This function is called when data is received from L2CAP.
 *                  if we are the originator of the connection, we are the ATT
 *                  client, and the received message is queued up for the
 *                  client.
 *
 *                  If we are the destination of the connection, we are the ATT
 *                  server, so the message is passed to the server processing
 *                  function.
 *
 * Returns          void
 *
 ******************************************************************************/
void gatt_data_process(tGATT_TCB& tcb, uint16_t lcid, BT_HDR* p_buf) {
  uint8_t* p = (uint8_t*)(p_buf + 1) + p_buf->offset;
  uint8_t op_code, pseudo_op_code;

  if (p_buf->len <= 0) {
    LOG(ERROR) << "invalid data length, ignore";
    return;
  }

  uint16_t msg_len = p_buf->len - 1;
  STREAM_TO_UINT8(op_code, p);

  LOG(INFO) << __func__ << " op_code = " << +op_code
                        << ", msg_len = " << +msg_len;

  /* remove the two MSBs associated with sign write and write cmd */
  pseudo_op_code = op_code & (~GATT_WRITE_CMD_MASK);

  if (pseudo_op_code >= GATT_OP_CODE_MAX) {
    /* Note: PTS: GATT/SR/UNS/BI-01-C mandates error on unsupported ATT request.
     */
    LOG(ERROR) << __func__
               << ": ATT - Rcvd L2CAP data, unknown cmd: " << loghex(op_code);
    gatt_send_error_rsp(tcb, lcid, GATT_REQ_NOT_SUPPORTED, op_code, 0, false);
    return;
  }

  if (op_code == GATT_SIGN_CMD_WRITE) {
    gatt_verify_signature(tcb, p_buf);
  } else {
    /* message from client */
    if ((op_code % 2) == 0)
      gatt_server_handle_client_req(tcb, lcid, op_code, msg_len, p);
    else
      gatt_client_handle_server_rsp(tcb, lcid, op_code, msg_len, p);
  }
}

/** Add a bonded dev to the service changed client list */
void gatt_add_a_bonded_dev_for_srv_chg(const RawAddress& bda) {
  tGATTS_SRV_CHG_REQ req;
  tGATTS_SRV_CHG srv_chg_clt;

  srv_chg_clt.bda = bda;
  srv_chg_clt.srv_changed = false;
  if (!gatt_add_srv_chg_clt(&srv_chg_clt)) return;

  req.srv_chg.bda = bda;
  req.srv_chg.srv_changed = false;
  if (gatt_cb.cb_info.p_srv_chg_callback)
    (*gatt_cb.cb_info.p_srv_chg_callback)(GATTS_SRV_CHG_CMD_ADD_CLIENT, &req,
                                          NULL);
}

/** This function is called to send a service chnaged indication to the
 * specified bd address */
void gatt_send_srv_chg_ind(const RawAddress& peer_bda) {
  VLOG(1) << __func__;

  if (!gatt_cb.handle_of_h_r) return;

  uint16_t conn_id = gatt_profile_find_conn_id_by_bd_addr(peer_bda);
  if (conn_id == GATT_INVALID_CONN_ID) {
    LOG(ERROR) << "Unable to find conn_id for " << peer_bda;
    return;
  }

  uint8_t handle_range[GATT_SIZE_OF_SRV_CHG_HNDL_RANGE];
  uint8_t* p = handle_range;
  UINT16_TO_STREAM(p, 1);
  UINT16_TO_STREAM(p, 0xFFFF);
  GATTS_HandleValueIndication(conn_id, gatt_cb.handle_of_h_r,
                              GATT_SIZE_OF_SRV_CHG_HNDL_RANGE, handle_range);
}

/** Check sending service chnaged Indication is required or not if required then
 * send the Indication */
void gatt_chk_srv_chg(tGATTS_SRV_CHG* p_srv_chg_clt) {
  VLOG(1) << __func__ << " srv_changed=" << +p_srv_chg_clt->srv_changed;

  if (p_srv_chg_clt->srv_changed) {
    char remote_name[BTM_MAX_REM_BD_NAME_LEN] = "";
    if (btif_storage_get_stored_remote_name(p_srv_chg_clt->bda, remote_name) &&
      (interop_match_name(INTEROP_GATTC_NO_SERVICE_CHANGED_IND,
      remote_name))) {
      VLOG(1) << "discard srv chg - interop matched " << remote_name;
    } else {
      gatt_send_srv_chg_ind(p_srv_chg_clt->bda);
    }
  }
}

/** This function is used to initialize the service changed attribute value */
void gatt_init_srv_chg(void) {
  tGATTS_SRV_CHG_REQ req;
  tGATTS_SRV_CHG_RSP rsp;
  tGATTS_SRV_CHG srv_chg_clt;

  VLOG(1) << __func__;
  if (!gatt_cb.cb_info.p_srv_chg_callback) {
    VLOG(1) << __func__ << " callback not registered yet";
    return;
  }

  bool status = (*gatt_cb.cb_info.p_srv_chg_callback)(
      GATTS_SRV_CHG_CMD_READ_NUM_CLENTS, NULL, &rsp);

  if (!(status && rsp.num_clients)) return;

  VLOG(1) << "num_srv_chg_clt_clients=" << +rsp.num_clients;
  uint8_t num_clients = rsp.num_clients;
  uint8_t i = 1; /* use one based index */
  while ((i <= num_clients) && status) {
    req.client_read_index = i;
    status = (*gatt_cb.cb_info.p_srv_chg_callback)(GATTS_SRV_CHG_CMD_READ_CLENT,
                                                   &req, &rsp);
    if (status) {
      memcpy(&srv_chg_clt, &rsp.srv_chg, sizeof(tGATTS_SRV_CHG));
      if (gatt_add_srv_chg_clt(&srv_chg_clt) == NULL) {
        LOG(ERROR) << "Unable to add a service change client";
        status = false;
      }
    }
    i++;
  }
}

/**This function is process the service changed request */
void gatt_proc_srv_chg(void) {
  RawAddress bda;
  tBT_TRANSPORT transport;
  uint8_t found_idx;

  VLOG(1) << __func__;

  if (!gatt_cb.cb_info.p_srv_chg_callback || !gatt_cb.handle_of_h_r) return;

  gatt_set_srv_chg();
  uint8_t start_idx = 0;
  while (gatt_find_the_connected_bda(start_idx, bda, &found_idx, &transport)) {
    tGATT_TCB* p_tcb = &gatt_cb.tcb[found_idx];

    bool send_indication = true;

    if (gatt_is_srv_chg_ind_pending(p_tcb)) {
      send_indication = false;
      VLOG(1) << "discard srv chg - already has one in the queue";
    }

    // Some LE GATT clients don't respond to service changed indications.
    char remote_name[BTM_MAX_REM_BD_NAME_LEN] = "";
    if (send_indication &&
        btif_storage_get_stored_remote_name(bda, remote_name)) {
      if (interop_match_name(INTEROP_GATTC_NO_SERVICE_CHANGED_IND,
                             remote_name)) {
        VLOG(1) << "discard srv chg - interop matched " << remote_name;
        send_indication = false;
      }
    }

    if (send_indication) gatt_send_srv_chg_ind(bda);

    start_idx = ++found_idx;
  }
}

/** This function set the ch_state in tcb */
void gatt_set_ch_state(tGATT_TCB* p_tcb, tGATT_CH_STATE ch_state) {
  if (!p_tcb) return;

  VLOG(1) << __func__ << ": old=" << +p_tcb->ch_state
          << " new=" << loghex(ch_state);
  p_tcb->ch_state = ch_state;
}

/** This function get the ch_state in tcb */
tGATT_CH_STATE gatt_get_ch_state(tGATT_TCB* p_tcb) {
  if (!p_tcb) return GATT_CH_CLOSE;

  VLOG(1) << "gatt_get_ch_state: ch_state=" << +p_tcb->ch_state;
  return p_tcb->ch_state;
}

/*******************************************************************************
 *
 * Function         gatt_establish_eatt_connect
 *
 * Description      This function calls L2CAP enhanced credit based connection
 *                  API to establish EATT connection.
 *
 *
 * Returns          void
 *
 ******************************************************************************/
void gatt_establish_eatt_connect(tGATT_TCB* p_tcb, uint8_t num_chnls) {
  uint8_t result, i=0;
  tL2CAP_COC_CONN_REQ conn_req;
  tGATT_EBCB* p_eatt_bcb;

  if (gatt_num_eatt_bcbs_in_progress(p_tcb) > 0) {
    VLOG(1) << __func__ << " Already processing EATT connect req";
    return;
  }

  if (p_tcb) {
    conn_req.mtu = p_tcb->mtu_for_eatt;
    conn_req.num_chnls = num_chnls;
    conn_req.psm = BT_PSM_EATT;
    conn_req.p_bd_addr = p_tcb->peer_bda;
    conn_req.transport = p_tcb->transport;
  }

  result = L2CA_ConnectCocReq(&conn_req);
  VLOG(1) << __func__ << " result:" << +result;

  if ((result == L2C_COC_CONNECT_REQ_SUCCESS) || (result == L2C_SOME_CONNS_ACCEPTED)) {
    for (i=0; i<num_chnls; i++) {
      if (conn_req.sr_cids[i] > 0 && p_tcb) {
        p_eatt_bcb = gatt_eatt_bcb_alloc(p_tcb, conn_req.sr_cids[i], true, false);
      }
      else {
        break;
      }
    }
  }

}
