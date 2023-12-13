/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EATT_INT_H
#define EATT_INT_H

#include "bt_target.h"

#include "btm_ble_api.h"
#include "btu.h"
#include "gatt_api.h"
#include "gatt_int.h"
#include "osi/include/fixed_queue.h"

#include <base/strings/stringprintf.h>
#include <string.h>
#include <list>
#include <unordered_set>
#include <vector>

extern tGATT_EBCB* gatt_eatt_bcb_alloc(tGATT_TCB* p_tcb, uint16_t lcid, bool create_in_prg, bool is_remote_initiated);
extern tGATT_EBCB* gatt_find_eatt_bcb_by_cid(tGATT_TCB* p_tcb, uint16_t lcid);
extern tGATT_EBCB* gatt_find_eatt_bcb_by_srv_trans_id(uint32_t trans_id, const RawAddress& bda);
extern tGATT_EBCB* gatt_find_eatt_bcb_by_cl_trans_id(uint32_t trans_id, const RawAddress& bda);
extern tGATT_EBCB* gatt_find_eatt_bcb_by_gatt_if(uint8_t gatt_if, const RawAddress& bda);
extern tGATT_EBCB* gatt_find_eatt_bcb_by_cid_in_progress(RawAddress bda, uint16_t lcid);
extern uint8_t gatt_eatt_bcb_in_progress_dealloc(RawAddress& bda);
extern bool gatt_eatt_bcb_dealloc(tGATT_TCB* p_tcb, uint16_t lcid);
extern tGATT_EBCB* gatt_find_best_eatt_bcb(tGATT_TCB* p_tcb, tGATT_IF gatt_if, uint16_t old_cid, bool opportunistic);
extern uint8_t gatt_num_eatt_bcbs_in_progress(tGATT_TCB* p_tcb);
extern uint16_t gatt_get_payload_size(tGATT_TCB* p_tcb, uint16_t lcid);
extern void gatt_remove_conn(uint16_t conn_id, uint16_t lcid);
extern bool is_gatt_conn_found(uint16_t conn_id, uint16_t lcid);
extern void gatt_add_conn(uint16_t conn_id, uint16_t lcid);
extern bool is_gatt_conn_id_found(uint16_t conn_id);
extern uint16_t gatt_get_cid_by_conn_id(uint16_t conn_id);
extern bool gatt_apps_need_eatt(tGATT_TCB* p_tcb);
extern void gatt_upgrade_conn(tGATT_TCB* p_tcb);
extern uint8_t gatt_num_eatt_bcbs(tGATT_TCB* p_tcb);
extern void gatt_move_apps(tGATT_TCB* p_tcb, uint16_t lcid);
extern void gatt_add_eatt_device(RawAddress bda);
extern bool is_eatt_device(RawAddress bda);
extern uint8_t gatt_remove_app_on_lcid(uint16_t lcid, tGATT_IF gatt_if);
extern void gatt_remove_conns_by_cid(tGATT_TCB* p_tcb, uint16_t lcid);
extern void eatt_cleanup_upon_disc(const RawAddress& bda);
extern void gatt_send_pending_ind(tGATT_TCB& tcb, uint16_t lcid);
extern void gatt_send_pending_notif(tGATT_TCB& tcb, uint16_t lcid);
extern void gatt_send_pending_rsp(tGATT_TCB& tcb, uint16_t cid);
extern void gatt_send_pending_disc_rsp(tGATT_TCB& tcb, uint16_t cid);
extern void gatt_notif_enq(tGATT_TCB* p_tcb, uint16_t cid, tGATT_VALUE* p_notif);
extern void gatt_rsp_enq(tGATT_TCB* p_tcb, uint16_t cid, tGATT_PEND_RSP* p_rsp);
extern void eatt_disc_rsp_enq(tGATT_TCB* p_tcb, uint16_t cid, BT_HDR *p_msg);
extern bool eatt_congest_notify_apps(tGATT_TCB* p_tcb, uint16_t cid, bool congested);
extern tGATT_EBCB* gatt_find_eatt_bcb_using_all_cids(uint16_t lcid);

#endif
