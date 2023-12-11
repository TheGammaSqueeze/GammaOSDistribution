/******************************************************************************
 *
 *  Copyright (c) 2016, The Linux Foundation. All rights reserved.
 *  Not a Contribution.
 *
 *  Copyright (C) 2015-2020 NXP
 *  The original Work has been changed by NXP.
 *
 *  Copyright (C) 2010-2014 Broadcom Corporation
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
 *  This file contains the action functions for the NFA HCI.
 *
 ******************************************************************************/
#include <log/log.h>
#include <string.h>

#include <android-base/stringprintf.h>
#include <base/logging.h>

#include "nfa_hci_api.h"
#include "nfa_hci_int.h"
#include "nfa_dm_int.h"
#include "nfa_hci_defs.h"
#if (NXP_EXTNS == TRUE)
#include "nfa_ee_int.h"
#include "nfc_int.h"
#endif

using android::base::StringPrintf;

extern bool nfc_debug_enabled;


/* Static local functions       */
static void nfa_hci_api_register(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_get_gate_pipe_list(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_alloc_gate(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_get_host_list(tNFA_HCI_EVENT_DATA* p_evt_data);
static bool nfa_hci_api_get_reg_value(tNFA_HCI_EVENT_DATA* p_evt_data);
static bool nfa_hci_api_set_reg_value(tNFA_HCI_EVENT_DATA* p_evt_data);
static bool nfa_hci_api_create_pipe(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_open_pipe(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_close_pipe(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_delete_pipe(tNFA_HCI_EVENT_DATA* p_evt_data);
static bool nfa_hci_api_send_event(tNFA_HCI_EVENT_DATA* p_evt_data);
static bool nfa_hci_api_send_cmd(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_send_rsp(tNFA_HCI_EVENT_DATA* p_evt_data);
static void nfa_hci_api_add_static_pipe(tNFA_HCI_EVENT_DATA* p_evt_data);

static void nfa_hci_handle_identity_mgmt_gate_pkt(uint8_t* p_data,
                                                  tNFA_HCI_DYN_PIPE* p_pipe);
static void nfa_hci_handle_loopback_gate_pkt(uint8_t* p_data, uint16_t data_len,
                                             tNFA_HCI_DYN_PIPE* p_pipe);
static void nfa_hci_handle_connectivity_gate_pkt(uint8_t* p_data,
                                                 uint16_t data_len,
                                                 tNFA_HCI_DYN_PIPE* p_pipe);
static void nfa_hci_handle_generic_gate_cmd(uint8_t* p_data, uint8_t data_len,
                                            tNFA_HCI_DYN_PIPE* p_pipe);
static void nfa_hci_handle_generic_gate_rsp(uint8_t* p_data, uint8_t data_len,
                                            tNFA_HCI_DYN_PIPE* p_pipe);
static void nfa_hci_handle_generic_gate_evt(uint8_t* p_data, uint16_t data_len,
                                            tNFA_HCI_DYN_GATE* p_gate,
                                            tNFA_HCI_DYN_PIPE* p_pipe);

#if (NXP_EXTNS == TRUE)
static __attribute__((unused)) void nfa_hci_api_get_host_id(tNFA_HCI_EVENT_DATA* p_evt_data);
static __attribute__((unused)) void nfa_hci_api_get_host_type(tNFA_HCI_EVENT_DATA* p_evt_data);
static tNFA_STATUS nfa_hci_api_get_host_type_list();
static void nfa_hci_api_getnoofhosts(uint8_t* p_data, uint8_t data_len);
static void nfa_hci_handle_Nfcee_admpipe_rsp(uint8_t* p_data, uint8_t data_len);
static void nfa_hci_handle_Nfcee_dynpipe_rsp(uint8_t pipeId, uint8_t* p_data,
                                             uint8_t data_len);
static bool nfa_hci_api_checkforAPDUGate(uint8_t* p_data, uint8_t data_len);
static bool nfa_hci_api_IspipePresent(uint8_t nfceeId, uint8_t gateId);
static __attribute__((unused)) bool nfa_hci_api_GetpipeId(uint8_t nfceeId, uint8_t gateId,
                                  uint8_t* pipeId);
static void nfa_hci_poll_session_id_cb(uint8_t event, uint16_t param_len,
                                       uint8_t* p_param);
static __attribute__((unused)) void nfa_hci_read_num_nfcee_config_cb(uint8_t event, uint16_t param_len,
                                             uint8_t* p_param);
static tNFA_STATUS nfa_hci_poll_session_id(uint8_t host_type);
static void nfa_hci_get_pipe_state_cb(uint8_t event, uint16_t param_len, uint8_t* p_param);
static void nfa_hci_update_pipe_status(uint8_t gateId, uint8_t pipeId);
#endif

/*******************************************************************************
**
** Function         nfa_hci_check_pending_api_requests
**
** Description      This function handles pending API requests
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_check_pending_api_requests(void) {
  NFC_HDR* p_msg;
  tNFA_HCI_EVENT_DATA* p_evt_data;
  bool b_free;

  /* If busy, or API queue is empty, then exit */
  if ((nfa_hci_cb.hci_state != NFA_HCI_STATE_IDLE) ||
      ((p_msg = (NFC_HDR*)GKI_dequeue(&nfa_hci_cb.hci_host_reset_api_q)) ==
       nullptr))
    return;

  /* Process API request */
  p_evt_data = (tNFA_HCI_EVENT_DATA*)p_msg;

  /* Save the application handle */
  nfa_hci_cb.app_in_use = p_evt_data->comm.hci_handle;

  b_free = true;
  switch (p_msg->event) {
    case NFA_HCI_API_CREATE_PIPE_EVT:
      if (nfa_hci_api_create_pipe(p_evt_data) == false) b_free = false;
      break;

    case NFA_HCI_API_GET_REGISTRY_EVT:
      if (nfa_hci_api_get_reg_value(p_evt_data) == false) b_free = false;
      break;

    case NFA_HCI_API_SET_REGISTRY_EVT:
      if (nfa_hci_api_set_reg_value(p_evt_data) == false) b_free = false;
      break;

    case NFA_HCI_API_SEND_CMD_EVT:
      if (nfa_hci_api_send_cmd(p_evt_data) == false) b_free = false;
      break;
    case NFA_HCI_API_SEND_EVENT_EVT:
      if (nfa_hci_api_send_event(p_evt_data) == false) b_free = false;
      break;
#if (NXP_EXTNS == TRUE)
    case NFA_HCI_API_CONFIGURE_EVT:
      if (nfa_hci_api_config_nfcee(
              p_evt_data->config_info.config_nfcee_event) == false)
        b_free = false;
      break;
#endif
  }

  if (b_free) GKI_freebuf(p_msg);
}

/*******************************************************************************
**
** Function         nfa_hci_check_api_requests
**
** Description      This function handles API requests
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_check_api_requests(void) {
  NFC_HDR* p_msg;
  tNFA_HCI_EVENT_DATA* p_evt_data;

  for (;;) {
    /* If busy, or API queue is empty, then exit */
    if ((nfa_hci_cb.hci_state != NFA_HCI_STATE_IDLE) ||
        ((p_msg = (NFC_HDR*)GKI_dequeue(&nfa_hci_cb.hci_api_q)) == nullptr))
      break;

    /* Process API request */
    p_evt_data = (tNFA_HCI_EVENT_DATA*)p_msg;

    /* Save the application handle */
    nfa_hci_cb.app_in_use = p_evt_data->comm.hci_handle;

    switch (p_msg->event) {
      case NFA_HCI_API_REGISTER_APP_EVT:
        nfa_hci_api_register(p_evt_data);
        break;

      case NFA_HCI_API_DEREGISTER_APP_EVT:
        nfa_hci_api_deregister(p_evt_data);
        break;

      case NFA_HCI_API_GET_APP_GATE_PIPE_EVT:
        nfa_hci_api_get_gate_pipe_list(p_evt_data);
        break;

      case NFA_HCI_API_ALLOC_GATE_EVT:
        nfa_hci_api_alloc_gate(p_evt_data);
        break;

      case NFA_HCI_API_DEALLOC_GATE_EVT:
        nfa_hci_api_dealloc_gate(p_evt_data);
        break;

      case NFA_HCI_API_GET_HOST_LIST_EVT:
        nfa_hci_api_get_host_list(p_evt_data);
        break;

      case NFA_HCI_API_GET_REGISTRY_EVT:
        if (nfa_hci_api_get_reg_value(p_evt_data) == false) continue;
        break;

      case NFA_HCI_API_SET_REGISTRY_EVT:
        if (nfa_hci_api_set_reg_value(p_evt_data) == false) continue;
        break;

      case NFA_HCI_API_CREATE_PIPE_EVT:
        if (nfa_hci_api_create_pipe(p_evt_data) == false) continue;
        break;

      case NFA_HCI_API_OPEN_PIPE_EVT:
        nfa_hci_api_open_pipe(p_evt_data);
        break;

      case NFA_HCI_API_CLOSE_PIPE_EVT:
        nfa_hci_api_close_pipe(p_evt_data);
        break;

      case NFA_HCI_API_DELETE_PIPE_EVT:
        nfa_hci_api_delete_pipe(p_evt_data);
        break;

      case NFA_HCI_API_SEND_CMD_EVT:
        if (nfa_hci_api_send_cmd(p_evt_data) == false) continue;
        break;

      case NFA_HCI_API_SEND_RSP_EVT:
        nfa_hci_api_send_rsp(p_evt_data);
        break;

      case NFA_HCI_API_SEND_EVENT_EVT:
        if (nfa_hci_api_send_event(p_evt_data) == false) continue;
        break;

      case NFA_HCI_API_ADD_STATIC_PIPE_EVT:
        nfa_hci_api_add_static_pipe(p_evt_data);
        break;
#if (NXP_EXTNS == TRUE)
      case NFA_HCI_API_CONFIGURE_EVT:
        nfa_hci_handle_nfcee_config_evt(
            p_evt_data->config_info.config_nfcee_event);
        break;
#endif
      default:
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_check_api_requests ()  Unknown event: 0x%04x",
                         p_msg->event);
        break;
    }

    GKI_freebuf(p_msg);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_register
**
** Description      action function to register the events for the given AID
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_register(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  char* p_app_name = p_evt_data->app_info.app_name;
  tNFA_HCI_CBACK* p_cback = p_evt_data->app_info.p_cback;
  int xx, yy;
  uint8_t num_gates = 0, num_pipes = 0;
  tNFA_HCI_DYN_GATE* pg = nfa_hci_cb.cfg.dyn_gates;

  /* First, see if the application was already registered */
  for (xx = 0; xx < NFA_HCI_MAX_APP_CB; xx++) {
    if ((nfa_hci_cb.cfg.reg_app_names[xx][0] != 0) &&
        !strncmp(p_app_name, &nfa_hci_cb.cfg.reg_app_names[xx][0],
                 strlen(p_app_name))) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_register (%s)  Reusing: %u", p_app_name,
                       xx);
      break;
    }
  }

  if (xx != NFA_HCI_MAX_APP_CB) {
    nfa_hci_cb.app_in_use = (tNFA_HANDLE)(xx | NFA_HANDLE_GROUP_HCI);
    /* The app was registered, find the number of gates and pipes associated to
     * the app */

    for (yy = 0; yy < NFA_HCI_MAX_GATE_CB; yy++, pg++) {
      if (pg->gate_owner == nfa_hci_cb.app_in_use) {
        num_gates++;
        num_pipes += nfa_hciu_count_pipes_on_gate(pg);
      }
    }
  } else {
    /* Not registered, look for a free entry */
    for (xx = 0; xx < NFA_HCI_MAX_APP_CB; xx++) {
      if (nfa_hci_cb.cfg.reg_app_names[xx][0] == 0) {
        memset(&nfa_hci_cb.cfg.reg_app_names[xx][0], 0,
               sizeof(nfa_hci_cb.cfg.reg_app_names[xx]));
        strlcpy(&nfa_hci_cb.cfg.reg_app_names[xx][0], p_app_name,
                NFA_MAX_HCI_APP_NAME_LEN);
        nfa_hci_cb.nv_write_needed = true;
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_register (%s)  Allocated: %u", p_app_name,
                         xx);
        break;
      }
    }

    if (xx == NFA_HCI_MAX_APP_CB) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_register (%s)  NO ENTRIES", p_app_name);

      evt_data.hci_register.status = NFA_STATUS_FAILED;
      p_evt_data->app_info.p_cback(NFA_HCI_REGISTER_EVT, &evt_data);
      return;
    }
  }

  evt_data.hci_register.num_pipes = num_pipes;
  evt_data.hci_register.num_gates = num_gates;
  nfa_hci_cb.p_app_cback[xx] = p_cback;

  nfa_hci_cb.cfg.b_send_conn_evts[xx] = p_evt_data->app_info.b_send_conn_evts;

  evt_data.hci_register.hci_handle = (tNFA_HANDLE)(xx | NFA_HANDLE_GROUP_HCI);

  evt_data.hci_register.status = NFA_STATUS_OK;

  /* notify NFA_HCI_REGISTER_EVT to the application */
  p_evt_data->app_info.p_cback(NFA_HCI_REGISTER_EVT, &evt_data);
}

/*******************************************************************************
**
** Function         nfa_hci_api_deregister
**
** Description      action function to deregister the given application
**
** Returns          None
**
*******************************************************************************/
void nfa_hci_api_deregister(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_CBACK* p_cback = nullptr;
  int xx;
  tNFA_HCI_DYN_PIPE* p_pipe;
  tNFA_HCI_DYN_GATE* p_gate;

  /* If needed, find the application registration handle */
  if (p_evt_data != nullptr) {
    for (xx = 0; xx < NFA_HCI_MAX_APP_CB; xx++) {
      if ((nfa_hci_cb.cfg.reg_app_names[xx][0] != 0) &&
          !strncmp(p_evt_data->app_info.app_name,
                   &nfa_hci_cb.cfg.reg_app_names[xx][0],
                   strlen(p_evt_data->app_info.app_name))) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_deregister (%s) inx: %u",
                         p_evt_data->app_info.app_name, xx);
        break;
      }
    }

    if (xx == NFA_HCI_MAX_APP_CB) {
      LOG(WARNING) << StringPrintf("nfa_hci_api_deregister () Unknown app: %s",
                         p_evt_data->app_info.app_name);
      return;
    }
    nfa_hci_cb.app_in_use = (tNFA_HANDLE)(xx | NFA_HANDLE_GROUP_HCI);
    p_cback = nfa_hci_cb.p_app_cback[xx];
  } else {
    nfa_sys_stop_timer(&nfa_hci_cb.timer);
    /* We are recursing through deleting all the app's pipes and gates */
    p_cback = nfa_hci_cb.p_app_cback[nfa_hci_cb.app_in_use & NFA_HANDLE_MASK];
  }

  /* See if any pipe is owned by this app */
  if (nfa_hciu_find_pipe_by_owner(nfa_hci_cb.app_in_use) == nullptr) {
    /* No pipes, release all gates owned by this app */
    while ((p_gate = nfa_hciu_find_gate_by_owner(nfa_hci_cb.app_in_use)) !=
           nullptr)
      nfa_hciu_release_gate(p_gate->gate_id);

    memset(&nfa_hci_cb.cfg
                .reg_app_names[nfa_hci_cb.app_in_use & NFA_HANDLE_MASK][0],
           0, NFA_MAX_HCI_APP_NAME_LEN + 1);
    nfa_hci_cb.p_app_cback[nfa_hci_cb.app_in_use & NFA_HANDLE_MASK] = nullptr;

    nfa_hci_cb.nv_write_needed = true;

    evt_data.hci_deregister.status = NFC_STATUS_OK;

    if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER)
      nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;

    /* notify NFA_HCI_DEREGISTER_EVT to the application */
    if (p_cback) p_cback(NFA_HCI_DEREGISTER_EVT, &evt_data);
  } else if ((p_pipe = nfa_hciu_find_active_pipe_by_owner(
                  nfa_hci_cb.app_in_use)) == nullptr) {
    /* No pipes, release all gates owned by this app */
    while ((p_gate = nfa_hciu_find_gate_with_nopipes_by_owner(
                nfa_hci_cb.app_in_use)) != nullptr)
      nfa_hciu_release_gate(p_gate->gate_id);

    nfa_hci_cb.p_app_cback[nfa_hci_cb.app_in_use & NFA_HANDLE_MASK] = nullptr;

    nfa_hci_cb.nv_write_needed = true;

    evt_data.hci_deregister.status = NFC_STATUS_FAILED;

    if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER)
      nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;

    /* notify NFA_HCI_DEREGISTER_EVT to the application */
    if (p_cback) p_cback(NFA_HCI_DEREGISTER_EVT, &evt_data);
  } else {
    /* Delete all active pipes created for the application before de registering
    **/
    nfa_hci_cb.hci_state = NFA_HCI_STATE_APP_DEREGISTER;

    nfa_hciu_send_delete_pipe_cmd(p_pipe->pipe_id);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_get_gate_pipe_list
**
** Description      action function to get application allocated gates and
**                  application created pipes
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_get_gate_pipe_list(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  int xx, yy;
  tNFA_HCI_DYN_GATE* pg = nfa_hci_cb.cfg.dyn_gates;
  tNFA_HCI_DYN_PIPE* pp = nfa_hci_cb.cfg.dyn_pipes;

  evt_data.gates_pipes.num_gates = 0;
  evt_data.gates_pipes.num_pipes = 0;

  for (xx = 0; xx < NFA_HCI_MAX_GATE_CB; xx++, pg++) {
    if (pg->gate_owner == p_evt_data->get_gate_pipe_list.hci_handle) {
      evt_data.gates_pipes.gate[evt_data.gates_pipes.num_gates++] = pg->gate_id;

      pp = nfa_hci_cb.cfg.dyn_pipes;

      /* Loop through looking for a match */
      for (yy = 0; yy < NFA_HCI_MAX_PIPE_CB; yy++, pp++) {
        if (pp->local_gate == pg->gate_id)
          evt_data.gates_pipes.pipe[evt_data.gates_pipes.num_pipes++] =
              *(tNFA_HCI_PIPE_INFO*)pp;
      }
    }
  }

  evt_data.gates_pipes.num_uicc_created_pipes = 0;
  /* Loop through all pipes that are connected to connectivity gate */
  for (xx = 0, pp = nfa_hci_cb.cfg.dyn_pipes; xx < NFA_HCI_MAX_PIPE_CB;
       xx++, pp++) {
    if (pp->pipe_id != 0 && pp->local_gate == NFA_HCI_CONNECTIVITY_GATE) {
      memcpy(&evt_data.gates_pipes.uicc_created_pipe
                  [evt_data.gates_pipes.num_uicc_created_pipes++],
             pp, sizeof(tNFA_HCI_PIPE_INFO));
    } else if (pp->pipe_id != 0 && pp->local_gate == NFA_HCI_LOOP_BACK_GATE) {
      memcpy(&evt_data.gates_pipes.uicc_created_pipe
                  [evt_data.gates_pipes.num_uicc_created_pipes++],
             pp, sizeof(tNFA_HCI_PIPE_INFO));
    } else if (pp->pipe_id >= NFA_HCI_FIRST_DYNAMIC_PIPE &&
               pp->pipe_id <= NFA_HCI_LAST_DYNAMIC_PIPE && pp->pipe_id &&
               pp->local_gate >= NFA_HCI_FIRST_PROP_GATE &&
               pp->local_gate <= NFA_HCI_LAST_PROP_GATE) {
      for (yy = 0, pg = nfa_hci_cb.cfg.dyn_gates; yy < NFA_HCI_MAX_GATE_CB;
           yy++, pg++) {
        if (pp->local_gate == pg->gate_id) {
          if (!pg->gate_owner)
            memcpy(&evt_data.gates_pipes.uicc_created_pipe
                        [evt_data.gates_pipes.num_uicc_created_pipes++],
                   pp, sizeof(tNFA_HCI_PIPE_INFO));
          break;
        }
      }
    }
  }

  evt_data.gates_pipes.status = NFA_STATUS_OK;

  /* notify NFA_HCI_GET_GATE_PIPE_LIST_EVT to the application */
  nfa_hciu_send_to_app(NFA_HCI_GET_GATE_PIPE_LIST_EVT, &evt_data,
                       p_evt_data->get_gate_pipe_list.hci_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_api_alloc_gate
**
** Description      action function to allocate gate
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_alloc_gate(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HANDLE app_handle = p_evt_data->comm.hci_handle;
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_DYN_GATE* p_gate;

  p_gate = nfa_hciu_alloc_gate(p_evt_data->gate_info.gate, app_handle);

  if (p_gate) {
    if (!p_gate->gate_owner) {
      /* No app owns the gate yet */
      p_gate->gate_owner = app_handle;
    } else if (p_gate->gate_owner != app_handle) {
      /* Some other app owns the gate */
      p_gate = nullptr;
      LOG(ERROR) << StringPrintf(
          "nfa_hci_api_alloc_gate (): The Gate (0X%02x) already taken!",
          p_evt_data->gate_info.gate);
    }
  }

  evt_data.allocated.gate = p_gate ? p_gate->gate_id : 0;
  evt_data.allocated.status = p_gate ? NFA_STATUS_OK : NFA_STATUS_FAILED;

  /* notify NFA_HCI_ALLOCATE_GATE_EVT to the application */
  nfa_hciu_send_to_app(NFA_HCI_ALLOCATE_GATE_EVT, &evt_data, app_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_api_dealloc_gate
**
** Description      action function to deallocate the given generic gate
**
** Returns          None
**
*******************************************************************************/
void nfa_hci_api_dealloc_gate(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  uint8_t gate_id;
  tNFA_HCI_DYN_GATE* p_gate;
  tNFA_HCI_DYN_PIPE* p_pipe;
  tNFA_HANDLE app_handle;

  /* p_evt_data may be NULL if we are recursively deleting pipes */
  if (p_evt_data) {
    gate_id = p_evt_data->gate_dealloc.gate;
    app_handle = p_evt_data->gate_dealloc.hci_handle;

  } else {
    nfa_sys_stop_timer(&nfa_hci_cb.timer);
    gate_id = nfa_hci_cb.local_gate_in_use;
    app_handle = nfa_hci_cb.app_in_use;
  }

  evt_data.deallocated.gate = gate_id;
  ;

  p_gate = nfa_hciu_find_gate_by_gid(gate_id);

  if (p_gate == nullptr) {
    evt_data.deallocated.status = NFA_STATUS_UNKNOWN_GID;
  } else if (p_gate->gate_owner != app_handle) {
    evt_data.deallocated.status = NFA_STATUS_FAILED;
  } else {
    /* See if any pipe is owned by this app */
    if (nfa_hciu_find_pipe_on_gate(p_gate->gate_id) == nullptr) {
      nfa_hciu_release_gate(p_gate->gate_id);

      nfa_hci_cb.nv_write_needed = true;
      evt_data.deallocated.status = NFA_STATUS_OK;

      if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE)
        nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
    } else if ((p_pipe = nfa_hciu_find_active_pipe_on_gate(p_gate->gate_id)) ==
               nullptr) {
      /* UICC is not active at the moment and cannot delete the pipe */
      nfa_hci_cb.nv_write_needed = true;
      evt_data.deallocated.status = NFA_STATUS_FAILED;

      if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE)
        nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
    } else {
      /* Delete pipes on the gate */
      nfa_hci_cb.local_gate_in_use = gate_id;
      nfa_hci_cb.app_in_use = app_handle;
      nfa_hci_cb.hci_state = NFA_HCI_STATE_REMOVE_GATE;

      nfa_hciu_send_delete_pipe_cmd(p_pipe->pipe_id);
      return;
    }
  }

  nfa_hciu_send_to_app(NFA_HCI_DEALLOCATE_GATE_EVT, &evt_data, app_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_api_get_host_list
**
** Description      action function to get the host list from HCI network
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_get_host_list(tNFA_HCI_EVENT_DATA* p_evt_data) {
  uint8_t app_inx = p_evt_data->get_host_list.hci_handle & NFA_HANDLE_MASK;

  nfa_hci_cb.app_in_use = p_evt_data->get_host_list.hci_handle;

  /* Send Get Host List command on "Internal request" or requested by registered
   * application with valid handle and callback function */
  if ((nfa_hci_cb.app_in_use == NFA_HANDLE_INVALID) ||
      ((app_inx < NFA_HCI_MAX_APP_CB) &&
       (nfa_hci_cb.p_app_cback[app_inx] != nullptr))) {
    nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE, NFA_HCI_HOST_LIST_INDEX);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_create_pipe
**
** Description      action function to create a pipe
**
** Returns          true, if the command is processed
**                  false, if command is queued for processing later
**
*******************************************************************************/
static bool nfa_hci_api_create_pipe(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_DYN_GATE* p_gate =
      nfa_hciu_find_gate_by_gid(p_evt_data->create_pipe.source_gate);
  tNFA_HCI_EVT_DATA evt_data;
  bool report_failed = false;

  /* Verify that the app owns the gate that the pipe is being created on */
  if ((p_gate == nullptr) ||
      (p_gate->gate_owner != p_evt_data->create_pipe.hci_handle)) {
    report_failed = true;
    LOG(ERROR) << StringPrintf(
        "nfa_hci_api_create_pipe Cannot create pipe! APP: 0x%02x does not own "
        "the gate:0x%x",
        p_evt_data->create_pipe.hci_handle,
        p_evt_data->create_pipe.source_gate);
  } else if (nfa_hciu_check_pipe_between_gates(
                 p_evt_data->create_pipe.source_gate,
                 p_evt_data->create_pipe.dest_host,
                 p_evt_data->create_pipe.dest_gate)) {
    report_failed = true;
    LOG(ERROR) << StringPrintf(
        "nfa_hci_api_create_pipe : Cannot create multiple pipe between the "
        "same two gates!");
  }

  if (report_failed) {
    evt_data.created.source_gate = p_evt_data->create_pipe.source_gate;
    evt_data.created.status = NFA_STATUS_FAILED;

    nfa_hciu_send_to_app(NFA_HCI_CREATE_PIPE_EVT, &evt_data,
                         p_evt_data->open_pipe.hci_handle);
  } else {
    if (nfa_hciu_is_host_reseting(p_evt_data->create_pipe.dest_gate)) {
      GKI_enqueue(&nfa_hci_cb.hci_host_reset_api_q, (NFC_HDR*)p_evt_data);
      return false;
    }

    nfa_hci_cb.local_gate_in_use = p_evt_data->create_pipe.source_gate;
    nfa_hci_cb.remote_gate_in_use = p_evt_data->create_pipe.dest_gate;
    nfa_hci_cb.remote_host_in_use = p_evt_data->create_pipe.dest_host;
    nfa_hci_cb.app_in_use = p_evt_data->create_pipe.hci_handle;

    nfa_hciu_send_create_pipe_cmd(p_evt_data->create_pipe.source_gate,
                                  p_evt_data->create_pipe.dest_host,
                                  p_evt_data->create_pipe.dest_gate);
  }
  return true;
}

/*******************************************************************************
**
** Function         nfa_hci_api_open_pipe
**
** Description      action function to open a pipe
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_open_pipe(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_DYN_PIPE* p_pipe =
      nfa_hciu_find_pipe_by_pid(p_evt_data->open_pipe.pipe);
  tNFA_HCI_DYN_GATE* p_gate = nullptr;

  if (p_pipe != nullptr) p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);

  if ((p_pipe != nullptr) && (p_gate != nullptr) &&
      (nfa_hciu_is_active_host(p_pipe->dest_host)) &&
      (p_gate->gate_owner == p_evt_data->open_pipe.hci_handle)) {
    if (p_pipe->pipe_state == NFA_HCI_PIPE_CLOSED) {
      nfa_hciu_send_open_pipe_cmd(p_evt_data->open_pipe.pipe);
    } else {
      evt_data.opened.pipe = p_evt_data->open_pipe.pipe;
      evt_data.opened.status = NFA_STATUS_OK;

      nfa_hciu_send_to_app(NFA_HCI_OPEN_PIPE_EVT, &evt_data,
                           p_evt_data->open_pipe.hci_handle);
    }
  } else {
    evt_data.opened.pipe = p_evt_data->open_pipe.pipe;
    evt_data.opened.status = NFA_STATUS_FAILED;

    nfa_hciu_send_to_app(NFA_HCI_OPEN_PIPE_EVT, &evt_data,
                         p_evt_data->open_pipe.hci_handle);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_get_reg_value
**
** Description      action function to get the reg value of the specified index
**
** Returns          true, if the command is processed
**                  false, if command is queued for processing later
**
*******************************************************************************/
static bool nfa_hci_api_get_reg_value(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_DYN_PIPE* p_pipe =
      nfa_hciu_find_pipe_by_pid(p_evt_data->get_registry.pipe);
  tNFA_HCI_DYN_GATE* p_gate;
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_EVT_DATA evt_data;

  if (p_pipe != nullptr) {
    p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);

    if ((p_gate != nullptr) && (nfa_hciu_is_active_host(p_pipe->dest_host)) &&
        (p_gate->gate_owner == p_evt_data->get_registry.hci_handle)) {
      nfa_hci_cb.app_in_use = p_evt_data->get_registry.hci_handle;

      if (nfa_hciu_is_host_reseting(p_pipe->dest_host)) {
        GKI_enqueue(&nfa_hci_cb.hci_host_reset_api_q, (NFC_HDR*)p_evt_data);
        return false;
      }

      if (p_pipe->pipe_state == NFA_HCI_PIPE_CLOSED) {
        LOG(WARNING) << StringPrintf("nfa_hci_api_get_reg_value pipe:%d not open",
                           p_evt_data->get_registry.pipe);
      } else {
        status = nfa_hciu_send_get_param_cmd(p_evt_data->get_registry.pipe,
                                             p_evt_data->get_registry.reg_inx);
        if (status == NFA_STATUS_OK) return true;
      }
    }
  }

  evt_data.cmd_sent.status = status;

  /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
  nfa_hciu_send_to_app(NFA_HCI_CMD_SENT_EVT, &evt_data,
                       p_evt_data->get_registry.hci_handle);
  return true;
}

/*******************************************************************************
**
** Function         nfa_hci_api_set_reg_value
**
** Description      action function to set the reg value at specified index
**
** Returns          true, if the command is processed
**                  false, if command is queued for processing later
**
*******************************************************************************/
static bool nfa_hci_api_set_reg_value(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_DYN_PIPE* p_pipe =
      nfa_hciu_find_pipe_by_pid(p_evt_data->set_registry.pipe);
  tNFA_HCI_DYN_GATE* p_gate;
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_EVT_DATA evt_data;

  if (p_pipe != nullptr) {
    p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);

    if ((p_gate != nullptr) && (nfa_hciu_is_active_host(p_pipe->dest_host)) &&
        (p_gate->gate_owner == p_evt_data->set_registry.hci_handle)) {
      nfa_hci_cb.app_in_use = p_evt_data->set_registry.hci_handle;

      if (nfa_hciu_is_host_reseting(p_pipe->dest_host)) {
        GKI_enqueue(&nfa_hci_cb.hci_host_reset_api_q, (NFC_HDR*)p_evt_data);
        return false;
      }

      if (p_pipe->pipe_state == NFA_HCI_PIPE_CLOSED) {
        LOG(WARNING) << StringPrintf("nfa_hci_api_set_reg_value pipe:%d not open",
                           p_evt_data->set_registry.pipe);
      } else {
        status = nfa_hciu_send_set_param_cmd(
            p_evt_data->set_registry.pipe, p_evt_data->set_registry.reg_inx,
            p_evt_data->set_registry.size, p_evt_data->set_registry.data);
        if (status == NFA_STATUS_OK) return true;
      }
    }
  }
  evt_data.cmd_sent.status = status;

  /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
  nfa_hciu_send_to_app(NFA_HCI_CMD_SENT_EVT, &evt_data,
                       p_evt_data->set_registry.hci_handle);
  return true;
}

/*******************************************************************************
**
** Function         nfa_hci_api_close_pipe
**
** Description      action function to close a pipe
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_close_pipe(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_DYN_PIPE* p_pipe =
      nfa_hciu_find_pipe_by_pid(p_evt_data->close_pipe.pipe);
  tNFA_HCI_DYN_GATE* p_gate = nullptr;

  if (p_pipe != nullptr) p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);

  if ((p_pipe != nullptr) && (p_gate != nullptr) &&
      (nfa_hciu_is_active_host(p_pipe->dest_host)) &&
      (p_gate->gate_owner == p_evt_data->close_pipe.hci_handle)) {
    if (p_pipe->pipe_state == NFA_HCI_PIPE_OPENED) {
      nfa_hciu_send_close_pipe_cmd(p_evt_data->close_pipe.pipe);
    } else {
      evt_data.closed.status = NFA_STATUS_OK;
      evt_data.closed.pipe = p_evt_data->close_pipe.pipe;

      nfa_hciu_send_to_app(NFA_HCI_CLOSE_PIPE_EVT, &evt_data,
                           p_evt_data->close_pipe.hci_handle);
    }
  } else {
    evt_data.closed.status = NFA_STATUS_FAILED;
    evt_data.closed.pipe = 0x00;

    nfa_hciu_send_to_app(NFA_HCI_CLOSE_PIPE_EVT, &evt_data,
                         p_evt_data->close_pipe.hci_handle);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_delete_pipe
**
** Description      action function to delete a pipe
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_delete_pipe(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_DYN_PIPE* p_pipe =
      nfa_hciu_find_pipe_by_pid(p_evt_data->delete_pipe.pipe);
  tNFA_HCI_DYN_GATE* p_gate = nullptr;

  if (p_pipe != nullptr) {
    p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);
    if ((p_gate != nullptr) &&
        (p_gate->gate_owner == p_evt_data->delete_pipe.hci_handle) &&
        (nfa_hciu_is_active_host(p_pipe->dest_host))) {
      nfa_hciu_send_delete_pipe_cmd(p_evt_data->delete_pipe.pipe);
      return;
    }
  }

  evt_data.deleted.status = NFA_STATUS_FAILED;
  evt_data.deleted.pipe = 0x00;
  nfa_hciu_send_to_app(NFA_HCI_DELETE_PIPE_EVT, &evt_data,
                       p_evt_data->close_pipe.hci_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_api_send_cmd
**
** Description      action function to send command on the given pipe
**
** Returns          true, if the command is processed
**                  false, if command is queued for processing later
**
*******************************************************************************/
static bool nfa_hci_api_send_cmd(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_DYN_PIPE* p_pipe;
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HANDLE app_handle;

  if ((p_pipe = nfa_hciu_find_pipe_by_pid(p_evt_data->send_cmd.pipe)) != nullptr) {
    app_handle = nfa_hciu_get_pipe_owner(p_evt_data->send_cmd.pipe);

    if ((nfa_hciu_is_active_host(p_pipe->dest_host)) &&
        ((app_handle == p_evt_data->send_cmd.hci_handle ||
          p_pipe->local_gate == NFA_HCI_CONNECTIVITY_GATE))) {
      if (nfa_hciu_is_host_reseting(p_pipe->dest_host)) {
        GKI_enqueue(&nfa_hci_cb.hci_host_reset_api_q, (NFC_HDR*)p_evt_data);
        return false;
      }

      if (p_pipe->pipe_state == NFA_HCI_PIPE_OPENED) {
        nfa_hci_cb.pipe_in_use = p_evt_data->send_cmd.pipe;
        status = nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_COMMAND_TYPE,
                                   p_evt_data->send_cmd.cmd_code,
                                   p_evt_data->send_cmd.cmd_len,
                                   p_evt_data->send_cmd.data);
        if (status == NFA_STATUS_OK) return true;
      } else {
        LOG(WARNING) << StringPrintf("nfa_hci_api_send_cmd pipe:%d not open",
                           p_pipe->pipe_id);
      }
    } else {
      LOG(WARNING) << StringPrintf(
          "nfa_hci_api_send_cmd pipe:%d Owned by different application or "
          "Destination host is not active",
          p_pipe->pipe_id);
    }
  } else {
    LOG(WARNING) << StringPrintf("nfa_hci_api_send_cmd pipe:%d not found",
                       p_evt_data->send_cmd.pipe);
  }

  evt_data.cmd_sent.status = status;

  /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
  nfa_hciu_send_to_app(NFA_HCI_CMD_SENT_EVT, &evt_data,
                       p_evt_data->send_cmd.hci_handle);
  return true;
}

/*******************************************************************************
**
** Function         nfa_hci_api_send_rsp
**
** Description      action function to send response on the given pipe
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_send_rsp(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_DYN_PIPE* p_pipe;
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HANDLE app_handle;

  if ((p_pipe = nfa_hciu_find_pipe_by_pid(p_evt_data->send_rsp.pipe)) != nullptr) {
    app_handle = nfa_hciu_get_pipe_owner(p_evt_data->send_rsp.pipe);

    if ((nfa_hciu_is_active_host(p_pipe->dest_host)) &&
        ((app_handle == p_evt_data->send_rsp.hci_handle ||
          p_pipe->local_gate == NFA_HCI_CONNECTIVITY_GATE))) {
      if (p_pipe->pipe_state == NFA_HCI_PIPE_OPENED) {
        status = nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE,
                                   p_evt_data->send_rsp.response,
                                   p_evt_data->send_rsp.size,
                                   p_evt_data->send_rsp.data);
        if (status == NFA_STATUS_OK) return;
      } else {
        LOG(WARNING) << StringPrintf("nfa_hci_api_send_rsp pipe:%d not open",
                           p_pipe->pipe_id);
      }
    } else {
      LOG(WARNING) << StringPrintf(
          "nfa_hci_api_send_rsp pipe:%d Owned by different application or "
          "Destination host is not active",
          p_pipe->pipe_id);
    }
  } else {
    LOG(WARNING) << StringPrintf("nfa_hci_api_send_rsp pipe:%d not found",
                       p_evt_data->send_rsp.pipe);
  }

  evt_data.rsp_sent.status = status;

  /* Send NFA_HCI_RSP_SENT_EVT to notify failure */
  nfa_hciu_send_to_app(NFA_HCI_RSP_SENT_EVT, &evt_data,
                       p_evt_data->send_rsp.hci_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_api_send_event
**
** Description      action function to send an event to the given pipe
**
** Returns          true, if the event is processed
**                  false, if event is queued for processing later
**
*******************************************************************************/
static bool nfa_hci_api_send_event(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_DYN_PIPE* p_pipe;
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HANDLE app_handle;

  if ((p_pipe = nfa_hciu_find_pipe_by_pid(p_evt_data->send_evt.pipe)) != nullptr) {
    app_handle = nfa_hciu_get_pipe_owner(p_evt_data->send_evt.pipe);

    if ((nfa_hciu_is_active_host(p_pipe->dest_host)) &&
        ((app_handle == p_evt_data->send_evt.hci_handle ||
          p_pipe->local_gate == NFA_HCI_CONNECTIVITY_GATE))) {
      if (nfa_hciu_is_host_reseting(p_pipe->dest_host)) {
        GKI_enqueue(&nfa_hci_cb.hci_host_reset_api_q, (NFC_HDR*)p_evt_data);
        return false;
      }

      if (p_pipe->pipe_state == NFA_HCI_PIPE_OPENED) {
        status = nfa_hciu_send_msg(
            p_pipe->pipe_id, NFA_HCI_EVENT_TYPE, p_evt_data->send_evt.evt_code,
            p_evt_data->send_evt.evt_len, p_evt_data->send_evt.p_evt_buf);

        if (status == NFA_STATUS_OK) {
          if (p_pipe->local_gate == NFA_HCI_LOOP_BACK_GATE) {
            nfa_hci_cb.w4_rsp_evt = true;
            nfa_hci_cb.hci_state = NFA_HCI_STATE_WAIT_RSP;
          }

          if (p_evt_data->send_evt.rsp_len) {
            nfa_hci_cb.pipe_in_use = p_evt_data->send_evt.pipe;
            nfa_hci_cb.rsp_buf_size = p_evt_data->send_evt.rsp_len;
            nfa_hci_cb.p_rsp_buf = p_evt_data->send_evt.p_rsp_buf;
            if (p_evt_data->send_evt.rsp_timeout) {
              nfa_hci_cb.w4_rsp_evt = true;
              nfa_hci_cb.hci_state = NFA_HCI_STATE_WAIT_RSP;
#if (NXP_EXTNS == TRUE)
              nfa_hci_cb.hciResponseTimeout = p_evt_data->send_evt.rsp_timeout;
#endif
              nfa_sys_start_timer(&nfa_hci_cb.timer, NFA_HCI_RSP_TIMEOUT_EVT,
                                  p_evt_data->send_evt.rsp_timeout);
            } else if (p_pipe->local_gate == NFA_HCI_LOOP_BACK_GATE) {
              nfa_sys_start_timer(&nfa_hci_cb.timer, NFA_HCI_RSP_TIMEOUT_EVT,
                                  p_nfa_hci_cfg->hcp_response_timeout);
            }
          } else {
            if (p_pipe->local_gate == NFA_HCI_LOOP_BACK_GATE) {
              nfa_hci_cb.pipe_in_use = p_evt_data->send_evt.pipe;
              nfa_sys_start_timer(&nfa_hci_cb.timer, NFA_HCI_RSP_TIMEOUT_EVT,
                                  p_nfa_hci_cfg->hcp_response_timeout);
            }
            nfa_hci_cb.rsp_buf_size = 0;
            nfa_hci_cb.p_rsp_buf = nullptr;
          }
        }
      } else {
        LOG(WARNING) << StringPrintf("nfa_hci_api_send_event pipe:%d not open",
                           p_pipe->pipe_id);
      }
    } else {
      LOG(WARNING) << StringPrintf(
          "nfa_hci_api_send_event pipe:%d Owned by different application or "
          "Destination host is not active",
          p_pipe->pipe_id);
    }
  } else {
    LOG(WARNING) << StringPrintf("nfa_hci_api_send_event pipe:%d not found",
                       p_evt_data->send_evt.pipe);
  }

  evt_data.evt_sent.status = status;

  /* Send NFC_HCI_EVENT_SENT_EVT to notify status */
  nfa_hciu_send_to_app(NFA_HCI_EVENT_SENT_EVT, &evt_data,
                       p_evt_data->send_evt.hci_handle);
  return true;
}

/*******************************************************************************
**
** Function         nfa_hci_api_add_static_pipe
**
** Description      action function to add static pipe
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_add_static_pipe(tNFA_HCI_EVENT_DATA* p_evt_data) {
  tNFA_HCI_DYN_GATE* pg;
  tNFA_HCI_DYN_PIPE* pp;
  tNFA_HCI_EVT_DATA evt_data;

  /* Allocate a proprietary gate */
  pg = nfa_hciu_alloc_gate(p_evt_data->add_static_pipe.gate,
                           p_evt_data->add_static_pipe.hci_handle);
  if (pg != nullptr) {
    /* Assign new owner to the gate */
    pg->gate_owner = p_evt_data->add_static_pipe.hci_handle;

    /* Add the dynamic pipe to the proprietary gate */
    if (nfa_hciu_add_pipe_to_gate(p_evt_data->add_static_pipe.pipe, pg->gate_id,
                                  p_evt_data->add_static_pipe.host,
                                  p_evt_data->add_static_pipe.gate) !=
        NFA_HCI_ANY_OK) {
      /* Unable to add the dynamic pipe, so release the gate */
      nfa_hciu_release_gate(pg->gate_id);
      evt_data.pipe_added.status = NFA_STATUS_FAILED;
      nfa_hciu_send_to_app(NFA_HCI_ADD_STATIC_PIPE_EVT, &evt_data,
                           p_evt_data->add_static_pipe.hci_handle);
      return;
    }
    pp = nfa_hciu_find_pipe_by_pid(p_evt_data->add_static_pipe.pipe);
    if (pp != nullptr) {
      /* This pipe is always opened */
      pp->pipe_state = NFA_HCI_PIPE_OPENED;
      evt_data.pipe_added.status = NFA_STATUS_OK;
      nfa_hciu_send_to_app(NFA_HCI_ADD_STATIC_PIPE_EVT, &evt_data,
                           p_evt_data->add_static_pipe.hci_handle);
      return;
    }
  }
  /* Unable to add static pipe */
  evt_data.pipe_added.status = NFA_STATUS_FAILED;
  nfa_hciu_send_to_app(NFA_HCI_ADD_STATIC_PIPE_EVT, &evt_data,
                       p_evt_data->add_static_pipe.hci_handle);
}

/*******************************************************************************
**
** Function         nfa_hci_handle_link_mgm_gate_cmd
**
** Description      This function handles incoming link management gate hci
**                  commands
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_link_mgm_gate_cmd(uint8_t* p_data) {
  uint8_t index;
  uint8_t data[2];
  uint8_t rsp_len = 0;
  uint8_t response = NFA_HCI_ANY_OK;

  if ((nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state != NFA_HCI_PIPE_OPENED) &&
      (nfa_hci_cb.inst != NFA_HCI_ANY_OPEN_PIPE)) {
    nfa_hciu_send_msg(NFA_HCI_LINK_MANAGEMENT_PIPE, NFA_HCI_RESPONSE_TYPE,
                      NFA_HCI_ANY_E_PIPE_NOT_OPENED, 0, nullptr);
    return;
  }

  switch (nfa_hci_cb.inst) {
    case NFA_HCI_ANY_SET_PARAMETER:
      STREAM_TO_UINT8(index, p_data);

      if (index == 1) {
        STREAM_TO_UINT16(nfa_hci_cb.cfg.link_mgmt_gate.rec_errors, p_data);
      } else
        response = NFA_HCI_ANY_E_REG_PAR_UNKNOWN;
      break;

    case NFA_HCI_ANY_GET_PARAMETER:
      STREAM_TO_UINT8(index, p_data);
      if (index == 1) {
        data[0] =
            (uint8_t)((nfa_hci_cb.cfg.link_mgmt_gate.rec_errors >> 8) & 0x00FF);
        data[1] = (uint8_t)(nfa_hci_cb.cfg.link_mgmt_gate.rec_errors & 0x000F);
        rsp_len = 2;
      } else
        response = NFA_HCI_ANY_E_REG_PAR_UNKNOWN;
      break;

    case NFA_HCI_ANY_OPEN_PIPE:
      data[0] = 0;
      rsp_len = 1;
      nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state = NFA_HCI_PIPE_OPENED;
      break;

    case NFA_HCI_ANY_CLOSE_PIPE:
      nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state = NFA_HCI_PIPE_CLOSED;
      break;

    default:
      response = NFA_HCI_ANY_E_CMD_NOT_SUPPORTED;
      break;
  }

  nfa_hciu_send_msg(NFA_HCI_LINK_MANAGEMENT_PIPE, NFA_HCI_RESPONSE_TYPE,
                    response, rsp_len, data);
}

/*******************************************************************************
**
** Function         nfa_hci_handle_pipe_open_close_cmd
**
** Description      This function handles all generic gates (excluding
**                  connectivity gate) commands
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_pipe_open_close_cmd(tNFA_HCI_DYN_PIPE* p_pipe) {
  uint8_t data[1];
  uint8_t rsp_len = 0;
  tNFA_HCI_RESPONSE response = NFA_HCI_ANY_OK;
  tNFA_HCI_DYN_GATE* p_gate;

  if (nfa_hci_cb.inst == NFA_HCI_ANY_OPEN_PIPE) {
    if ((p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate)) != nullptr)
      data[0] = nfa_hciu_count_open_pipes_on_gate(p_gate);
    else
      data[0] = 0;

    p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
    rsp_len = 1;
  } else if (nfa_hci_cb.inst == NFA_HCI_ANY_CLOSE_PIPE) {
    p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;
  }
#if (NXP_EXTNS == TRUE)
  nfa_hci_cb.nv_write_needed = true;
#endif
  nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE, response, rsp_len,
                    data);
}

/*******************************************************************************
**
** Function         nfa_hci_handle_admin_gate_cmd
**
** Description      This function handles incoming commands on ADMIN gate
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_admin_gate_cmd(uint8_t* p_data) {
  uint8_t source_host, source_gate, dest_host, dest_gate, pipe;
  uint8_t data = 0;
  uint8_t rsp_len = 0;
  tNFA_HCI_RESPONSE response = NFA_HCI_ANY_OK;
  tNFA_HCI_DYN_GATE* pgate;
  tNFA_HCI_EVT_DATA evt_data;

  switch (nfa_hci_cb.inst) {
    case NFA_HCI_ANY_OPEN_PIPE:
      nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_OPENED;
      data = 0;
      rsp_len = 1;
      break;

    case NFA_HCI_ANY_CLOSE_PIPE:
      nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_CLOSED;
      /* Reopen the pipe immediately */
      nfa_hciu_send_msg(NFA_HCI_ADMIN_PIPE, NFA_HCI_RESPONSE_TYPE, response,
                        rsp_len, &data);
      nfa_hci_cb.app_in_use = NFA_HANDLE_INVALID;
      nfa_hciu_send_open_pipe_cmd(NFA_HCI_ADMIN_PIPE);
      return;
      break;

    case NFA_HCI_ADM_NOTIFY_PIPE_CREATED:
      STREAM_TO_UINT8(source_host, p_data);
      STREAM_TO_UINT8(source_gate, p_data);
      STREAM_TO_UINT8(dest_host, p_data);
      STREAM_TO_UINT8(dest_gate, p_data);
      STREAM_TO_UINT8(pipe, p_data);

      if ((dest_gate == NFA_HCI_IDENTITY_MANAGEMENT_GATE) ||
          (dest_gate == NFA_HCI_LOOP_BACK_GATE)
#if (NXP_EXTNS == TRUE)
          || ((nfcFL.nfccFL._GEMALTO_SE_SUPPORT) && ((dest_gate == NFC_HCI_DEFAULT_DEST_GATE) ||
          (dest_gate == NFA_HCI_CONNECTIVITY_GATE)))
#endif
              )
#if (NXP_EXTNS == TRUE)
          if(nfcFL.eseFL._BLOCK_PROPRIETARY_APDU_GATE) {
              if (dest_gate == NFC_HCI_DEFAULT_DEST_GATE) {
                  response = NFA_HCI_ANY_E_NOK;
              } else {
                  response = nfa_hciu_add_pipe_to_static_gate(dest_gate, pipe,
                          source_host, source_gate);
              }
          }
          else{
              response = nfa_hciu_add_pipe_to_static_gate(dest_gate, pipe,
                      source_host, source_gate);
          }
#else
    response = nfa_hciu_add_pipe_to_static_gate(dest_gate, pipe,
            source_host, source_gate);
#endif
      else {
        if ((pgate = nfa_hciu_find_gate_by_gid(dest_gate)) != nullptr) {
          /* If the gate is valid, add the pipe to it  */
          if (nfa_hciu_check_pipe_between_gates(dest_gate, source_host,
                                                source_gate)) {
            /* Already, there is a pipe between these two gates, so will reject
             */
            response = NFA_HCI_ANY_E_NOK;
          } else {
            response = nfa_hciu_add_pipe_to_gate(pipe, dest_gate, source_host,
                                                 source_gate);
            if (response == NFA_HCI_ANY_OK) {
              /* Tell the application a pipe was created with its gate */

              evt_data.created.status = NFA_STATUS_OK;
              evt_data.created.pipe = pipe;
              evt_data.created.source_gate = dest_gate;
              evt_data.created.dest_host = source_host;
              evt_data.created.dest_gate = source_gate;

              nfa_hciu_send_to_app(NFA_HCI_CREATE_PIPE_EVT, &evt_data,
                                   pgate->gate_owner);
            }
          }
        } else {
          response = NFA_HCI_ANY_E_NOK;
          if ((dest_gate >= NFA_HCI_FIRST_PROP_GATE) &&
              (dest_gate <= NFA_HCI_LAST_PROP_GATE)) {
            if (nfa_hciu_alloc_gate(dest_gate, 0))
              response = nfa_hciu_add_pipe_to_gate(pipe, dest_gate, source_host,
                                                   source_gate);
          }
        }
      }
      break;

    case NFA_HCI_ADM_NOTIFY_PIPE_DELETED:
      STREAM_TO_UINT8(pipe, p_data);
      response = nfa_hciu_release_pipe(pipe);
      break;

    case NFA_HCI_ADM_NOTIFY_ALL_PIPE_CLEARED:
      STREAM_TO_UINT8(source_host, p_data);

      nfa_hciu_remove_all_pipes_from_host(source_host);

      if (source_host == NFA_HCI_HOST_CONTROLLER) {
        nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state = NFA_HCI_PIPE_CLOSED;
        nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_CLOSED;

        /* Reopen the admin pipe immediately */
        nfa_hci_cb.app_in_use = NFA_HANDLE_INVALID;
        nfa_hciu_send_open_pipe_cmd(NFA_HCI_ADMIN_PIPE);
        return;
      } else {
        uint8_t host_index = 0;
        if ((source_host == NFA_HCI_HOST_ID_UICC0) ||
            (source_host >= NFA_HCI_HOST_ID_FIRST_DYNAMICALLY_ALLOCATED)) {
          while (host_index < NFA_HCI_MAX_HOST_IN_NETWORK) {
            if (nfa_hci_cb.reset_host[host_index] == 0x0) {
              nfa_hci_cb.reset_host[host_index] = source_host;
              break;
            }
            host_index++;
          }
        }
#if (NXP_EXTNS == TRUE)
        nfc_cb.bBlockWiredMode = FALSE;
        nfc_cb.bBlkPwrlinkAndModeSetCmd = FALSE;
        nfa_hci_cb.bClearAllPipeHandling = true;

        nfa_hciu_send_msg(NFA_HCI_ADMIN_PIPE, NFA_HCI_RESPONSE_TYPE, response,
                          rsp_len, &data);
        nfa_hciu_set_nfceeid_config_mask(NFA_HCI_CLEAR_CONFIG_EVENT,
                                         source_host);
        nfa_hciu_set_nfceeid_poll_mask(NFA_HCI_CLEAR_CONFIG_EVENT, source_host);
        if (nfa_hci_cb.nfcee_cfg.nfc_init_state == false)
          nfa_hci_handle_nfcee_config_evt(NFA_HCI_ADM_NOTIFY_ALL_PIPE_CLEARED);
        return;
#endif
      }
      break;

    default:
      response = NFA_HCI_ANY_E_CMD_NOT_SUPPORTED;
      break;
  }

  nfa_hciu_send_msg(NFA_HCI_ADMIN_PIPE, NFA_HCI_RESPONSE_TYPE, response,
                    rsp_len, &data);
}

/*******************************************************************************
**
** Function         nfa_hci_handle_admin_gate_rsp
**
** Description      This function handles response received on admin gate
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_admin_gate_rsp(uint8_t* p_data, uint8_t data_len) {
  uint8_t source_host;
  uint8_t source_gate = nfa_hci_cb.local_gate_in_use;
  uint8_t dest_host = nfa_hci_cb.remote_host_in_use;
  uint8_t dest_gate = nfa_hci_cb.remote_gate_in_use;
  uint8_t pipe = 0;
  tNFA_STATUS status;
  tNFA_HCI_EVT_DATA evt_data;
  uint8_t default_session[NFA_HCI_SESSION_ID_LEN] = {0xFF, 0xFF, 0xFF, 0xFF,
                                                     0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t host_count = 0;
  uint8_t host_id = 0;
  uint32_t os_tick;
#if (NXP_EXTNS == TRUE)
  // Terminal Host Type as ETSI12  Byte1 -Host Id Byte2 - 00
  uint8_t terminal_host_type[NFA_HCI_HOST_TYPE_LEN] = {0x01, 0x00};
#endif

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "nfa_hci_handle_admin_gate_rsp - LastCmdSent: %s  App: 0x%04x  Gate: "
      "0x%02x  Pipe: 0x%02x",
      nfa_hciu_instr_2_str(nfa_hci_cb.cmd_sent).c_str(), nfa_hci_cb.app_in_use,
      nfa_hci_cb.local_gate_in_use, nfa_hci_cb.pipe_in_use);

  /* If starting up, handle events here */
  if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_STARTUP) ||
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE) ||
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_WAIT_NETWK_ENABLE) ||
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE_NETWK_ENABLE)) {
    if (nfa_hci_cb.inst == NFA_HCI_ANY_E_PIPE_NOT_OPENED) {
      nfa_hciu_send_open_pipe_cmd(NFA_HCI_ADMIN_PIPE);
      return;
    }

    if (nfa_hci_cb.inst != NFA_HCI_ANY_OK) {
#if (NXP_EXTNS == TRUE)
      if (nfa_hci_cb.param_in_use == NFA_HCI_HOST_TYPE_INDEX) {
        if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_GET_PARAMETER) {
           DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
              "nfa_hci_handle_admin_gate_rsp - HCI Controller is ETSI 9 !!!");
          // Set a variable to set ETSI version of HCI Controller
          nfa_hci_cb.host_controller_version = NFA_HCI_CONTROLLER_VERSION_9;
        }
      } else {
        LOG(ERROR) << StringPrintf(
            "nfa_hci_handle_admin_gate_rsp - Initialization failed");
        nfa_hci_startup_complete(NFA_STATUS_FAILED);
        return;
      }
#else
      LOG(ERROR) << StringPrintf("nfa_hci_handle_admin_gate_rsp - Initialization failed");
      nfa_hci_startup_complete(NFA_STATUS_FAILED);
      return;
#endif
    }

    switch (nfa_hci_cb.cmd_sent) {
      case NFA_HCI_ANY_SET_PARAMETER:
#if (NXP_EXTNS != TRUE)
        if (nfa_hci_cb.param_in_use == NFA_HCI_SESSION_IDENTITY_INDEX) {
          /* Set WHITELIST */
          nfa_hciu_send_set_param_cmd(
              NFA_HCI_ADMIN_PIPE, NFA_HCI_WHITELIST_INDEX,
              p_nfa_hci_cfg->num_whitelist_host, p_nfa_hci_cfg->p_whitelist);
        } else if (nfa_hci_cb.param_in_use == NFA_HCI_WHITELIST_INDEX) {
          if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_STARTUP) ||
              (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE))
            nfa_hci_dh_startup_complete();
        }
#else
        if (nfa_hci_cb.param_in_use == NFA_HCI_WHITELIST_INDEX) {
           DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
              "nfa_hci_handle_admin_gate_rsp - Set the HOST_TYPE as per ETSI "
              "12 !!!");
          /* Set the HOST_TYPE as per ETSI 12 */
          nfa_hciu_send_set_param_cmd(
              NFA_HCI_ADMIN_PIPE, NFA_HCI_HOST_TYPE_INDEX,
              NFA_HCI_HOST_TYPE_LEN, terminal_host_type);
          return;
        }

        if (nfa_hci_cb.param_in_use == NFA_HCI_HOST_TYPE_INDEX) {
          if (nfa_hci_cb.inst == NFA_HCI_ANY_OK) {
             DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
                "nfa_hci_handle_admin_gate_rsp - HCI Controller is ETSI 12 "
                "!!!");
            // Set a variable  to set ETSI version of HCI Controller
            nfa_hci_cb.host_controller_version = NFA_HCI_CONTROLLER_VERSION_12;
          }
          if (nfa_hci_cb.b_hci_netwk_reset) {
            nfa_hci_cb.b_hci_netwk_reset = false;
            /* Session ID is reset, Set New session id */
            memcpy(&nfa_hci_cb.cfg.admin_gate
                        .session_id[NFA_HCI_SESSION_ID_LEN / 2],
                   nfa_hci_cb.cfg.admin_gate.session_id,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            os_tick = GKI_get_os_tick_count();
            memcpy(nfa_hci_cb.cfg.admin_gate.session_id, (uint8_t*)&os_tick,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            nfa_hciu_send_set_param_cmd(
                NFA_HCI_ADMIN_PIPE, NFA_HCI_SESSION_IDENTITY_INDEX,
                NFA_HCI_SESSION_ID_LEN,
                (uint8_t*)nfa_hci_cb.cfg.admin_gate.session_id);
          } else {
            /* First thing is to get the session ID */
            nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE,
                                        NFA_HCI_SESSION_IDENTITY_INDEX);
          }
        } else if (nfa_hci_cb.param_in_use == NFA_HCI_SESSION_IDENTITY_INDEX) {
            nfa_hci_network_enable();
          if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_STARTUP) ||
              (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE))
          {
            if(NFA_GetNCIVersion() == NCI_VERSION_2_0)
            {
                NFA_EeGetInfo(&nfa_hci_cb.num_nfcee, nfa_hci_cb.ee_info);
                nfa_hci_cb.hci_state = NFA_HCI_STATE_WAIT_NETWK_ENABLE;
                nfa_hci_cb.w4_nfcee_enable = true;
                nfa_hci_enable_one_nfcee();
            }
            else
            {
                nfa_hci_dh_startup_complete();
            }
          }
        }
#endif
        break;

      case NFA_HCI_ANY_GET_PARAMETER:
        if (nfa_hci_cb.param_in_use == NFA_HCI_HOST_LIST_INDEX) {
          uint8_t host_index = 0;

          memset(nfa_hci_cb.active_host, 0x0, NFA_HCI_MAX_HOST_IN_NETWORK);

          host_count = 0;

          /* Collect active host in the Host Network */
          while ((host_count < data_len) &&
                 (host_count < NFA_HCI_MAX_HOST_IN_NETWORK)) {
            host_id = (uint8_t)*p_data++;
            if ((host_id == NFA_HCI_HOST_ID_UICC0) ||
                (host_id >= NFA_HCI_HOST_ID_FIRST_DYNAMICALLY_ALLOCATED)) {
              nfa_hci_cb.active_host[host_index] = host_id;
              uint8_t index = 0;
              while (index < NFA_HCI_MAX_HOST_IN_NETWORK) {
                if (nfa_hci_cb.reset_host[index] == host_id) {
                  nfa_hci_cb.reset_host[index] = 0x0;
                  break;
                }
                index++;
              }
              host_index++;
            }
            host_count++;
          }
            nfa_hci_startup_complete(NFA_STATUS_OK);
        } else if (nfa_hci_cb.param_in_use == NFA_HCI_SESSION_IDENTITY_INDEX) {
          /* The only parameter we get when initializing is the session ID.
           * Check for match. */
          if (data_len >= NFA_HCI_SESSION_ID_LEN &&
              !memcmp((uint8_t*)nfa_hci_cb.cfg.admin_gate.session_id, p_data,
                      NFA_HCI_SESSION_ID_LEN)) {
#if (NXP_EXTNS == TRUE)
            nfa_hci_network_enable();
            NFA_EeGetInfo(&nfa_hci_cb.num_nfcee, nfa_hci_cb.ee_info);
            if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_STARTUP) ||
                (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE))
            {
              if(NFA_GetNCIVersion() == NCI_VERSION_2_0)
              {
                  nfa_hci_cb.hci_state = NFA_HCI_STATE_WAIT_NETWK_ENABLE;
                  nfa_hci_cb.w4_nfcee_enable = true;
                  nfa_hci_enable_one_nfcee();
              }
              else
              {
                  nfa_hci_dh_startup_complete();
              }
            }
#else
            /* Session has not changed, Set WHITELIST */
            nfa_hciu_send_set_param_cmd(
                NFA_HCI_ADMIN_PIPE, NFA_HCI_WHITELIST_INDEX,
                p_nfa_hci_cfg->num_whitelist_host, p_nfa_hci_cfg->p_whitelist);
#endif
          } else {
#if (NXP_EXTNS == TRUE)
            /* Session ID is reset, Set New session id */
            memcpy(&nfa_hci_cb.cfg.admin_gate
                        .session_id[NFA_HCI_SESSION_ID_LEN / 2],
                   nfa_hci_cb.cfg.admin_gate.session_id,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            os_tick = GKI_get_os_tick_count();
            memcpy(nfa_hci_cb.cfg.admin_gate.session_id, (uint8_t*)&os_tick,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            nfa_hciu_send_set_param_cmd(
                NFA_HCI_ADMIN_PIPE, NFA_HCI_SESSION_IDENTITY_INDEX,
                NFA_HCI_SESSION_ID_LEN,
                (uint8_t*)nfa_hci_cb.cfg.admin_gate.session_id);
#else
            /* Something wrong, NVRAM data could be corrupt or first start with
             * default session id */
            nfa_hciu_send_clear_all_pipe_cmd();
            nfa_hci_cb.b_hci_new_sessionId = true;
            if (data_len < NFA_HCI_SESSION_ID_LEN) {
              android_errorWriteLog(0x534e4554, "124524315");
            }
#endif
          }
        }
        break;
      case NFA_HCI_ANY_OPEN_PIPE:
        nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_OPENED;

#if (NXP_EXTNS != TRUE)
        if (nfa_hci_cb.b_hci_netwk_reset) {
          /* Something wrong, NVRAM data could be corrupt or first start with
           * default session id */
          nfa_hciu_send_clear_all_pipe_cmd();
          nfa_hci_cb.b_hci_netwk_reset = false;
          nfa_hci_cb.b_hci_new_sessionId = true;
        } else if (nfa_hci_cb.b_hci_new_sessionId) {
          nfa_hci_cb.b_hci_new_sessionId = false;

          /* Session ID is reset, Set New session id */
          memcpy(
              &nfa_hci_cb.cfg.admin_gate.session_id[NFA_HCI_SESSION_ID_LEN / 2],
              nfa_hci_cb.cfg.admin_gate.session_id,
              (NFA_HCI_SESSION_ID_LEN / 2));
          os_tick = GKI_get_os_tick_count();
          memcpy(nfa_hci_cb.cfg.admin_gate.session_id, (uint8_t*)&os_tick,
                 (NFA_HCI_SESSION_ID_LEN / 2));
          nfa_hciu_send_set_param_cmd(
              NFA_HCI_ADMIN_PIPE, NFA_HCI_SESSION_IDENTITY_INDEX,
              NFA_HCI_SESSION_ID_LEN,
              (uint8_t*)nfa_hci_cb.cfg.admin_gate.session_id);
        } else {
          /* First thing is to get the session ID */
          nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE,
                                      NFA_HCI_SESSION_IDENTITY_INDEX);
        }
#else
        nfa_hciu_send_set_param_cmd(NFA_HCI_ADMIN_PIPE, NFA_HCI_WHITELIST_INDEX,
                                    p_nfa_hci_cfg->num_whitelist_host,
                                    p_nfa_hci_cfg->p_whitelist);
#endif
        break;

      case NFA_HCI_ADM_CLEAR_ALL_PIPE:
        nfa_hciu_remove_all_pipes_from_host(0);
        nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_CLOSED;
        nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state = NFA_HCI_PIPE_CLOSED;
        nfa_hci_cb.nv_write_needed = true;

        /* Open admin */
        nfa_hciu_send_open_pipe_cmd(NFA_HCI_ADMIN_PIPE);
        break;
    }
  }
#if (NXP_EXTNS == TRUE)
  else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_NFCEE_ENABLE) {
    nfa_hci_handle_Nfcee_admpipe_rsp(p_data, data_len);
  }
#endif
  else {
    status =
        (nfa_hci_cb.inst == NFA_HCI_ANY_OK) ? NFA_STATUS_OK : NFA_STATUS_FAILED;

    switch (nfa_hci_cb.cmd_sent) {
      case NFA_HCI_ANY_SET_PARAMETER:
        if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER)
          nfa_hci_api_deregister(nullptr);
        else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE)
          nfa_hci_api_dealloc_gate(nullptr);
        break;

      case NFA_HCI_ANY_GET_PARAMETER:
        if (nfa_hci_cb.param_in_use == NFA_HCI_SESSION_IDENTITY_INDEX) {
          if (data_len >= NFA_HCI_SESSION_ID_LEN &&
              !memcmp((uint8_t*)default_session, p_data,
                      NFA_HCI_SESSION_ID_LEN)) {
            memcpy(&nfa_hci_cb.cfg.admin_gate
                        .session_id[(NFA_HCI_SESSION_ID_LEN / 2)],
                   nfa_hci_cb.cfg.admin_gate.session_id,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            os_tick = GKI_get_os_tick_count();
            memcpy(nfa_hci_cb.cfg.admin_gate.session_id, (uint8_t*)&os_tick,
                   (NFA_HCI_SESSION_ID_LEN / 2));
            nfa_hci_cb.nv_write_needed = true;
            nfa_hciu_send_set_param_cmd(
                NFA_HCI_ADMIN_PIPE, NFA_HCI_SESSION_IDENTITY_INDEX,
                NFA_HCI_SESSION_ID_LEN,
                (uint8_t*)nfa_hci_cb.cfg.admin_gate.session_id);
          } else {
            if (data_len < NFA_HCI_SESSION_ID_LEN) {
              android_errorWriteLog(0x534e4554, "124524315");
            }
            if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER)
              nfa_hci_api_deregister(nullptr);
            else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE)
              nfa_hci_api_dealloc_gate(nullptr);
          }
        } else if (nfa_hci_cb.param_in_use == NFA_HCI_HOST_LIST_INDEX) {
          evt_data.hosts.status = status;
          if (data_len > NFA_HCI_MAX_HOST_IN_NETWORK) {
            data_len = NFA_HCI_MAX_HOST_IN_NETWORK;
            android_errorWriteLog(0x534e4554, "124524315");
          }
          evt_data.hosts.num_hosts = data_len;
          memcpy(evt_data.hosts.host, p_data, data_len);

          uint8_t host_index = 0;

          memset(nfa_hci_cb.active_host, 0x0, NFA_HCI_MAX_HOST_IN_NETWORK);

          host_count = 0;
          /* Collect active host in the Host Network */
          while ((host_count < data_len) &&
                 (host_count < NFA_HCI_MAX_HOST_IN_NETWORK)) {
            host_id = (uint8_t)*p_data++;
            if ((host_id == NFA_HCI_HOST_ID_UICC0) ||
                (host_id >= NFA_HCI_HOST_ID_FIRST_DYNAMICALLY_ALLOCATED)) {
              nfa_hci_cb.active_host[host_index] = host_id;
              uint8_t index = 0;
              while (index < NFA_HCI_MAX_HOST_IN_NETWORK) {
                if (nfa_hci_cb.reset_host[index] == host_id) {
                  nfa_hci_cb.reset_host[index] = 0x0;
                  break;
                }
                index++;
              }
              host_index++;
            }
            host_count++;
          }

          if (nfa_hciu_is_no_host_resetting())
            nfa_hci_check_pending_api_requests();
          nfa_hciu_send_to_app(NFA_HCI_HOST_LIST_EVT, &evt_data,
                               nfa_hci_cb.app_in_use);
        }
        break;

      case NFA_HCI_ADM_CREATE_PIPE:
        // p_data should have at least 5 bytes length for pipe info
        if (data_len >= 5 && status == NFA_STATUS_OK) {
          STREAM_TO_UINT8(source_host, p_data);
          STREAM_TO_UINT8(source_gate, p_data);
          STREAM_TO_UINT8(dest_host, p_data);
          STREAM_TO_UINT8(dest_gate, p_data);
          STREAM_TO_UINT8(pipe, p_data);
          /* Sanity check */
          if (source_gate != nfa_hci_cb.local_gate_in_use) {
            LOG(WARNING) << StringPrintf(
                "nfa_hci_handle_admin_gate_rsp sent create pipe with gate: %u "
                "got back: %u",
                nfa_hci_cb.local_gate_in_use, source_gate);
            break;
          }
          nfa_hciu_add_pipe_to_gate(pipe, source_gate, dest_host, dest_gate);
        } else if (data_len < 5 && status == NFA_STATUS_OK) {
          android_errorWriteLog(0x534e4554, "124524315");
          status = NFA_STATUS_FAILED;
        }
        /* Tell the application his pipe was created or not */
        evt_data.created.status = status;
        evt_data.created.pipe = pipe;
        evt_data.created.source_gate = source_gate;
        evt_data.created.dest_host = dest_host;
        evt_data.created.dest_gate = dest_gate;

        nfa_hciu_send_to_app(NFA_HCI_CREATE_PIPE_EVT, &evt_data,
                             nfa_hci_cb.app_in_use);
        break;

      case NFA_HCI_ADM_DELETE_PIPE:
        if (status == NFA_STATUS_OK) {
          nfa_hciu_release_pipe(nfa_hci_cb.pipe_in_use);

          /* If only deleting one pipe, tell the app we are done */
          if (nfa_hci_cb.hci_state == NFA_HCI_STATE_IDLE) {
            evt_data.deleted.status = status;
            evt_data.deleted.pipe = nfa_hci_cb.pipe_in_use;

            nfa_hciu_send_to_app(NFA_HCI_DELETE_PIPE_EVT, &evt_data,
                                 nfa_hci_cb.app_in_use);
          } else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER)
            nfa_hci_api_deregister(nullptr);
          else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE)
            nfa_hci_api_dealloc_gate(nullptr);
        } else {
          /* If only deleting one pipe, tell the app we are done */
          if (nfa_hci_cb.hci_state == NFA_HCI_STATE_IDLE) {
            evt_data.deleted.status = status;
            evt_data.deleted.pipe = nfa_hci_cb.pipe_in_use;

            nfa_hciu_send_to_app(NFA_HCI_DELETE_PIPE_EVT, &evt_data,
                                 nfa_hci_cb.app_in_use);
          } else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_APP_DEREGISTER) {
            nfa_hciu_release_pipe(nfa_hci_cb.pipe_in_use);
            nfa_hci_api_deregister(nullptr);
          } else if (nfa_hci_cb.hci_state == NFA_HCI_STATE_REMOVE_GATE) {
            nfa_hciu_release_pipe(nfa_hci_cb.pipe_in_use);
            nfa_hci_api_dealloc_gate(nullptr);
          }
        }
        break;

      case NFA_HCI_ANY_OPEN_PIPE:
        nfa_hci_cb.cfg.admin_gate.pipe01_state =
            status ? NFA_HCI_PIPE_CLOSED : NFA_HCI_PIPE_OPENED;
        nfa_hci_cb.nv_write_needed = true;
        if (nfa_hci_cb.cfg.admin_gate.pipe01_state == NFA_HCI_PIPE_OPENED) {
          /* First thing is to get the session ID */
          nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE,
                                      NFA_HCI_SESSION_IDENTITY_INDEX);
        }
        break;

      case NFA_HCI_ADM_CLEAR_ALL_PIPE:
        nfa_hciu_remove_all_pipes_from_host(0);
        nfa_hci_cb.cfg.admin_gate.pipe01_state = NFA_HCI_PIPE_CLOSED;
        nfa_hci_cb.cfg.link_mgmt_gate.pipe00_state = NFA_HCI_PIPE_CLOSED;
        nfa_hci_cb.nv_write_needed = true;
        /* Open admin */
        nfa_hciu_send_open_pipe_cmd(NFA_HCI_ADMIN_PIPE);
        break;
    }
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_admin_gate_evt
**
** Description      This function handles events received on admin gate
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_admin_gate_evt() {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HCI_API_GET_HOST_LIST* p_msg;
  if (nfa_hci_cb.inst != NFA_HCI_EVT_HOT_PLUG) {
    LOG(ERROR) << StringPrintf(
        "nfa_hci_handle_admin_gate_evt - Unknown event on ADMIN Pipe");
    return;
  }

   DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "nfa_hci_handle_admin_gate_evt - HOT PLUG EVT event on ADMIN Pipe");
  nfa_hci_cb.num_hot_plug_evts++;

  if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_WAIT_NETWK_ENABLE) ||
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE_NETWK_ENABLE)) {
    /* Received Hot Plug evt while waiting for other Host in the network to
     * bootup after DH host bootup is complete */
    if ((nfa_hci_cb.ee_disable_disc) &&
        (nfa_hci_cb.num_hot_plug_evts == (nfa_hci_cb.num_nfcee - 1)) &&
        (nfa_hci_cb.num_ee_dis_req_ntf < (nfa_hci_cb.num_nfcee - 1))) {
      /* Received expected number of Hot Plug event(s) before as many number of
       * EE DISC REQ Ntf(s) are received */
      nfa_sys_stop_timer(&nfa_hci_cb.timer);
      /* Received HOT PLUG EVT(s), now wait some more time for EE DISC REQ
       * Ntf(s) */
      nfa_sys_start_timer(&nfa_hci_cb.timer, NFA_HCI_RSP_TIMEOUT_EVT,
                          p_nfa_hci_cfg->hci_netwk_enable_timeout);
    }
  } else if ((nfa_hci_cb.hci_state == NFA_HCI_STATE_STARTUP) ||
             (nfa_hci_cb.hci_state == NFA_HCI_STATE_RESTORE)) {
    /* Received Hot Plug evt during DH host bootup */
    if ((nfa_hci_cb.ee_disable_disc) &&
        (nfa_hci_cb.num_hot_plug_evts == (nfa_hci_cb.num_nfcee - 1)) &&
        (nfa_hci_cb.num_ee_dis_req_ntf < (nfa_hci_cb.num_nfcee - 1))) {
      /* Received expected number of Hot Plug event(s) before as many number of
       * EE DISC REQ Ntf(s) are received */
      nfa_hci_cb.w4_hci_netwk_init = false;
    }
  } else {
    /* Received Hot Plug evt on UICC self reset */
    evt_data.rcvd_evt.evt_code = nfa_hci_cb.inst;
    /* Notify all registered application with the HOT_PLUG_EVT */
    nfa_hciu_send_to_all_apps(NFA_HCI_EVENT_RCVD_EVT, &evt_data);

    /* Send Get Host List after receiving any pending response */
    p_msg = (tNFA_HCI_API_GET_HOST_LIST*)GKI_getbuf(
        sizeof(tNFA_HCI_API_GET_HOST_LIST));
    if (p_msg != nullptr) {
      p_msg->hdr.event = NFA_HCI_API_GET_HOST_LIST_EVT;
      /* Set Invalid handle to identify this Get Host List command is internal
       */
      p_msg->hci_handle = NFA_HANDLE_INVALID;

      nfa_sys_sendmsg(p_msg);
    }
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_dyn_pipe_pkt
**
** Description      This function handles data received via dynamic pipe
**
** Returns          none
**
*******************************************************************************/
void nfa_hci_handle_dyn_pipe_pkt(uint8_t pipe_id, uint8_t* p_data,
                                 uint16_t data_len) {
  tNFA_HCI_DYN_PIPE* p_pipe = nfa_hciu_find_pipe_by_pid(pipe_id);
  tNFA_HCI_DYN_GATE* p_gate;
  tNFA_HCI_EVT_DATA  evt_data;

  if (p_pipe == nullptr) {
    /* Invalid pipe ID */
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_dyn_pipe_pkt - Unknown pipe %d", pipe_id);
    if (nfa_hci_cb.type == NFA_HCI_COMMAND_TYPE)
      nfa_hciu_send_msg(pipe_id, NFA_HCI_RESPONSE_TYPE, NFA_HCI_ANY_E_NOK, 0,
                        nullptr);
#if(NXP_EXTNS == TRUE)
    if(nfa_hci_cb.hci_state == NFA_HCI_STATE_NFCEE_ENABLE){
      nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
      evt_data.config_rsp_rcvd.status = NFA_STATUS_FAILED;
      /*Notify failure*/
      nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
    }
#endif
    return;
  }
#if (NXP_EXTNS == TRUE)
  if (nfa_hci_cb.hci_state == NFA_HCI_STATE_NFCEE_ENABLE) {
    nfa_hci_handle_Nfcee_dynpipe_rsp(pipe_id, p_data, data_len);
  }
#endif
  if (p_pipe->local_gate == NFA_HCI_IDENTITY_MANAGEMENT_GATE) {
    nfa_hci_handle_identity_mgmt_gate_pkt(p_data, p_pipe);
  } else if (p_pipe->local_gate == NFA_HCI_LOOP_BACK_GATE) {
    nfa_hci_handle_loopback_gate_pkt(p_data, data_len, p_pipe);
  } else if (p_pipe->local_gate == NFA_HCI_CONNECTIVITY_GATE) {
    nfa_hci_handle_connectivity_gate_pkt(p_data, data_len, p_pipe);
  }
#if (NXP_EXTNS == TRUE)
  else if ((nfcFL.nfccFL._GEMALTO_SE_SUPPORT) &&
          (p_pipe->local_gate == NFC_HCI_DEFAULT_DEST_GATE)) {
    /* Check if data packet is a command, response or event */
    p_gate = nfa_hci_cb.cfg.dyn_gates;
    p_gate->gate_owner = 0x0800;

    switch (nfa_hci_cb.type) {
      case NFA_HCI_COMMAND_TYPE:
        nfa_hci_handle_generic_gate_cmd(p_data, (uint8_t)data_len, p_pipe);
        break;

      case NFA_HCI_RESPONSE_TYPE:
        nfa_hci_handle_generic_gate_rsp(p_data, (uint8_t)data_len, p_pipe);
        break;

      case NFA_HCI_EVENT_TYPE:
        nfa_hci_handle_generic_gate_evt(p_data, data_len, p_gate, p_pipe);
        break;
    }
  }
#endif
  else {
    p_gate = nfa_hciu_find_gate_by_gid(p_pipe->local_gate);
    if (p_gate == nullptr) {
      LOG(ERROR) << StringPrintf(
          "nfa_hci_handle_dyn_pipe_pkt - Pipe's gate %d is corrupt",
          p_pipe->local_gate);
      if (nfa_hci_cb.type == NFA_HCI_COMMAND_TYPE)
        nfa_hciu_send_msg(pipe_id, NFA_HCI_RESPONSE_TYPE, NFA_HCI_ANY_E_NOK, 0,
                          nullptr);
      return;
    }
    /* Check if data packet is a command, response or event */
    switch (nfa_hci_cb.type) {
      case NFA_HCI_COMMAND_TYPE:
        nfa_hci_handle_generic_gate_cmd(p_data, (uint8_t)data_len, p_pipe);
        break;

      case NFA_HCI_RESPONSE_TYPE:
        nfa_hci_handle_generic_gate_rsp(p_data, (uint8_t)data_len, p_pipe);
        break;

      case NFA_HCI_EVENT_TYPE:
        nfa_hci_handle_generic_gate_evt(p_data, data_len, p_gate, p_pipe);
        break;
    }
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_identity_mgmt_gate_pkt
**
** Description      This function handles incoming Identity Management gate hci
**                  commands
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_identity_mgmt_gate_pkt(uint8_t* p_data,
                                                  tNFA_HCI_DYN_PIPE* p_pipe) {
  uint8_t data[20];
  uint8_t index;
  uint8_t gate_rsp[3 + NFA_HCI_MAX_GATE_CB], num_gates;
  uint16_t rsp_len = 0;
  uint8_t* p_rsp = data;
  tNFA_HCI_RESPONSE response = NFA_HCI_ANY_OK;

  /* We never send commands on a pipe where the local gate is the identity
   * management
   * gate, so only commands should be processed.
   */
  if (nfa_hci_cb.type != NFA_HCI_COMMAND_TYPE) return;

  switch (nfa_hci_cb.inst) {
    case NFA_HCI_ANY_GET_PARAMETER:
      index = *(p_data++);
      if (p_pipe->pipe_state == NFA_HCI_PIPE_OPENED) {
        switch (index) {
          case NFA_HCI_VERSION_SW_INDEX:
            data[0] = (uint8_t)((NFA_HCI_VERSION_SW >> 16) & 0xFF);
            data[1] = (uint8_t)((NFA_HCI_VERSION_SW >> 8) & 0xFF);
            data[2] = (uint8_t)((NFA_HCI_VERSION_SW)&0xFF);
            rsp_len = 3;
            break;

          case NFA_HCI_HCI_VERSION_INDEX:
            data[0] = NFA_HCI_VERSION;
            rsp_len = 1;
            break;

          case NFA_HCI_VERSION_HW_INDEX:
            data[0] = (uint8_t)((NFA_HCI_VERSION_HW >> 16) & 0xFF);
            data[1] = (uint8_t)((NFA_HCI_VERSION_HW >> 8) & 0xFF);
            data[2] = (uint8_t)((NFA_HCI_VERSION_HW)&0xFF);
            rsp_len = 3;
            break;

          case NFA_HCI_VENDOR_NAME_INDEX:
            memcpy(data, NFA_HCI_VENDOR_NAME, strlen(NFA_HCI_VENDOR_NAME));
            rsp_len = (uint8_t)strlen(NFA_HCI_VENDOR_NAME);
            break;

          case NFA_HCI_MODEL_ID_INDEX:
            data[0] = NFA_HCI_MODEL_ID;
            rsp_len = 1;
            break;

          case NFA_HCI_GATES_LIST_INDEX:
            gate_rsp[0] = NFA_HCI_LOOP_BACK_GATE;
            gate_rsp[1] = NFA_HCI_IDENTITY_MANAGEMENT_GATE;
            gate_rsp[2] = NFA_HCI_CONNECTIVITY_GATE;
            num_gates = nfa_hciu_get_allocated_gate_list(&gate_rsp[3]);
            rsp_len = num_gates + 3;
            p_rsp = gate_rsp;
            break;

          default:
            response = NFA_HCI_ANY_E_NOK;
            break;
        }
      } else {
        response = NFA_HCI_ANY_E_PIPE_NOT_OPENED;
      }
      break;

    case NFA_HCI_ANY_OPEN_PIPE:
      data[0] = 0;
      rsp_len = 1;
      p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
      break;

    case NFA_HCI_ANY_CLOSE_PIPE:
      p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;
      break;

    default:
      response = NFA_HCI_ANY_E_CMD_NOT_SUPPORTED;
      break;
  }

  nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE, response, rsp_len,
                    p_rsp);
}

/*******************************************************************************
**
** Function         nfa_hci_handle_generic_gate_cmd
**
** Description      This function handles all generic gates (excluding
**                  connectivity gate) commands
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_generic_gate_cmd(uint8_t* p_data, uint8_t data_len,
                                            tNFA_HCI_DYN_PIPE* p_pipe) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_HANDLE app_handle = nfa_hciu_get_pipe_owner(p_pipe->pipe_id);

  switch (nfa_hci_cb.inst) {
    case NFA_HCI_ANY_SET_PARAMETER:
      evt_data.registry.pipe = p_pipe->pipe_id;
      evt_data.registry.index = *p_data++;
      if (data_len > 0) data_len--;
      evt_data.registry.data_len = data_len;

      memcpy(evt_data.registry.reg_data, p_data, data_len);

      nfa_hciu_send_to_app(NFA_HCI_SET_REG_CMD_EVT, &evt_data, app_handle);
      break;

    case NFA_HCI_ANY_GET_PARAMETER:
      evt_data.registry.pipe = p_pipe->pipe_id;
      evt_data.registry.index = *p_data;
      evt_data.registry.data_len = 0;

      nfa_hciu_send_to_app(NFA_HCI_GET_REG_CMD_EVT, &evt_data, app_handle);
      break;

    case NFA_HCI_ANY_OPEN_PIPE:
      nfa_hci_handle_pipe_open_close_cmd(p_pipe);

      evt_data.opened.pipe = p_pipe->pipe_id;
      evt_data.opened.status = NFA_STATUS_OK;

      nfa_hciu_send_to_app(NFA_HCI_OPEN_PIPE_EVT, &evt_data, app_handle);
      break;

    case NFA_HCI_ANY_CLOSE_PIPE:
      nfa_hci_handle_pipe_open_close_cmd(p_pipe);

      evt_data.closed.pipe = p_pipe->pipe_id;
      evt_data.opened.status = NFA_STATUS_OK;

      nfa_hciu_send_to_app(NFA_HCI_CLOSE_PIPE_EVT, &evt_data, app_handle);
      break;

    default:
      /* Could be application specific command, pass it on */
      evt_data.cmd_rcvd.status = NFA_STATUS_OK;
      evt_data.cmd_rcvd.pipe = p_pipe->pipe_id;
      ;
      evt_data.cmd_rcvd.cmd_code = nfa_hci_cb.inst;
      evt_data.cmd_rcvd.cmd_len = data_len;

      if (data_len <= NFA_MAX_HCI_CMD_LEN)
        memcpy(evt_data.cmd_rcvd.cmd_data, p_data, data_len);

      nfa_hciu_send_to_app(NFA_HCI_CMD_RCVD_EVT, &evt_data, app_handle);
      break;
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_generic_gate_rsp
**
** Description      This function handles all generic gates (excluding
**                  connectivity) response
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_generic_gate_rsp(uint8_t* p_data, uint8_t data_len,
                                            tNFA_HCI_DYN_PIPE* p_pipe) {
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_STATUS status = NFA_STATUS_OK;

  if (nfa_hci_cb.inst != NFA_HCI_ANY_OK) status = NFA_STATUS_FAILED;

  if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_OPEN_PIPE) {
    if (status == NFA_STATUS_OK) p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;

    nfa_hci_cb.nv_write_needed = true;
    /* Tell application */
    evt_data.opened.status = status;
    evt_data.opened.pipe = p_pipe->pipe_id;

    nfa_hciu_send_to_app(NFA_HCI_OPEN_PIPE_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_CLOSE_PIPE) {
    p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;

    nfa_hci_cb.nv_write_needed = true;
    /* Tell application */
    evt_data.opened.status = status;
    ;
    evt_data.opened.pipe = p_pipe->pipe_id;

    nfa_hciu_send_to_app(NFA_HCI_CLOSE_PIPE_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_GET_PARAMETER) {
    /* Tell application */
    evt_data.registry.status = status;
    evt_data.registry.pipe = p_pipe->pipe_id;
    evt_data.registry.data_len = data_len;
    evt_data.registry.index = nfa_hci_cb.param_in_use;

    memcpy(evt_data.registry.reg_data, p_data, data_len);

    nfa_hciu_send_to_app(NFA_HCI_GET_REG_RSP_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_SET_PARAMETER) {
    /* Tell application */
    evt_data.registry.status = status;
    ;
    evt_data.registry.pipe = p_pipe->pipe_id;

    nfa_hciu_send_to_app(NFA_HCI_SET_REG_RSP_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else {
    /* Could be a response to application specific command sent, pass it on */
#if (NXP_EXTNS == TRUE)
    if(nfa_hci_cb.inst == NFA_HCI_ANY_E_PIPE_NOT_OPENED) {
      p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;
      nfa_hci_cb.nv_write_needed = true;
    }
#endif
    evt_data.rsp_rcvd.status = NFA_STATUS_OK;
    evt_data.rsp_rcvd.pipe = p_pipe->pipe_id;
    ;
    evt_data.rsp_rcvd.rsp_code = nfa_hci_cb.inst;
    evt_data.rsp_rcvd.rsp_len = data_len;

    if (data_len <= NFA_MAX_HCI_RSP_LEN)
      memcpy(evt_data.rsp_rcvd.rsp_data, p_data, data_len);

    nfa_hciu_send_to_app(NFA_HCI_RSP_RCVD_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_connectivity_gate_pkt
**
** Description      This function handles incoming connectivity gate packets
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_connectivity_gate_pkt(uint8_t* p_data,
                                                 uint16_t data_len,
                                                 tNFA_HCI_DYN_PIPE* p_pipe) {
  tNFA_HCI_EVT_DATA evt_data;

  if (nfa_hci_cb.type == NFA_HCI_COMMAND_TYPE) {
    switch (nfa_hci_cb.inst) {
      case NFA_HCI_ANY_OPEN_PIPE:
      case NFA_HCI_ANY_CLOSE_PIPE:
        nfa_hci_handle_pipe_open_close_cmd(p_pipe);
        break;

      case NFA_HCI_CON_PRO_HOST_REQUEST:
        /* A request to the DH to activate another host. This is not supported
         * for */
        /* now, we will implement it when the spec is clearer and UICCs need it.
         */
        nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE,
                          NFA_HCI_ANY_E_CMD_NOT_SUPPORTED, 0, nullptr);
        break;

      default:
        nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE,
                          NFA_HCI_ANY_E_CMD_NOT_SUPPORTED, 0, nullptr);
        break;
    }
  } else if (nfa_hci_cb.type == NFA_HCI_RESPONSE_TYPE) {
    if ((nfa_hci_cb.cmd_sent == NFA_HCI_ANY_OPEN_PIPE) &&
        (nfa_hci_cb.inst == NFA_HCI_ANY_OK))
      p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
    else if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_CLOSE_PIPE)
      p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;

    /* Could be a response to application specific command sent, pass it on */
    evt_data.rsp_rcvd.status = NFA_STATUS_OK;
    evt_data.rsp_rcvd.pipe = p_pipe->pipe_id;
    ;
    evt_data.rsp_rcvd.rsp_code = nfa_hci_cb.inst;
    evt_data.rsp_rcvd.rsp_len = data_len;

    if (data_len <= NFA_MAX_HCI_RSP_LEN)
      memcpy(evt_data.rsp_rcvd.rsp_data, p_data, data_len);

    nfa_hciu_send_to_app(NFA_HCI_RSP_RCVD_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else if (nfa_hci_cb.type == NFA_HCI_EVENT_TYPE) {
    evt_data.rcvd_evt.pipe = p_pipe->pipe_id;
    evt_data.rcvd_evt.evt_code = nfa_hci_cb.inst;
    evt_data.rcvd_evt.evt_len = data_len;
    evt_data.rcvd_evt.p_evt_buf = p_data;

    /* notify NFA_HCI_EVENT_RCVD_EVT to the application */
    nfa_hciu_send_to_apps_handling_connectivity_evts(NFA_HCI_EVENT_RCVD_EVT,
                                                     &evt_data);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_loopback_gate_pkt
**
** Description      This function handles incoming loopback gate hci events
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_loopback_gate_pkt(uint8_t* p_data, uint16_t data_len,
                                             tNFA_HCI_DYN_PIPE* p_pipe) {
  uint8_t data[1];
  uint8_t rsp_len = 0;
  tNFA_HCI_RESPONSE response = NFA_HCI_ANY_OK;
  tNFA_HCI_EVT_DATA evt_data;

  /* Check if data packet is a command, response or event */
  if (nfa_hci_cb.type == NFA_HCI_COMMAND_TYPE) {
    if (nfa_hci_cb.inst == NFA_HCI_ANY_OPEN_PIPE) {
      data[0] = 0;
      rsp_len = 1;
      p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
    } else if (nfa_hci_cb.inst == NFA_HCI_ANY_CLOSE_PIPE) {
      p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;
    } else
      response = NFA_HCI_ANY_E_CMD_NOT_SUPPORTED;

    nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_RESPONSE_TYPE, response, rsp_len,
                      data);
  } else if (nfa_hci_cb.type == NFA_HCI_RESPONSE_TYPE) {
    if ((nfa_hci_cb.cmd_sent == NFA_HCI_ANY_OPEN_PIPE) &&
        (nfa_hci_cb.inst == NFA_HCI_ANY_OK))
      p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
    else if (nfa_hci_cb.cmd_sent == NFA_HCI_ANY_CLOSE_PIPE)
      p_pipe->pipe_state = NFA_HCI_PIPE_CLOSED;

    /* Could be a response to application specific command sent, pass it on */
    evt_data.rsp_rcvd.status = NFA_STATUS_OK;
    evt_data.rsp_rcvd.pipe = p_pipe->pipe_id;
    ;
    evt_data.rsp_rcvd.rsp_code = nfa_hci_cb.inst;
    evt_data.rsp_rcvd.rsp_len = data_len;

    if (data_len <= NFA_MAX_HCI_RSP_LEN)
      memcpy(evt_data.rsp_rcvd.rsp_data, p_data, data_len);

    nfa_hciu_send_to_app(NFA_HCI_RSP_RCVD_EVT, &evt_data,
                         nfa_hci_cb.app_in_use);
  } else if (nfa_hci_cb.type == NFA_HCI_EVENT_TYPE) {
    if (nfa_hci_cb.w4_rsp_evt) {
      evt_data.rcvd_evt.pipe = p_pipe->pipe_id;
      evt_data.rcvd_evt.evt_code = nfa_hci_cb.inst;
      evt_data.rcvd_evt.evt_len = data_len;
      evt_data.rcvd_evt.p_evt_buf = p_data;

      nfa_hciu_send_to_app(NFA_HCI_EVENT_RCVD_EVT, &evt_data,
                           nfa_hci_cb.app_in_use);
    } else if (nfa_hci_cb.inst == NFA_HCI_EVT_POST_DATA) {
      /* Send back the same data we got */
      nfa_hciu_send_msg(p_pipe->pipe_id, NFA_HCI_EVENT_TYPE,
                        NFA_HCI_EVT_POST_DATA, data_len, p_data);
    }
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_generic_gate_evt
**
** Description      This function handles incoming Generic gate hci events
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_generic_gate_evt(uint8_t* p_data, uint16_t data_len,
                                            tNFA_HCI_DYN_GATE* p_gate,
                                            tNFA_HCI_DYN_PIPE* p_pipe) {
  tNFA_HCI_EVT_DATA evt_data;

  evt_data.rcvd_evt.pipe = p_pipe->pipe_id;
  evt_data.rcvd_evt.evt_code = nfa_hci_cb.inst;
  evt_data.rcvd_evt.evt_len = data_len;
  evt_data.rcvd_evt.last_SentEvtType = 0;

  if (nfa_hci_cb.assembly_failed)
    evt_data.rcvd_evt.status = NFA_STATUS_BUFFER_FULL;
  else
    evt_data.rcvd_evt.status = NFA_STATUS_OK;

  evt_data.rcvd_evt.p_evt_buf = p_data;
#if (NXP_EXTNS == TRUE)
  if (nfa_hci_cb.inst != NFA_HCI_EVT_WTX) {
#endif
    nfa_hci_cb.rsp_buf_size = 0;
    nfa_hci_cb.p_rsp_buf = nullptr;
#if (NXP_EXTNS == TRUE)
  }
  if (nfa_hci_cb.IsEventAbortSent) {
    nfa_hci_cb.IsEventAbortSent = false;
    if (nfa_hci_cb.evt_sent.evt_type != NFA_EVT_ABORT) {
      evt_data.rcvd_evt.evt_code = nfa_hci_cb.evt_sent.evt_type;
      evt_data.rcvd_evt.evt_len = 0;
    }
  }
#endif

  /* notify NFA_HCI_EVENT_RCVD_EVT to the application */
  nfa_hciu_send_to_app(NFA_HCI_EVENT_RCVD_EVT, &evt_data, p_gate->gate_owner);
}

#if (NXP_EXTNS == TRUE)
/*******************************************************************************
**
** Function         nfa_hci_api_get_host_id
**
** Description      action function to get the host id from HCI controller
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_get_host_id(tNFA_HCI_EVENT_DATA* p_evt_data) {
  uint8_t app_inx = p_evt_data->get_host_list.hci_handle & NFA_HANDLE_MASK;

  nfa_hci_cb.app_in_use = p_evt_data->get_host_list.hci_handle;

  /* Send Get Host List command on "Internal request" or requested by registered
   * application with valid handle and callback function */
  if ((nfa_hci_cb.app_in_use == NFA_HANDLE_INVALID) ||
      ((app_inx < NFA_HCI_MAX_APP_CB) &&
       (nfa_hci_cb.p_app_cback[app_inx] != nullptr))) {
    nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE, NFA_HCI_HOST_ID_INDEX);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_get_host_type
**
** Description      action function to get the host type from HCI controller
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_get_host_type(tNFA_HCI_EVENT_DATA* p_evt_data) {
  uint8_t app_inx = p_evt_data->get_host_list.hci_handle & NFA_HANDLE_MASK;

  nfa_hci_cb.app_in_use = p_evt_data->get_host_list.hci_handle;

  /* Send Get Host List command on "Internal request" or requested by registered
   * application with valid handle and callback function */
  if ((nfa_hci_cb.app_in_use == NFA_HANDLE_INVALID) ||
      ((app_inx < NFA_HCI_MAX_APP_CB) &&
       (nfa_hci_cb.p_app_cback[app_inx] != nullptr))) {
    if (nfa_hci_cb.cfg.admin_gate.pipe01_state == NFA_HCI_PIPE_OPENED) {
      nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE, NFA_HCI_HOST_TYPE_INDEX);
    }
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_get_host_type_list
**
** Description      action function to get the host type list from HCI
*controller
**
** Returns          Status
**
*******************************************************************************/
tNFA_STATUS nfa_hci_api_get_host_type_list() {
  tNFA_STATUS status = NFA_STATUS_FAILED;
  tNFA_HCI_EVT_DATA evt_data;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_get_host_type_list - enter!!");
  if ((nfa_hci_cb.host_controller_version == NFA_HCI_CONTROLLER_VERSION_12) &&
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_NFCEE_ENABLE)) {
     DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "nfa_hci_api_get_host_type_list - Sending get_host_type_list!!!");
    if ((status = nfa_hciu_send_get_param_cmd(NFA_HCI_ADMIN_PIPE,
                                              NFA_HCI_HOST_TYPE_LIST_INDEX)) ==
        NFA_STATUS_OK)
      return NFA_STATUS_OK;
  }
  evt_data.admin_rsp_rcvd.status = status;
  evt_data.admin_rsp_rcvd.NoHostsPresent = 0;
  /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
  nfa_hciu_send_to_all_apps(NFA_HCI_HOST_TYPE_LIST_READ_EVT, &evt_data);
  return NFA_STATUS_OK;
}
/*******************************************************************************
**
** Function         nfa_hci_api_config_nfcee
**
** Description      action function to configure NFCEE found in network as per
*ETSI12
**
** Returns          if success NFA_STATUS_OK or NFA_STATUS_FAILED
**
*******************************************************************************/
tNFA_STATUS nfa_hci_api_config_nfcee(uint8_t hostId) {
  tNFA_STATUS status = NFA_STATUS_OK;
  tNFA_HCI_EVT_DATA evt_data;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_config_nfcee - enter!!");

  nfa_hciu_set_nfceeid_config_mask(NFA_HCI_SET_CONFIG_EVENT, hostId);
  if ((nfa_hci_cb.host_controller_version == NFA_HCI_CONTROLLER_VERSION_12) &&
      (nfa_hci_cb.hci_state == NFA_HCI_STATE_NFCEE_ENABLE)) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_config_nfcee -Entry");
    if ((nfa_hci_api_IspipePresent(hostId, NFA_HCI_ETSI12_APDU_GATE) ==
         false)) {
      nfa_hci_cb.current_nfcee = hostId;
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_config_nfcee - creating APDU gate pipe!!!");
      nfa_hciu_alloc_gate(NFA_HCI_ETSI12_APDU_GATE, NFA_HANDLE_GROUP_HCI);
      nfa_hciu_send_create_pipe_cmd (NFA_HCI_ETSI12_APDU_GATE, nfa_hci_cb.current_nfcee, NFA_HCI_ETSI12_APDU_GATE);

      return (NFA_STATUS_OK);
    } else {
      status = NFA_STATUS_OK;
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "nfa_hci_api_config_nfcee - APDU Gate is present and pipe is already "
          "created!!!");
    }
  }
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_config_nfcee - No NFCEE Config is needed!!!");
  evt_data.config_rsp_rcvd.status = status;
  /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
  nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
  return NFA_STATUS_OK;
}

/*******************************************************************************
**
** Function         nfa_hci_handle_nfcee_config
**
** Description      handle  NFCEE configuration of discovered ETSI 12 host.
**
** Returns          if success NFA_STATUS_OK or NFA_STATUS_FAILED
**
*********************************************************************************/
static bool nfa_hci_handle_nfcee_config() {
  bool status = false;
  int xx;
  for (xx = 00; xx < nfa_hci_cb.host_count; xx++) {
    if (nfa_hciu_check_nfcee_config_done(nfa_hci_cb.host_id[xx]) == false) {
      NFC_NfceeModeSet(nfa_hci_cb.host_id[xx], NFC_MODE_ACTIVATE);
      nfa_hci_cb.current_nfcee = nfa_hci_cb.host_id[xx];
#if(NXP_NFC_UICC_ETSI12 == true)
      if(NFA_HCI_HOST_ID_ESE != nfa_hci_cb.host_id[xx])
      {
        nfa_hci_api_config_nfcee(nfa_hci_cb.current_nfcee);
      }
#endif
      break;
    }
  }
  if (xx == nfa_hci_cb.host_count) status = true;
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_get_num_nfcee_configured
**
** Description      Read number of NFCEE config.
**
**
** Returns          None
**
*********************************************************************************/
static tNFA_STATUS nfa_hci_get_num_nfcee_configured() {
  uint8_t num_param_id = 0x00, xx;
  tNFA_STATUS status = NFA_STATUS_OK;
  nfa_sys_stop_timer(&nfa_hci_cb.timer);
  nfa_hci_cb.num_nfcee = NFA_HCI_MAX_HOST_IN_NETWORK;
  NFA_AllEeGetInfo(&nfa_hci_cb.num_nfcee, nfa_hci_cb.hci_ee_info);
  for (xx = 0; xx < nfa_hci_cb.num_nfcee; xx++) {
    if ((((nfa_hci_cb.hci_ee_info[xx].ee_interface[0] !=
        NCI_NFCEE_INTERFACE_HCI_ACCESS) &&
        nfa_hci_cb.hci_ee_info[xx].ee_status == NFA_EE_STATUS_ACTIVE)) &&
        (nfa_hci_cb.hci_ee_info[xx].ee_handle != 0x410)) {
      nfa_hci_cb.nfcee_cfg.host_cb[num_param_id++] =
          nfa_hci_cb.hci_ee_info[xx].ee_handle;
    }
  }
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_read_num_nfcee_config_cb  nfa_ee_max_ee_cfg%x", nfa_ee_max_ee_cfg);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_read_num_nfcee_config_cb nfa_hci_cb.num_nfcee%x", nfa_hci_cb.num_nfcee);
  if (nfa_ee_max_ee_cfg > nfa_hci_cb.num_nfcee) {
    nfa_sys_start_timer(&nfa_hci_cb.timer, NFA_HCI_NFCEE_DISCOVER_TIMEOUT_EVT,
                        nfa_hci_cb.max_nfcee_disc_timeout);
    status = NFA_STATUS_BUSY;
  }
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_poll_all_nfcee_session_id
**
** Description      poll continuously for session ID for all discovered hosts.
**
** Returns          if success NFA_STATUS_OK or NFA_STATUS_FAILED
**
*********************************************************************************/
static tNFA_STATUS nfa_hci_poll_all_nfcee_session_id() {
  uint8_t xx;
  tNFA_STATUS status = NFA_STATUS_OK;
  for (xx = 0; xx < nfa_hci_cb.num_nfcee; xx++) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_pollsession_id   -%x",
                     nfa_hci_cb.hci_ee_info[xx].ee_handle);
    if ((((nfa_hci_cb.hci_ee_info[xx].ee_interface[0] !=
        NCI_NFCEE_INTERFACE_HCI_ACCESS)&& nfa_hci_cb.hci_ee_info[xx].ee_status == NFA_EE_STATUS_ACTIVE))&&
        (nfa_hci_cb.hci_ee_info[xx].ee_handle != 0x410)) {
      if (nfa_hciu_check_nfcee_poll_done(nfa_hci_cb.hci_ee_info[xx].ee_handle &
                                         ~(NFA_HANDLE_GROUP_EE)) == false) {
        if (nfa_hci_cb.nfcee_cfg.session_id_retry <=
            nfa_hci_cb.max_hci_session_id_read_count) {
          status = nfa_hci_poll_session_id(
              nfa_hci_cb.hci_ee_info[xx].ee_handle & ~(NFA_HANDLE_GROUP_EE));
          if (status == NFA_STATUS_OK) break;
        } else {
          nfa_hci_cb.nfcee_cfg.session_id_retry = 0x00;
          nfa_hciu_set_nfceeid_poll_mask(
              NFA_HCI_SET_CONFIG_EVENT,
              nfa_hci_cb.hci_ee_info[xx].ee_handle & ~(NFA_HANDLE_GROUP_EE));
        }
      }
    }
  }
  if (xx == nfa_hci_cb.num_nfcee)
    nfa_hci_handle_nfcee_config_evt(NFA_HCI_HOST_TYPE_LIST_INDEX);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_poll_all_nfcee_session_id - exit!!");
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_poll_session_id
**
** Description      poll continuously for session ID of particular host
**
** Returns          if success NFA_STATUS_OK or NFA_STATUS_FAILED
**
*********************************************************************************/
static tNFA_STATUS nfa_hci_poll_session_id(uint8_t host_type) {
  uint8_t p_data[NFA_MAX_HCI_CMD_LEN];
  uint8_t* p = p_data;
  tNFA_STATUS status = NFA_STATUS_OK;

  NCI_MSG_BLD_HDR0(p, NCI_MT_CMD, NCI_GID_CORE);
  NCI_MSG_BLD_HDR1(p, NCI_MSG_CORE_GET_CONFIG);
  UINT8_TO_STREAM(p, 0x03);
  UINT8_TO_STREAM(p, 0x01);
  UINT8_TO_STREAM(p, NXP_NFC_SET_CONFIG_PARAM_EXT);

  if (NFA_HCI_HOST_ID_UICC0 == host_type || NFA_HCI_HOST_ID_FIRST_DYNAMICALLY_ALLOCATED == host_type) {
    UINT8_TO_STREAM(p, NXP_NFC_PARAM_SWP_SESSIONID_INT1);
  } else if (NFA_HCI_HOST_ID_UICC1 == host_type) {
    UINT8_TO_STREAM(p, NXP_NFC_PARAM_SWP_SESSIONID_INT1A);
  } else if (NFA_HCI_HOST_ID_ESE == host_type) {
    UINT8_TO_STREAM(p, NXP_NFC_PARAM_SWP_SESSIONID_INT2);
  } else
    status = NFA_STATUS_BAD_HANDLE;

  if (status == NFA_STATUS_OK && ((p - p_data) > 0x00)) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_clear_all_pipe_ntf session id read");
    nfa_hci_cb.nfcee_cfg.session_id_retry++;
    status =
        nfa_hciu_send_raw_cmd(p - p_data, p_data, nfa_hci_poll_session_id_cb);
  }
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_poll_session_id_cb
**
** Description      callback handler for session ID read commands response.
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_poll_session_id_cb(__attribute__((unused)) uint8_t event, uint16_t param_len,
                                       uint8_t* p_param) {
  uint8_t default_session[NFA_HCI_SESSION_ID_LEN] = {0xFF, 0xFF, 0xFF, 0xFF,
                                                     0xFF, 0xFF, 0xFF, 0xFF};
  nfa_sys_stop_timer(&nfa_hci_cb.timer);
  uint8_t SESSION_ID_INDEX = 0x08;

  if (param_len < NFA_HCI_SESSION_ID_LEN || p_param == nullptr ||
      p_param[3] != NFA_STATUS_OK) {
    nfa_hci_handle_nfcee_config_evt(NFA_HCI_READ_SESSIONID);
    return;
  }

  if (!memcmp((uint8_t*)default_session, p_param + SESSION_ID_INDEX,
              NFA_HCI_SESSION_ID_LEN)) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_poll_session_id_cb invalid session id");
    if (nfa_hci_cb.nfcee_cfg.session_id_retry <=
        nfa_hci_cb.max_hci_session_id_read_count) {
      nfa_sys_start_timer(&nfa_hci_cb.timer,
                          NFA_HCI_SESSION_ID_POLL_DELAY_TIMEOUT_EVT,
                          NFA_HCI_SESSION_ID_POLL_DELAY);
    } else {
      nfa_hci_handle_nfcee_config_evt(NFA_HCI_READ_SESSIONID);
    }
  } else {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_poll_session_id_cb valid session id");
    nfa_hci_cb.nfcee_cfg.session_id_retry =
        nfa_hci_cb.max_hci_session_id_read_count + 1;
    nfa_hci_handle_nfcee_config_evt(NFA_HCI_READ_SESSIONID);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_handle_nfcee_config_evt
**
** Description      In case of NFCEE CONFIG EVT , the following sequence of
** commands are sent.
**                  This function also handles the CLEAR_ALL_PIPE_NTF from
*respective host.
**                      a.Get the number of secelement configured and
*discovered, in case of less than configured wait for
**                        for all the secelement to be discovered.
**                      b.Poll for session ID of all the discovered secure
*Element to check whether
**                        the secure Element is initialized or not.
**                      c.Read the HOST_TYPE_LIST_INDEX to get the number of
*hosts configured.
**                      d.Check for APDU gate discovered or not.
**                      e.Create identity management pipe and APDU pipe and open
*the pipe.
**                      f.Read parameters from APDU gate.
**
**
** Returns              None
**
*******************************************************************************/
void nfa_hci_handle_nfcee_config_evt(uint16_t event) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_nfcee_config_evt enter %x", event);
  switch (event) {
    case NFA_HCI_GET_NUM_NFCEE_CONFIGURED:
      nfa_hci_cb.nfcee_cfg.nfc_init_state = true;
      if (nfa_hci_cb.hci_state == NFA_HCI_STATE_IDLE) {
        nfa_hci_cb.hci_state = NFA_HCI_STATE_NFCEE_ENABLE;
        nfa_hci_cb.nfcee_cfg.config_nfcee_state =
            NFA_HCI_GET_NUM_NFCEE_CONFIGURED;
        if (nfa_hci_get_num_nfcee_configured() != NFA_STATUS_BUSY) {
          /* Send read session event to continue with other initialization*/
          /*Read the session ID of the host discovered */
          nfa_hci_cb.nfcee_cfg.config_nfcee_state = NFA_HCI_READ_SESSIONID;
          nfa_hci_poll_all_nfcee_session_id();
        }
      } else {
        event = NFA_HCI_NFCEE_CONFIG_COMPLETE;
      }
      break;
    case NFA_HCI_ADM_NOTIFY_ALL_PIPE_CLEARED:
      /* Stop RF discovery if running and update state*/
      if (nfa_hci_cb.hci_state < NFA_HCI_STATE_IDLE) {
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_nfcee_config_evt  will be handled later");
        return;
      }
      if (NFA_DM_RFST_DISCOVERY == nfa_dm_cb.disc_cb.disc_state) {
        nfa_hci_cb.nfcee_cfg.discovery_stopped =
            nfa_dm_act_stop_rf_discovery(nullptr);
      }
      FALLTHROUGH;
    case NFA_HCI_READ_SESSIONID:
      /*Read the session ID of the host discovered */
      nfa_hci_cb.nfcee_cfg.config_nfcee_state = NFA_HCI_READ_SESSIONID;
      nfa_hci_poll_all_nfcee_session_id();
      break;
    case NFA_HCI_HOST_TYPE_LIST_INDEX:
      /*Read the host type list index to get ETSI Host configured*/
      nfa_hci_cb.nfcee_cfg.config_nfcee_state = NFA_HCI_HOST_TYPE_LIST_INDEX;
      nfa_hci_cb.hci_state = NFA_HCI_STATE_NFCEE_ENABLE;
      if (nfa_hci_api_get_host_type_list() != NFA_STATUS_OK)
        event = NFA_HCI_NFCEE_CONFIG_COMPLETE;
      break;
    case NFA_HCI_INIT_NFCEE_CONFIG:
      /*Perform nfcee configuration of all nfcee list found */
      nfa_hci_cb.nfcee_cfg.config_nfcee_state = NFA_HCI_INIT_NFCEE_CONFIG;
      nfa_hci_cb.hci_state = NFA_HCI_STATE_NFCEE_ENABLE;
      if (nfa_hci_cb.nfcee_cfg.nfc_init_state == true ||
          nfa_hci_handle_nfcee_config() == true)
        event = NFA_HCI_NFCEE_CONFIG_COMPLETE;
      break;
    default:
      break;
  }
  if (NFA_HCI_NFCEE_CONFIG_COMPLETE == event ||
      NFA_HCI_RSP_TIMEOUT_EVT == event) {
    if (true == nfa_hci_cb.nfcee_cfg.discovery_stopped)
      nfa_dm_act_start_rf_discovery(nullptr);
    nfa_hci_cb.nfcee_cfg.discovery_stopped = false;
    nfa_hci_cb.nfcee_cfg.session_id_retry = false;
    nfa_hci_cb.nfcee_cfg.config_nfcee_state = NFA_HCI_NFCEE_CONFIG_COMPLETE;
    nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;

     DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "nfa_hci_handle_nfcee_config_evt  complete , notify upper layer");
    if (nfa_hci_cb.nfcee_cfg.nfc_init_state == true) {
      if (nfa_hciu_check_any_host_reset_pending()) {
        tNFA_HCI_API_CONFIGURE_EVT* p_msg;
        /* Send read session event to continue with other initialization*/
        if ((p_msg = (tNFA_HCI_API_CONFIGURE_EVT*)GKI_getbuf(
                 sizeof(tNFA_HCI_API_CONFIGURE_EVT))) != nullptr) {
          p_msg->hdr.event = NFA_HCI_API_CONFIGURE_EVT;
          p_msg->config_nfcee_event = NFA_HCI_READ_SESSIONID;
          nfa_sys_sendmsg(p_msg);
        }
      } else {
        nfa_hci_cb.nfcee_cfg.nfc_init_state = false;
        nfa_sys_cback_notify_enable_complete(NFA_ID_HCI);
      }
    }

    if (nfa_hciu_is_no_host_resetting()) nfa_hci_check_pending_api_requests();
  }
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_nfcee_config_evt exit");
}

/*******************************************************************************
**
** Function         nfa_hci_nfcee_config_rsp_handler
**
** Description      Function to handle response of nfcee config
**
** Returns          None
**
*******************************************************************************/
void nfa_hci_nfcee_config_rsp_handler(tNFA_HCI_EVT event,
                                      tNFA_HCI_EVT_DATA* p_evt) {
  if (NFA_HCI_CONFIG_DONE_EVT == event) {
    nfa_hci_handle_nfcee_config_evt(NFA_HCI_INIT_NFCEE_CONFIG);
  } else if (NFA_HCI_HOST_TYPE_LIST_READ_EVT == event) {
    if (p_evt->admin_rsp_rcvd.status != NFA_STATUS_OK ||
        nfa_hci_cb.nfcee_cfg.nfc_init_state == true) {
      nfa_hci_handle_nfcee_config_evt(NFA_HCI_NFCEE_CONFIG_COMPLETE);
    } else
      nfa_hci_handle_nfcee_config_evt(NFA_HCI_INIT_NFCEE_CONFIG);
  }
}

/*******************************************************************************
**
** Function         nfa_hci_api_getnoofhosts
**
** Description      action function to get the host type from HCI controller
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_api_getnoofhosts(uint8_t* p_data, uint8_t data_len) {
  uint8_t noofhosts = 0;
  uint8_t count = 0;
  uint8_t host_id = 0;

  nfa_hci_cb.host_count = host_id;
  noofhosts = ((data_len / NFA_HCI_HOST_TYPE_LEN) - 2);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_getnoofhosts :-no of hosts in HCI Network-%d",
                   noofhosts);
  for (count = 0; count < data_len; count++) {
     DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_getnoofhosts :data[%d] - %d\n", count,
                     p_data[count]);
  }
  for (count = 0; count < noofhosts; count++) {
    host_id = (((count + 1) * NFA_HCI_HOST_TYPE_LEN) + NFA_HCI_HOST_TYPE_LEN);
     DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "nfa_hci_api_getnoofhosts -NFA_HCI_HOST_TYPE_LIST_INDEX id -- %d !!!",
        host_id);
    if ((p_data[host_id] & p_data[host_id + 1]) != 0xFF) {
      if ((p_data[host_id] == NFA_HCI_HOST_ID_UICC0) &&
          (p_data[host_id + 1] == 0x00)) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_getnoofhosts :- UICC !!!!");
        nfa_hci_cb.host_id[nfa_hci_cb.host_count] = p_data[host_id];
        nfa_hci_cb.host_count++;
      } else if ((p_data[host_id] == 0x03) && (p_data[host_id + 1] == 0x00)) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_getnoofhosts :- eSE !!!!");
        nfa_hci_cb.host_id[nfa_hci_cb.host_count] = 0xC0;
        nfa_hci_cb.host_count++;
      }
    }
  }
}
/*******************************************************************************
**
** Function         nfa_hci_api_checkforAPDUGate
**
** Description      action function to get the host type from HCI controller
**
** Returns          None
**
*******************************************************************************/
static bool nfa_hci_api_checkforAPDUGate(uint8_t* p_data, uint8_t data_len) {
  uint8_t count = 0;
  bool status = false;
  for (count = 0; count < data_len; count++) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_checkforAPDUGate -Gate id -- %d !!!",
                     p_data[count]);
    if (p_data[count] == NFA_HCI_ETSI12_APDU_GATE) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_checkforAPDUGate -count -- %d !!!", count);
      status = true;
      break;
    }
  }
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_handle_Nfcee_admpipe_rsp
**
** Description      This function handles responses received for commands during
*NFCEE init
**                  on Admin pipe
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_Nfcee_admpipe_rsp(uint8_t* p_data,
                                             uint8_t data_len) {
  uint8_t source_host;
  uint8_t source_gate = nfa_hci_cb.local_gate_in_use;
  uint8_t dest_host = nfa_hci_cb.remote_host_in_use;
  uint8_t dest_gate = nfa_hci_cb.remote_gate_in_use;
  uint8_t pipe = 0;
  uint8_t count = 0;
  tNFA_HCI_EVT_DATA evt_data;
  tNFA_STATUS status = NFA_STATUS_OK;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "nfa_hci_handle_Nfcee_admpipe_rsp - LastCmdSent: %s  App: 0x%04x  Gate: "
      "0x%02x  Pipe: 0x%02x",
      nfa_hciu_instr_2_str(nfa_hci_cb.cmd_sent).c_str(), nfa_hci_cb.app_in_use,
      nfa_hci_cb.local_gate_in_use, nfa_hci_cb.pipe_in_use);
  if (nfa_hci_cb.inst != NFA_HCI_ANY_OK) {

    nfa_sys_stop_timer(&nfa_hci_cb.timer);

    nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
    /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
    if ((nfa_hci_cb.cmd_sent == NFA_HCI_ANY_GET_PARAMETER) &&
        (nfa_hci_cb.param_in_use == NFA_HCI_HOST_TYPE_LIST_INDEX)) {
      evt_data.admin_rsp_rcvd.status = NFA_STATUS_FAILED;
      evt_data.admin_rsp_rcvd.NoHostsPresent = 0;
      nfa_hciu_send_to_all_apps(NFA_HCI_HOST_TYPE_LIST_READ_EVT, &evt_data);
    } else {
      evt_data.config_rsp_rcvd.status = NFA_STATUS_FAILED;
      nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
    }
  } else if ((nfa_hci_cb.cmd_sent == NFA_HCI_ANY_GET_PARAMETER) &&
             (nfa_hci_cb.inst == NFA_HCI_ANY_OK)) {
    if (nfa_hci_cb.param_in_use == NFA_HCI_HOST_TYPE_LIST_INDEX) {
      nfa_sys_stop_timer(&nfa_hci_cb.timer);
      nfa_hci_cb.bClearAllPipeHandling = false;
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "nfa_hci_handle_admin_gate_rsp - Received the HOST_TYPE_LIST as per "
          "ETSI 12 !!!");
      if (data_len > 4) {
        nfa_hci_api_getnoofhosts(p_data, data_len);
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_admin_gate_rsp - Calling complete here !!!");
        evt_data.admin_rsp_rcvd.status = NFA_STATUS_OK;
        evt_data.admin_rsp_rcvd.NoHostsPresent = nfa_hci_cb.host_count;
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_admin_gate_rsp -nfa_hci_cb.host_countt --%d !",
            nfa_hci_cb.host_count);
        if (nfa_hci_cb.host_count > 0) {
          for (count = 0; count < nfa_hci_cb.host_count; count++) {
            evt_data.admin_rsp_rcvd.HostIds[count] = nfa_hci_cb.host_id[count];
             DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
                "nfa_hci_handle_admin_gate_rsp -nfa_hci_cb.host_iddd --%d !",
                nfa_hci_cb.host_id[count]);
          }
        }
        nfa_hciu_send_to_all_apps(NFA_HCI_HOST_TYPE_LIST_READ_EVT, &evt_data);

      } else {
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_admin_gate_rsp -No host is connected!!");
        evt_data.admin_rsp_rcvd.status = status;
        evt_data.admin_rsp_rcvd.NoHostsPresent = 0;
        nfa_hciu_send_to_all_apps(NFA_HCI_HOST_TYPE_LIST_READ_EVT, &evt_data);
      }
    }
  } else if ((nfa_hci_cb.cmd_sent == NFA_HCI_ADM_CREATE_PIPE) &&
             (nfa_hci_cb.inst == NFA_HCI_ANY_OK)) {
    STREAM_TO_UINT8(source_host, p_data);
    STREAM_TO_UINT8(source_gate, p_data);
    STREAM_TO_UINT8(dest_host, p_data);
    STREAM_TO_UINT8(dest_gate, p_data);
    STREAM_TO_UINT8(pipe, p_data);

    nfa_hciu_add_pipe_to_static_gate(source_gate, pipe, dest_host, dest_gate);
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_Nfcee_admpipe_rsp - Opening pipe!!!");
    nfa_hciu_send_open_pipe_cmd(pipe);
  } else {
    nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
    evt_data.config_rsp_rcvd.status = NFA_STATUS_FAILED;
    /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
    nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
  }
}
/*******************************************************************************
**
** Function         nfa_hci_handle_Nfcee_dynpipe_rsp
**
** Description      This function handles response received for commands during
*NFCEE init
**                   on dynamic pipe
**
** Returns          none
**
*******************************************************************************/
static void nfa_hci_handle_Nfcee_dynpipe_rsp(uint8_t pipeId, uint8_t* p_data,
                                             uint8_t data_len) {
  tNFA_HCI_DYN_PIPE* p_pipe = nfa_hciu_find_pipe_by_pid(pipeId);
  tNFA_STATUS status = NFA_STATUS_FAILED;
  bool wStatus = false;
  tNFA_HCI_EVT_DATA evt_data;

  if (nfa_hci_cb.type == NFA_HCI_RESPONSE_TYPE) {
    nfa_sys_stop_timer(&nfa_hci_cb.timer);
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_Nfcee_dynpipe_rsp - HCI Timer stopped!!!");
    if (nfa_hci_cb.inst != NFA_HCI_ANY_OK) {
      nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
      evt_data.config_rsp_rcvd.status = status;
      /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
      nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
      return;
    }
  }
  if (!pipeId) {
    /* Invalid pipe ID */
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_handle_Nfcee_dynpipe_rsp - Unknown pipe %d",
                     pipeId);
    if (nfa_hci_cb.type == NFA_HCI_COMMAND_TYPE)
      nfa_hciu_send_msg(pipeId, NFA_HCI_RESPONSE_TYPE, NFA_HCI_ANY_E_NOK, 0,
                        nullptr);
    evt_data.config_rsp_rcvd.status = status;
    /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
    nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
    nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
    return;
  }
  switch (nfa_hci_cb.cmd_sent) {
    case NFA_HCI_ANY_OPEN_PIPE:
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "nfa_hci_handle_Nfcee_dynpipe_rsp - Response received open Pipe get "
          "the Gate List on Id Gate!!!");
      if (!p_pipe) {
        LOG(ERROR) << StringPrintf(
            "nfa_hci_handle_Nfcee_dynpipe_rsp - NULL pipe for PipeId %d",
            pipeId);
        break;
      }
      if ((p_pipe->dest_gate == NFA_HCI_IDENTITY_MANAGEMENT_GATE) &&
          (p_pipe->local_gate == NFA_HCI_IDENTITY_MANAGEMENT_GATE)) {
        p_pipe->pipe_state = NFA_HCI_PIPE_OPENED;
        nfa_hciu_send_get_param_cmd(pipeId, NFA_HCI_GATES_LIST_INDEX);
      }
      break;
    case NFA_HCI_ANY_GET_PARAMETER:
      if (nfa_hci_cb.param_in_use == NFA_HCI_GATES_LIST_INDEX) {
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_Nfcee_dynpipe_rsp - Response received Gate List on "
            "Id Gate!!!");
        if (data_len > 0) {
          wStatus = nfa_hci_api_checkforAPDUGate(p_data, data_len);
          if (wStatus == true) {
             DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
                "nfa_hci_handle_Nfcee_dynpipe_rsp - creating APDU pipee!!!");
            nfa_hciu_alloc_gate(NFA_HCI_ETSI12_APDU_GATE, NFA_HANDLE_GROUP_HCI);
            nfa_hciu_send_create_pipe_cmd(NFA_HCI_ETSI12_APDU_GATE,
                                          nfa_hci_cb.current_nfcee,
                                          NFA_HCI_ETSI12_APDU_GATE);
          } else {
            nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
            evt_data.config_rsp_rcvd.status = NFA_STATUS_OK;
            /* Send NFA_HCI_CMD_SENT_EVT to notify failure */
            nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
          }
        }
      } else if (nfa_hci_cb.param_in_use == NFA_HCI_MAX_C_APDU_SIZE_INDEX) {
        // Read the parameter and save in Non volatile Memory
         DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "nfa_hci_handle_Nfcee_dynpipe_rsp - Read HCI Max Wait time!!!");
        nfa_hciu_send_get_param_cmd(pipeId, NFA_HCI_MAX_WAIT_TIME_INDEX);
      } else if (nfa_hci_cb.param_in_use == NFA_HCI_MAX_WAIT_TIME_INDEX) {
        // Read the parameter and save in Non volatile Memory
        evt_data.admin_rsp_rcvd.status = NFA_STATUS_OK;
        /* Send NFA_HCI_CMD_SENT_EVT to notify success */
        nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
      }
      break;
  }
  if (nfa_hci_cb.type == NFA_HCI_EVENT_TYPE) {
    if (nfa_hci_cb.inst == NFA_HCI_ABORT) {
      // display atr and read first parameter on APDU Gate
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "nfa_hci_handle_Nfcee_dynpipe_rsp - ATR received read APDU Size!!!");
       DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "nfa_hci_handle_Nfcee_dynpipe_rsp - ETSI12 init complete");
      evt_data.admin_rsp_rcvd.status = NFA_STATUS_OK;
      nfa_hci_cb.hci_state = NFA_HCI_STATE_IDLE;
      nfa_hciu_send_to_all_apps(NFA_HCI_CONFIG_DONE_EVT, &evt_data);
    }
  }
}
/*******************************************************************************
**
** Function         nfa_hci_api_IspipePresent
**
** Description      Check if APDU Pipe is already present or needs to created
**
** Returns          None
**
*******************************************************************************/
static bool nfa_hci_api_IspipePresent(uint8_t nfceeId, uint8_t gateId) {
  uint8_t count = 0;
  bool status = false;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_IspipePresent");
  for (count = 0; count < NFA_HCI_MAX_PIPE_CB; count++) {
    if (((nfa_hci_cb.cfg.dyn_pipes[count].dest_host) == nfceeId) &&
        ((nfa_hci_cb.cfg.dyn_pipes[count].dest_gate) == gateId) &&
        ((nfa_hci_cb.cfg.dyn_pipes[count].local_gate) == gateId)) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_IspipePresent -count -- %d !!!", count);
      status = true;
      break;
    }
  }
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_api_GetpipeId
**
** Description      Check if APDU Pipe is already present or needs to created
**
** Returns          None
**
*******************************************************************************/
static bool nfa_hci_api_GetpipeId(uint8_t nfceeId, uint8_t gateId,
                                  uint8_t* pipeId) {
  uint8_t count = 0;
  bool status = false;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_GetpipeId");
  for (count = 0; count < NFA_HCI_MAX_PIPE_CB; count++) {
    if (((nfa_hci_cb.cfg.dyn_pipes[count].dest_host) == nfceeId) &&
        ((nfa_hci_cb.cfg.dyn_pipes[count].dest_gate) == gateId) &&
        ((nfa_hci_cb.cfg.dyn_pipes[count].local_gate) == gateId)) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_api_GetpipeId -count -- %d !!!",
                       nfa_hci_cb.cfg.dyn_pipes[count].pipe_id);
      *pipeId = nfa_hci_cb.cfg.dyn_pipes[count].pipe_id;
      status = true;
      break;
    }
  }
  return status;
}

/*******************************************************************************
**
** Function         nfa_hci_getApduAndConnectivity_PipeStatus
**
** Description      API to retrieve APDU & Connectivity pipe created status from
**                  FirmWare
**
** Returns          If NCI command is SUCCESS/FAILED
**
*******************************************************************************/
tNFA_STATUS nfa_hci_getApduAndConnectivity_PipeStatus()
{
    tNFA_STATUS         status = NFA_STATUS_OK;
    uint8_t p_data[NFA_MAX_HCI_CMD_LEN];
    uint8_t *p = p_data, *parm_len , *num_param;
    memset(p_data, 0, sizeof(p_data));
    NCI_MSG_BLD_HDR0 (p, NCI_MT_CMD, NCI_GID_CORE);
    NCI_MSG_BLD_HDR1 (p, NCI_MSG_CORE_GET_CONFIG);
    parm_len  = p++;
    num_param = p++;
    UINT8_TO_STREAM (p, NXP_NFC_SET_CONFIG_PARAM_EXT);
    UINT8_TO_STREAM (p, NXP_NFC_ESE_APDU_PIPE_STATUS);
    (*num_param)++;
    UINT8_TO_STREAM (p, NXP_NFC_SET_CONFIG_PARAM_EXT);
    UINT8_TO_STREAM (p, NXP_NFC_ESE_CONN_PIPE_STATUS);
    (*num_param)++;

    *parm_len = (p - num_param);
    if(*num_param != 0x00)
    {
        status = nfa_hciu_send_raw_cmd(p-p_data, p_data, nfa_hci_get_pipe_state_cb);
    }
     DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_getApduConnectivity_PipeStatus %x",*num_param);

    return status;
}

/*******************************************************************************
**
** Function         nfa_hci_get_pipe_state_cb
**
** Description      Callback API to retrieve APDU & Connectivity pipe created
**                  status from FirmWare
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_get_pipe_state_cb(__attribute__((unused)) uint8_t event, __attribute__((unused))
                                          uint16_t param_len, uint8_t* p_param) {
    uint8_t num_param_id         = 0x00;
    uint8_t NFA_PARAM_ID_INDEX   = 0x04;
    uint8_t param_id1 = 0x00;
    uint8_t param_id2 = 0x00;
    uint8_t status    = 0x00;

    nfa_sys_stop_timer (&nfa_hci_cb.timer);
    p_param += NFA_PARAM_ID_INDEX;
    STREAM_TO_UINT8(num_param_id , p_param);
    while(num_param_id > 0x00)
    {
        STREAM_TO_UINT8(param_id1 , p_param);
        STREAM_TO_UINT8(param_id2 , p_param);
        p_param++;
        STREAM_TO_UINT8(status    , p_param);
        if(param_id1 == NXP_NFC_SET_CONFIG_PARAM_EXT
                && param_id2 == NXP_NFC_ESE_APDU_PIPE_STATUS)
        {
            /*Update eSE APDU pipe status*/
            if(status == 1)
            {
                /*UINT8 local_gate, UINT8 pipe_id, UINT8 dest_host, UINT8 dest_gate*/
                if(!nfa_hci_api_IspipePresent(NFA_HCI_HOST_ID_ESE, NFA_HCI_ETSI12_APDU_GATE))
                {
                    nfa_hci_update_pipe_status(NFA_HCI_ETSI12_APDU_GATE, NFA_HCI_APDU_PIPE);
                    nfa_hci_cb.IsApduPipeStatusNotCorrect = true;
                    if(nfa_hciu_find_gate_by_gid (NFA_HCI_ETSI12_APDU_GATE) == nullptr)
                    {
                        tNFA_HCI_DYN_GATE   *pg;
                        int                 xx;
                        for (xx = 0, pg = nfa_hci_cb.cfg.dyn_gates; xx < NFA_HCI_MAX_GATE_CB; xx++, pg++)
                        {
                            if (pg->gate_id == 0)
                            {
                                /* Found a free gate control block */
                                pg->gate_id       = NFA_HCI_ETSI12_APDU_GATE;
                                pg->gate_owner    = NFA_HANDLE_GROUP_HCI;
                                pg->pipe_inx_mask = 0;

                                 DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("nfa_hci_alloc_apdu_gate id:%d  app_handle: 0x%04x",
                                NFA_HCI_ETSI12_APDU_GATE, NFA_HANDLE_GROUP_HCI);
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                nfa_hciu_release_pipe (NFA_HCI_APDU_PIPE);
            }
        }
        else if(param_id1 == NXP_NFC_SET_CONFIG_PARAM_EXT
                && param_id2 == NXP_NFC_ESE_CONN_PIPE_STATUS)
        {
            /*Update eSE Connectivity pipe status*/
            if(status == 1)
            {
                if(!nfa_hci_api_IspipePresent(NFA_HCI_HOST_ID_ESE, NFA_HCI_CONNECTIVITY_GATE))
                {
                    nfa_hci_update_pipe_status(NFA_HCI_CONNECTIVITY_GATE, NFA_HCI_CONN_ESE_PIPE);
                }
            }
            else
            {
                nfa_hciu_release_pipe (NFA_HCI_CONN_ESE_PIPE);
            }
        }
        num_param_id--;
    }
}

/*******************************************************************************
**
** Function         nfa_hci_update_pipe_status
**
** Description      API to update APDU & Connectivity pipe hci_cfg status
**
** Returns          None
**
*******************************************************************************/
static void nfa_hci_update_pipe_status(uint8_t gateId, uint8_t pipeId)
{
    uint8_t count = 0;
    nfa_hciu_add_pipe_to_static_gate(gateId, pipeId, NFA_HCI_HOST_ID_ESE, gateId);

    /*Set the pipe status HCI_OPENED*/
    for (count = 0;count < NFA_HCI_MAX_PIPE_CB;count++)
    {
        if(((nfa_hci_cb.cfg.dyn_pipes[count].dest_host) == NFA_HCI_HOST_ID_ESE) &&
        ((nfa_hci_cb.cfg.dyn_pipes[count].dest_gate) == gateId)
        &&((nfa_hci_cb.cfg.dyn_pipes[count].local_gate) == gateId))
        {
             DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("Set the pipe state to open  -- %d !!!",nfa_hci_cb.cfg.dyn_pipes[count].pipe_id);
            nfa_hci_cb.cfg.dyn_pipes[count].pipe_state = NFA_HCI_PIPE_OPENED;
            break;
        }
    }
}
#endif
