/******************************************************************************
 *
 *  Copyright (C) 1999-2012 Broadcom Corporation
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
 *  This file contains L2CAP utility functions
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bt_common.h"
#include "bt_types.h"
#include "bt_utils.h"
#include "btm_api.h"
#include "btm_int.h"
#include "btu.h"
#include "device/include/controller.h"
#include "hci/include/btsnoop.h"
#include "hcidefs.h"
#include "hcimsgs.h"
#include "l2c_int.h"
#include "l2cdefs.h"
#include "osi/include/allocator.h"
#include "osi/include/time.h"

#define MAX_ACL_SLAVE_LINKS  0x03

/*******************************************************************************
 *
 * Function         l2cu_can_allocate_lcb
 *
 * Description      Look for an unused LCB
 *
 * Returns          true if there is space for one more lcb
 *
 ******************************************************************************/
bool l2cu_can_allocate_lcb(void) {
  for (int i = 0; i < MAX_L2CAP_LINKS; i++) {
    if (!l2cb.lcb_pool[i].in_use) return true;
  }
  return false;
}

/*******************************************************************************
 *
 * Function         l2cu_allocate_lcb
 *
 * Description      Look for an unused LCB
 *
 * Returns          LCB address or NULL if none found
 *
 ******************************************************************************/
tL2C_LCB* l2cu_allocate_lcb(const RawAddress& p_bd_addr, bool is_bonding,
                            tBT_TRANSPORT transport) {
  int xx;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (xx = 0; xx < MAX_L2CAP_LINKS; xx++, p_lcb++) {
    if (!p_lcb->in_use) {
      alarm_free(p_lcb->l2c_lcb_timer);
      alarm_free(p_lcb->info_resp_timer);
      memset(p_lcb, 0, sizeof(tL2C_LCB));

      p_lcb->remote_bd_addr = p_bd_addr;

      p_lcb->in_use = true;
      p_lcb->link_state = LST_DISCONNECTED;
      p_lcb->handle = HCI_INVALID_HANDLE;
      p_lcb->link_flush_tout = 0xFFFF;
      p_lcb->l2c_lcb_timer = alarm_new("l2c_lcb.l2c_lcb_timer");
      p_lcb->info_resp_timer = alarm_new("l2c_lcb.info_resp_timer");
      p_lcb->idle_timeout = l2cb.idle_timeout;
      p_lcb->id = 1; /* spec does not allow '0' */
      p_lcb->is_bonding = is_bonding;
      p_lcb->transport = transport;
      p_lcb->tx_data_len =
          controller_get_interface()->get_ble_default_data_packet_length();
      p_lcb->le_sec_pending_q = fixed_queue_new(SIZE_MAX);

      if (transport == BT_TRANSPORT_LE) {
        l2cb.num_ble_links_active++;
        l2c_ble_link_adjust_allocation();
      } else {
        l2cb.num_links_active++;
        l2c_link_adjust_allocation();
      }
#if (L2CAP_UCD_INCLUDED == TRUE)
      p_lcb->ucd_out_sec_pending_q = fixed_queue_new(SIZE_MAX);
      p_lcb->ucd_in_sec_pending_q = fixed_queue_new(SIZE_MAX);
#endif
      p_lcb->link_xmit_data_q = list_new(NULL);
      return (p_lcb);
    }
  }

  /* If here, no free LCB found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_update_lcb_4_bonding
 *
 * Description      Mark the lcb for bonding. Used when bonding takes place on
 *                  an existing ACL connection.  (Pre-Lisbon devices)
 *
 * Returns          Nothing
 *
 ******************************************************************************/
void l2cu_update_lcb_4_bonding(const RawAddress& p_bd_addr, bool is_bonding) {
  tL2C_LCB* p_lcb = l2cu_find_lcb_by_bd_addr(p_bd_addr, BT_TRANSPORT_BR_EDR);

  if (p_lcb) {
    VLOG(1) << __func__ << " BDA: " << p_bd_addr
            << " is_bonding: " << is_bonding;
    p_lcb->is_bonding = is_bonding;
  }
}

/*******************************************************************************
 *
 * Function         l2cu_release_lcb
 *
 * Description      Release an LCB. All timers will be stopped and freed,
 *                  channels dropped, buffers returned etc.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_release_lcb(tL2C_LCB* p_lcb) {
  tL2C_CCB* p_ccb;

  p_lcb->in_use = false;
  p_lcb->is_bonding = false;

  /* Stop the timers */
  alarm_cancel(p_lcb->l2c_lcb_timer);
  alarm_cancel(p_lcb->info_resp_timer);

  /* Release any unfinished L2CAP packet on this link */
  osi_free_and_reset((void**)&p_lcb->p_hcit_rcv_acl);

#if (BTM_SCO_INCLUDED == TRUE)
  if (p_lcb->transport == BT_TRANSPORT_BR_EDR) /* Release all SCO links */
    btm_remove_sco_links(p_lcb->remote_bd_addr);
#endif

  if (p_lcb->sent_not_acked > 0) {
    if (p_lcb->transport == BT_TRANSPORT_LE) {
      l2cb.controller_le_xmit_window += p_lcb->sent_not_acked;
      if (l2cb.controller_le_xmit_window > l2cb.num_lm_ble_bufs) {
        l2cb.controller_le_xmit_window = l2cb.num_lm_ble_bufs;
      }
    } else {
      l2cb.controller_xmit_window += p_lcb->sent_not_acked;
      if (l2cb.controller_xmit_window > l2cb.num_lm_acl_bufs) {
        l2cb.controller_xmit_window = l2cb.num_lm_acl_bufs;
      }
    }
  }

#if (L2CAP_NUM_FIXED_CHNLS > 0)
  l2cu_process_fixed_disc_cback(p_lcb);
#endif

  /* Ensure no CCBs left on this LCB */
  for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb;
       p_ccb = p_lcb->ccb_queue.p_first_ccb) {
    l2cu_release_ccb(p_ccb);
  }

  /* Tell BTM Acl management the link was removed */
  if ((p_lcb->link_state == LST_CONNECTED) ||
      (p_lcb->link_state == LST_DISCONNECTING))
    btm_acl_removed(p_lcb->remote_bd_addr, p_lcb->transport);

  /* Release any held buffers */
  if (p_lcb->link_xmit_data_q) {
    while (!list_is_empty(p_lcb->link_xmit_data_q)) {
      BT_HDR* p_buf = static_cast<BT_HDR*>(list_front(p_lcb->link_xmit_data_q));
      list_remove(p_lcb->link_xmit_data_q, p_buf);
      osi_free(p_buf);
    }
    list_free(p_lcb->link_xmit_data_q);
    p_lcb->link_xmit_data_q = NULL;
  }

#if (L2CAP_UCD_INCLUDED == TRUE)
  /* clean up any security pending UCD */
  l2c_ucd_delete_sec_pending_q(p_lcb);
#endif

  /* Re-adjust flow control windows make sure it does not go negative */
  if (p_lcb->transport == BT_TRANSPORT_LE) {
    if (l2cb.num_ble_links_active >= 1) l2cb.num_ble_links_active--;

    l2c_ble_link_adjust_allocation();
  } else {
    if (l2cb.num_links_active >= 1) l2cb.num_links_active--;

    l2c_link_adjust_allocation();
  }

  /* Check for ping outstanding */
  if (p_lcb->p_echo_rsp_cb) {
    tL2CA_ECHO_RSP_CB* p_cb = p_lcb->p_echo_rsp_cb;

    /* Zero out the callback in case app immediately calls us again */
    p_lcb->p_echo_rsp_cb = NULL;

    (*p_cb)(L2CAP_PING_RESULT_NO_LINK);
  }

  /* Check and release all the LE COC connections waiting for security */
  if (p_lcb->le_sec_pending_q) {
    while (!fixed_queue_is_empty(p_lcb->le_sec_pending_q)) {
      tL2CAP_SEC_DATA* p_buf =
          (tL2CAP_SEC_DATA*)fixed_queue_try_dequeue(p_lcb->le_sec_pending_q);
      if (p_buf && p_buf->p_callback) {
        p_buf->p_callback(p_lcb->remote_bd_addr, p_lcb->transport,
                          p_buf->p_ref_data, BTM_DEV_RESET);
        osi_free(p_buf);
      }
    }
    fixed_queue_free(p_lcb->le_sec_pending_q, NULL);
    p_lcb->le_sec_pending_q = NULL;
  }
}

/*******************************************************************************
 *
 * Function         l2cu_find_lcb_by_bd_addr
 *
 * Description      Look through all active LCBs for a match based on the
 *                  remote BD address.
 *
 * Returns          pointer to matched LCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_LCB* l2cu_find_lcb_by_bd_addr(const RawAddress& p_bd_addr,
                                   tBT_TRANSPORT transport) {
  int xx;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (xx = 0; xx < MAX_L2CAP_LINKS; xx++, p_lcb++) {
    if ((p_lcb->in_use) && p_lcb->transport == transport &&
        (p_lcb->remote_bd_addr == p_bd_addr)) {
      return (p_lcb);
    }
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_get_conn_role
 *
 * Description      Determine the desired role (master or slave) of a link.
 *                  If already got a slave link, this one must be a master. If
 *                  already got at least 1 link where we are the master, make
 *                  this also a master.
 *
 * Returns          HCI_ROLE_MASTER or HCI_ROLE_SLAVE
 *
 ******************************************************************************/
uint8_t l2cu_get_conn_role(tL2C_LCB* p_this_lcb) { return l2cb.desire_role; }

/*******************************************************************************
 *
 * Function         l2c_is_cmd_rejected
 *
 * Description      Checks if cmd_code is command or response
 *                  If a command it will be rejected per spec.
 *                  This function is used when a illegal packet length is
 *                  detected.
 *
 * Returns          bool    - true if cmd_code is a command and it is rejected,
 *                            false if response code. (command not rejected)
 *
 ******************************************************************************/
bool l2c_is_cmd_rejected(uint8_t cmd_code, uint8_t id, tL2C_LCB* p_lcb) {
  switch (cmd_code) {
    case L2CAP_CMD_CONN_REQ:
    case L2CAP_CMD_CONFIG_REQ:
    case L2CAP_CMD_DISC_REQ:
    case L2CAP_CMD_ECHO_REQ:
    case L2CAP_CMD_INFO_REQ:
    case L2CAP_CMD_AMP_CONN_REQ:
    case L2CAP_CMD_AMP_MOVE_REQ:
    case L2CAP_CMD_BLE_UPDATE_REQ:
      l2cu_send_peer_cmd_reject(p_lcb, L2CAP_CMD_REJ_MTU_EXCEEDED, id,
                                L2CAP_DEFAULT_MTU, 0);
      L2CAP_TRACE_WARNING("Dumping first Command (%d)", cmd_code);
      return true;

    default: /* Otherwise a response */
      return false;
  }
}

/*******************************************************************************
 *
 * Function         l2cu_build_header
 *
 * Description      Builds the L2CAP command packet header
 *
 * Returns          Pointer to allocated packet or NULL if no resources
 *
 ******************************************************************************/
BT_HDR* l2cu_build_header(tL2C_LCB* p_lcb, uint16_t len, uint8_t cmd,
                          uint8_t id) {
  BT_HDR* p_buf = (BT_HDR*)osi_malloc(L2CAP_CMD_BUF_SIZE);
  uint8_t* p;

  p_buf->offset = L2CAP_SEND_CMD_OFFSET;
  p_buf->len =
      len + HCI_DATA_PREAMBLE_SIZE + L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;
  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET;

  /* Put in HCI header - handle + pkt boundary */
  if (p_lcb->transport == BT_TRANSPORT_LE) {
    UINT16_TO_STREAM(p, (p_lcb->handle | (L2CAP_PKT_START_NON_FLUSHABLE
                                          << L2CAP_PKT_TYPE_SHIFT)));
  } else {
#if (L2CAP_NON_FLUSHABLE_PB_INCLUDED == TRUE)
    UINT16_TO_STREAM(p, p_lcb->handle | l2cb.non_flushable_pbf);
#else
    UINT16_TO_STREAM(
        p, (p_lcb->handle | (L2CAP_PKT_START << L2CAP_PKT_TYPE_SHIFT)));
#endif
  }

  UINT16_TO_STREAM(p, len + L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD);
  UINT16_TO_STREAM(p, len + L2CAP_CMD_OVERHEAD);

  if (p_lcb->transport == BT_TRANSPORT_LE) {
    UINT16_TO_STREAM(p, L2CAP_BLE_SIGNALLING_CID);
  } else {
    UINT16_TO_STREAM(p, L2CAP_SIGNALLING_CID);
  }

  /* Put in L2CAP command header */
  UINT8_TO_STREAM(p, cmd);
  UINT8_TO_STREAM(p, id);
  UINT16_TO_STREAM(p, len);

  return (p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_adj_id
 *
 * Description      Checks for valid ID based on specified mask
 *                  and adjusts the id if invalid.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_adj_id(tL2C_LCB* p_lcb, uint8_t adj_mask) {
  if ((adj_mask & L2CAP_ADJ_ZERO_ID) && !p_lcb->id) {
    p_lcb->id++;
  }
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_cmd_reject
 *
 * Description      Build and send an L2CAP "command reject" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_cmd_reject(tL2C_LCB* p_lcb, uint16_t reason, uint8_t rem_id,
                               uint16_t p1, uint16_t p2) {
  uint16_t param_len;
  BT_HDR* p_buf;
  uint8_t* p;

  /* Put in L2CAP packet header */
  if (reason == L2CAP_CMD_REJ_MTU_EXCEEDED)
    param_len = 2;
  else if (reason == L2CAP_CMD_REJ_INVALID_CID)
    param_len = 4;
  else
    param_len = 0;

  p_buf = l2cu_build_header(p_lcb, (uint16_t)(L2CAP_CMD_REJECT_LEN + param_len),
                            L2CAP_CMD_REJECT, rem_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer cmd_rej");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, reason);

  if (param_len >= 2) UINT16_TO_STREAM(p, p1);

  if (param_len >= 4) UINT16_TO_STREAM(p, p2);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_connect_req
 *
 * Description      Build and send an L2CAP "connection request" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_connect_req(tL2C_CCB* p_ccb) {
  BT_HDR* p_buf;
  uint8_t* p;

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;

  p_buf = l2cu_build_header(p_ccb->p_lcb, L2CAP_CONN_REQ_LEN,
                            L2CAP_CMD_CONN_REQ, p_ccb->local_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for conn_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->p_rcb->real_psm);
  UINT16_TO_STREAM(p, p_ccb->local_cid);

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_credit_ecfc_connect_req
 *
 * Description      Build and send an L2CAP "credit based connection request"
 *                  message to the peer.
 *
 * Returns          bool
 *
 ******************************************************************************/
bool l2cu_send_peer_credit_ecfc_connect_req(tL2C_CCB* p_ccb) {
  BT_HDR* p_buf;
  uint8_t* p;
  tL2C_LCB* p_lcb = NULL;
  uint16_t mtu;
  uint16_t mps;
  uint16_t initial_credit;
  uint16_t sr_cids[5] = {0};

  if (!p_ccb) return false;
  p_lcb = p_ccb->p_lcb;

  L2CAP_TRACE_WARNING("%s ", __func__);
  if (p_ccb->p_lcb->transport == BT_TRANSPORT_LE) {
    if(!l2cu_set_data_length_ext(p_ccb))
      L2CAP_TRACE_ERROR("%s Data Length Extension not support ", __func__);
  }

  /* Create an identifier for this packet */
  p_lcb->id++;

  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  l2cu_set_ccbs_local_id(p_ccb);

  int p_len = L2CAP_CMD_CREDIT_BASED_CONN_LEN +
              (2 * (p_ccb->coc_cmd_info.num_coc_chnls));
  p_buf = l2cu_build_header(p_lcb, p_len,
                            L2CAP_CMD_CREDIT_BASED_CONNECTION_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_credit_based_conn_req - no buffer");
    return false;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  mtu = p_ccb->local_conn_cfg.mtu;
  mps = p_ccb->local_conn_cfg.mps;
  initial_credit = p_ccb->local_conn_cfg.credits;

  L2CAP_TRACE_DEBUG(
      "l2cu_send_peer_ecfc_credit_based_conn_req PSM:0x%04x local_cid:%d\
                mtu:%d mps:%d initial_credit:%d",
      p_ccb->p_rcb->real_psm, p_ccb->local_cid, mtu, mps, initial_credit);

  l2cu_get_coc_local_cids(sr_cids, p_ccb);

  UINT16_TO_STREAM(p, p_ccb->p_rcb->real_psm);
  UINT16_TO_STREAM(p, mtu);
  UINT16_TO_STREAM(p, mps);
  UINT16_TO_STREAM(p, initial_credit);
  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    UINT16_TO_STREAM(p, sr_cids[i]);
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
  return true;
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_connect_rsp
 *
 * Description      Build and send an L2CAP "connection response" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_connect_rsp(tL2C_CCB* p_ccb, uint16_t result,
                                uint16_t status) {
  BT_HDR* p_buf;
  uint8_t* p;

  if (result == L2CAP_CONN_PENDING) {
    /* if we already sent pending response */
    if (p_ccb->flags & CCB_FLAG_SENT_PENDING)
      return;
    else
      p_ccb->flags |= CCB_FLAG_SENT_PENDING;
  }

  p_buf = l2cu_build_header(p_ccb->p_lcb, L2CAP_CONN_RSP_LEN,
                            L2CAP_CMD_CONN_RSP, p_ccb->remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for conn_rsp");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->local_cid);
  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p, result);
  UINT16_TO_STREAM(p, status);

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_reject_connection
 *
 * Description      Build and send an L2CAP "connection response neg" message
 *                  to the peer. This function is called when there is no peer
 *                  CCB (non-existant PSM or no resources).
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_reject_connection(tL2C_LCB* p_lcb, uint16_t remote_cid,
                            uint8_t rem_id, uint16_t result) {
  BT_HDR* p_buf;
  uint8_t* p;

  p_buf =
      l2cu_build_header(p_lcb, L2CAP_CONN_RSP_LEN, L2CAP_CMD_CONN_RSP, rem_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for conn_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, 0); /* Local CID of 0   */
  UINT16_TO_STREAM(p, remote_cid);
  UINT16_TO_STREAM(p, result);
  UINT16_TO_STREAM(p, 0); /* Status of 0      */

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_config_req
 *
 * Description      Build and send an L2CAP "configuration request" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_config_req(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  BT_HDR* p_buf;
  uint16_t cfg_len = 0;
  uint8_t* p;

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;

  if (p_cfg->mtu_present)
    cfg_len += L2CAP_CFG_MTU_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->flush_to_present)
    cfg_len += L2CAP_CFG_FLUSH_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->qos_present)
    cfg_len += L2CAP_CFG_QOS_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->fcr_present)
    cfg_len += L2CAP_CFG_FCR_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->fcs_present)
    cfg_len += L2CAP_CFG_FCS_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->ext_flow_spec_present)
    cfg_len += L2CAP_CFG_EXT_FLOW_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;

  p_buf = l2cu_build_header(p_ccb->p_lcb,
                            (uint16_t)(L2CAP_CONFIG_REQ_LEN + cfg_len),
                            L2CAP_CMD_CONFIG_REQ, p_ccb->local_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for conn_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p, p_cfg->flags); /* Flags (continuation) */

  /* Now, put the options */
  if (p_cfg->mtu_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_MTU);
    UINT8_TO_STREAM(p, L2CAP_CFG_MTU_OPTION_LEN);
    UINT16_TO_STREAM(p, p_cfg->mtu);
  }
  if (p_cfg->flush_to_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FLUSH_TOUT);
    UINT8_TO_STREAM(p, L2CAP_CFG_FLUSH_OPTION_LEN);
    UINT16_TO_STREAM(p, p_cfg->flush_to);
  }
  if (p_cfg->qos_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_QOS);
    UINT8_TO_STREAM(p, L2CAP_CFG_QOS_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->qos.qos_unused);
    UINT8_TO_STREAM(p, p_cfg->qos.service_type);
    UINT32_TO_STREAM(p, p_cfg->qos.token_rate);
    UINT32_TO_STREAM(p, p_cfg->qos.token_bucket_size);
    UINT32_TO_STREAM(p, p_cfg->qos.peak_bandwidth);
    UINT32_TO_STREAM(p, p_cfg->qos.latency);
    UINT32_TO_STREAM(p, p_cfg->qos.delay_variation);
  }
  if (p_cfg->fcr_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FCR);
    UINT8_TO_STREAM(p, L2CAP_CFG_FCR_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->fcr.mode);
    UINT8_TO_STREAM(p, p_cfg->fcr.tx_win_sz);
    UINT8_TO_STREAM(p, p_cfg->fcr.max_transmit);
    UINT16_TO_STREAM(p, p_cfg->fcr.rtrans_tout);
    UINT16_TO_STREAM(p, p_cfg->fcr.mon_tout);
    UINT16_TO_STREAM(p, p_cfg->fcr.mps);
  }

  if (p_cfg->fcs_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FCS);
    UINT8_TO_STREAM(p, L2CAP_CFG_FCS_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->fcs);
  }

  if (p_cfg->ext_flow_spec_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_EXT_FLOW);
    UINT8_TO_STREAM(p, L2CAP_CFG_EXT_FLOW_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->ext_flow_spec.id);
    UINT8_TO_STREAM(p, p_cfg->ext_flow_spec.stype);
    UINT16_TO_STREAM(p, p_cfg->ext_flow_spec.max_sdu_size);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.sdu_inter_time);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.access_latency);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.flush_timeout);
  }

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_config_rsp
 *
 * Description      Build and send an L2CAP "configuration response" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_config_rsp(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  BT_HDR* p_buf;
  uint16_t cfg_len = 0;
  uint8_t* p;

  /* Create an identifier for this packet */
  if (p_cfg->mtu_present)
    cfg_len += L2CAP_CFG_MTU_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->flush_to_present)
    cfg_len += L2CAP_CFG_FLUSH_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->qos_present)
    cfg_len += L2CAP_CFG_QOS_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->fcr_present)
    cfg_len += L2CAP_CFG_FCR_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;
  if (p_cfg->ext_flow_spec_present)
    cfg_len += L2CAP_CFG_EXT_FLOW_OPTION_LEN + L2CAP_CFG_OPTION_OVERHEAD;

  p_buf = l2cu_build_header(p_ccb->p_lcb,
                            (uint16_t)(L2CAP_CONFIG_RSP_LEN + cfg_len),
                            L2CAP_CMD_CONFIG_RSP, p_ccb->remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for conn_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p,
                   p_cfg->flags); /* Flags (continuation) Must match request */
  UINT16_TO_STREAM(p, p_cfg->result);

  /* Now, put the options */
  if (p_cfg->mtu_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_MTU);
    UINT8_TO_STREAM(p, L2CAP_CFG_MTU_OPTION_LEN);
    UINT16_TO_STREAM(p, p_cfg->mtu);
  }
  if (p_cfg->flush_to_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FLUSH_TOUT);
    UINT8_TO_STREAM(p, L2CAP_CFG_FLUSH_OPTION_LEN);
    UINT16_TO_STREAM(p, p_cfg->flush_to);
  }
  if (p_cfg->qos_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_QOS);
    UINT8_TO_STREAM(p, L2CAP_CFG_QOS_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->qos.qos_unused);
    UINT8_TO_STREAM(p, p_cfg->qos.service_type);
    UINT32_TO_STREAM(p, p_cfg->qos.token_rate);
    UINT32_TO_STREAM(p, p_cfg->qos.token_bucket_size);
    UINT32_TO_STREAM(p, p_cfg->qos.peak_bandwidth);
    UINT32_TO_STREAM(p, p_cfg->qos.latency);
    UINT32_TO_STREAM(p, p_cfg->qos.delay_variation);
  }
  if (p_cfg->fcr_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_FCR);
    UINT8_TO_STREAM(p, L2CAP_CFG_FCR_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->fcr.mode);
    UINT8_TO_STREAM(p, p_cfg->fcr.tx_win_sz);
    UINT8_TO_STREAM(p, p_cfg->fcr.max_transmit);
    UINT16_TO_STREAM(p, p_ccb->our_cfg.fcr.rtrans_tout);
    UINT16_TO_STREAM(p, p_ccb->our_cfg.fcr.mon_tout);
    UINT16_TO_STREAM(p, p_cfg->fcr.mps);
  }

  if (p_cfg->ext_flow_spec_present) {
    UINT8_TO_STREAM(p, L2CAP_CFG_TYPE_EXT_FLOW);
    UINT8_TO_STREAM(p, L2CAP_CFG_EXT_FLOW_OPTION_LEN);
    UINT8_TO_STREAM(p, p_cfg->ext_flow_spec.id);
    UINT8_TO_STREAM(p, p_cfg->ext_flow_spec.stype);
    UINT16_TO_STREAM(p, p_cfg->ext_flow_spec.max_sdu_size);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.sdu_inter_time);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.access_latency);
    UINT32_TO_STREAM(p, p_cfg->ext_flow_spec.flush_timeout);
  }

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_config_rej
 *
 * Description      Build and send an L2CAP "configuration reject" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_config_rej(tL2C_CCB* p_ccb, uint8_t* p_data,
                               uint16_t data_len, uint16_t rej_len) {
  uint16_t len, cfg_len, buf_space, len1;
  uint8_t *p, *p_hci_len, *p_data_end;
  uint8_t cfg_code;

  L2CAP_TRACE_DEBUG("l2cu_send_peer_config_rej: data_len=%d, rej_len=%d",
                    data_len, rej_len);

  len = BT_HDR_SIZE + HCI_DATA_PREAMBLE_SIZE + L2CAP_PKT_OVERHEAD +
        L2CAP_CMD_OVERHEAD + L2CAP_CONFIG_RSP_LEN;
  len1 = 0xFFFF - len;
  if (rej_len > len1) {
    L2CAP_TRACE_ERROR(
        "L2CAP - cfg_rej pkt size exceeds buffer design max limit.");
    return;
  }

  BT_HDR* p_buf = (BT_HDR*)osi_malloc(len + rej_len);
  p_buf->offset = L2CAP_SEND_CMD_OFFSET;
  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET;

/* Put in HCI header - handle + pkt boundary */
#if (L2CAP_NON_FLUSHABLE_PB_INCLUDED == TRUE)
  if (HCI_NON_FLUSHABLE_PB_SUPPORTED(BTM_ReadLocalFeatures())) {
    UINT16_TO_STREAM(p, (p_ccb->p_lcb->handle | (L2CAP_PKT_START_NON_FLUSHABLE
                                                 << L2CAP_PKT_TYPE_SHIFT)));
  } else
#endif
  {
    UINT16_TO_STREAM(
        p, (p_ccb->p_lcb->handle | (L2CAP_PKT_START << L2CAP_PKT_TYPE_SHIFT)));
  }

  /* Remember the HCI header length position, and save space for it */
  p_hci_len = p;
  p += 2;

  /* Put in L2CAP packet header */
  UINT16_TO_STREAM(p, L2CAP_CMD_OVERHEAD + L2CAP_CONFIG_RSP_LEN + rej_len);
  UINT16_TO_STREAM(p, L2CAP_SIGNALLING_CID);

  /* Put in L2CAP command header */
  UINT8_TO_STREAM(p, L2CAP_CMD_CONFIG_RSP);
  UINT8_TO_STREAM(p, p_ccb->remote_id);

  UINT16_TO_STREAM(p, L2CAP_CONFIG_RSP_LEN + rej_len);

  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p, 0); /* Flags = 0 (no continuation) */
  UINT16_TO_STREAM(p, L2CAP_CFG_UNKNOWN_OPTIONS);

  buf_space = rej_len;

  /* Now, put the rejected options */
  p_data_end = p_data + data_len;
  while (p_data < p_data_end) {
    cfg_code = *p_data;
    cfg_len = *(p_data + 1);

    switch (cfg_code & 0x7F) {
      /* skip known options */
      case L2CAP_CFG_TYPE_MTU:
      case L2CAP_CFG_TYPE_FLUSH_TOUT:
      case L2CAP_CFG_TYPE_QOS:
      case L2CAP_CFG_TYPE_FCR:
      case L2CAP_CFG_TYPE_FCS:
      case L2CAP_CFG_TYPE_EXT_FLOW:
        p_data += cfg_len + L2CAP_CFG_OPTION_OVERHEAD;
        break;

      /* unknown options; copy into rsp if not hints */
      default:
        /* sanity check option length */
        if ((cfg_len + L2CAP_CFG_OPTION_OVERHEAD) <= data_len) {
          if ((cfg_code & 0x80) == 0) {
            if (buf_space >= (cfg_len + L2CAP_CFG_OPTION_OVERHEAD)) {
              memcpy(p, p_data, cfg_len + L2CAP_CFG_OPTION_OVERHEAD);
              p += cfg_len + L2CAP_CFG_OPTION_OVERHEAD;
              buf_space -= (cfg_len + L2CAP_CFG_OPTION_OVERHEAD);
            } else {
              L2CAP_TRACE_WARNING("L2CAP - cfg_rej exceeds allocated buffer");
              p_data = p_data_end; /* force loop exit */
              break;
            }
          }
          p_data += cfg_len + L2CAP_CFG_OPTION_OVERHEAD;
        }
        /* bad length; force loop exit */
        else {
          p_data = p_data_end;
        }
        break;
    }
  }

  len = (uint16_t)(p - p_hci_len - 2);
  UINT16_TO_STREAM(p_hci_len, len);

  p_buf->len = len + 4;

  L2CAP_TRACE_DEBUG("L2CAP - cfg_rej pkt hci_len=%d, l2cap_len=%d", len,
                    (L2CAP_CMD_OVERHEAD + L2CAP_CONFIG_RSP_LEN + rej_len));

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_disc_req
 *
 * Description      Build and send an L2CAP "disconnect request" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_disc_req(tL2C_CCB* p_ccb) {
  BT_HDR *p_buf, *p_buf2;
  uint8_t* p;

  L2CAP_TRACE_DEBUG("%s L2CAP - Local CID %d ", __func__, p_ccb->local_cid);

  if ((!p_ccb) || (p_ccb->p_lcb == NULL)) {
    L2CAP_TRACE_ERROR("%s L2CAP - ccb or lcb invalid", __func__);
    return;
  }

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;

  p_buf = l2cu_build_header(p_ccb->p_lcb, L2CAP_DISC_REQ_LEN,
                            L2CAP_CMD_DISC_REQ, p_ccb->local_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for disc_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p, p_ccb->local_cid);

  /* Move all queued data packets to the LCB. In FCR mode, assume the higher
     layer checks that all buffers are sent before disconnecting.
  */
  if (p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_BASIC_MODE) {
    while ((p_buf2 = (BT_HDR*)fixed_queue_try_dequeue(p_ccb->xmit_hold_q)) !=
           NULL) {
      l2cu_set_acl_hci_header(p_buf2, p_ccb);
      l2c_link_check_send_pkts(p_ccb->p_lcb, p_ccb, p_buf2);
    }
  }

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_disc_rsp
 *
 * Description      Build and send an L2CAP "disconnect response" message
 *                  to the peer.
 *
 *                  This function is passed the parameters for the disconnect
 *                  response instead of the CCB address, as it may be called
 *                  to send a disconnect response when there is no CCB.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_disc_rsp(tL2C_LCB* p_lcb, uint8_t remote_id,
                             uint16_t local_cid, uint16_t remote_cid) {
  BT_HDR* p_buf;
  uint8_t* p;

  p_buf = l2cu_build_header(p_lcb, L2CAP_DISC_RSP_LEN, L2CAP_CMD_DISC_RSP,
                            remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for disc_rsp");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, local_cid);
  UINT16_TO_STREAM(p, remote_cid);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_echo_req
 *
 * Description      Build and send an L2CAP "echo request" message
 *                  to the peer. Note that we do not currently allow
 *                  data in the echo request.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_echo_req(tL2C_LCB* p_lcb, uint8_t* p_data,
                             uint16_t data_len) {
  BT_HDR* p_buf;
  uint8_t* p;

  p_lcb->id++;
  l2cu_adj_id(p_lcb, L2CAP_ADJ_ZERO_ID); /* check for wrap to '0' */

  p_buf = l2cu_build_header(p_lcb, (uint16_t)(L2CAP_ECHO_REQ_LEN + data_len),
                            L2CAP_CMD_ECHO_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for echo_req");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  if (data_len) {
    ARRAY_TO_STREAM(p, p_data, data_len);
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_echo_rsp
 *
 * Description      Build and send an L2CAP "echo response" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_echo_rsp(tL2C_LCB* p_lcb, uint8_t id, uint8_t* p_data,
                             uint16_t data_len) {
  BT_HDR* p_buf;
  uint8_t* p;
  uint16_t maxlen;
  /* Filter out duplicate IDs or if available buffers are low (intruder
   * checking) */
  if (!id || id == p_lcb->cur_echo_id) {
    /* Dump this request since it is illegal */
    L2CAP_TRACE_WARNING("L2CAP ignoring duplicate echo request (%d)", id);
    return;
  } else
    p_lcb->cur_echo_id = id;

  uint16_t acl_data_size =
      controller_get_interface()->get_acl_data_size_classic();
  uint16_t acl_packet_size =
      controller_get_interface()->get_acl_packet_size_classic();
  /* Don't return data if it does not fit in ACL and L2CAP MTU */
  maxlen = (L2CAP_CMD_BUF_SIZE > acl_packet_size)
               ? acl_data_size
               : (uint16_t)L2CAP_CMD_BUF_SIZE;
  maxlen -=
      (uint16_t)(BT_HDR_SIZE + HCI_DATA_PREAMBLE_SIZE + L2CAP_PKT_OVERHEAD +
                 L2CAP_CMD_OVERHEAD + L2CAP_ECHO_RSP_LEN);

  if (data_len > maxlen) data_len = 0;

  p_buf = l2cu_build_header(p_lcb, (uint16_t)(L2CAP_ECHO_RSP_LEN + data_len),
                            L2CAP_CMD_ECHO_RSP, id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for echo_rsp");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  if (data_len) {
    ARRAY_TO_STREAM(p, p_data, data_len);
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_info_req
 *
 * Description      Build and send an L2CAP "info request" message
 *                  to the peer.
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_info_req(tL2C_LCB* p_lcb, uint16_t info_type) {
  BT_HDR* p_buf;
  uint8_t* p;

  /* check for wrap and/or BRCM ID */
  p_lcb->id++;
  l2cu_adj_id(p_lcb, L2CAP_ADJ_ID);

  p_buf = l2cu_build_header(p_lcb, 2, L2CAP_CMD_INFO_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for info_req");
    return;
  }

  L2CAP_TRACE_EVENT("l2cu_send_peer_info_req: type 0x%04x", info_type);

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, info_type);

  p_lcb->w4_info_rsp = true;
  alarm_set_on_mloop(p_lcb->info_resp_timer, L2CAP_WAIT_INFO_RSP_TIMEOUT_MS,
                     l2c_info_resp_timer_timeout, p_lcb);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_info_rsp
 *
 * Description      Build and send an L2CAP "info response" message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_info_rsp(tL2C_LCB* p_lcb, uint8_t remote_id,
                             uint16_t info_type) {
  BT_HDR* p_buf;
  uint8_t* p;
  uint16_t len = L2CAP_INFO_RSP_LEN;

#if (L2CAP_CONFORMANCE_TESTING == TRUE)
  if ((info_type == L2CAP_EXTENDED_FEATURES_INFO_TYPE) &&
      (l2cb.test_info_resp &
       (L2CAP_EXTFEA_ENH_RETRANS | L2CAP_EXTFEA_STREAM_MODE |
        L2CAP_EXTFEA_NO_CRC | L2CAP_EXTFEA_EXT_FLOW_SPEC |
        L2CAP_EXTFEA_FIXED_CHNLS | L2CAP_EXTFEA_EXT_WINDOW |
        L2CAP_EXTFEA_UCD_RECEPTION | L2CAP_EXTFEA_ECFC_MODE)))
#else
  if ((info_type == L2CAP_EXTENDED_FEATURES_INFO_TYPE) &&
      (L2CAP_EXTFEA_SUPPORTED_MASK &
       (L2CAP_EXTFEA_ENH_RETRANS | L2CAP_EXTFEA_STREAM_MODE |
        L2CAP_EXTFEA_NO_CRC | L2CAP_EXTFEA_FIXED_CHNLS |
        L2CAP_EXTFEA_UCD_RECEPTION | L2CAP_EXTFEA_ECFC_MODE)) != 0)
#endif
  {
    len += L2CAP_EXTENDED_FEATURES_ARRAY_SIZE;
  } else if (info_type == L2CAP_FIXED_CHANNELS_INFO_TYPE) {
    len += L2CAP_FIXED_CHNL_ARRAY_SIZE;
  } else if (info_type == L2CAP_CONNLESS_MTU_INFO_TYPE) {
    len += L2CAP_CONNLESS_MTU_INFO_SIZE;
  }

  p_buf = l2cu_build_header(p_lcb, len, L2CAP_CMD_INFO_RSP, remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no buffer for info_rsp");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, info_type);

#if (L2CAP_CONFORMANCE_TESTING == TRUE)
  if ((info_type == L2CAP_EXTENDED_FEATURES_INFO_TYPE) &&
      (l2cb.test_info_resp &
       (L2CAP_EXTFEA_ENH_RETRANS | L2CAP_EXTFEA_STREAM_MODE |
        L2CAP_EXTFEA_UCD_RECEPTION)))
#else
  if ((info_type == L2CAP_EXTENDED_FEATURES_INFO_TYPE) &&
      (L2CAP_EXTFEA_SUPPORTED_MASK &
       (L2CAP_EXTFEA_ENH_RETRANS | L2CAP_EXTFEA_STREAM_MODE |
        L2CAP_EXTFEA_UCD_RECEPTION)) != 0)
#endif
  {
    UINT16_TO_STREAM(p, L2CAP_INFO_RESP_RESULT_SUCCESS);
    if (p_lcb->transport == BT_TRANSPORT_LE) {
      /* optional data are not added for now */
      UINT32_TO_STREAM(p, L2CAP_BLE_EXTFEA_MASK);
    } else {
#if (L2CAP_CONFORMANCE_TESTING == TRUE)
      UINT32_TO_STREAM(p, l2cb.test_info_resp);
#else
#if (L2CAP_NUM_FIXED_CHNLS > 0)
      UINT32_TO_STREAM(p,
                       L2CAP_EXTFEA_SUPPORTED_MASK | L2CAP_EXTFEA_FIXED_CHNLS);
#else
      UINT32_TO_STREAM(p, L2CAP_EXTFEA_SUPPORTED_MASK);
#endif
#endif
    }
  } else if (info_type == L2CAP_FIXED_CHANNELS_INFO_TYPE) {
    UINT16_TO_STREAM(p, L2CAP_INFO_RESP_RESULT_SUCCESS);
    memset(p, 0, L2CAP_FIXED_CHNL_ARRAY_SIZE);

    p[0] = L2CAP_FIXED_CHNL_SIG_BIT;

    if (L2CAP_EXTFEA_SUPPORTED_MASK & L2CAP_EXTFEA_UCD_RECEPTION)
      p[0] |= L2CAP_FIXED_CHNL_CNCTLESS_BIT;

#if (L2CAP_NUM_FIXED_CHNLS > 0)
    {
      int xx;

      for (xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
        /* Skip fixed channels not used on BR/EDR-ACL link */
        if ((xx >= L2CAP_ATT_CID - L2CAP_FIRST_FIXED_CHNL) &&
            (xx <= L2CAP_SMP_CID - L2CAP_FIRST_FIXED_CHNL))
          continue;

        if (l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb != NULL)
          p[(xx + L2CAP_FIRST_FIXED_CHNL) / 8] |=
              1 << ((xx + L2CAP_FIRST_FIXED_CHNL) % 8);
      }
    }
#endif
  } else if (info_type == L2CAP_CONNLESS_MTU_INFO_TYPE) {
    UINT16_TO_STREAM(p, L2CAP_INFO_RESP_RESULT_SUCCESS);
    UINT16_TO_STREAM(p, L2CAP_UCD_MTU);
  } else {
    UINT16_TO_STREAM(
        p, L2CAP_INFO_RESP_RESULT_NOT_SUPPORTED); /* 'not supported' */
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/******************************************************************************
 *
 * Function         l2cu_enqueue_ccb
 *
 * Description      queue CCB by priority. The first CCB is highest priority and
 *                  is served at first. The CCB is queued to an LLCB or an LCB.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_enqueue_ccb(tL2C_CCB* p_ccb) {
  tL2C_CCB* p_ccb1;
  tL2C_CCB_Q* p_q = NULL;

  /* Find out which queue the channel is on
  */
  if (p_ccb->p_lcb != NULL) p_q = &p_ccb->p_lcb->ccb_queue;

  if ((!p_ccb->in_use) || (p_q == NULL)) {
    L2CAP_TRACE_ERROR("%s: CID: 0x%04x ERROR in_use: %u  p_lcb: %p", __func__,
                      p_ccb->local_cid, p_ccb->in_use, p_ccb->p_lcb);
    return;
  }

  L2CAP_TRACE_DEBUG("l2cu_enqueue_ccb CID: 0x%04x  priority: %d",
                    p_ccb->local_cid, p_ccb->ccb_priority);

  /* If the queue is empty, we go at the front */
  if (!p_q->p_first_ccb) {
    p_q->p_first_ccb = p_q->p_last_ccb = p_ccb;
    p_ccb->p_next_ccb = p_ccb->p_prev_ccb = NULL;
  } else {
    p_ccb1 = p_q->p_first_ccb;

    while (p_ccb1 != NULL) {
      /* Insert new ccb at the end of the same priority. Lower number, higher
       * priority */
      if (p_ccb->ccb_priority < p_ccb1->ccb_priority) {
        /* Are we at the head of the queue ? */
        if (p_ccb1 == p_q->p_first_ccb)
          p_q->p_first_ccb = p_ccb;
        else
          p_ccb1->p_prev_ccb->p_next_ccb = p_ccb;

        p_ccb->p_next_ccb = p_ccb1;
        p_ccb->p_prev_ccb = p_ccb1->p_prev_ccb;
        p_ccb1->p_prev_ccb = p_ccb;
        break;
      }

      p_ccb1 = p_ccb1->p_next_ccb;
    }

    /* If we are lower then anyone in the list, we go at the end */
    if (!p_ccb1) {
      /* add new ccb at the end of the list */
      p_q->p_last_ccb->p_next_ccb = p_ccb;

      p_ccb->p_next_ccb = NULL;
      p_ccb->p_prev_ccb = p_q->p_last_ccb;
      p_q->p_last_ccb = p_ccb;
    }
  }

#if (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE)
  /* Adding CCB into round robin service table of its LCB */
  if (p_ccb->p_lcb != NULL) {
    /* if this is the first channel in this priority group */
    if (p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb == 0) {
      /* Set the first channel to this CCB */
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb = p_ccb;
      /* Set the next serving channel in this group to this CCB */
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb = p_ccb;
      /* Initialize quota of this priority group based on its priority */
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].quota =
          L2CAP_GET_PRIORITY_QUOTA(p_ccb->ccb_priority);
    }
    /* increase number of channels in this group */
    p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb++;
  }
#endif
}

/******************************************************************************
 *
 * Function         l2cu_dequeue_ccb
 *
 * Description      dequeue CCB from a queue
 *
 * Returns          -
 *
 ******************************************************************************/
void l2cu_dequeue_ccb(tL2C_CCB* p_ccb) {
  tL2C_CCB_Q* p_q = NULL;

  L2CAP_TRACE_DEBUG("l2cu_dequeue_ccb  CID: 0x%04x", p_ccb->local_cid);

  /* Find out which queue the channel is on
  */
  if (p_ccb->p_lcb != NULL) p_q = &p_ccb->p_lcb->ccb_queue;

  if ((!p_ccb->in_use) || (p_q == NULL) || (p_q->p_first_ccb == NULL)) {
    L2CAP_TRACE_ERROR(
        "l2cu_dequeue_ccb  CID: 0x%04x ERROR in_use: %u  p_lcb: 0x%08x  p_q: "
        "0x%08x  p_q->p_first_ccb: 0x%08x",
        p_ccb->local_cid, p_ccb->in_use, p_ccb->p_lcb, p_q,
        p_q ? p_q->p_first_ccb : 0);
    return;
  }

#if (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE)
  /* Removing CCB from round robin service table of its LCB */
  if (p_ccb->p_lcb != NULL) {
    /* decrease number of channels in this priority group */
    p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb--;

    /* if it was the last channel in the priority group */
    if (p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb == 0) {
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb = NULL;
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb = NULL;
    } else {
      /* if it is the first channel of this group */
      if (p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb == p_ccb) {
        p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb =
            p_ccb->p_next_ccb;
      }
      /* if it is the next serving channel of this group */
      if (p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb == p_ccb) {
        /* simply, start serving from the first channel */
        p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb =
            p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb;
      }
    }
  }
#endif

  if (p_ccb == p_q->p_first_ccb) {
    /* We are removing the first in a queue */
    p_q->p_first_ccb = p_ccb->p_next_ccb;

    if (p_q->p_first_ccb)
      p_q->p_first_ccb->p_prev_ccb = NULL;
    else
      p_q->p_last_ccb = NULL;
  } else if (p_ccb == p_q->p_last_ccb) {
    /* We are removing the last in a queue */
    p_q->p_last_ccb = p_ccb->p_prev_ccb;
    p_q->p_last_ccb->p_next_ccb = NULL;
  } else {
    /* In the middle of a chain. */
    p_ccb->p_prev_ccb->p_next_ccb = p_ccb->p_next_ccb;
    p_ccb->p_next_ccb->p_prev_ccb = p_ccb->p_prev_ccb;
  }

  p_ccb->p_next_ccb = p_ccb->p_prev_ccb = NULL;
}

/******************************************************************************
 *
 * Function         l2cu_change_pri_ccb
 *
 * Description
 *
 * Returns          -
 *
 ******************************************************************************/
void l2cu_change_pri_ccb(tL2C_CCB* p_ccb, tL2CAP_CHNL_PRIORITY priority) {
  if (p_ccb->ccb_priority != priority) {
    /* If CCB is not the only guy on the queue */
    if ((p_ccb->p_next_ccb != NULL) || (p_ccb->p_prev_ccb != NULL)) {
      L2CAP_TRACE_DEBUG("Update CCB list in logical link");

      /* Remove CCB from queue and re-queue it at new priority */
      l2cu_dequeue_ccb(p_ccb);

      p_ccb->ccb_priority = priority;
      l2cu_enqueue_ccb(p_ccb);
    }
#if (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE)
    else {
      /* If CCB is the only guy on the queue, no need to re-enqueue */
      /* update only round robin service data */
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb = 0;
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb = NULL;
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb = NULL;

      p_ccb->ccb_priority = priority;

      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_first_ccb = p_ccb;
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].p_serve_ccb = p_ccb;
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].quota =
          L2CAP_GET_PRIORITY_QUOTA(p_ccb->ccb_priority);
      p_ccb->p_lcb->rr_serv[p_ccb->ccb_priority].num_ccb = 1;
    }
#endif
  }
}

/*******************************************************************************
 *
 * Function         l2cu_allocate_coc_ccbs
 *
 * Description      This function allocates a Channel Control Block and
 *                  attaches it to a link control block. The local CID
 *                  is also assigned.
 *
 * Returns          L2C_COC_CONNECT_REQ_SUCCESS - if all channels are allocated
 *                  L2C_SOME_CONNS_ACCEPTED- if some channles are allocated
 *                  L2C_LCB_NOT_ALLOCATED- if no channels are allocated.
 *
 ******************************************************************************/
uint8_t l2cu_allocate_coc_ccbs(tL2C_LCB* p_lcb, tL2C_CCB** p_ccb,
                            uint8_t* num_chnls) {
  uint8_t allocated_ccbs = 0;
  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  uint8_t status = 0;

  L2CAP_TRACE_WARNING("%s Num_chnls %d", __func__, *num_chnls);
  for (int i = 0; i < *num_chnls; i++) {
    p_ccb[i] = l2cu_allocate_ccb(p_lcb, 0);
    if (p_ccb[i] == NULL) {
      L2CAP_TRACE_WARNING("%s no CCB ALLOCATED", __func__);
    } else {
      allocated_ccbs++;
      p_ccb[i]->remote_credit_count = L2CAP_COC_CREDIT_DEFAULT;
      p_ccb[i]->rx_buf.rcv_data_q =
                    fixed_queue_new(p_ccb[i]->remote_credit_count);
      p_ccb[i]->rx_buf.rx_data_q_size = p_ccb[i]->remote_credit_count;
      sr_cids[i] = p_ccb[i]->local_cid;
      p_ccb[i]->our_cfg.fcr.mode = L2CAP_FCR_ECFC_MODE;
      p_ccb[i]->coc_cmd_info.ecfc_grp_status = 0;
      p_ccb[i]->config_done = IB_CFG_DONE|OB_CFG_DONE;
    }
    L2CAP_TRACE_WARNING("%s Allocated CCB's Count %d ", __func__, allocated_ccbs);
  }

  if (allocated_ccbs == 0) {
    return L2C_NO_RESOURCE_AVALIABLE;
  } else if (allocated_ccbs < *num_chnls) {
    *num_chnls = allocated_ccbs;
    status = L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES;
  }
  for (int i = 0; i < allocated_ccbs; i++) {
    memcpy(p_ccb[i]->coc_cmd_info.ecfc_cids_group, sr_cids,
          sizeof(sr_cids));
  }
  L2CAP_TRACE_WARNING("%s status %d Num_chnls %d", __func__,
                       status, *num_chnls);
  return status;
}

/*******************************************************************************
 *
 * Function         l2cu_allocate_ccb
 *
 * Description      This function allocates a Channel Control Block and
 *                  attaches it to a link control block. The local CID
 *                  is also assigned.
 *
 * Returns          pointer to CCB, or NULL if none
 *
 ******************************************************************************/
tL2C_CCB* l2cu_allocate_ccb(tL2C_LCB* p_lcb, uint16_t cid) {
  tL2C_CCB* p_ccb;
  tL2C_CCB* p_prev;

  L2CAP_TRACE_DEBUG("l2cu_allocate_ccb: cid 0x%04x", cid);

  if (!l2cb.p_free_ccb_first) return (NULL);

  /* If a CID was passed in, use that, else take the first free one */
  if (cid == 0) {
    p_ccb = l2cb.p_free_ccb_first;
    l2cb.p_free_ccb_first = p_ccb->p_next_ccb;
  } else {
    p_prev = NULL;

    p_ccb = &l2cb.ccb_pool[cid - L2CAP_BASE_APPL_CID];

    if (p_ccb == l2cb.p_free_ccb_first)
      l2cb.p_free_ccb_first = p_ccb->p_next_ccb;
    else {
      for (p_prev = l2cb.p_free_ccb_first; p_prev != NULL;
           p_prev = p_prev->p_next_ccb) {
        if (p_prev->p_next_ccb == p_ccb) {
          p_prev->p_next_ccb = p_ccb->p_next_ccb;

          if (p_ccb == l2cb.p_free_ccb_last) l2cb.p_free_ccb_last = p_prev;

          break;
        }
      }
      if (p_prev == NULL) {
        L2CAP_TRACE_ERROR(
            "l2cu_allocate_ccb: could not find CCB for CID 0x%04x in the free "
            "list",
            cid);
        return NULL;
      }
    }
  }

  p_ccb->p_next_ccb = p_ccb->p_prev_ccb = NULL;

  p_ccb->in_use = true;

  /* Get a CID for the connection */
  p_ccb->local_cid = L2CAP_BASE_APPL_CID + (uint16_t)(p_ccb - l2cb.ccb_pool);

  p_ccb->p_lcb = p_lcb;
  p_ccb->p_rcb = NULL;
  p_ccb->should_free_rcb = false;

  /* Set priority then insert ccb into LCB queue (if we have an LCB) */
  p_ccb->ccb_priority = L2CAP_CHNL_PRIORITY_LOW;

  if (p_lcb) l2cu_enqueue_ccb(p_ccb);

  /* clear what peer wants to configure */
  p_ccb->peer_cfg_bits = 0;

  /* Put in default values for configuration */
  memset(&p_ccb->our_cfg, 0, sizeof(tL2CAP_CFG_INFO));
  memset(&p_ccb->peer_cfg, 0, sizeof(tL2CAP_CFG_INFO));

  /* Put in default values for local/peer configurations */
  p_ccb->our_cfg.flush_to = p_ccb->peer_cfg.flush_to = L2CAP_DEFAULT_FLUSH_TO;
  p_ccb->our_cfg.mtu = p_ccb->peer_cfg.mtu = L2CAP_DEFAULT_MTU;
  p_ccb->our_cfg.qos.service_type = p_ccb->peer_cfg.qos.service_type =
      L2CAP_DEFAULT_SERV_TYPE;
  p_ccb->our_cfg.qos.token_rate = p_ccb->peer_cfg.qos.token_rate =
      L2CAP_DEFAULT_TOKEN_RATE;
  p_ccb->our_cfg.qos.token_bucket_size = p_ccb->peer_cfg.qos.token_bucket_size =
      L2CAP_DEFAULT_BUCKET_SIZE;
  p_ccb->our_cfg.qos.peak_bandwidth = p_ccb->peer_cfg.qos.peak_bandwidth =
      L2CAP_DEFAULT_PEAK_BANDWIDTH;
  p_ccb->our_cfg.qos.latency = p_ccb->peer_cfg.qos.latency =
      L2CAP_DEFAULT_LATENCY;
  p_ccb->our_cfg.qos.delay_variation = p_ccb->peer_cfg.qos.delay_variation =
      L2CAP_DEFAULT_DELAY;

  p_ccb->bypass_fcs = 0;
  memset(&p_ccb->ertm_info, 0, sizeof(tL2CAP_ERTM_INFO));
  p_ccb->peer_cfg_already_rejected = false;
  p_ccb->fcr_cfg_tries = L2CAP_MAX_FCR_CFG_TRIES;

  alarm_free(p_ccb->fcrb.ack_timer);
  p_ccb->fcrb.ack_timer = alarm_new("l2c_fcrb.ack_timer");

  /*  CSP408639 Fix: When L2CAP send amp move channel request or receive
    * L2CEVT_AMP_MOVE_REQ do following sequence. Send channel move
    * request -> Stop retrans/monitor timer -> Change channel state to
   * CST_AMP_MOVING. */
  alarm_free(p_ccb->fcrb.mon_retrans_timer);
  p_ccb->fcrb.mon_retrans_timer = alarm_new("l2c_fcrb.mon_retrans_timer");

  p_ccb->ertm_info.preferred_mode =
      L2CAP_FCR_BASIC_MODE; /* Default mode for channel is basic mode */
  p_ccb->ertm_info.allowed_modes =
      L2CAP_FCR_CHAN_OPT_BASIC; /* Default mode for channel is basic mode */
  p_ccb->ertm_info.fcr_rx_buf_size = L2CAP_FCR_RX_BUF_SIZE;
  p_ccb->ertm_info.fcr_tx_buf_size = L2CAP_FCR_TX_BUF_SIZE;
  p_ccb->ertm_info.user_rx_buf_size = L2CAP_USER_RX_BUF_SIZE;
  p_ccb->ertm_info.user_tx_buf_size = L2CAP_USER_TX_BUF_SIZE;
  p_ccb->max_rx_mtu = L2CAP_MTU_SIZE;
  p_ccb->tx_mps = L2CAP_FCR_TX_BUF_SIZE - 32;

  p_ccb->xmit_hold_q = fixed_queue_new(SIZE_MAX);
  p_ccb->fcrb.srej_rcv_hold_q = fixed_queue_new(SIZE_MAX);
  p_ccb->fcrb.retrans_q = fixed_queue_new(SIZE_MAX);
  p_ccb->fcrb.waiting_for_ack_q = fixed_queue_new(SIZE_MAX);

  p_ccb->cong_sent = false;
  p_ccb->buff_quota = 2; /* This gets set after config */

  /* If CCB was reserved Config_Done can already have some value */
  if (cid == 0)
    p_ccb->config_done = 0;
  else {
    L2CAP_TRACE_DEBUG("l2cu_allocate_ccb: cid 0x%04x config_done:0x%x", cid,
                      p_ccb->config_done);
  }

  p_ccb->chnl_state = CST_CLOSED;
  p_ccb->flags = 0;
  p_ccb->tx_data_rate = L2CAP_CHNL_DATA_RATE_LOW;
  p_ccb->rx_data_rate = L2CAP_CHNL_DATA_RATE_LOW;

#if (L2CAP_NON_FLUSHABLE_PB_INCLUDED == TRUE)
  p_ccb->is_flushable = false;
#endif

  alarm_free(p_ccb->l2c_ccb_timer);
  p_ccb->l2c_ccb_timer = alarm_new("l2c.l2c_ccb_timer");

  l2c_link_adjust_chnl_allocation();

  return (p_ccb);
}

/*******************************************************************************
 *
 * Function         l2cu_start_post_bond_timer
 *
 * Description      This function starts the ACL Link inactivity timer after
 *                  dedicated bonding
 *                  This timer can be longer than the normal link inactivity
 *                  timer for some platforms.
 *
 * Returns          bool  - true if idle timer started or disconnect initiated
 *                          false if there's one or more pending CCB's exist
 *
 ******************************************************************************/
bool l2cu_start_post_bond_timer(uint16_t handle) {
  tL2C_LCB* p_lcb = l2cu_find_lcb_by_handle(handle);

  if (!p_lcb) return (true);

  p_lcb->is_bonding = false;

  /* Only start timer if no control blocks allocated */
  if (p_lcb->ccb_queue.p_first_ccb != NULL) return (false);

  /* If no channels on the connection, start idle timeout */
  if ((p_lcb->link_state == LST_CONNECTED) ||
      (p_lcb->link_state == LST_CONNECTING) ||
      (p_lcb->link_state == LST_DISCONNECTING)) {
    period_ms_t timeout_ms = L2CAP_BONDING_TIMEOUT * 1000;

    if (p_lcb->idle_timeout == 0) {
      btsnd_hcic_disconnect(p_lcb->handle, HCI_ERR_PEER_USER);
      p_lcb->link_state = LST_DISCONNECTING;
      timeout_ms = L2CAP_LINK_DISCONNECT_TIMEOUT_MS;
    }
    alarm_set_on_mloop(p_lcb->l2c_lcb_timer, timeout_ms, l2c_lcb_timer_timeout,
                       p_lcb);
    return (true);
  }

  return (false);
}

/*******************************************************************************
 *
 * Function         l2cu_release_ccb
 *
 * Description      This function releases a Channel Control Block. The timer
 *                  is stopped, any attached buffers freed, and the CCB is
 *                  removed from the link control block.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_release_ccb(tL2C_CCB* p_ccb) {
  tL2C_LCB* p_lcb = NULL;
  tL2C_RCB* p_rcb = NULL;

  if(!p_ccb) return;

  L2CAP_TRACE_DEBUG("l2cu_release_ccb: cid 0x%04x  in_use: %u",
                    p_ccb->local_cid, p_ccb->in_use);

  /* If already released, could be race condition */
  if (!p_ccb->in_use) return;

  p_lcb = p_ccb->p_lcb;
  p_rcb = p_ccb->p_rcb;

  if (p_rcb && p_lcb && p_ccb->chnl_state >= CST_OPEN) {
    btsnoop_get_interface()->set_l2cap_channel_close(p_ccb->p_lcb->handle,
                                        p_ccb->local_cid, p_ccb->remote_cid);
  }
#if (defined(LE_L2CAP_CFC_INCLUDED) && (LE_L2CAP_CFC_INCLUDED == TRUE))
  if (p_rcb && p_lcb && (p_rcb->psm != p_rcb->real_psm)) {
#else
  if (p_lcb)
    btsnoop_get_interface()->clear_l2cap_whitelist(
        p_lcb->handle, p_ccb->local_cid, p_ccb->remote_cid);

  if (p_rcb && (p_rcb->psm != p_rcb->real_psm)) {
#endif
    btm_sec_clr_service_by_psm(p_rcb->psm);
  }

  if (p_ccb->should_free_rcb) {
    osi_free(p_rcb);
    p_ccb->p_rcb = NULL;
    p_ccb->should_free_rcb = false;
  }

  if(p_lcb)
    btm_sec_clr_temp_auth_service(p_lcb->remote_bd_addr);

  /* Cancel the timer */
  alarm_cancel(p_ccb->l2c_ccb_timer);

  fixed_queue_free(p_ccb->xmit_hold_q, osi_free);
  p_ccb->xmit_hold_q = NULL;

  l2c_fcr_cleanup(p_ccb);

  /* Channel may not be assigned to any LCB if it was just pre-reserved */
  if ((p_lcb) && ((p_ccb->local_cid >= L2CAP_BASE_APPL_CID)
#if (L2CAP_UCD_INCLUDED == TRUE)
                  || (p_ccb->local_cid == L2CAP_CONNECTIONLESS_CID)
#endif
                      )) {
    l2cu_dequeue_ccb(p_ccb);

    /* Delink the CCB from the LCB */
    p_ccb->p_lcb = NULL;
  }

  /* Put the CCB back on the free pool */
  if (!l2cb.p_free_ccb_first) {
    l2cb.p_free_ccb_first = p_ccb;
    l2cb.p_free_ccb_last = p_ccb;
    p_ccb->p_next_ccb = NULL;
    p_ccb->p_prev_ccb = NULL;
  } else {
    p_ccb->p_next_ccb = NULL;
    p_ccb->p_prev_ccb = l2cb.p_free_ccb_last;
    l2cb.p_free_ccb_last->p_next_ccb = p_ccb;
    l2cb.p_free_ccb_last = p_ccb;
  }

  /* Flag as not in use */
  p_ccb->in_use = false;
  p_ccb->chnl_state = CST_CLOSED;
  p_ccb->coc_cmd_info.disc_pending = 0;
  p_ccb->coc_cmd_info.ecfc_conn_alarm = NULL;
  p_ccb->coc_cmd_info.num_coc_chnls = 0;
  p_ccb->coc_cmd_info.requested_ecfc_chnls = 0;
  p_ccb->remote_cid = 0;
  p_ccb->local_id = 0;

  // reset ECFC reconfig params reference in ccb
  p_ccb->pending_inc_cfg = NULL;
  p_ccb->pending_out_cfg = NULL;

  /* If no channels on the connection, start idle timeout */
  if ((p_lcb) && p_lcb->in_use) {
    if (p_lcb->link_state == LST_CONNECTED) {
      if (!p_lcb->ccb_queue.p_first_ccb) {
        // Closing a security channel on LE device should not start connection
        // timeout
        if (p_lcb->transport == BT_TRANSPORT_LE &&
            p_ccb->local_cid == L2CAP_SMP_CID)
          return;

        l2cu_no_dynamic_ccbs(p_lcb);
      } else {
        /* Link is still active, adjust channel quotas. */
        l2c_link_adjust_chnl_allocation();
      }
    } else if (p_lcb->link_state == LST_CONNECTING) {
      if (!p_lcb->ccb_queue.p_first_ccb) {
        if (p_lcb->transport == BT_TRANSPORT_LE &&
            p_ccb->local_cid == L2CAP_ATT_CID) {
          L2CAP_TRACE_WARNING("%s - disconnecting the LE link", __func__);
          l2cu_no_dynamic_ccbs(p_lcb);
        }
      }
    }
  }
}

/*******************************************************************************
 *
 * Function         l2cu_find_ccb_by_remote_cid
 *
 * Description      Look through all active CCBs on a link for a match based
 *                  on the remote CID.
 *
 * Returns          pointer to matched CCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_CCB* l2cu_find_ccb_by_remote_cid(tL2C_LCB* p_lcb, uint16_t remote_cid) {
  tL2C_CCB* p_ccb;

  /* If LCB is NULL, look through all active links */
  if (!p_lcb) {
    return NULL;
  } else {
    for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb; p_ccb = p_ccb->p_next_ccb)
      if ((p_ccb->in_use) && (p_ccb->remote_cid == remote_cid)) return (p_ccb);
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_allocate_rcb
 *
 * Description      Look through the Registration Control Blocks for a free
 *                  one.
 *
 * Returns          Pointer to the RCB or NULL if not found
 *
 ******************************************************************************/
tL2C_RCB* l2cu_allocate_rcb(uint16_t psm) {
  tL2C_RCB* p_rcb = &l2cb.rcb_pool[0];
  uint16_t xx;

  for (xx = 0; xx < MAX_L2CAP_CLIENTS; xx++, p_rcb++) {
    if (!p_rcb->in_use) {
      p_rcb->in_use = true;
      p_rcb->psm = psm;
#if (L2CAP_UCD_INCLUDED == TRUE)
      p_rcb->ucd.state = L2C_UCD_STATE_UNUSED;
#endif
      return (p_rcb);
    }
  }

  /* If here, no free RCB found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_allocate_coc_rcb
 *
 * Description      Look through the COC Registration Control Blocks for a free
 *                  one.
 *
 * Returns          Pointer to the COC RCB or NULL if not found
 *
 ******************************************************************************/
tL2C_RCB* l2cu_allocate_coc_rcb(uint16_t psm) {
  tL2C_RCB* p_rcb = &l2cb.coc_rcb_pool[0];
  uint16_t xx;

  for (xx = 0; xx < L2CAP_COC_MAX_CLIENTS; xx++, p_rcb++) {
    if (!p_rcb->in_use) {
      p_rcb->in_use = true;
      p_rcb->psm = psm;
#if (L2CAP_UCD_INCLUDED == TRUE)
      p_rcb->ucd.state = L2C_UCD_STATE_UNUSED;
#endif
      return (p_rcb);
    }
  }

  /* If here, no free RCB found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_release_rcb
 *
 * Description      Mark an RCB as no longet in use
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_release_rcb(tL2C_RCB* p_rcb) {
  p_rcb->in_use = false;
  p_rcb->psm = 0;
}

/*******************************************************************************
 *
 * Function         l2cu_release_coc_rcb
 *
 * Description      Mark an LE RCB as no longer in use
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_release_coc_rcb(tL2C_RCB* p_rcb) {
  L2CA_FreeCocPSM(p_rcb->psm);
  p_rcb->in_use = false;
  p_rcb->psm = 0;
}

/*******************************************************************************
 *
 * Function         l2cu_disconnect_chnl
 *
 * Description      Disconnect a channel. Typically, this is due to either
 *                  receiving a bad configuration,  bad packet or max_retries
 *                  expiring.
 *
 ******************************************************************************/
void l2cu_disconnect_chnl(tL2C_CCB* p_ccb) {
  uint16_t local_cid = p_ccb->local_cid;

  if (local_cid >= L2CAP_BASE_APPL_CID) {
    tL2CA_DISCONNECT_IND_CB* p_disc_cb;

    if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_ECFC_MODE) {
      p_disc_cb = p_ccb->p_rcb->api.pL2CA_DisconnectInd_Cb;
    } else {
      p_disc_cb = p_ccb->p_rcb->coc_api.pL2CA_DisconnectInd_Cb;
    }

    L2CAP_TRACE_WARNING("L2CAP - disconnect_chnl CID: 0x%04x", local_cid);

    l2cu_send_peer_disc_req(p_ccb);

    l2cu_release_ccb(p_ccb);

    L2CAP_TRACE_WARNING("L2CAP - disconnect_chnl CID: %d", local_cid);
    (*p_disc_cb)(local_cid, false);
  } else {
    /* failure on the AMP channel, probably need to disconnect ACL */
    L2CAP_TRACE_ERROR("L2CAP - disconnect_chnl CID: 0x%04x Ignored", local_cid);
  }
}

/*******************************************************************************
 *
 * Function         l2cu_find_rcb_by_psm
 *
 * Description      Look through the Registration Control Blocks to see if
 *                  anyone registered to handle the PSM in question
 *
 * Returns          Pointer to the RCB or NULL if not found
 *
 ******************************************************************************/
tL2C_RCB* l2cu_find_rcb_by_psm(uint16_t psm) {
  tL2C_RCB* p_rcb = &l2cb.rcb_pool[0];
  uint16_t xx;

  for (xx = 0; xx < MAX_L2CAP_CLIENTS; xx++, p_rcb++) {
    if ((p_rcb->in_use) && (p_rcb->psm == psm)) return (p_rcb);
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_find_coc_rcb_by_psm
 *
 * Description      Look through the BLE Registration Control Blocks to see if
 *                  anyone registered to handle the PSM in question
 *
 * Returns          Pointer to the BLE RCB or NULL if not found
 *
 ******************************************************************************/
tL2C_RCB* l2cu_find_coc_rcb_by_psm(uint16_t psm) {
  tL2C_RCB* p_rcb = &l2cb.coc_rcb_pool[0];
  uint16_t xx;

  for (xx = 0; xx < L2CAP_COC_MAX_CLIENTS; xx++, p_rcb++) {
    if ((p_rcb->in_use) && (p_rcb->psm == psm)) return (p_rcb);
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_process_peer_cfg_req
 *
 * Description      This function is called when the peer sends us a "config
 *                  request" message. It extracts the configuration of interest
 *                  and saves it in the CCB.
 *
 *                  Note:  Negotiation of the FCR channel type is handled
 *                         internally, all others are passed to the upper layer.
 *
 * Returns          uint8_t - L2CAP_PEER_CFG_OK if passed to upper layer,
 *                            L2CAP_PEER_CFG_UNACCEPTABLE if automatically
 *                                      responded to because parameters are
 *                                      unnacceptable from a specification point
 *                                      of view.
 *                            L2CAP_PEER_CFG_DISCONNECT if no compatible channel
 *                                      modes between the two devices, and shall
 *                                      be closed.
 *
 ******************************************************************************/
uint8_t l2cu_process_peer_cfg_req(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  bool mtu_ok = true;
  bool qos_type_ok = true;
  bool flush_to_ok = true;
  bool fcr_ok = true;
  uint8_t fcr_status;

  /* Ignore FCR parameters for basic mode */
  if (!p_cfg->fcr_present) p_cfg->fcr.mode = L2CAP_FCR_BASIC_MODE;

  /* Save the MTU that our peer can receive */
  if (p_cfg->mtu_present) {
    /* Make sure MTU is at least the minimum */
    if (p_cfg->mtu >= L2CAP_MIN_MTU) {
      /* In basic mode, limit the MTU to our buffer size */
      if ((p_cfg->fcr_present == false) && (p_cfg->mtu > L2CAP_MTU_SIZE))
        p_cfg->mtu = L2CAP_MTU_SIZE;

      /* Save the accepted value in case of renegotiation */
      p_ccb->peer_cfg.mtu = p_cfg->mtu;
      p_ccb->peer_cfg.mtu_present = true;
      p_ccb->peer_cfg_bits |= L2CAP_CH_CFG_MASK_MTU;
    } else /* Illegal MTU value */
    {
      p_cfg->mtu = L2CAP_MIN_MTU;
      mtu_ok = false;
    }
  }
  /* Reload mtu from a previously accepted config request */
  else if (p_ccb->peer_cfg.mtu_present) {
    p_cfg->mtu_present = true;
    p_cfg->mtu = p_ccb->peer_cfg.mtu;
  }

  /* Verify that the flush timeout is a valid value (0 is illegal) */
  if (p_cfg->flush_to_present) {
    if (!p_cfg->flush_to) {
      p_cfg->flush_to = 0xFFFF; /* Infinite retransmissions (spec default) */
      flush_to_ok = false;
    } else /* Save the accepted value in case of renegotiation */
    {
      p_ccb->peer_cfg.flush_to_present = true;
      p_ccb->peer_cfg.flush_to = p_cfg->flush_to;
      p_ccb->peer_cfg_bits |= L2CAP_CH_CFG_MASK_FLUSH_TO;
    }
  }
  /* Reload flush_to from a previously accepted config request */
  else if (p_ccb->peer_cfg.flush_to_present) {
    p_cfg->flush_to_present = true;
    p_cfg->flush_to = p_ccb->peer_cfg.flush_to;
  }

  /* Save the QOS settings the the peer is using */
  if (p_cfg->qos_present) {
    /* Make sure service type is not a reserved value; otherwise let upper
       layer decide if acceptable
    */
    if (p_cfg->qos.service_type <= GUARANTEED) {
      p_ccb->peer_cfg.qos = p_cfg->qos;
      p_ccb->peer_cfg.qos_present = true;
      p_ccb->peer_cfg_bits |= L2CAP_CH_CFG_MASK_QOS;
    } else /* Illegal service type value */
    {
      p_cfg->qos.service_type = BEST_EFFORT;
      qos_type_ok = false;
    }
  }
  /* Reload QOS from a previously accepted config request */
  else if (p_ccb->peer_cfg.qos_present) {
    p_cfg->qos_present = true;
    p_cfg->qos = p_ccb->peer_cfg.qos;
  }

  fcr_status = l2c_fcr_process_peer_cfg_req(p_ccb, p_cfg);
  if (fcr_status == L2CAP_PEER_CFG_DISCONNECT) {
    /* Notify caller to disconnect the channel (incompatible modes) */
    p_cfg->result = L2CAP_CFG_FAILED_NO_REASON;
    p_cfg->mtu_present = p_cfg->qos_present = p_cfg->flush_to_present = 0;

    return (L2CAP_PEER_CFG_DISCONNECT);
  }

  fcr_ok = (fcr_status == L2CAP_PEER_CFG_OK);

  /* Return any unacceptable parameters */
  if (p_ccb->p_lcb == NULL) {
    L2CAP_TRACE_ERROR("%s L2CAP - lcb invalid, clear ccb ", __func__);
    return (L2CAP_PEER_CFG_DISCONNECT);
  } else if (mtu_ok && flush_to_ok && qos_type_ok && fcr_ok) {
    l2cu_adjust_out_mps(p_ccb);
    return (L2CAP_PEER_CFG_OK);
  } else {
    p_cfg->result = L2CAP_CFG_UNACCEPTABLE_PARAMS;

    if (mtu_ok) p_cfg->mtu_present = false;
    if (flush_to_ok) p_cfg->flush_to_present = false;
    if (qos_type_ok) p_cfg->qos_present = false;
    if (fcr_ok) p_cfg->fcr_present = false;

    return (L2CAP_PEER_CFG_UNACCEPTABLE);
  }
}

/*******************************************************************************
 *
 * Function         l2cu_process_peer_cfg_rsp
 *
 * Description      This function is called when the peer sends us a "config
 *                  response" message. It extracts the configuration of interest
 *                  and saves it in the CCB.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_process_peer_cfg_rsp(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  /* If we wanted QoS and the peer sends us a positive response with QoS, use
   * his values */
  if ((p_cfg->qos_present) && (p_ccb->our_cfg.qos_present))
    p_ccb->our_cfg.qos = p_cfg->qos;

  if (p_cfg->fcr_present) {
    /* Save the retransmission and monitor timeout values */
    if (p_cfg->fcr.mode == L2CAP_FCR_ERTM_MODE) {
      p_ccb->peer_cfg.fcr.rtrans_tout = p_cfg->fcr.rtrans_tout;
      p_ccb->peer_cfg.fcr.mon_tout = p_cfg->fcr.mon_tout;
    }

    /* Calculate the max number of packets for which we can delay sending an ack
     */
    if (p_cfg->fcr.tx_win_sz < p_ccb->our_cfg.fcr.tx_win_sz)
      p_ccb->fcrb.max_held_acks = p_cfg->fcr.tx_win_sz / 3;
    else
      p_ccb->fcrb.max_held_acks = p_ccb->our_cfg.fcr.tx_win_sz / 3;

    L2CAP_TRACE_DEBUG(
        "l2cu_process_peer_cfg_rsp(): peer tx_win_sz: %d, our tx_win_sz: %d, "
        "max_held_acks: %d",
        p_cfg->fcr.tx_win_sz, p_ccb->our_cfg.fcr.tx_win_sz,
        p_ccb->fcrb.max_held_acks);
  }
}

/*******************************************************************************
 *
 * Function         l2cu_process_our_cfg_req
 *
 * Description      This function is called when we send a "config request"
 *                  message. It extracts the configuration of interest and saves
 *                  it in the CCB.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_process_our_cfg_req(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  tL2C_LCB* p_lcb;
  uint16_t hci_flush_to;

  /* Save the QOS settings we are using for transmit */
  if (p_cfg->qos_present) {
    p_ccb->our_cfg.qos_present = true;
    p_ccb->our_cfg.qos = p_cfg->qos;
  }

  if (p_cfg->fcr_present) {
    /* Override FCR options if attempting streaming or basic */
    if (p_cfg->fcr.mode == L2CAP_FCR_BASIC_MODE)
      memset(&p_cfg->fcr, 0, sizeof(tL2CAP_FCR_OPTS));
    else {
      /* On BR/EDR, timer values are zero in config request */
      /* On class 2 AMP, timer value in config request shall be non-0 processing
       * time */
      /*                 timer value in config response shall be greater than
       * received processing time */
      p_cfg->fcr.mon_tout = p_cfg->fcr.rtrans_tout = 0;

      if (p_cfg->fcr.mode == L2CAP_FCR_STREAM_MODE)
        p_cfg->fcr.max_transmit = p_cfg->fcr.tx_win_sz = 0;
    }

    /* Set the threshold to send acks (may be updated in the cfg response) */
    p_ccb->fcrb.max_held_acks = p_cfg->fcr.tx_win_sz / 3;

    /* Include FCS option only if peer can handle it */
    if (p_ccb->p_lcb->peer_ext_fea & L2CAP_EXTFEA_NO_CRC) {
      /* FCS check can be bypassed if peer also desires to bypass */
      if (p_cfg->fcs_present && p_cfg->fcs == L2CAP_CFG_FCS_BYPASS)
        p_ccb->bypass_fcs |= L2CAP_CFG_FCS_OUR;
    } else
      p_cfg->fcs_present = false;
  } else {
    p_cfg->fcr.mode = L2CAP_FCR_BASIC_MODE;
  }

  p_ccb->our_cfg.fcr.mode = p_cfg->fcr.mode;
  p_ccb->our_cfg.fcr_present = p_cfg->fcr_present;

  /* Check the flush timeout. If it is lower than the current one used */
  /* then we need to adjust the flush timeout sent to the controller   */
  if (p_cfg->flush_to_present) {
    if ((p_cfg->flush_to == 0) ||
        (p_cfg->flush_to == L2CAP_NO_AUTOMATIC_FLUSH)) {
      /* don't send invalid flush timeout */
      /* SPEC: The sender of the Request shall specify its flush timeout value
       */
      /*       if it differs from the default value of 0xFFFF */
      p_cfg->flush_to_present = false;
    } else {
      p_ccb->our_cfg.flush_to = p_cfg->flush_to;
      p_lcb = p_ccb->p_lcb;

      if (p_cfg->flush_to < p_lcb->link_flush_tout) {
        p_lcb->link_flush_tout = p_cfg->flush_to;

        /* If the timeout is within range of HCI, set the flush timeout */
        if (p_cfg->flush_to <= ((HCI_MAX_AUTOMATIC_FLUSH_TIMEOUT * 5) / 8)) {
          /* Convert flush timeout to 0.625 ms units, with round */
          hci_flush_to = ((p_cfg->flush_to * 8) + 3) / 5;
          btsnd_hcic_write_auto_flush_tout(p_lcb->handle, hci_flush_to);
        }
      }
    }
  }
}

/*******************************************************************************
 *
 * Function         l2cu_process_our_cfg_rsp
 *
 * Description      This function is called when we send the peer a "config
 *                  response" message. It extracts the configuration of interest
 *                  and saves it in the CCB.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_process_our_cfg_rsp(tL2C_CCB* p_ccb, tL2CAP_CFG_INFO* p_cfg) {
  /* If peer wants QoS, we are allowed to change the values in a positive
   * response */
  if ((p_cfg->qos_present) && (p_ccb->peer_cfg.qos_present))
    p_ccb->peer_cfg.qos = p_cfg->qos;
  else
    p_cfg->qos_present = false;

  l2c_fcr_adj_our_rsp_options(p_ccb, p_cfg);
}

/*******************************************************************************
 *
 * Function         l2cu_device_reset
 *
 * Description      This function is called when reset of the device is
 *                  completed.  For all active connection simulate HCI_DISC
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_device_reset(void) {
  int xx;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (xx = 0; xx < MAX_L2CAP_LINKS; xx++, p_lcb++) {
    if ((p_lcb->in_use) && (p_lcb->handle != HCI_INVALID_HANDLE)) {
      l2c_link_hci_disc_comp(p_lcb->handle, (uint8_t)-1);
    }
  }
}

/*******************************************************************************
 *
 * Function         l2cu_create_conn
 *
 * Description      This function initiates an acl connection via HCI
 *
 * Returns          true if successful, false if get buffer fails.
 *
 ******************************************************************************/
bool l2cu_create_conn(tL2C_LCB* p_lcb, tBT_TRANSPORT transport) {
  uint8_t phy = controller_get_interface()->get_le_all_initiating_phys();
  return l2cu_create_conn(p_lcb, transport, phy);
}

bool l2cu_create_conn(tL2C_LCB* p_lcb, tBT_TRANSPORT transport,
                      uint8_t initiating_phys) {
  int xx;
  tL2C_LCB* p_lcb_cur = &l2cb.lcb_pool[0];
#if (BTM_SCO_INCLUDED == TRUE)
  bool is_sco_active;
#endif

  tBT_DEVICE_TYPE dev_type;
  tBLE_ADDR_TYPE addr_type;

  BTM_ReadDevInfo(p_lcb->remote_bd_addr, &dev_type, &addr_type);

  if (transport == BT_TRANSPORT_LE) {
    if (!controller_get_interface()->supports_ble()) return false;

    p_lcb->ble_addr_type = addr_type;
    p_lcb->transport = BT_TRANSPORT_LE;
    p_lcb->initiating_phys = initiating_phys;

    return (l2cble_create_conn(p_lcb));
  }

  /* If there is a connection where we perform as a slave, try to switch roles
     for this connection */
  for (xx = 0, p_lcb_cur = &l2cb.lcb_pool[0]; xx < MAX_L2CAP_LINKS;
       xx++, p_lcb_cur++) {
    if (p_lcb_cur == p_lcb) continue;

    if ((p_lcb_cur->in_use) && (p_lcb_cur->link_role == HCI_ROLE_SLAVE)) {
#if (BTM_SCO_INCLUDED == TRUE)
      /* The LMP_switch_req shall be sent only if the ACL logical transport
      is in active mode, when encryption is disabled, and all synchronous
      logical transports on the same physical link are disabled." */

      /* Check if there is any SCO Active on this BD Address */
      is_sco_active = btm_is_sco_active_by_bdaddr(p_lcb_cur->remote_bd_addr);

      L2CAP_TRACE_API(
          "l2cu_create_conn - btm_is_sco_active_by_bdaddr() is_sco_active = %s",
          (is_sco_active == true) ? "true" : "false");

      if (is_sco_active == true)
        continue; /* No Master Slave switch not allowed when SCO Active */
#endif
      /*4_1_TODO check  if btm_cb.devcb.local_features to be used instead */
      if (HCI_SWITCH_SUPPORTED(BTM_ReadLocalFeatures())) {
        /* mark this lcb waiting for switch to be completed and
           start switch on the other one */
        p_lcb->link_state = LST_CONNECTING_WAIT_SWITCH;
        p_lcb->link_role = HCI_ROLE_MASTER;

        if (BTM_SwitchRole(p_lcb_cur->remote_bd_addr, HCI_ROLE_MASTER, NULL) ==
            BTM_CMD_STARTED) {
          alarm_set_on_mloop(p_lcb->l2c_lcb_timer,
                             L2CAP_LINK_ROLE_SWITCH_TIMEOUT_MS,
                             l2c_lcb_timer_timeout, p_lcb);
          return (true);
        }
      }
    }
  }

  p_lcb->link_state = LST_CONNECTING;

  return (l2cu_create_conn_after_switch(p_lcb));
}

/*******************************************************************************
 *
 * Function         l2cu_get_num_hi_priority
 *
 * Description      Gets the number of high priority channels.
 *
 * Returns
 *
 ******************************************************************************/
uint8_t l2cu_get_num_hi_priority(void) {
  uint8_t no_hi = 0;
  int xx;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (xx = 0; xx < MAX_L2CAP_LINKS; xx++, p_lcb++) {
    if ((p_lcb->in_use) && (p_lcb->acl_priority == L2CAP_PRIORITY_HIGH)) {
      no_hi++;
    }
  }
  return no_hi;
}

/*******************************************************************************
 *
 * Function         l2cu_create_conn_after_switch
 *
 * Description      This function initiates an acl connection via HCI
 *                  If switch required to create connection it is already done.
 *
 * Returns          true if successful, false if get buffer fails.
 *
 ******************************************************************************/

bool l2cu_create_conn_after_switch(tL2C_LCB* p_lcb) {
  uint8_t allow_switch = HCI_CR_CONN_ALLOW_SWITCH;
  tBTM_INQ_INFO* p_inq_info;
  uint8_t page_scan_rep_mode;
  uint8_t page_scan_mode;
  uint16_t clock_offset;
  uint8_t* p_features;
  uint16_t num_slave_acl_links = BTM_GetNumSlaveAclLinks();
  tBTM_SEC_DEV_REC* p_dev_rec = btm_find_dev(p_lcb->remote_bd_addr);
  uint8_t no_hi_prio_chs = l2cu_get_num_hi_priority();

  p_features = BTM_ReadLocalFeatures();

  L2CAP_TRACE_DEBUG(
      "l2cu_create_conn_after_switch :%d num_slave_acl_links :%d no_hi: %d is_bonding:%d",
      l2cb.disallow_switch, num_slave_acl_links, no_hi_prio_chs, p_lcb->is_bonding);
  /* FW team says that we can participant in 4 piconets
   * typically 3 piconet + 1 for scanning.
   * We can enhance the code to count the number of piconets later. */
  if (((!l2cb.disallow_switch && (num_slave_acl_links < MAX_ACL_SLAVE_LINKS)) ||
       (p_lcb->is_bonding && (no_hi_prio_chs == 0))) &&
      HCI_SWITCH_SUPPORTED(p_features))
    allow_switch = HCI_CR_CONN_ALLOW_SWITCH;
  else
    allow_switch = HCI_CR_CONN_NOT_ALLOW_SWITCH;

  p_lcb->link_state = LST_CONNECTING;

  /* Check with the BT manager if details about remote device are known */
  p_inq_info = BTM_InqDbRead(p_lcb->remote_bd_addr);
  if ((p_inq_info != NULL) &&
      (p_inq_info->results.inq_result_type & BTM_INQ_RESULT_BR)) {
    page_scan_rep_mode = p_inq_info->results.page_scan_rep_mode;
    page_scan_mode = p_inq_info->results.page_scan_mode;
    clock_offset = (uint16_t)(p_inq_info->results.clock_offset);
  } else {
    /* No info known. Use default settings */
    page_scan_rep_mode = HCI_PAGE_SCAN_REP_MODE_R1;
    page_scan_mode = HCI_MANDATARY_PAGE_SCAN_MODE;

    clock_offset = (p_dev_rec) ? p_dev_rec->clock_offset : 0;
  }

  btsnd_hcic_create_conn(
      p_lcb->remote_bd_addr, (HCI_PKT_TYPES_MASK_DM1 | HCI_PKT_TYPES_MASK_DH1 |
                              HCI_PKT_TYPES_MASK_DM3 | HCI_PKT_TYPES_MASK_DH3 |
                              HCI_PKT_TYPES_MASK_DM5 | HCI_PKT_TYPES_MASK_DH5),
      page_scan_rep_mode, page_scan_mode, clock_offset, allow_switch);

  btm_acl_update_busy_level(BTM_BLI_PAGE_EVT);

  /* if ACL collision occurs and if remote retrail time matches
  with DUT link time out ,it may lead to collision again.
  hence wait random timeout (20 - 29 sec) */
  period_ms_t interval_ms = L2CAP_LINK_CONNECT_TIMEOUT_MS +
                            ((time_get_os_boottime_ms() % 10) *1000);
  alarm_set_on_mloop(p_lcb->l2c_lcb_timer, interval_ms,
                     l2c_lcb_timer_timeout, p_lcb);

  return (true);
}

/*******************************************************************************
 *
 * Function         l2cu_find_lcb_by_state
 *
 * Description      Look through all active LCBs for a match based on the
 *                  LCB state.
 *
 * Returns          pointer to first matched LCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_LCB* l2cu_find_lcb_by_state(tL2C_LINK_STATE state) {
  uint16_t i;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (i = 0; i < MAX_L2CAP_LINKS; i++, p_lcb++) {
    if ((p_lcb->in_use) && (p_lcb->link_state == state)) {
      return (p_lcb);
    }
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_lcb_disconnecting
 *
 * Description      On each active lcb, check if the lcb is in disconnecting
 *                  state, or if there are no ccb's on the lcb (implying
                    idle timeout is running), or if last ccb on the link
                    is in disconnecting state.
 *
 * Returns          true if any of above conditions met, false otherwise
 *
 ******************************************************************************/
bool l2cu_lcb_disconnecting(void) {
  tL2C_LCB* p_lcb;
  tL2C_CCB* p_ccb;
  uint16_t i;
  bool status = false;

  p_lcb = &l2cb.lcb_pool[0];

  for (i = 0; i < MAX_L2CAP_LINKS; i++, p_lcb++) {
    if (p_lcb->in_use) {
      /* no ccbs on lcb, or lcb is in disconnecting state */
      if ((!p_lcb->ccb_queue.p_first_ccb) ||
          (p_lcb->link_state == LST_DISCONNECTING)) {
        status = true;
        break;
      }
      /* only one ccb left on lcb */
      else if (p_lcb->ccb_queue.p_first_ccb == p_lcb->ccb_queue.p_last_ccb) {
        p_ccb = p_lcb->ccb_queue.p_first_ccb;

        if ((p_ccb->in_use) &&
            ((p_ccb->chnl_state == CST_W4_L2CAP_DISCONNECT_RSP) ||
             (p_ccb->chnl_state == CST_W4_L2CA_DISCONNECT_RSP))) {
          status = true;
          break;
        }
      }
    }
  }
  return status;
}

/*******************************************************************************
 *
 * Function         l2cu_set_acl_priority
 *
 * Description      Sets the transmission priority for a channel.
 *                  (For initial implementation only two values are valid.
 *                  L2CAP_PRIORITY_NORMAL and L2CAP_PRIORITY_HIGH).
 *
 * Returns          true if a valid channel, else false
 *
 ******************************************************************************/

bool l2cu_set_acl_priority(const RawAddress& bd_addr, uint8_t priority,
                           bool reset_after_rs) {
  tL2C_LCB* p_lcb;
  uint8_t* pp;
  uint8_t command[HCI_BRCM_ACL_PRIORITY_PARAM_SIZE];
  uint8_t vs_param;

  APPL_TRACE_EVENT("SET ACL PRIORITY %d", priority);

  /* Find the link control block for the acl channel */
  p_lcb = l2cu_find_lcb_by_bd_addr(bd_addr, BT_TRANSPORT_BR_EDR);
  if (p_lcb == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - no LCB for L2CA_SetAclPriority");
    return (false);
  }

  if (BTM_IS_BRCM_CONTROLLER()) {
    /* Called from above L2CAP through API; send VSC if changed */
    if ((!reset_after_rs && (priority != p_lcb->acl_priority)) ||
        /* Called because of a master/slave role switch; if high resend VSC */
        (reset_after_rs && p_lcb->acl_priority == L2CAP_PRIORITY_HIGH)) {
      pp = command;

      vs_param = (priority == L2CAP_PRIORITY_HIGH) ? HCI_BRCM_ACL_PRIORITY_HIGH
                                                   : HCI_BRCM_ACL_PRIORITY_LOW;

      UINT16_TO_STREAM(pp, p_lcb->handle);
      UINT8_TO_STREAM(pp, vs_param);

      BTM_VendorSpecificCommand(HCI_BRCM_SET_ACL_PRIORITY,
                                HCI_BRCM_ACL_PRIORITY_PARAM_SIZE, command,
                                NULL);
    }
  }

  /* Adjust lmp buffer allocation for this channel if priority changed */
  if (p_lcb->acl_priority != priority) {
    p_lcb->acl_priority = priority;
    l2c_link_adjust_allocation();
  }
  return (true);
}

#if (L2CAP_NON_FLUSHABLE_PB_INCLUDED == TRUE)
/******************************************************************************
 *
 * Function         l2cu_set_non_flushable_pbf
 *
 * Description      set L2CAP_PKT_START_NON_FLUSHABLE if controller supoorts
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_set_non_flushable_pbf(bool is_supported) {
  if (is_supported)
    l2cb.non_flushable_pbf =
        (L2CAP_PKT_START_NON_FLUSHABLE << L2CAP_PKT_TYPE_SHIFT);
  else
    l2cb.non_flushable_pbf = (L2CAP_PKT_START << L2CAP_PKT_TYPE_SHIFT);
}
#endif

/*******************************************************************************
 *
 * Function         l2cu_resubmit_pending_sec_req
 *
 * Description      This function is called when required security procedures
 *                  are completed and any pending requests can be re-submitted.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_resubmit_pending_sec_req(const RawAddress* p_bda) {
  tL2C_LCB* p_lcb;
  tL2C_CCB* p_ccb;
  tL2C_CCB* p_next_ccb;
  int xx;

  L2CAP_TRACE_DEBUG("l2cu_resubmit_pending_sec_req  p_bda: 0x%08x", p_bda);

  /* If we are called with a BDA, only resubmit for that BDA */
  if (p_bda) {
    p_lcb = l2cu_find_lcb_by_bd_addr(*p_bda, BT_TRANSPORT_BR_EDR);

    /* If we don't have one, this is an error */
    if (p_lcb) {
      /* For all channels, send the event through their FSMs */
      for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb; p_ccb = p_next_ccb) {
        p_next_ccb = p_ccb->p_next_ccb;
        if ((p_ccb->our_cfg.fcr.mode == L2CAP_FCR_ECFC_MODE)
          && (p_ccb->coc_cmd_info.ecfc_grp_status &
              L2CAP_ECFC_SEC_PENDING_CB)) {
          L2CAP_TRACE_WARNING("L2CEVT_SEC_RE_SEND_CMD for cid %d", p_ccb->local_cid);
          continue;
        }
        l2c_csm_execute(p_ccb, L2CEVT_SEC_RE_SEND_CMD, NULL);
      }
    } else {
      L2CAP_TRACE_WARNING("l2cu_resubmit_pending_sec_req - unknown BD_ADDR");
    }
  } else {
    /* No BDA pasesed in, so check all links */
    for (xx = 0, p_lcb = &l2cb.lcb_pool[0]; xx < MAX_L2CAP_LINKS;
         xx++, p_lcb++) {
      if (p_lcb->in_use) {
        /* For all channels, send the event through their FSMs */
        for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb; p_ccb = p_next_ccb) {
          p_next_ccb = p_ccb->p_next_ccb;
          l2c_csm_execute(p_ccb, L2CEVT_SEC_RE_SEND_CMD, NULL);
        }
      }
    }
  }
}

#if (L2CAP_CONFORMANCE_TESTING == TRUE)
/*******************************************************************************
 *
 * Function         l2cu_set_info_rsp_mask
 *
 * Description      This function allows the script wrapper to change the
 *                  info resp mask for conformance testing.
 *
 * Returns          pointer to CCB, or NULL if none
 *
 ******************************************************************************/
void l2cu_set_info_rsp_mask(uint32_t mask) { l2cb.test_info_resp = mask; }
#endif /* L2CAP_CONFORMANCE_TESTING */

/*******************************************************************************
 *
 * Function         l2cu_adjust_out_mps
 *
 * Description      Sets our MPS based on current controller capabilities
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_adjust_out_mps(tL2C_CCB* p_ccb) {
  uint16_t packet_size;

  /* on the tx side MTU is selected based on packet size of the controller */
  packet_size = btm_get_max_packet_size(p_ccb->p_lcb->remote_bd_addr);

  if (packet_size <= (L2CAP_PKT_OVERHEAD + L2CAP_FCR_OVERHEAD +
                      L2CAP_SDU_LEN_OVERHEAD + L2CAP_FCS_LEN)) {
    /* something is very wrong */
    L2CAP_TRACE_ERROR(
        "l2cu_adjust_out_mps bad packet size: %u  will use MPS: %u",
        packet_size, p_ccb->peer_cfg.fcr.mps);
    p_ccb->tx_mps = p_ccb->peer_cfg.fcr.mps;
  } else {
    packet_size -= (L2CAP_PKT_OVERHEAD + L2CAP_FCR_OVERHEAD +
                    L2CAP_SDU_LEN_OVERHEAD + L2CAP_FCS_LEN);

    /* We try to negotiate MTU that each packet can be split into whole
    number of max packets.  For example if link is 1.2 max packet size is 339
    bytes.
    At first calculate how many whole packets it is.  MAX L2CAP is 1691 + 4
    overhead.
    1695, that will be 5 Dh5 packets.  Now maximum L2CAP packet is
    5 * 339 = 1695. Minus 4 bytes L2CAP header 1691.

    For EDR 2.0 packet size is 1027.  So we better send RFCOMM packet as 1 3DH5
    packet
    1 * 1027 = 1027.  Minus 4 bytes L2CAP header 1023.  */
    if (p_ccb->peer_cfg.fcr.mps >= packet_size)
      p_ccb->tx_mps = p_ccb->peer_cfg.fcr.mps / packet_size * packet_size;
    else
      p_ccb->tx_mps = p_ccb->peer_cfg.fcr.mps;

    L2CAP_TRACE_DEBUG(
        "l2cu_adjust_out_mps use %d   Based on peer_cfg.fcr.mps: %u  "
        "packet_size: %u",
        p_ccb->tx_mps, p_ccb->peer_cfg.fcr.mps, packet_size);
  }
}

/*******************************************************************************
 *
 * Function         l2cu_initialize_fixed_ccb
 *
 * Description      Initialize a fixed channel's CCB
 *
 * Returns          true or false
 *
 ******************************************************************************/
bool l2cu_initialize_fixed_ccb(tL2C_LCB* p_lcb, uint16_t fixed_cid,
                               tL2CAP_FCR_OPTS* p_fcr) {
#if (L2CAP_NUM_FIXED_CHNLS > 0)
  tL2C_CCB* p_ccb;

  /* If we already have a CCB, then simply return */
  p_ccb = p_lcb->p_fixed_ccbs[fixed_cid - L2CAP_FIRST_FIXED_CHNL];
  if ((p_ccb != NULL) && p_ccb->in_use) {
    /*
     * NOTE: The "in_use" check is needed to ignore leftover entries
     * that have been already released by l2cu_release_ccb().
     */
    return (true);
  }

  p_ccb = l2cu_allocate_ccb(NULL, 0);
  if (p_ccb == NULL) return (false);

  alarm_cancel(p_lcb->l2c_lcb_timer);

  /* Set CID for the connection */
  p_ccb->local_cid = fixed_cid;
  p_ccb->remote_cid = fixed_cid;

  p_ccb->is_flushable = false;

  if (p_fcr) {
    /* Set the FCR parameters. For now, we will use default pools */
    p_ccb->our_cfg.fcr = p_ccb->peer_cfg.fcr = *p_fcr;

    p_ccb->ertm_info.fcr_rx_buf_size = L2CAP_FCR_RX_BUF_SIZE;
    p_ccb->ertm_info.fcr_tx_buf_size = L2CAP_FCR_TX_BUF_SIZE;
    p_ccb->ertm_info.user_rx_buf_size = L2CAP_USER_RX_BUF_SIZE;
    p_ccb->ertm_info.user_tx_buf_size = L2CAP_USER_TX_BUF_SIZE;

    p_ccb->fcrb.max_held_acks = p_fcr->tx_win_sz / 3;
  }

  /* Link ccb to lcb and lcb to ccb */
  p_lcb->p_fixed_ccbs[fixed_cid - L2CAP_FIRST_FIXED_CHNL] = p_ccb;
  p_ccb->p_lcb = p_lcb;

  /* There is no configuration, so if the link is up, the channel is up */
  if (p_lcb->link_state == LST_CONNECTED) p_ccb->chnl_state = CST_OPEN;

  /* Set the default idle timeout value to use */
  p_ccb->fixed_chnl_idle_tout =
      l2cb.fixed_reg[fixed_cid - L2CAP_FIRST_FIXED_CHNL].default_idle_tout;
#endif
  return (true);
}

/*******************************************************************************
 *
 * Function         l2cu_no_dynamic_ccbs
 *
 * Description      Handles the case when there are no more dynamic CCBs. If
 *                  there are any fixed CCBs, start the longest of the fixed CCB
 *                  timeouts, otherwise start the default link idle timeout or
 *                  disconnect.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_no_dynamic_ccbs(tL2C_LCB* p_lcb) {
  tBTM_STATUS rc;
  period_ms_t timeout_ms = p_lcb->idle_timeout * 1000;
  bool start_timeout = true;

#if (L2CAP_NUM_FIXED_CHNLS > 0)
  int xx;

  for (xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
    if ((p_lcb->p_fixed_ccbs[xx] != NULL) &&
        (p_lcb->p_fixed_ccbs[xx]->fixed_chnl_idle_tout * 1000 > timeout_ms)) {

      if (p_lcb->p_fixed_ccbs[xx]->fixed_chnl_idle_tout == L2CAP_NO_IDLE_TIMEOUT) {
         L2CAP_TRACE_DEBUG("%s NO IDLE timeout set for fixed cid 0x%04x", __func__,
            p_lcb->p_fixed_ccbs[xx]->local_cid);
         start_timeout = false;
      }
      timeout_ms = p_lcb->p_fixed_ccbs[xx]->fixed_chnl_idle_tout * 1000;
    }
  }
#endif

  /* If the link is pairing, do not mess with the timeouts */
  if (p_lcb->is_bonding) return;

  if (timeout_ms == 0) {
    L2CAP_TRACE_DEBUG(
        "l2cu_no_dynamic_ccbs() IDLE timer 0, disconnecting link");

    rc = btm_sec_disconnect(p_lcb->handle, HCI_ERR_PEER_USER);
    if (rc == BTM_CMD_STARTED) {
      l2cu_process_fixed_disc_cback(p_lcb);
      p_lcb->link_state = LST_DISCONNECTING;
      timeout_ms = L2CAP_LINK_DISCONNECT_TIMEOUT_MS;
    } else if (rc == BTM_SUCCESS) {
      l2cu_process_fixed_disc_cback(p_lcb);
      /* BTM SEC will make sure that link is release (probably after pairing is
       * done) */
      p_lcb->link_state = LST_DISCONNECTING;
      start_timeout = false;
    } else if (p_lcb->is_bonding) {
      btsnd_hcic_disconnect(p_lcb->handle, HCI_ERR_PEER_USER);
      l2cu_process_fixed_disc_cback(p_lcb);
      p_lcb->link_state = LST_DISCONNECTING;
      timeout_ms = L2CAP_LINK_DISCONNECT_TIMEOUT_MS;
    } else {
      /* probably no buffer to send disconnect */
      timeout_ms = BT_1SEC_TIMEOUT_MS;
    }
  }

  if (start_timeout) {
    L2CAP_TRACE_DEBUG("%s starting IDLE timeout: %d ms", __func__, timeout_ms);
    alarm_set_on_mloop(p_lcb->l2c_lcb_timer, timeout_ms, l2c_lcb_timer_timeout,
                       p_lcb);
  } else {
    alarm_cancel(p_lcb->l2c_lcb_timer);
  }
}

#if (L2CAP_NUM_FIXED_CHNLS > 0)
/*******************************************************************************
 *
 * Function         l2cu_process_fixed_chnl_resp
 *
 * Description      handle a fixed channel response (or lack thereof)
 *                  if the link failed, or a fixed channel response was
 *                  not received, the bitfield is all zeros.
 *
 ******************************************************************************/
void l2cu_process_fixed_chnl_resp(tL2C_LCB* p_lcb) {
  if (p_lcb->transport == BT_TRANSPORT_BR_EDR) {
    /* ignore all not assigned BR/EDR channels */
    p_lcb->peer_chnl_mask[0] &=
        (L2CAP_FIXED_CHNL_SIG_BIT | L2CAP_FIXED_CHNL_CNCTLESS_BIT |
         L2CAP_FIXED_CHNL_SMP_BR_BIT);
  } else
    p_lcb->peer_chnl_mask[0] = l2cb.l2c_ble_fixed_chnls_mask;

  /* Tell all registered fixed channels about the connection */
  for (int xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
    uint16_t channel_id = xx + L2CAP_FIRST_FIXED_CHNL;

    /* See BT Spec Ver 5.0 | Vol 3, Part A 2.1 table 2.1 and 2.2 */

    /* skip sending LE fix channel callbacks on BR/EDR links */
    if (p_lcb->transport == BT_TRANSPORT_BR_EDR &&
        channel_id >= L2CAP_ATT_CID && channel_id <= L2CAP_SMP_CID)
      continue;

    /* skip sending BR fix channel callbacks on LE links */
    if (p_lcb->transport == BT_TRANSPORT_LE && channel_id == L2CAP_SMP_BR_CID)
      continue;

    if (!l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb) continue;

    if (p_lcb->peer_chnl_mask[(channel_id) / 8] & (1 << ((channel_id) % 8))) {
      if (p_lcb->p_fixed_ccbs[xx])
        p_lcb->p_fixed_ccbs[xx]->chnl_state = CST_OPEN;
      (*l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb)(
          channel_id, p_lcb->remote_bd_addr, true, 0, p_lcb->transport);
    } else {
      (*l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb)(
          channel_id, p_lcb->remote_bd_addr, false, p_lcb->disc_reason,
          p_lcb->transport);

      if (p_lcb->p_fixed_ccbs[xx]) {
        l2cu_release_ccb(p_lcb->p_fixed_ccbs[xx]);
        p_lcb->p_fixed_ccbs[xx] = NULL;
      }
    }
  }
}
#endif

/*******************************************************************************
 *
 * Function         l2cu_process_fixed_disc_cback
 *
 * Description      send l2cap fixed channel disconnection callback to the
 *                  application
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_process_fixed_disc_cback(tL2C_LCB* p_lcb) {
#if (L2CAP_NUM_FIXED_CHNLS > 0)

  /* Select peer channels mask to use depending on transport */
  uint8_t peer_channel_mask = p_lcb->peer_chnl_mask[0];

  // For LE, reset the stored peer channel mask
  if (p_lcb->transport == BT_TRANSPORT_LE) p_lcb->peer_chnl_mask[0] = 0;

  for (int xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
    if (p_lcb->p_fixed_ccbs[xx]) {
      if (p_lcb->p_fixed_ccbs[xx] != p_lcb->p_pending_ccb) {
        tL2C_CCB* p_l2c_chnl_ctrl_block;
        p_l2c_chnl_ctrl_block = p_lcb->p_fixed_ccbs[xx];
        p_lcb->p_fixed_ccbs[xx] = NULL;
        l2cu_release_ccb(p_l2c_chnl_ctrl_block);
        (*l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb)(
            xx + L2CAP_FIRST_FIXED_CHNL, p_lcb->remote_bd_addr, false,
            p_lcb->disc_reason, p_lcb->transport);
      }
    } else if ((peer_channel_mask & ((uint64_t)1 << (xx + L2CAP_FIRST_FIXED_CHNL))) &&
               (l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb != NULL))
      (*l2cb.fixed_reg[xx].pL2CA_FixedConn_Cb)(
          xx + L2CAP_FIRST_FIXED_CHNL, p_lcb->remote_bd_addr, false,
          p_lcb->disc_reason, p_lcb->transport);
  }
#endif
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_par_req
 *
 * Description      Build and send a BLE parameter update request message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_par_req(tL2C_LCB* p_lcb, uint16_t min_int,
                                uint16_t max_int, uint16_t latency,
                                uint16_t timeout) {
  BT_HDR* p_buf;
  uint8_t* p;

  /* Create an identifier for this packet */
  p_lcb->id++;
  l2cu_adj_id(p_lcb, L2CAP_ADJ_ID);

  p_buf = l2cu_build_header(p_lcb, L2CAP_CMD_BLE_UPD_REQ_LEN,
                            L2CAP_CMD_BLE_UPDATE_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_par_req - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, min_int);
  UINT16_TO_STREAM(p, max_int);
  UINT16_TO_STREAM(p, latency);
  UINT16_TO_STREAM(p, timeout);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_par_rsp
 *
 * Description      Build and send a BLE parameter update response message
 *                  to the peer.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_par_rsp(tL2C_LCB* p_lcb, uint16_t reason,
                                uint8_t rem_id) {
  BT_HDR* p_buf;
  uint8_t* p;

  p_buf = l2cu_build_header(p_lcb, L2CAP_CMD_BLE_UPD_RSP_LEN,
                            L2CAP_CMD_BLE_UPDATE_RSP, rem_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_par_rsp - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, reason);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_credit_based_conn_req
 *
 * Description      Build and send a BLE packet to establish LE connection
 *                  oriented L2CAP channel.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_credit_based_conn_req(tL2C_CCB* p_ccb) {
  BT_HDR* p_buf;
  uint8_t* p;
  tL2C_LCB* p_lcb = NULL;
  uint16_t mtu;
  uint16_t mps;
  uint16_t initial_credit;

  if (!p_ccb) return;
  p_lcb = p_ccb->p_lcb;

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;

  p_buf = l2cu_build_header(p_lcb, L2CAP_CMD_BLE_CREDIT_BASED_CONN_REQ_LEN,
                            L2CAP_CMD_BLE_CREDIT_BASED_CONN_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_credit_based_conn_req - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  mtu = p_ccb->local_conn_cfg.mtu;
  mps = p_ccb->local_conn_cfg.mps;
  initial_credit = p_ccb->local_conn_cfg.credits;

  L2CAP_TRACE_DEBUG(
      "l2cu_send_peer_ble_credit_based_conn_req PSM:0x%04x local_cid:%d\
                mtu:%d mps:%d initial_credit:%d",
      p_ccb->p_rcb->real_psm, p_ccb->local_cid, mtu, mps, initial_credit);

  UINT16_TO_STREAM(p, p_ccb->p_rcb->real_psm);
  UINT16_TO_STREAM(p, p_ccb->local_cid);
  UINT16_TO_STREAM(p, mtu);
  UINT16_TO_STREAM(p, mps);
  UINT16_TO_STREAM(p, initial_credit);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_reject_ble_connection
 *
 * Description      Build and send an L2CAP "Credit based connection res"
 *                  message to the peer. This function is called for non-success
 *                  cases.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_reject_ble_connection(tL2C_LCB* p_lcb, uint8_t rem_id,
                                uint16_t result) {
  BT_HDR* p_buf;
  uint8_t* p;

  p_buf = l2cu_build_header(p_lcb, L2CAP_CMD_BLE_CREDIT_BASED_CONN_RES_LEN,
                            L2CAP_CMD_BLE_CREDIT_BASED_CONN_RES, rem_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_reject_ble_connection - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, 0); /* Local CID of 0   */
  UINT16_TO_STREAM(p, 0); /* MTU */
  UINT16_TO_STREAM(p, 0); /* MPS */
  UINT16_TO_STREAM(p, 0); /* initial credit */
  UINT16_TO_STREAM(p, result);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_reject_coc_connection
 *
 * Description      Build and send an L2CAP "Credit based connection res"
 *                  message to the peer. This function is called for non-success
 *                  cases.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_reject_coc_connection(tL2C_LCB* p_lcb, uint8_t rem_id,
                                uint16_t result, uint8_t num_chnls) {
  BT_HDR* p_buf;
  uint8_t* p;
  uint16_t pkt_len = L2CAP_CMD_CREDIT_BASED_CONN_LEN + (2 * num_chnls);
  p_buf = l2cu_build_header(p_lcb, pkt_len,
                            L2CAP_CMD_CREDIT_BASED_CONNECTION_RSP, rem_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_reject_coc_connection - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, L2CAP_COC_MIN_MTU); /* MTU */
  UINT16_TO_STREAM(p, L2CAP_COC_MIN_MPS); /* MPS */
  UINT16_TO_STREAM(p, L2CAP_COC_CREDIT_DEFAULT); /* initial credit */
  UINT16_TO_STREAM(p, result);
  for (int i = 0; i < num_chnls; i++) {
    UINT16_TO_STREAM(p, 0); /* Local CID of 0   */
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_credit_based_conn_res
 *
 * Description      Build and send an L2CAP "Credit based connection res"
 *                  message to the peer. This function is called in case of
 *                  success.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_credit_based_conn_res(tL2C_CCB* p_ccb,
                                              uint16_t result) {
  BT_HDR* p_buf;
  uint8_t* p;

  L2CAP_TRACE_DEBUG("l2cu_send_peer_ble_credit_based_conn_res");
  p_buf =
      l2cu_build_header(p_ccb->p_lcb, L2CAP_CMD_BLE_CREDIT_BASED_CONN_RES_LEN,
                        L2CAP_CMD_BLE_CREDIT_BASED_CONN_RES, p_ccb->remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_credit_based_conn_res - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->local_cid);              /* Local CID */
  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.mtu);     /* MTU */
  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.mps);     /* MPS */
  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.credits); /* initial credit */
  UINT16_TO_STREAM(p, result);

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_sendpeer_credit_based_conn_res

 *
 * Description      Build and send an L2CAP "Credit based connection res"
 *                  message to the peer. This function is called in case of
 *                  success.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_credit_based_conn_res(tL2C_CCB* p_ccb,
                                              uint16_t result) {
  BT_HDR* p_buf;
  uint8_t* p;

  L2CAP_TRACE_DEBUG("l2cu_send_peer_credit_based_conn_res");

  if (p_ccb == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_credit_based_conn_res FAILED- NO CCB");
    return;
  }

  uint16_t pkt_len = L2CAP_CMD_CREDIT_BASED_CONN_LEN +
                      (2 * p_ccb->coc_cmd_info.requested_ecfc_chnls);
  p_buf =
      l2cu_build_header(p_ccb->p_lcb, pkt_len,
                        L2CAP_CMD_CREDIT_BASED_CONNECTION_RSP, p_ccb->remote_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_credit_based_conn_res - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.mtu);     /* MTU */
  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.mps);     /* MPS */
  UINT16_TO_STREAM(p, p_ccb->local_conn_cfg.credits); /* initial credit */
  UINT16_TO_STREAM(p, result);

  for (int i = 0; i < p_ccb->coc_cmd_info.requested_ecfc_chnls; i++) {
    UINT16_TO_STREAM(p, p_ccb->coc_cmd_info.peer_rsp_cids[i]);
  }

  l2c_link_check_send_pkts(p_ccb->p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_flow_control_credit
 *
 * Description      Build and send a BLE packet to give credits to peer device
 *                  for LE connection oriented L2CAP channel.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_flow_control_credit(tL2C_CCB* p_ccb,
                                            uint16_t credit_value) {
  BT_HDR* p_buf;
  uint8_t* p;
  tL2C_LCB* p_lcb = NULL;

  if (!p_ccb) return;
  p_lcb = p_ccb->p_lcb;

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;

  p_buf = l2cu_build_header(p_lcb, L2CAP_CMD_BLE_FLOW_CTRL_CREDIT_LEN,
                            L2CAP_CMD_FLOW_CONTROL_CREDIT_IND, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_ble_credit_based_conn_req - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->local_cid);
  UINT16_TO_STREAM(p, credit_value);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_ble_credit_based_conn_req
 *
 * Description      Build and send a BLE packet to disconnect LE connection
 *                  oriented L2CAP channel.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_ble_credit_based_disconn_req(tL2C_CCB* p_ccb) {
  BT_HDR* p_buf;
  uint8_t* p;
  tL2C_LCB* p_lcb = NULL;
  L2CAP_TRACE_DEBUG("%s", __func__);

  if (!p_ccb) return;
  p_lcb = p_ccb->p_lcb;

  /* Create an identifier for this packet */
  p_ccb->p_lcb->id++;
  l2cu_adj_id(p_ccb->p_lcb, L2CAP_ADJ_ID);

  p_ccb->local_id = p_ccb->p_lcb->id;
  p_buf = l2cu_build_header(p_lcb, L2CAP_DISC_REQ_LEN, L2CAP_CMD_DISC_REQ,
                            p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING(
        "l2cu_send_peer_ble_credit_based_disconn_req - no buffer");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
      L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, p_ccb->remote_cid);
  UINT16_TO_STREAM(p, p_ccb->local_cid);

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/*******************************************************************************
 * Functions used by both Full and Light Stack
 ******************************************************************************/

/*******************************************************************************
 *
 * Function         l2cu_find_lcb_by_handle
 *
 * Description      Look through all active LCBs for a match based on the
 *                  HCI handle.
 *
 * Returns          pointer to matched LCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_LCB* l2cu_find_lcb_by_handle(uint16_t handle) {
  int xx;
  tL2C_LCB* p_lcb = &l2cb.lcb_pool[0];

  for (xx = 0; xx < MAX_L2CAP_LINKS; xx++, p_lcb++) {
    if ((p_lcb->in_use) && (p_lcb->handle == handle)) {
      return (p_lcb);
    }
  }

  /* If here, no match found */
  return (NULL);
}

/*******************************************************************************
 *
 * Function         l2cu_find_ccb_by_cid
 *
 * Description      Look through all active CCBs on a link for a match based
 *                  on the local CID. If passed the link pointer is NULL, all
 *                  active links are searched.
 *
 * Returns          pointer to matched CCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_CCB* l2cu_find_ccb_by_cid(tL2C_LCB* p_lcb, uint16_t local_cid) {
  tL2C_CCB* p_ccb = NULL;
#if (L2CAP_UCD_INCLUDED == TRUE)
  uint8_t xx;
#endif

  if (local_cid >= L2CAP_BASE_APPL_CID) {
    /* find the associated CCB by "index" */
    local_cid -= L2CAP_BASE_APPL_CID;

    if (local_cid >= MAX_L2CAP_CHANNELS) return NULL;

    p_ccb = l2cb.ccb_pool + local_cid;

    /* make sure the CCB is in use */
    if (!p_ccb->in_use) {
      p_ccb = NULL;
    }
    /* make sure it's for the same LCB */
    else if (p_lcb && p_lcb != p_ccb->p_lcb) {
      p_ccb = NULL;
    }
  }
#if (L2CAP_UCD_INCLUDED == TRUE)
  else {
    /* searching fixed channel */
    p_ccb = l2cb.ccb_pool;
    for (xx = 0; xx < MAX_L2CAP_CHANNELS; xx++) {
      if ((p_ccb->local_cid == local_cid) && (p_ccb->in_use) &&
          (p_lcb == p_ccb->p_lcb))
        break;
      else
        p_ccb++;
    }
    if (xx >= MAX_L2CAP_CHANNELS) return NULL;
  }
#endif

  return (p_ccb);
}

#if (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE)

/******************************************************************************
 *
 * Function         l2cu_get_next_channel_in_rr
 *
 * Description      get the next channel to send on a link. It also adjusts the
 *                  CCB queue to do a basic priority and round-robin scheduling.
 *
 * Returns          pointer to CCB or NULL
 *
 ******************************************************************************/
static tL2C_CCB* l2cu_get_next_channel_in_rr(tL2C_LCB* p_lcb) {
  tL2C_CCB* p_serve_ccb = NULL;
  tL2C_CCB* p_ccb;

  int i, j;

  /* scan all of priority until finding a channel to serve */
  for (i = 0; (i < L2CAP_NUM_CHNL_PRIORITY) && (!p_serve_ccb); i++) {
    /* scan all channel within serving priority group until finding a channel to
     * serve */
    for (j = 0; (j < p_lcb->rr_serv[p_lcb->rr_pri].num_ccb) && (!p_serve_ccb);
         j++) {
      /* scaning from next serving channel */
      p_ccb = p_lcb->rr_serv[p_lcb->rr_pri].p_serve_ccb;

      if (!p_ccb) {
        L2CAP_TRACE_ERROR("p_serve_ccb is NULL, rr_pri=%d", p_lcb->rr_pri);
        return NULL;
      }

      L2CAP_TRACE_DEBUG("RR scan pri=%d, lcid=0x%04x, q_cout=%d",
                        p_ccb->ccb_priority, p_ccb->local_cid,
                        fixed_queue_length(p_ccb->xmit_hold_q));

      /* store the next serving channel */
      /* this channel is the last channel of its priority group */
      if ((p_ccb->p_next_ccb == NULL) ||
          (p_ccb->p_next_ccb->ccb_priority != p_ccb->ccb_priority)) {
        /* next serving channel is set to the first channel in the group */
        p_lcb->rr_serv[p_lcb->rr_pri].p_serve_ccb =
            p_lcb->rr_serv[p_lcb->rr_pri].p_first_ccb;
      } else {
        /* next serving channel is set to the next channel in the group */
        p_lcb->rr_serv[p_lcb->rr_pri].p_serve_ccb = p_ccb->p_next_ccb;
      }

      if (p_ccb->chnl_state != CST_OPEN) continue;

      if (p_ccb->p_lcb->transport == BT_TRANSPORT_LE) {
        L2CAP_TRACE_DEBUG("%s : Connection oriented channel", __func__);
        if (fixed_queue_is_empty(p_ccb->xmit_hold_q)) continue;

      } else {
        /* eL2CAP option in use */
        if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_BASIC_MODE) {
          if (p_ccb->fcrb.wait_ack || p_ccb->fcrb.remote_busy) continue;

          if (fixed_queue_is_empty(p_ccb->fcrb.retrans_q)) {
            if (fixed_queue_is_empty(p_ccb->xmit_hold_q)) continue;

            /* If in eRTM mode, check for window closure */
            if ((p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_ERTM_MODE) &&
                (l2c_fcr_is_flow_controlled(p_ccb)))
              continue;
          }
        } else {
          if (fixed_queue_is_empty(p_ccb->xmit_hold_q)) continue;
        }
      }

      /* found a channel to serve */
      p_serve_ccb = p_ccb;
      /* decrease quota of its priority group */
      p_lcb->rr_serv[p_lcb->rr_pri].quota--;
    }

    /* if there is no more quota of the priority group or no channel to have
     * data to send */
    if ((p_lcb->rr_serv[p_lcb->rr_pri].quota == 0) || (!p_serve_ccb)) {
      /* serve next priority group */
      p_lcb->rr_pri = (p_lcb->rr_pri + 1) % L2CAP_NUM_CHNL_PRIORITY;
      /* initialize its quota */
      p_lcb->rr_serv[p_lcb->rr_pri].quota =
          L2CAP_GET_PRIORITY_QUOTA(p_lcb->rr_pri);
    }
  }

  if (p_serve_ccb) {
    L2CAP_TRACE_DEBUG("RR service pri=%d, quota=%d, lcid=0x%04x",
                      p_serve_ccb->ccb_priority,
                      p_lcb->rr_serv[p_serve_ccb->ccb_priority].quota,
                      p_serve_ccb->local_cid);
  }

  return p_serve_ccb;
}

#else  /* (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE) */

/******************************************************************************
 *
 * Function         l2cu_get_next_channel
 *
 * Description      get the next channel to send on a link bassed on priority
 *                  scheduling.
 *
 * Returns          pointer to CCB or NULL
 *
 ******************************************************************************/
static tL2C_CCB* l2cu_get_next_channel(tL2C_LCB* p_lcb) {
  tL2C_CCB* p_ccb;

  /* Get the first CCB with data to send.
  */
  for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb; p_ccb = p_ccb->p_next_ccb) {
    if (p_ccb->chnl_state != CST_OPEN) continue;

    if (p_ccb->fcrb.wait_ack || p_ccb->fcrb.remote_busy) continue;

    if (!fixed_queue_is_empty(p_ccb->fcrb.retrans_q)) return p_ccb;

    if (fixed_queue_is_empty(p_ccb->xmit_hold_q)) continue;

    /* If in eRTM mode, check for window closure */
    if ((p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_ERTM_MODE) &&
        (l2c_fcr_is_flow_controlled(p_ccb)))
      continue;

    /* If here, we found someone */
    return p_ccb;
  }

  return NULL;
}
#endif /* (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE) */

void l2cu_tx_complete(tL2C_TX_COMPLETE_CB_INFO* p_cbi) {
  if (p_cbi->cb != NULL) p_cbi->cb(p_cbi->local_cid, p_cbi->num_sdu);
}

/******************************************************************************
 *
 * Function         l2cu_get_next_buffer_to_send
 *
 * Description      get the next buffer to send on a link. It also adjusts the
 *                  CCB queue to do a basic priority and round-robin scheduling.
 *
 * Returns          pointer to buffer or NULL
 *
 ******************************************************************************/
BT_HDR* l2cu_get_next_buffer_to_send(tL2C_LCB* p_lcb,
                                     tL2C_TX_COMPLETE_CB_INFO* p_cbi) {
  tL2C_CCB* p_ccb;
  BT_HDR* p_buf;

/* Highest priority are fixed channels */
#if (L2CAP_NUM_FIXED_CHNLS > 0)
  int xx;

  p_cbi->cb = NULL;

  for (xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
    p_ccb = p_lcb->p_fixed_ccbs[xx];
    if (p_ccb == NULL) continue;

    /* eL2CAP option in use */
    if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_BASIC_MODE) {
      if (p_ccb->fcrb.wait_ack || p_ccb->fcrb.remote_busy) continue;

      /* No more checks needed if sending from the reatransmit queue */
      if (fixed_queue_is_empty(p_ccb->fcrb.retrans_q)) {
        if (fixed_queue_is_empty(p_ccb->xmit_hold_q)) continue;

        /* If in eRTM mode, check for window closure */
        if ((p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_ERTM_MODE) &&
            (l2c_fcr_is_flow_controlled(p_ccb)))
          continue;
      }

      p_buf = l2c_fcr_get_next_xmit_sdu_seg(p_ccb, 0);
      if (p_buf != NULL) {
        l2cu_check_channel_congestion(p_ccb);
        l2cu_set_acl_hci_header(p_buf, p_ccb);
        return (p_buf);
      }
    } else {
      if (!fixed_queue_is_empty(p_ccb->xmit_hold_q)) {
        p_buf = (BT_HDR*)fixed_queue_try_dequeue(p_ccb->xmit_hold_q);
        if (NULL == p_buf) {
          L2CAP_TRACE_ERROR("%s: No data to be sent", __func__);
          return (NULL);
        }

        /* Prepare callback info for TX completion */
        p_cbi->cb = l2cb.fixed_reg[xx].pL2CA_FixedTxComplete_Cb;
        p_cbi->local_cid = p_ccb->local_cid;
        p_cbi->num_sdu = 1;

        l2cu_check_channel_congestion(p_ccb);
        l2cu_set_acl_hci_header(p_buf, p_ccb);
        return (p_buf);
      }
    }
  }
#endif

#if (L2CAP_ROUND_ROBIN_CHANNEL_SERVICE == TRUE)
  /* get next serving channel in round-robin */
  p_ccb = l2cu_get_next_channel_in_rr(p_lcb);
#else
  p_ccb = l2cu_get_next_channel(p_lcb);
#endif

  /* Return if no buffer */
  if (p_ccb == NULL) return (NULL);

  if (p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_ECFC_MODE) {
    if (p_ccb->peer_conn_cfg.credits == 0) {
      L2CAP_TRACE_DEBUG("%s No credits to send packets", __func__);
      return NULL;
    }
    p_buf = l2c_lcc_get_next_xmit_sdu_seg(p_ccb, 0);
    if (p_buf == NULL ||
        (p_ccb->chnl_state == CST_CONFIG && !(p_ccb->config_done & IB_CFG_DONE))) {
      return (NULL);
    }
    p_ccb->peer_conn_cfg.credits--;
  } else if (p_ccb->p_lcb->transport == BT_TRANSPORT_LE) {
    /* Check credits */
    if (p_ccb->peer_conn_cfg.credits == 0) {
      L2CAP_TRACE_DEBUG("%s No credits to send packets", __func__);
      return NULL;
    }
    p_buf = l2c_lcc_get_next_xmit_sdu_seg(p_ccb, 0);
    if (p_buf == NULL) return (NULL);

    p_ccb->peer_conn_cfg.credits--;
  } else {
    if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_BASIC_MODE) {
      p_buf = l2c_fcr_get_next_xmit_sdu_seg(p_ccb, 0);
      if (p_buf == NULL) return (NULL);
    } else {
      p_buf = (BT_HDR*)fixed_queue_try_dequeue(p_ccb->xmit_hold_q);
      if (NULL == p_buf) {
        L2CAP_TRACE_ERROR("l2cu_get_buffer_to_send() #2: No data to be sent");
        return (NULL);
      }
    }
  }

  if (p_ccb->p_rcb && p_ccb->p_rcb->api.pL2CA_TxComplete_Cb &&
      (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_ERTM_MODE))
    (*p_ccb->p_rcb->api.pL2CA_TxComplete_Cb)(p_ccb->local_cid, 1);

  l2cu_check_channel_congestion(p_ccb);

  l2cu_set_acl_hci_header(p_buf, p_ccb);

  return (p_buf);
}

/******************************************************************************
 *
 * Function         l2cu_set_acl_hci_header
 *
 * Description      Set HCI handle for ACL packet
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_acl_hci_header(BT_HDR* p_buf, tL2C_CCB* p_ccb) {
  uint8_t* p;

  /* Set the pointer to the beginning of the data minus 4 bytes for the packet
   * header */
  p = (uint8_t*)(p_buf + 1) + p_buf->offset - HCI_DATA_PREAMBLE_SIZE;

  if (p_ccb->p_lcb->transport == BT_TRANSPORT_LE) {
    UINT16_TO_STREAM(p, p_ccb->p_lcb->handle | (L2CAP_PKT_START_NON_FLUSHABLE
                                                << L2CAP_PKT_TYPE_SHIFT));

    uint16_t acl_data_size =
        controller_get_interface()->get_acl_data_size_ble();
    /* The HCI transport will segment the buffers. */
    if (p_buf->len > acl_data_size) {
      UINT16_TO_STREAM(p, acl_data_size);
    } else {
      UINT16_TO_STREAM(p, p_buf->len);
    }
  } else {
#if (L2CAP_NON_FLUSHABLE_PB_INCLUDED == TRUE)
    if ((((p_buf->layer_specific & L2CAP_FLUSHABLE_MASK) ==
          L2CAP_FLUSHABLE_CH_BASED) &&
         (p_ccb->is_flushable)) ||
        ((p_buf->layer_specific & L2CAP_FLUSHABLE_MASK) ==
         L2CAP_FLUSHABLE_PKT)) {
      UINT16_TO_STREAM(
          p, p_ccb->p_lcb->handle | (L2CAP_PKT_START << L2CAP_PKT_TYPE_SHIFT));
    } else {
      UINT16_TO_STREAM(p, p_ccb->p_lcb->handle | l2cb.non_flushable_pbf);
    }
#else
    UINT16_TO_STREAM(
        p, p_ccb->p_lcb->handle | (L2CAP_PKT_START << L2CAP_PKT_TYPE_SHIFT));
#endif

    uint16_t acl_data_size =
        controller_get_interface()->get_acl_data_size_classic();
    /* The HCI transport will segment the buffers. */
    if (p_buf->len > acl_data_size) {
      UINT16_TO_STREAM(p, acl_data_size);
    } else {
      UINT16_TO_STREAM(p, p_buf->len);
    }
  }
  p_buf->offset -= HCI_DATA_PREAMBLE_SIZE;
  p_buf->len += HCI_DATA_PREAMBLE_SIZE;
}

/******************************************************************************
 *
 * Function         l2cu_check_channel_congestion
 *
 * Description      check if any change in congestion status
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_check_channel_congestion(tL2C_CCB* p_ccb) {
  size_t q_count = fixed_queue_length(p_ccb->xmit_hold_q);

#if (L2CAP_UCD_INCLUDED == TRUE)
  if (p_ccb->local_cid == L2CAP_CONNECTIONLESS_CID) {
    q_count += fixed_queue_length(p_ccb->p_lcb->ucd_out_sec_pending_q);
  }
#endif
  /* If the CCB queue limit is subject to a quota, check for congestion */
  /* if this channel has outgoing traffic */
  if (p_ccb->buff_quota != 0) {
    /* If this channel was congested */
    if (p_ccb->cong_sent) {
      /* If the channel is not congested now, tell the app */
      if (q_count <= (p_ccb->buff_quota / 2)) {
        p_ccb->cong_sent = false;
        if (p_ccb->p_rcb && p_ccb->p_rcb->api.pL2CA_CongestionStatus_Cb) {
          L2CAP_TRACE_DEBUG(
              "L2CAP - Calling CongestionStatus_Cb (false), CID: 0x%04x  "
              "xmit_hold_q.count: %u  buff_quota: %u",
              p_ccb->local_cid, q_count, p_ccb->buff_quota);

          /* Prevent recursive calling */
          l2cb.is_cong_cback_context = true;
          (*p_ccb->p_rcb->api.pL2CA_CongestionStatus_Cb)(p_ccb->local_cid,
                                                         false);
          l2cb.is_cong_cback_context = false;
        }
#if (L2CAP_UCD_INCLUDED == TRUE)
        else if (p_ccb->p_rcb && p_ccb->local_cid == L2CAP_CONNECTIONLESS_CID) {
          if (p_ccb->p_rcb->ucd.cb_info.pL2CA_UCD_Congestion_Status_Cb) {
            L2CAP_TRACE_DEBUG(
                "L2CAP - Calling UCD CongestionStatus_Cb (false), "
                "SecPendingQ:%u,XmitQ:%u,Quota:%u",
                fixed_queue_length(p_ccb->p_lcb->ucd_out_sec_pending_q),
                fixed_queue_length(p_ccb->xmit_hold_q), p_ccb->buff_quota);
            p_ccb->p_rcb->ucd.cb_info.pL2CA_UCD_Congestion_Status_Cb(
                p_ccb->p_lcb->remote_bd_addr, false);
          }
        }
#endif
#if (L2CAP_NUM_FIXED_CHNLS > 0)
        else {
          uint8_t xx;
          for (xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
            if (p_ccb->p_lcb->p_fixed_ccbs[xx] == p_ccb) {
              if (l2cb.fixed_reg[xx].pL2CA_FixedCong_Cb != NULL)
                (*l2cb.fixed_reg[xx].pL2CA_FixedCong_Cb)(
                    p_ccb->p_lcb->remote_bd_addr, false);
              break;
            }
          }
        }
#endif
      }
    } else {
      /* If this channel was not congested but it is congested now, tell the app
       */
      if (q_count > p_ccb->buff_quota) {
        p_ccb->cong_sent = true;
        if (p_ccb->p_rcb && p_ccb->p_rcb->api.pL2CA_CongestionStatus_Cb) {
          L2CAP_TRACE_WARNING(
              "L2CAP - Calling CongestionStatus_Cb "
              "(true),CID:0x%04x,XmitQ:%u,Quota:%u",
              p_ccb->local_cid, q_count, p_ccb->buff_quota);

          (*p_ccb->p_rcb->api.pL2CA_CongestionStatus_Cb)(p_ccb->local_cid,
                                                         true);
        }
#if (L2CAP_UCD_INCLUDED == TRUE)
        else if (p_ccb->p_rcb && p_ccb->local_cid == L2CAP_CONNECTIONLESS_CID) {
          if (p_ccb->p_rcb->ucd.cb_info.pL2CA_UCD_Congestion_Status_Cb) {
            L2CAP_TRACE_DEBUG(
                "L2CAP - Calling UCD CongestionStatus_Cb (true), "
                "SecPendingQ:%u,XmitQ:%u,Quota:%u",
                fixed_queue_length(p_ccb->p_lcb->ucd_out_sec_pending_q),
                fixed_queue_length(p_ccb->xmit_hold_q), p_ccb->buff_quota);
            p_ccb->p_rcb->ucd.cb_info.pL2CA_UCD_Congestion_Status_Cb(
                p_ccb->p_lcb->remote_bd_addr, true);
          }
        }
#endif
#if (L2CAP_NUM_FIXED_CHNLS > 0)
        else {
          uint8_t xx;
          for (xx = 0; xx < L2CAP_NUM_FIXED_CHNLS; xx++) {
            if (p_ccb->p_lcb->p_fixed_ccbs[xx] == p_ccb) {
              if (l2cb.fixed_reg[xx].pL2CA_FixedCong_Cb != NULL)
                (*l2cb.fixed_reg[xx].pL2CA_FixedCong_Cb)(
                    p_ccb->p_lcb->remote_bd_addr, true);
              break;
            }
          }
        }
#endif
      }
    }
  }
}

/*******************************************************************************
 *
 * Function         l2cu_is_ccb_active
 *
 * Description      Check if Channel Control Block is in use or released
 *
 * Returns          bool    - true if Channel Control Block is in use
 *                            false if p_ccb is null or is released.
 *
 ******************************************************************************/
bool l2cu_is_ccb_active(tL2C_CCB* p_ccb) { return (p_ccb && p_ccb->in_use); }

/*******************************************************************************
 *
 * Function         l2cu_is_active_ccb_connected
 *
 * Description      Check if any Channel Control Block is in connected state
 *
 * Returns          bool    - true if any Channel Control Block is connected
 *                            false if lcb is null or no channels in connected state.
 *
 ******************************************************************************/
bool l2cu_is_active_ccb_connected(const RawAddress& p_bd_addr) {
  tL2C_LCB *p_lcb = l2cu_find_lcb_by_bd_addr (p_bd_addr, BT_TRANSPORT_BR_EDR);

  if (p_lcb == NULL) return false;

  for (tL2C_CCB* p_ccb  = p_lcb->ccb_queue.p_first_ccb; p_ccb; ) {
    if (p_ccb->chnl_state == CST_OPEN) {
      return true;
    }
    p_ccb = p_ccb->p_next_ccb;
  }
  return false;
}

/******************************************************************************
 *
 * Function         l2cu_set_coc_chnl_state
 *
 * Description      Setting the chnl_state to ccb which belongs to same ecfc
 *                  connection mode.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_coc_chnl_state(tL2C_CCB* p_ccb, tL2C_CHNL_STATE chnl_state) {
  L2CAP_TRACE_WARNING("%s chnl_state %d", __func__, chnl_state);
  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  l2cu_get_coc_local_cids(sr_cids, p_ccb);
  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb, sr_cids[i]);
    if(tmp_ccb != NULL) {
      tmp_ccb->chnl_state = chnl_state;
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_set_ecfc_grp_status
 *
 * Description      Setting status to all the ecfc channels
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_ecfc_grp_status(tL2C_CCB* p_ccb, uint8_t flag) {
  L2CAP_TRACE_WARNING("%s flag %d", __func__, flag);
  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if(tmp_ccb != NULL) {
      tmp_ccb->coc_cmd_info.ecfc_grp_status |= flag;
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_set_alarm_ecfc_grp
 *
 * Description
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_alarm_ecfc_grp(tL2C_CCB* p_ccb, alarm_t* ecfc_conn_alarm) {
  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if(tmp_ccb != NULL) {
      tmp_ccb->coc_cmd_info.ecfc_conn_alarm = ecfc_conn_alarm;
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_release_coc_ccbs
 *
 * Description      releasing group of ccb's which are linked to same ecfc
 *                  connection
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_release_coc_ccbs(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_WARNING("%s local_cid %d", __func__, p_ccb->local_cid);

  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  l2cu_get_coc_local_cids(sr_cids, p_ccb);
  uint8_t num_chnls = p_ccb->coc_cmd_info.num_coc_chnls;
  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < num_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb, sr_cids[i]);
    if(tmp_ccb != NULL) {
      tmp_ccb->coc_cmd_info.ecfc_conn_alarm = NULL; //TODO added as safer side.
      l2cu_release_ccb(tmp_ccb);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_get_coc_local_cids
 *
 * Description      getting the group of sr_cids from the p_ccb
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_get_coc_local_cids(uint16_t* sr_cids, tL2C_CCB* p_ccb) {
  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    if (p_ccb->coc_cmd_info.ecfc_cids_group[i]) {
      sr_cids[i] = p_ccb->coc_cmd_info.ecfc_cids_group[i];
    } else {
      sr_cids[i] = 0;
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_send_disconnect_ind
 *
 * Description      sending the disconnect ind to all ccbs which are group
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_send_disconnect_ind(uint16_t *sr_cids, uint8_t num_chnls,
                              tL2CA_DISCONNECT_IND_CB* disconnect_ind) {
  for(int i = 0;i < num_chnls; i++) {
    (*disconnect_ind)(sr_cids[i], false);
  }
}

/******************************************************************************
 *
 * Function         l2cu_set_ccbs_local_id
 *
 * Description      Update local id in all ccbs which are linked to same ecfc
 *                  connection mode
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_ccbs_local_id(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_WARNING("%s ", __func__);

  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  l2cu_get_coc_local_cids(sr_cids, p_ccb);
  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb, sr_cids[i]);
    if(tmp_ccb != NULL) {
      tmp_ccb->local_id = p_lcb->id;
      L2CAP_TRACE_WARNING("%d ", tmp_ccb->local_cid);
    } else {
      L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_reset_sr_cid
 *
 * Description      When upper calls disconnect for particular CID. Then this
 *                  API sets the particular CID index in the disc_pending
 *                  variable.
 *                  And then update the disc_pending value to all CCB's in the
 *                  group.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_reset_sr_cid(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_WARNING("%s Removing Local cid %d", __func__,
                        p_ccb->local_cid);

  tL2C_LCB* p_lcb = p_ccb->p_lcb;
  int indx = -1;
  uint64_t disc_pending_ccb = 0;

  for (uint64_t i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    if (p_ccb->local_cid == p_ccb->coc_cmd_info.ecfc_cids_group[i]) {
      disc_pending_ccb = ((uint64_t)1 << i);
      indx = i;
      break;
    }
  }
  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if((tmp_ccb != NULL) && (indx >= 0)) {
      tmp_ccb->coc_cmd_info.disc_pending |= disc_pending_ccb;
    } else {
      L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_update_ccb_peer_params
 *
 * Description      Update the remote parameters into all the CCB's which are
 *                  accepted for the ecfc connection request.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_update_ccb_peer_params(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_WARNING("%s ", __func__);

  tL2C_LCB* p_lcb = p_ccb->p_lcb;

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if (tmp_ccb != NULL) {
      tmp_ccb->tx_mps = p_ccb->peer_conn_cfg.mps;
      tmp_ccb->ble_sdu = NULL;
      tmp_ccb->ble_sdu_length = 0;
      tmp_ccb->is_first_seg = true;
      tmp_ccb->peer_conn_cfg.mtu = p_ccb->peer_conn_cfg.mtu;
      tmp_ccb->peer_conn_cfg.credits = p_ccb->peer_conn_cfg.credits;
      tmp_ccb->peer_conn_cfg.mps = p_ccb->peer_conn_cfg.mps;

      tmp_ccb->peer_cfg.fcr.mode = L2CAP_FCR_ECFC_MODE;
    } else {
      L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_update_ecfc_grp_dest_cids
 *
 * Description      It re adjusts the ecfc_cids_group array and dest_cids array.
 *                  Means if any index got removed from the group, then right most
 *                  elements will be shifted to left side by 1 index and decrease
 *                  the size of array by 1.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_update_ecfc_grp_dest_cids(tL2C_CCB** p_ccb,
                                    uint16_t* dest_cids,
                                    uint16_t sr_cid) {
  uint16_t num_chnls = (*p_ccb)->coc_cmd_info.num_coc_chnls;

  // If sr_cid is last element in the coc_group
  if ((*p_ccb)->coc_cmd_info.ecfc_cids_group[num_chnls-1] == sr_cid) {
    dest_cids[num_chnls - 1] = 0;
    (*p_ccb)->coc_cmd_info.num_coc_chnls--;
    L2CAP_TRACE_WARNING("%s  num_chnls %d",__func__,
                        (*p_ccb)->coc_cmd_info.num_coc_chnls);
    return;
  }

  // Start from last element and traverse back to 0 index
  // elements one position ahead.
  uint16_t prev_cid = (*p_ccb)->coc_cmd_info.ecfc_cids_group[num_chnls-1];
  uint16_t prev_des_cid = dest_cids[num_chnls -1];
  uint16_t i;
  for (i=num_chnls-2; (i>=0) &&
      ((*p_ccb)->coc_cmd_info.ecfc_cids_group[i] != sr_cid); i--) {
    int curr_cid = (*p_ccb)->coc_cmd_info.ecfc_cids_group[i];
    (*p_ccb)->coc_cmd_info.ecfc_cids_group[i] = prev_cid;
    prev_cid = curr_cid;
    curr_cid = dest_cids[i];
    dest_cids[i] = prev_des_cid;
    prev_des_cid = curr_cid;
  }

  if (i < 0)  return;

  (*p_ccb)->coc_cmd_info.ecfc_cids_group[i] = prev_cid;
  (*p_ccb)->coc_cmd_info.num_coc_chnls--;
  dest_cids[i] = prev_des_cid;
  L2CAP_TRACE_WARNING("%s  num_chnls %d",__func__,
                      (*p_ccb)->coc_cmd_info.num_coc_chnls);
  return;
}

/******************************************************************************
 *
 * Function         l2cu_clear_disc_pending
 *
 * Description      clearing the disc_pending bit after disconnection initiated
 *                  for that particular cid. And the update the value to all
 *                  the CCB's in the group.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_clear_disc_pending(tL2C_CCB* p_ccb, uint64_t index) {
  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  l2cu_get_coc_local_cids(sr_cids, p_ccb);

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if((tmp_ccb != NULL)) {
      tmp_ccb->coc_cmd_info.disc_pending &= ~(1 << index);
       memcpy(tmp_ccb->coc_cmd_info.ecfc_cids_group,
              sr_cids, sizeof(sr_cids));
    } else {
      L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_set_ecfc_num_chnls
 *
 * Description      Setting the valid num_chnls value to all the valids CCB's
 *                  in the group.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_ecfc_num_chnls(tL2C_CCB* p_ccb, uint8_t num_chnls) {
  for (int i = 0; i < num_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb,
                                            p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if (tmp_ccb) {
      tmp_ccb->coc_cmd_info.num_coc_chnls = num_chnls;
    } else {
      L2CAP_TRACE_WARNING("%s Not a valid CCB ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_find_ecfc_grp_next_ccb
 *
 * Description      Getting the next valid CCB from the ecfc_cids_group.
 *
 * Returns          tL2C_CCB* - returns the valid CCB from the ecfc_cids_group
 *
 ******************************************************************************/
tL2C_CCB* l2cu_find_ecfc_grp_next_ccb(tL2C_CCB* p_ccb, uint16_t local_cid) {

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if (tmp_ccb && (tmp_ccb->local_cid != local_cid)) {
      L2CAP_TRACE_WARNING("%s CCB is pointing to new one", __func__);
      return tmp_ccb;
    }
  }
  return NULL;
}

/******************************************************************************
 *
 * Function         l2cu_process_ecfc_pending_disconnect
 *
 * Description      It deals with what ever pending requests trigerred from the
 *                  upper layer when Credit connection request is on process.
 *                  It set bit in a disconnect_pending flag indicates particular
 *                  index in the ecfc_group for that particular connection.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_process_ecfc_pending_disconnect(tL2C_CCB** p_ccb,
                                          uint16_t* dest_cids) {
  uint8_t num_chnls = (*p_ccb)->coc_cmd_info.num_coc_chnls;
  L2CAP_TRACE_WARNING("%s disc_pending %d", __func__,
                      (*p_ccb)->coc_cmd_info.disc_pending);

  uint16_t disc_pend_cnt = 0;
  uint16_t disc_pending_cid[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};

  l2cu_get_coc_local_cids(sr_cids, *p_ccb);

  for (uint64_t i = 0; i < num_chnls; i++) {
    if ((*p_ccb)->coc_cmd_info.disc_pending & ((uint64_t)1 << i)) {
      disc_pending_cid[i] = (*p_ccb)->coc_cmd_info.ecfc_cids_group[i];
      L2CAP_TRACE_WARNING("%s Sr_cid %d", __func__, disc_pending_cid[i]);
    }
  }
  int j = 0;
  for(int i = 0; i < num_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid((*p_ccb)->p_lcb, sr_cids[i]);
    if (tmp_ccb) {
      if (tmp_ccb->local_cid == disc_pending_cid[i]) {
        if (dest_cids[j] != 0) {
          L2CAP_TRACE_WARNING("%s Sending Disconnect to cid %d ", __func__,
                             tmp_ccb->local_cid);

          tmp_ccb->remote_cid = dest_cids[j];
          l2cu_send_peer_disc_req(tmp_ccb);

          if ((*p_ccb)->local_cid == tmp_ccb->local_cid) {
            *p_ccb = l2cu_find_ecfc_grp_next_ccb(*p_ccb, tmp_ccb->local_cid);
            if (!(*p_ccb) || !(*p_ccb)->in_use) {
              L2CAP_TRACE_WARNING("%s No Chnls left.. ", __func__);
              break;
            }
            L2CAP_TRACE_WARNING("%s Point the P_CCB to next one local cid %d ",
                                __func__, (*p_ccb) ? (*p_ccb)->local_cid: 0);
          }
          disc_pend_cnt++;
          l2cu_update_ecfc_grp_dest_cids(p_ccb, dest_cids,
                                         sr_cids[i]);
          l2cu_clear_disc_pending(*p_ccb, i);
          l2cu_set_ecfc_num_chnls(*p_ccb, (*p_ccb)->coc_cmd_info.num_coc_chnls);
          l2cu_release_ccb(tmp_ccb);
          (*p_ccb)->coc_cmd_info.disc_pending &= ~(1 << i);
        } else {
          j++;
          L2CAP_TRACE_WARNING("%s No valid dest id - No need to send response",
                                __func__);
        }
      } else {
        j++;
      }
    } else {
      L2CAP_TRACE_WARNING("%s ABORT.. Something WRONG", __func__);
    }
  }
  if (*p_ccb) {
    L2CAP_TRACE_WARNING("%s Final Num Chanls %d ", __func__, (*p_ccb)->coc_cmd_info.num_coc_chnls);
    for (int i = 0; i < (*p_ccb)->coc_cmd_info.num_coc_chnls; i++) {
      L2CAP_TRACE_WARNING("%s Dest %d sr_cid %d ", __func__, dest_cids[i],
                          (*p_ccb)->coc_cmd_info.ecfc_cids_group[i]);
    }
    if (((*p_ccb)->coc_cmd_info.num_coc_chnls == 0) &&
        ((*p_ccb)->in_use)) {
      L2CAP_TRACE_WARNING("%s Clearing CCB %d Since num chnls 0  ",
                          __func__, (*p_ccb)->local_cid);
      l2cu_release_ccb(*p_ccb);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_check_for_valid_sr_cids
 *
 * Description      Validate the Source CIDS based on the ecfc connection
 *                  response.
 *                  If some cids are not accepted then release those ccb's
 *                  and update the number of channels.
 *
 * Returns          None
 *
 ******************************************************************************/
bool l2cu_check_for_valid_sr_cids(tL2C_CCB** p_ccb, uint16_t* dest_cids,
                                  uint16_t result) {
  uint8_t valid_chnls = 0;
  uint16_t actual_sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  tL2C_LCB* p_lcb = (*p_ccb)->p_lcb;
  bool status = true;

  L2CAP_TRACE_WARNING("%s p_ccb %d", __func__, (*p_ccb)->local_cid);
  if ((*p_ccb)->coc_cmd_info.disc_pending) {
    L2CAP_TRACE_WARNING("%s Disconnection was initiated for some CCBS",
                        __func__);
    l2cu_process_ecfc_pending_disconnect(p_ccb, dest_cids);
  }

  uint8_t num_chnls = (*p_ccb)->coc_cmd_info.num_coc_chnls;
  l2cu_get_coc_local_cids(actual_sr_cids, *p_ccb);

  switch (result) {
    case L2CAP_ECFC_ALL_CONNS_SUCCESSFUL:
    case L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES:
    case L2CAP_ECFC_SOME_CONNS_REFUSED_INVALID_SOURCE_CID:
    case L2CAP_ECFC_SOME_CONNS_REFUSED_SOURCE_CID_ALREADY_ALLOCATED:
      //TODO move this functionality to separate API
      if ((result != L2CAP_ECFC_ALL_CONNS_SUCCESSFUL) &&
          (num_chnls == 1)) {
          status = false;
          break;
      }
      for (int i = 0; i < num_chnls; i++) {
        if (dest_cids[i] == 0) {
          tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb, actual_sr_cids[i]);
          if (tmp_ccb) {
            if (num_chnls != 1) {
              l2cu_release_ccb(tmp_ccb);
            }
          }
          actual_sr_cids[i] = 0;
        } else {
          valid_chnls++;
        }
      }
      if (valid_chnls == 0) {
        status = false;
        break;
      }
      //If the P_CCB got released due to invalid dest_id with '0'
      //So we will update with next CCB in the link.
      if (((*p_ccb)->in_use == false) && (valid_chnls > 0)) {
        L2CAP_TRACE_WARNING("%s First CCB is invalid. Checking for valid ",
                            __func__);
        for (int i = 0; i < num_chnls; i++) {
          *p_ccb = l2cu_find_ccb_by_cid(p_lcb, actual_sr_cids[i]);
          if (*p_ccb) {
            L2CAP_TRACE_WARNING(" %s Changed CID %d", __func__,
                                (*p_ccb)->local_cid);
            (*p_ccb)->coc_cmd_info.num_coc_chnls = valid_chnls;
            break;
          } else {
            L2CAP_TRACE_WARNING("%s CCB is invalid at index %d", __func__, i);
          }
        }
      }
      L2CAP_TRACE_WARNING("%s valid_chnls %d ", __func__, valid_chnls);
      for (int i = 0; i < num_chnls; i++) {
        tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_lcb, actual_sr_cids[i]);
        if (tmp_ccb) {
          memcpy(tmp_ccb->coc_cmd_info.ecfc_cids_group, actual_sr_cids,
                 sizeof(actual_sr_cids));
          tmp_ccb->coc_cmd_info.num_coc_chnls = valid_chnls;
          L2CAP_TRACE_WARNING("%s Copied CCB group in Cid is %d", __func__,
                              tmp_ccb->local_cid);
        } else {
          L2CAP_TRACE_WARNING("%s CCB not found at index %d", __func__, i);
        }
      }
      L2CAP_TRACE_WARNING("%s Accepted with result %s num_chnls %d CID %d", __func__,
                          l2cu_get_connection_result(result),
                          (*p_ccb) ? (*p_ccb)->coc_cmd_info.num_coc_chnls: 0,
                          (*p_ccb) ? (*p_ccb)->local_cid: 0);
      break;
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_AUTHENTICATION:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_AUTHERIZATION:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_ENCRYPTION_KEY_SIZE:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_ENCRYPTION:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_UNACCEPTABLE_PARAMS:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INVALID_PARAMS:
    case L2CAP_ECFC_ALL_CONNS_REFUSED_SPSM_NOT_SUPPORTED:
      L2CAP_TRACE_WARNING("%s failed due to %s", __func__,
                          l2cu_get_connection_result(result));
      status = false;
      break;
  }
  return status;
}

/******************************************************************************
 *
 * Function         l2cu_set_data_length_ext
 *
 * Description      Setting the DLE in LE Transport
 *
 * Returns          bool
 *
 ******************************************************************************/
bool l2cu_set_data_length_ext(tL2C_CCB* p_ccb) {
  tL2C_LCB* p_lcb = p_ccb->p_lcb;
  uint16_t tx_mtu = 0;

  /* See if we have a link control block for the connection */
  if (p_lcb == NULL) {
    L2CAP_TRACE_ERROR("%s No link, DLE is not set", __func__);
    return false;
  }

  tx_mtu = p_ccb->local_conn_cfg.mps;
  L2CAP_TRACE_DEBUG("%s Data len %d %d", __func__, tx_mtu, p_lcb->tx_data_len);
  if (tx_mtu > BTM_BLE_DATA_SIZE_MAX) tx_mtu = BTM_BLE_DATA_SIZE_MAX;

  /* update TX data length if changed */
  if (p_lcb->tx_data_len < tx_mtu) {
    if (BTM_SetBleDataLength(p_lcb->remote_bd_addr, tx_mtu)) {
      return false;
    } else {
      L2CAP_TRACE_DEBUG("%s DataLength EXT Success %d", __func__, tx_mtu);
    }
  }
  return true;
}

/******************************************************************************
 *
 * Function         l2cu_set_coc_remote_cids
 *
 * Description      Maps destination cids in the response pakcet to the
 *                  allocated CCB's
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_coc_remote_cids(uint16_t* dest_cids, tL2C_CCB* p_ccb) {
  uint16_t sr_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};
  l2cu_get_coc_local_cids(sr_cids, p_ccb);
  L2CAP_TRACE_WARNING("%s Local_cid %d", __func__, p_ccb->local_cid);

  for (int i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb, sr_cids[i]);
    if(tmp_ccb != NULL) {
        tmp_ccb->remote_cid = dest_cids[i];
    } else {
        L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_reset_ecfc_cids
 *
 * Description      resetting cid array values to zero
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_reset_ecfc_cids(uint16_t *sr_cids) {
  //TODO Use Memset..
  for (int i = 0; i < L2C_MAX_ECFC_CHNLS_PER_CONN; i++) {
    sr_cids[i] = 0;
  }
}

/******************************************************************************
 *
 * Function         l2cu_set_coc_map_cids
 *
 * Description      It maps the valid destination cids to control blocks which
 *                  are allocation for the ecfc connection mode.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_coc_map_cids(tL2C_CCB* p_ccb, uint16_t* dest_cid,
                           uint8_t valid_chnls, uint8_t req_chnls) {
  uint8_t valid_indx = 0;
  uint16_t peer_rsp_cids[L2C_MAX_ECFC_CHNLS_PER_CONN] = {0};

  for (uint8_t req_indx = 0; req_indx < req_chnls; req_indx++) {
    if (dest_cid[req_indx] != 0) {
      tL2C_CCB *tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[valid_indx]);
      if (tmp_ccb) {
        tmp_ccb->remote_cid = dest_cid[req_indx];
        peer_rsp_cids[req_indx] = tmp_ccb->local_cid;
      }
      valid_indx++;
      //TODO No need to of this check.. But cross check once again
      if (valid_indx == valid_chnls) break;
    }
  }
  L2CAP_TRACE_WARNING("%s valid Chnls %d Req_chnls %d", __func__,
                      valid_chnls, req_chnls);
  l2cu_set_coc_conn_rsp_cids(peer_rsp_cids, p_ccb, valid_chnls);
}

/******************************************************************************
 *
 * Function         l2cu_set_coc_conn_rsp_cids
 *
 * Description      It sets the source cids for the ECFC connection request.
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_set_coc_conn_rsp_cids(uint16_t* dest_cids,
                                tL2C_CCB* p_ccb,
                                uint8_t num_chnls) {
  L2CAP_TRACE_WARNING("%s ", __func__);

  for (int i = 0; i < num_chnls; i++) {
    tL2C_CCB* tmp_ccb = l2cu_find_ccb_by_cid(p_ccb->p_lcb,
                          p_ccb->coc_cmd_info.ecfc_cids_group[i]);
    if(tmp_ccb != NULL) {
      memcpy(tmp_ccb->coc_cmd_info.peer_rsp_cids, dest_cids,
             sizeof(p_ccb->coc_cmd_info.peer_rsp_cids));
    } else {
      L2CAP_TRACE_ERROR("%s CCB is not present ", __func__);
    }
  }
}

/******************************************************************************
 *
 * Function         l2cu_process_peer_conn_request
 *
 * Description      It process the remote ECFC connection request. And it will
 *                  process the parameters in the request and sends to the
 *                  upper layers if parametes are valid
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_process_peer_conn_request(tL2C_LCB* p_lcb,
                                   tL2CAP_COC_CFG_INFO *p_conf_info,
                                   tL2C_CONN_INFO* con_info,
                                   uint16_t* dest_cid,
                                   uint8_t num_chnls, uint8_t id) {
  int8_t ecfc_conn_req_result = 0;
  uint8_t valid_chnls = 0;
  tL2C_CCB* p_ccb;
  tL2C_RCB *p_rcb;
  L2CAP_TRACE_DEBUG(
    "Recv L2CAP_CMD_CREDIT_BASED_CONNECTION_REQ with "
    "mtu = %d, "
    "mps = %d, "
    "initial credit = %d, "
    "num_chnls %d ",
    p_conf_info->mtu, p_conf_info->mps, p_conf_info->credits,
    num_chnls);

  p_rcb = l2cu_find_coc_rcb_by_psm(con_info->psm);
  if (p_rcb == NULL) {
    L2CAP_TRACE_WARNING("L2CAP - rcvd conn req for unknown PSM: 0x%04x",
                        con_info->psm);
    l2cu_reject_coc_connection(p_lcb, id,
      L2CAP_ECFC_ALL_CONNS_REFUSED_SPSM_NOT_SUPPORTED, num_chnls);
      return;
  } else {
    if (!p_rcb->coc_api.pL2CA_CocConnectInd_Cb) {
      L2CAP_TRACE_WARNING(
         "L2CAP - rcvd conn req for outgoing-only connection PSM: %d",
          con_info->psm);
      l2cu_reject_coc_connection(p_lcb, id,
        L2CAP_ECFC_ALL_CONNS_REFUSED_SPSM_NOT_SUPPORTED, num_chnls);
      return;
    }
  }

  for (int i = 0; i < num_chnls; i++) {
    p_ccb = l2cu_find_ccb_by_remote_cid(p_lcb, dest_cid[i]);
    if (p_ccb) {
      L2CAP_TRACE_WARNING("L2CAP - rcvd conn req for duplicated cid: 0x%04x",
                        dest_cid[i]);
      dest_cid[i] = 0;
      ecfc_conn_req_result =
          L2CAP_ECFC_SOME_CONNS_REFUSED_SOURCE_CID_ALREADY_ALLOCATED;
    } else if (dest_cid[i] == 0) {
      ecfc_conn_req_result =
          L2CAP_ECFC_SOME_CONNS_REFUSED_INVALID_SOURCE_CID;
    } else {
      valid_chnls++;
    }
  }

  L2CAP_TRACE_WARNING("%s ecfc_conn_req_result %d", __func__, ecfc_conn_req_result);
  if (valid_chnls == 0) {
    L2CAP_TRACE_WARNING("L2CAP - rcvd conn req for unknown PSM: 0x%04x",
                        con_info->psm);
    if (ecfc_conn_req_result == 0)
      ecfc_conn_req_result = L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES;

    l2cu_reject_coc_connection(p_lcb, id, ecfc_conn_req_result, num_chnls);
    return;
  }
  /* Allocate a channel control block */
  tL2C_CCB* p_coc_ccb[5];
  uint8_t chnl_status = l2cu_allocate_coc_ccbs(p_lcb, &p_coc_ccb[0],
                                                   &valid_chnls);

  if (chnl_status == L2C_NO_RESOURCE_AVALIABLE) {
    L2CAP_TRACE_ERROR("L2CAP - unable to allocate CCBs");
    l2cu_reject_coc_connection(p_lcb, id,
      L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES, num_chnls);
      return;
  }

  /* validate the parameters */
  if (p_conf_info->mtu < L2CAP_COC_MIN_MTU ||
      p_conf_info->mps < L2CAP_COC_MIN_MPS ||
      p_conf_info->mps > L2CAP_COC_MAX_MPS) {
        L2CAP_TRACE_ERROR("L2CAP don't like the params");
        l2cu_reject_coc_connection(p_lcb, id,
          L2CAP_ECFC_ALL_CONNS_REFUSED_INVALID_PARAMS, num_chnls);
        return;
  }
  l2cu_set_coc_map_cids(p_coc_ccb[0], dest_cid, valid_chnls, num_chnls);
  for (int i = 0; i < valid_chnls; i++) {
    p_coc_ccb[i]->remote_id = id;
    p_coc_ccb[i]->p_rcb = p_rcb;

    p_coc_ccb[i]->peer_conn_cfg.mtu = p_conf_info->mtu;
    p_coc_ccb[i]->peer_conn_cfg.mps = p_conf_info->mps;
    p_coc_ccb[i]->peer_conn_cfg.credits = p_conf_info->credits;

    p_coc_ccb[i]->tx_mps = p_conf_info->mps;
    p_coc_ccb[i]->ble_sdu = NULL;
    p_coc_ccb[i]->ble_sdu_length = 0;
    p_coc_ccb[i]->is_first_seg = true;

    p_coc_ccb[i]->peer_cfg.fcr.mode = L2CAP_FCR_ECFC_MODE;
    p_coc_ccb[i]->coc_cmd_info.num_coc_chnls = valid_chnls;

    if ((chnl_status == 0) && (ecfc_conn_req_result != 0)) {
      p_coc_ccb[i]->coc_cmd_info.ecfc_conn_result =
        ecfc_conn_req_result;
    } else {
      p_coc_ccb[i]->coc_cmd_info.ecfc_conn_result = chnl_status;
    }
    p_coc_ccb[i]->coc_cmd_info.requested_ecfc_chnls = num_chnls;
  }
  l2c_csm_execute(p_coc_ccb[0], L2CEVT_L2CAP_COC_CONNECT_REQ, con_info);
}

/******************************************************************************
 *
 * Function         l2cu_process_peer_ecfc_conn_res
 *
 * Description      It process the connection response which was trigerred from
 *                  remote device. It will validate the connection request is
 *                  success or not
 *
 * Returns          None
 *
 ******************************************************************************/
void l2cu_process_peer_ecfc_conn_res(tL2C_CCB* p_ccb, uint16_t* dest_cid,
                                     tL2C_CONN_INFO* con_info) {
  l2cu_update_ccb_peer_params(p_ccb);

  //TODO Need to check with Spec.. whether separate error code will come or not
  //If not keep this condition to handle this scenario - when no channels are
  //allocated due to insufficient resource
  if (con_info->l2cap_result == L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES) {
    int i = 0;
    for (i = 0; i < p_ccb->coc_cmd_info.num_coc_chnls; i++) {
      if (dest_cid[i] != 0) break;
    }
    if (i == p_ccb->coc_cmd_info.num_coc_chnls) {
      l2c_csm_execute(p_ccb, L2CEVT_L2CAP_COC_CONNECT_NEG_RSP, con_info);
      return;
    }
  }
  bool valid_conn = l2cu_check_for_valid_sr_cids
                          (&p_ccb, &dest_cid[0],con_info->l2cap_result);
  L2CAP_TRACE_WARNING("%s valid_conn %d", __func__, valid_conn);
  if (valid_conn) {
    l2cu_set_coc_remote_cids(&dest_cid[0], p_ccb);

    L2CAP_TRACE_DEBUG(
      "mtu = %d, "
      "mps = %d, "
      "initial_credit = %d, "
      "con_info.l2cap_result = %d",
       p_ccb->peer_conn_cfg.mtu, p_ccb->peer_conn_cfg.mps,
       p_ccb->peer_conn_cfg.credits, con_info->l2cap_result);

    /* validate the parameters */
    if (p_ccb->peer_conn_cfg.mtu < L2CAP_COC_MIN_MTU ||
      p_ccb->peer_conn_cfg.mps < L2CAP_COC_MIN_MPS ||
      p_ccb->peer_conn_cfg.mps > L2CAP_COC_MAX_MPS) {
      L2CAP_TRACE_ERROR("L2CAP don't like the params");
      con_info->l2cap_result = L2CAP_ECFC_ALL_CONNS_REFUSED_INVALID_PARAMS;
      l2c_csm_execute(p_ccb, L2CEVT_L2CAP_COC_CONNECT_NEG_RSP, con_info);
      return;
    }
    l2c_csm_execute(p_ccb, L2CEVT_L2CAP_COC_CONNECT_RSP, con_info);
  } else {
    l2c_csm_execute(p_ccb, L2CEVT_L2CAP_COC_CONNECT_NEG_RSP, con_info);
  }
}

/******************************************************************************
 *
 * Function         l2cu_get_connection_result
 *
 * Description      This function is used for getting the error name
 *
 * Returns          const char*
 *
 ******************************************************************************/
const char* l2cu_get_connection_result(uint16_t result) {
  switch(result) {
    case L2CAP_ECFC_ALL_CONNS_SUCCESSFUL:
      return ("Connection successful");
    case L2CAP_ECFC_SOME_CONNS_REFUSED_INSUFF_RESOURCES:
      return ("Some connections refused – insufficient resources available");
    case L2CAP_ECFC_SOME_CONNS_REFUSED_INVALID_SOURCE_CID:
      return ("Some connections refused – invalid Source CID");
    case L2CAP_ECFC_SOME_CONNS_REFUSED_SOURCE_CID_ALREADY_ALLOCATED:
      return ("Some connections refused – Source CID already allocated");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INVALID_PARAMS:
      return ("All connections refused – invalid parameters");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_SPSM_NOT_SUPPORTED:
      return ("All connections refused – SPSM not supported");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_UNACCEPTABLE_PARAMS:
      return ("All connections refused – unacceptable parameters");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_AUTHENTICATION:
      return ("All connections refused – insufficient authentication");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_AUTHERIZATION:
      return ("All connections refused – insufficient authorization");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_ENCRYPTION:
      return ("All connections refused – insufficient encryption");
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_ENCRYPTION_KEY_SIZE:
      return ("All connections refused – insufficient encryption key size");
    default:
      return ("Unknown result code");
  }
}

/*******************************************************************************
 *
 * Function         l2cu_is_active_ccb_connected
 *
 * Description      Gives data indication callback to upper layer as a new task
 *                  on BTU thread. Upper layer on receiving this indication shall
 *                  invoke api L2CA_ReadData() to read data from rcv_data_q.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_post_data_ind_cb_to_btu(tL2C_CCB* p_ccb) {
  base::MessageLoop* btu_message_loop = get_message_loop();

  if (!btu_message_loop || !btu_message_loop->task_runner().get()) {
    L2CAP_TRACE_WARNING("%s: BTU message loop is not running", __func__);
    return;
  }

  if ((p_ccb->p_rcb) && (p_ccb->p_rcb->coc_api.pL2CA_CocDataInd_Cb)) {
    btu_message_loop->task_runner()->PostTask(FROM_HERE,
        base::Bind(*p_ccb->p_rcb->coc_api.pL2CA_CocDataInd_Cb, p_ccb->local_cid));
  }
}

/*******************************************************************************
 *
 * Function         l2cu_reconfig_coc_req
 *
 * Description      This API sends credit based reconfiguration request.
 *
 * Parameters       chmap_info: info about channels to be configured
 *                  mtu: MTU to be updated.
 *                  mps: MPS to be updated.
 *
 * Returns          return true if sent successfully otherwise false.
 *
 ******************************************************************************/
bool l2cu_reconfig_coc_req(tL2CAP_COC_CHMAP_INFO* chmap_info,
                           uint16_t mtu, uint16_t mps) {
  tL2C_CCB *p_ccb = NULL;
  uint16_t result = l2cu_validate_cids_in_use_status(chmap_info, &p_ccb);

  if (!result || p_ccb == NULL) {
    L2CAP_TRACE_WARNING("%s: all/some l2cap channels already closed , reject request"
                            ,__func__);
    return (false);
  }

  if (p_ccb->our_cfg.fcr.mode != L2CAP_FCR_ECFC_MODE) {
    L2CAP_TRACE_WARNING("%s: these l2cap channel's doesnt support ECFC mode ", __func__);
    return (false);
  }

  if (p_ccb->p_lcb->transport == BT_TRANSPORT_BR_EDR) {
    if (!mps) mps = controller_get_interface()->get_acl_data_size_classic();
  } else if (!mps){
    mps = controller_get_interface()->get_acl_data_size_ble();
  }

  if (l2cu_validate_mps_for_chnls(mps, chmap_info->sr_cids, chmap_info->num_chnls, true)) {
    return false;
  }

  // form reconfig request params
  tL2C_CFG_REQ_PARAM *req_param =
      (tL2C_CFG_REQ_PARAM *)osi_malloc(sizeof(tL2C_CFG_REQ_PARAM));
  memcpy(&req_param->chnl_info, chmap_info, sizeof(tL2CAP_COC_CHMAP_INFO));
  req_param->cfg_params.mtu = mtu;
  req_param->cfg_params.mps = mps;

  l2c_csm_execute(p_ccb, L2CEVT_L2CA_COC_RECONFIG_REQ, req_param);
  return (true);
}

/**************************************************************************************
 *
 * Function         l2cu_send_peer_reconfig_req
 *
 * Description      This API creates reconfiguration request PDU.
 *
 * Parameters       p_ccb: CCB pointer of the l2cap channel
 *                  cfg: reconfiguration request related params.
 *
 * Returns          void
 *
 **************************************************************************************/
void l2cu_send_peer_reconfig_req(tL2C_CCB* p_ccb, tL2C_CFG_REQ_PARAM *cfg) {
  BT_HDR* p_buf;
  uint8_t* p;
  uint8_t num_cids = cfg->chnl_info.num_chnls;
  tL2C_LCB* p_lcb = NULL;

  if (!p_ccb) return;
  p_lcb = p_ccb->p_lcb;

  // length of reconfig request (MTU + MPS + length of cid[] )
  uint16_t reconfig_req_cmd_len = L2CAP_CMD_MTU_MPS_OVERHEAD
                                  + (num_cids * L2CAP_CMD_CID_LEN);

  /* Create an L2CAP identifier for this signalling pdu */
  p_lcb->id++;
  l2cu_adj_id(p_lcb, L2CAP_ADJ_ID);

  // update identifier in all CCB's
  for (int i = 0; i < num_cids; i++) {
    tL2C_CCB *cur_ccb = l2cu_find_ccb_by_cid(NULL, cfg->chnl_info.sr_cids[i]);
    if (cur_ccb) cur_ccb->local_id = p_lcb->id;
  }

  p_buf = l2cu_build_header(p_lcb, reconfig_req_cmd_len,
                            L2CAP_CMD_CREDIT_BASED_RECONFIGURE_REQ, p_lcb->id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_reconfig_req - no buffer allocated");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
          L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, cfg->cfg_params.mtu);
  UINT16_TO_STREAM(p, cfg->cfg_params.mps);
  for (int i = 0; i < num_cids; i++) {
    UINT16_TO_STREAM(p, cfg->chnl_info.sr_cids[i]);
  }

  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);
}

/************************************************************************************
 *
 * Function         l2cu_send_peer_rcfg_rsp
 *
 * Description      This API is used to compose reconfiguration respose pdu
 *
 * Parameters       p_ccb: CCB pointer of the l2cap channel.
 *                  cfg: reconfiguration request related params.
 *
 * Returns          void
 *
 ***********************************************************************************/
void l2cu_send_peer_rcfg_rsp(tL2C_LCB* p_lcb, tL2C_CCB* p_ccb, tL2C_CFG_REQ_PARAM *cfg) {
  BT_HDR* p_buf;
  uint8_t* p;
  if (!p_lcb) p_lcb = (p_ccb ? p_ccb->p_lcb : NULL);

  if (!p_lcb) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_rcfg_rsp - link is not present");
    return;
  }

  // length of reconfig response (result length)
  uint16_t reconfig_req_cmd_len = 2;

  /* Create l2cap response header*/
  p_buf = l2cu_build_header(p_lcb, reconfig_req_cmd_len,
                            L2CAP_CMD_CREDIT_BASED_RECONFIGURE_RSP, cfg->trans_id);
  if (p_buf == NULL) {
    L2CAP_TRACE_WARNING("l2cu_send_peer_rcfg_rsp - no buffer allocated");
    return;
  }

  p = (uint8_t*)(p_buf + 1) + L2CAP_SEND_CMD_OFFSET + HCI_DATA_PREAMBLE_SIZE +
          L2CAP_PKT_OVERHEAD + L2CAP_CMD_OVERHEAD;

  UINT16_TO_STREAM(p, cfg->result);
  l2c_link_check_send_pkts(p_lcb, NULL, p_buf);

  // free tL2C_CFG_REQ_PARAM
  osi_free(cfg);
}

/************************************************************************************
 *
 * Function         l2cu_set_multi_coc_chnl_cfg
 *
 * Description      This API is used to update ccb parameters after reconfig req/res
 *
 * Parameters       p_lcb: LCB pointer of the link.
 *                  cfg: reconfiguration request related params.
 *                  state: state to be updated in CCB for L2CAP channel.
 *                  cfg_state: configuration state (Inbound or Outbound)
 *
 * Returns          void
 *
 ***********************************************************************************/
void l2cu_set_multi_coc_chnl_cfg(tL2C_LCB* p_lcb, tL2C_CFG_REQ_PARAM* cfg,
                                 tL2C_CHNL_STATE state, uint8_t cfg_state) {
  for (int i = 0; i < cfg->chnl_info.num_chnls; i++) {
    tL2C_CCB *p_ccb = l2cu_find_ccb_by_cid(p_lcb, cfg->chnl_info.sr_cids[i]);
    if (p_ccb) {
      p_ccb->chnl_state = state;
      p_ccb->config_done &= cfg_state;
      if (!(cfg_state & OB_CFG_DONE)) {
        p_ccb->pending_out_cfg = cfg;
      } else if (!(cfg_state & IB_CFG_DONE)) {
        p_ccb->pending_inc_cfg = cfg;
      }
    }
  }
}

/************************************************************************************
 *
 * Function         l2cu_validate_mps_for_chnls
 *
 * Description      This function checks if updated MPS value is valid or not.
 *
 * Parameters       mps: updated MPS value
 *                  cid: pointer to array of CID's for which MPS update is required
 *                  num_chnls: number of channels for which MPS update is required.
 *
 * Returns          result code based on MPS validity.
 *
 ***********************************************************************************/
uint16_t l2cu_validate_mps_for_chnls(uint16_t mps, uint16_t *cid,
                                     uint8_t num_chnls, bool isOutgoing) {
  if (mps < L2CAP_COC_MIN_MPS || mps > L2CAP_COC_MAX_MPS) {
    L2CAP_TRACE_WARNING("%s: Unacceptable MPS(%d) value, reject reconfig request"
        , __func__, mps);
    return L2CAP_RCFG_UNACCEPTABLE_PARAMS;
  }

  if (num_chnls > 1) {
    for (int i = 0; i < num_chnls; i++) {
      tL2C_CCB *p_ccb = l2cu_find_ccb_by_cid(NULL, cid[i]);
      if (isOutgoing && p_ccb && p_ccb->local_conn_cfg.mps > mps) {
        L2CAP_TRACE_WARNING("%s: Unacceptable MPS(%d) value, lesser than cid(%x)'s mps(%d)"
            , __func__, mps, cid[i], p_ccb->local_conn_cfg.mps);
        return L2CAP_RCFG_MPS_REDUCTION_NOT_ALLOWED;
      } else if (!isOutgoing && p_ccb && p_ccb->peer_conn_cfg.mps > mps) {
        L2CAP_TRACE_WARNING("%s: Unacceptable MPS(%d) value, lesser than remote cid(%x)'s"
            " mps(%d)", __func__, mps, p_ccb->remote_cid, p_ccb->peer_conn_cfg.mps);
        return L2CAP_RCFG_MPS_REDUCTION_NOT_ALLOWED;
      }
    }
  }
  return L2CAP_RCFG_OK;
}

/************************************************************************************
 *
 * Function         l2cu_validate_mtu_for_chnls
 *
 * Description      This function checks if updated MPS value is valid or not.
 *
 * Parameters       mtu: updated MTU value
 *                  cid: pointer to array of CID's for which MTU update is required
 *                  num_chnls: number of channels for which MTU update is required.
 *
 * Returns          result code based on MTU validity.
 *
 ***********************************************************************************/
uint16_t l2cu_validate_mtu_for_chnls(uint16_t mtu,
                                     uint16_t *cid, uint8_t num_chnls, bool isOutgoing) {
  if (mtu < L2CAP_COC_MIN_MTU) {
    L2CAP_TRACE_WARNING("%s: Unacceptable MTU(%d) value, reject reconfig request"
        , __func__, mtu);
    return L2CAP_RCFG_UNACCEPTABLE_PARAMS;
  }

  for (int i = 0; i < num_chnls; i++) {
    tL2C_CCB *p_ccb = l2cu_find_ccb_by_cid(NULL, cid[i]);

    if (isOutgoing && p_ccb && p_ccb->local_conn_cfg.mtu > mtu) {
      L2CAP_TRACE_WARNING("%s: Unacceptable update in mtu(%d), lesser than cid(%x)'s mtu(%d)"
          , __func__, mtu, cid[i], p_ccb->local_conn_cfg.mtu);
      return L2CAP_RCFG_MTU_REDUCTION_NOT_ALLOWED;
    } else if (!isOutgoing && p_ccb && p_ccb->peer_conn_cfg.mtu > mtu) {
      L2CAP_TRACE_WARNING("%s: Unacceptable update in mtu(%d), lesser than remote cid(%x)'s"
          " mtu(%d)", __func__, mtu, p_ccb->remote_cid, p_ccb->peer_conn_cfg.mtu);
      return L2CAP_RCFG_MTU_REDUCTION_NOT_ALLOWED;
    }
  }

  return L2CAP_RCFG_OK;
}

/************************************************************************************
 *
 * Function         l2cu_find_params_for_peer_rcfg_rsp
 *
 * Description      this function extracts reconfig request params from l2cap id
 *                  and send reconfig rsp event to state machine based.
 *
 * Parameters       p_lcb: LCB pointer of the link on which response has come.
 *                  result: result code in reconfig response from peer.
 *                  id: Identifier in l2cap signalling command.
 *
 * Returns          void
 *
 ***********************************************************************************/
void l2cu_find_req_params_for_peer_rcfg_rsp(tL2C_LCB* p_lcb,
                                            uint16_t result, uint8_t id) {
  tL2C_CCB* p_ccb;

  for (p_ccb = p_lcb->ccb_queue.p_first_ccb; p_ccb; p_ccb = p_ccb->p_next_ccb) {
    if ((p_ccb->in_use) && (p_ccb->local_id == id)) {
      if (p_ccb->pending_out_cfg) {
        p_ccb->pending_out_cfg->result = result;
        L2CAP_TRACE_WARNING("%s: response received for sent reconfig request(id: %d),"
            "result = %d MTU = %d, MPS = %d", __func__, id, result,
            p_ccb->pending_out_cfg->cfg_params.mtu, p_ccb->pending_out_cfg->cfg_params.mps);
        l2c_csm_execute(p_ccb, L2CEVT_L2CAP_COC_RECONFIG_RSP, p_ccb->pending_out_cfg);
        break;
      } else {
        L2CAP_TRACE_WARNING("%s: transaction with id(%x) has timed out", __func__, id);
        return;
      }
    }
  }
}

/************************************************************************************
 *
 * Function         l2cu_process_peer_coc_rcfg_rsp
 *
 * Description      This function processes reconfig reponse from peer and updates
 *                  local configuration parameters.
 *
 * Parameters       cfg: reconfig params sent by local device in reconfig request.
 *
 * Returns          void
 *
 ***********************************************************************************/
void l2cu_process_peer_rcfg_rsp(tL2C_CFG_REQ_PARAM *cfg) {
  uint8_t num_cids = cfg->chnl_info.num_chnls;

  for (int i = 0; i < num_cids; i++) {
    tL2C_CCB *p_ccb = l2cu_find_ccb_by_cid(NULL, cfg->chnl_info.sr_cids[i]);
    if (p_ccb) {
      // reset config_done to OB_CFG_DONE and change state if reconfig is completed
      p_ccb->config_done |= OB_CFG_DONE;
      if (p_ccb->config_done & IB_CFG_DONE) {
        p_ccb->chnl_state = CST_OPEN;       // move to CST_OPEN State
      }
      // update MTU and MPS values to new values
      if (cfg->result == L2CAP_RCFG_OK) {
        p_ccb->local_conn_cfg.mtu = p_ccb->pending_out_cfg->cfg_params.mtu;
        p_ccb->local_conn_cfg.mps = p_ccb->pending_out_cfg->cfg_params.mps;
      }
      p_ccb->pending_out_cfg = NULL;
    }
  }

  // cancel alarm for outgoing reconfiguration
  if (alarm_is_scheduled(cfg->l2c_cfg_timer)) {
    alarm_free(cfg->l2c_cfg_timer);
  }
}

/************************************************************************************
 *
 * Function         l2cu_process_peer_rcfg_req
 *
 * Description      This function processes reconfig request sent by peer device.
 *
 * Parameters       cfg: reconfig params sent by peer device in reconfig request.
 *
 * Returns          void
 *
 ***********************************************************************************/
bool l2cu_process_peer_rcfg_req(tL2C_CFG_REQ_PARAM *cfg) {
  uint16_t result = 0;
  tL2C_CCB* p_ccb = NULL;

  result = l2cu_validate_mtu_for_chnls(cfg->cfg_params.mtu,
              cfg->chnl_info.sr_cids, cfg->chnl_info.num_chnls, false);
  if (result) {
    //0x0001 Reconfiguration failed - reduction in size of MTU not allowed
    //0x0004 Reconfiguration failed - other unacceptable parameters
    cfg->result = result;
    l2cu_validate_cids_in_use_status(&cfg->chnl_info, &p_ccb);
    L2CAP_TRACE_WARNING("%s: Result = %x (%s)", __func__, result,
                       l2cu_get_reconfig_result(result));
    l2cu_send_peer_rcfg_rsp(p_ccb->p_lcb, p_ccb, cfg);
    return false;
  }

  result = l2cu_validate_mps_for_chnls(cfg->cfg_params.mps,
              cfg->chnl_info.sr_cids, cfg->chnl_info.num_chnls, false);
  if (result) {
    //0x0002 Reconfiguration failed - reduction in size of MPS not allowed for
    //0x0004 Reconfiguration failed - other unacceptable parameters
    cfg->result = result;
    l2cu_validate_cids_in_use_status(&cfg->chnl_info, &p_ccb);
    L2CAP_TRACE_WARNING("%s: Result = %x (%s)", __func__, result,
                       l2cu_get_reconfig_result(result));
    l2cu_send_peer_rcfg_rsp(p_ccb->p_lcb, p_ccb, cfg);
    return false;
  }

  l2cu_set_multi_coc_chnl_cfg(NULL, cfg, CST_CONFIG, ~IB_CFG_DONE);
  return true;
}

/************************************************************************************
 *
 * Function         l2cu_process_local_rcfg_rsp
 *
 * Description      This function processes reconfig response from upper layer or
 *                  set internally by l2cap.
 *
 * Parameters       cfg: reconfig params sent by peer device in reconfig request.
 *
 * Returns          void
 *
 ***********************************************************************************/
void l2cu_process_local_rcfg_rsp(tL2C_CFG_REQ_PARAM *rcfg) {
  uint8_t num_cids = rcfg->chnl_info.num_chnls;

  for (int i = 0; i < num_cids; i++) {
    tL2C_CCB *p_ccb = l2cu_find_ccb_by_cid(NULL, rcfg->chnl_info.sr_cids[i]);
    if (p_ccb) {
      // reset config_done to OB_CFG_DONE and change state if reconfig is completed
      p_ccb->config_done |= IB_CFG_DONE;
      if (p_ccb->config_done & OB_CFG_DONE) {
        p_ccb->chnl_state = CST_OPEN;        // move to CST_OPEN State
      }
      // update MTU and MPS values to new values
      if (rcfg->result == L2CAP_RCFG_OK) {
        p_ccb->peer_conn_cfg.mtu = p_ccb->pending_inc_cfg->cfg_params.mtu;
        p_ccb->peer_conn_cfg.mps = p_ccb->pending_inc_cfg->cfg_params.mps;
      }
      p_ccb->pending_inc_cfg = NULL;
    }
  }

  // cancel incoming reconfig alarm
  if (alarm_is_scheduled(rcfg->l2c_cfg_timer)) {
    alarm_free(rcfg->l2c_cfg_timer);
  }
}

/************************************************************************************
 *
 * Function         l2cu_validate_cids_in_use_status
 *
 * Description      This function validates if all channels corresponding to CID's in
 *                  chnl_inf are connected or not. Also, sends the active CCB among
 *                  the set of channels.
 *
 * Parameters       chnl_inf: info l2cap channels used.
 *                  p_active_ccb: one of the active CCB will be updated in this pointer.
 *
 * Returns          true, if all channels are in use. Otherwise, false.
 *
 ***********************************************************************************/
bool l2cu_validate_cids_in_use_status(tL2CAP_COC_CHMAP_INFO *chnl_inf,
                                      tL2C_CCB **p_active_ccb) {
  uint8_t num_cids = chnl_inf->num_chnls;
  bool all_active = true;

  for (int i = 0; i < num_cids; i++) {
    tL2C_CCB *cur_ccb = l2cu_find_ccb_by_cid(NULL, chnl_inf->sr_cids[i]);
    if (!cur_ccb) all_active = false;
    if (!(*p_active_ccb) && cur_ccb) *p_active_ccb = cur_ccb;
    if (*p_active_ccb && !all_active) return all_active;
  }
  return all_active;
}

/*******************************************************************************
 *
 * Function         l2cu_send_flow_control_credit
 *
 * Description      This function sends flow control credits for
 *                  LE connection oriented channels.
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_flow_control_credit(tL2C_CCB* p_ccb, uint16_t credit_value) {
  if (!p_ccb) return;
  L2CAP_TRACE_WARNING("%s: sending %d credits to channel %x", __func__,
      credit_value, p_ccb->local_cid);

  if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_ECFC_MODE
      && p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_LE_COC_MODE) {
    L2CAP_TRACE_WARNING("%s: Can not send credit indication in this mode: %d", __func__,
                        p_ccb->peer_cfg.fcr.mode);
    return;
  }

  l2cu_send_peer_ble_flow_control_credit(p_ccb, credit_value);
  return;
}

/*******************************************************************************
 *
 * Function         l2cu_send_peer_coc_disc_req
 *
 * Description      This function sends disconnect request
 *                  to the peer LE device
 *
 * Returns          void
 *
 ******************************************************************************/
void l2cu_send_peer_coc_disc_req(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_DEBUG("%s", __func__);

  if (!p_ccb) return;

  if (p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_ECFC_MODE
          && p_ccb->peer_cfg.fcr.mode != L2CAP_FCR_LE_COC_MODE) {
    L2CAP_TRACE_WARNING("Disconnection trigered for incorrect mode: %d",
        p_ccb->peer_cfg.fcr.mode);
    return;
  }

  l2cu_send_peer_ble_credit_based_disconn_req(p_ccb);
  return;
}

/************************************************************************************
 *
 * Function         l2cu_clear_reconfig_params
 *
 * Description      Clear pending reconfiguration parameters on link disconnection.
 *
 * Parameters       void
 *
 ***********************************************************************************/
void l2cu_clear_reconfig_params(tL2C_CCB* p_ccb) {
  L2CAP_TRACE_DEBUG("%s", __func__);

  if (p_ccb && p_ccb->peer_cfg.fcr.mode == L2CAP_FCR_ECFC_MODE) {
    // clear and deallocate incoming reconfig params in ccb
    if (p_ccb->pending_inc_cfg &&
        alarm_is_scheduled(p_ccb->pending_inc_cfg->l2c_cfg_timer)) {
      alarm_free(p_ccb->pending_inc_cfg->l2c_cfg_timer);
    }
    osi_free(p_ccb->pending_inc_cfg);
    p_ccb->pending_inc_cfg = NULL;

    // clear and deallocate outgoing reconfig params in ccb
    if (p_ccb->pending_out_cfg &&
        alarm_is_scheduled(p_ccb->pending_out_cfg->l2c_cfg_timer)) {
      alarm_free(p_ccb->pending_out_cfg->l2c_cfg_timer);
    }
    osi_free(p_ccb->pending_out_cfg);
    p_ccb->pending_out_cfg = NULL;
  }
}

/************************************************************************************
 *
 * Function         l2cu_get_reconfig_result
 *
 * Description      Sends the result description as in reconfig respose in spec.
 *
 * Parameters       result : result code
 *
 * Returns          result text.
 *
 ***********************************************************************************/
const char* l2cu_get_reconfig_result(uint16_t result) {
  switch(result) {
    case L2CAP_RCFG_OK:
      return ("Reconfiguration successful");
    case L2CAP_RCFG_MTU_REDUCTION_NOT_ALLOWED:
      return ("Reconfiguration failed - reduction in size of MTU not allowed");
    case L2CAP_RCFG_MPS_REDUCTION_NOT_ALLOWED:
      return ("Reconfiguration failed - reduction in size of MPS not allowed for"
                  " more than one channel at a time");
    case L2CAP_RCFG_INVALID_DCID:
      return ("Reconfiguration failed - one or more Destination CIDs invalid");
    case L2CAP_RCFG_UNACCEPTABLE_PARAMS:
      return ("Reconfiguration failed - other unacceptable parameters");
    default:
      return ("Unknown result code");
  }
}

/*******************************************************************************
 *
 * Function         l2cu_find_ccb_by_l2cap_id
 *
 * Description      Look through all active CCB on a link for a match based
 *                  on the l2cap_id. If passed the link pointer is NULL, all
 *                  active ccbs are searched.
 *
 * Returns          pointer to matched CCB, or NULL if no match
 *
 ******************************************************************************/
tL2C_CCB* l2cu_find_ccb_by_l2cap_id(tL2C_LCB* p_lcb, uint16_t l2cap_id) {
  tL2C_CCB* p_ccb = NULL;
  uint8_t xx;

    /* searching fixed channel */
    p_ccb = l2cb.ccb_pool;
    for (xx = 0; xx < MAX_L2CAP_CHANNELS; xx++) {
      if ((p_ccb->remote_id == l2cap_id) && (p_ccb->in_use) &&
          (p_lcb == p_ccb->p_lcb))
        break;
      else
        p_ccb++;
    }
    if (xx >= MAX_L2CAP_CHANNELS) return NULL;

  return (p_ccb);
}


/*******************************************************************************
 *
 * Function         l2cu_is_unaccepted_coc_result_code
 *
 * Description      Check for unacceptable/invalid/insufficient result code
 *
 * Returns          true , if it matches any of the above one
                    false default
 *
 ******************************************************************************/
bool l2cu_is_unaccepted_coc_result_code(uint16_t result) {
  switch (result) {
    case L2CAP_ECFC_ALL_CONNS_REFUSED_UNACCEPTABLE_PARAMS:
      FALLTHROUGH_INTENDED; /* FALLTHROUGH */
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INSUFF_AUTHERIZATION:
      FALLTHROUGH_INTENDED; /* FALLTHROUGH */
    case L2CAP_ECFC_ALL_CONNS_REFUSED_INVALID_PARAMS:
      return true;
    default:
      return false;
  }
}

