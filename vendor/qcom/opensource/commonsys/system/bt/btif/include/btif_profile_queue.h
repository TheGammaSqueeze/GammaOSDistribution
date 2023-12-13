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

/*******************************************************************************
 *
 *  Filename:      btif_profile_queue.h
 *
 *  Description:   Bluetooth remote device connection queuing
 *
 ******************************************************************************/

#ifndef BTIF_PROFILE_QUEUE_H
#define BTIF_PROFILE_QUEUE_H

#include <hardware/bluetooth.h>

typedef bt_status_t (*btif_connect_cb_t)(RawAddress* bda, uint16_t uuid);

bt_status_t btif_queue_connect(uint16_t uuid, const RawAddress& bda,
                               btif_connect_cb_t connect_cb, uint16_t max_connections);
void btif_queue_cleanup(uint16_t uuid);
void btif_queue_advance();
void btif_queue_advance_by_uuid(uint16_t uuid, const RawAddress* bda);
bt_status_t btif_queue_connect_next(void);
void btif_queue_release();


typedef bt_status_t (*btif_disconnect_cb_t)(RawAddress* bda, uint16_t uuid);
bt_status_t btif_disconnect_queue_disconnect(uint16_t uuid, const RawAddress& bda,
                                             btif_disconnect_cb_t disconnect_cb);
void btif_disconnect_queue_cleanup(uint16_t uuid);
void btif_disconnect_queue_advance(const RawAddress* bda);
void btif_disconnect_queue_advance_by_uuid(uint16_t uuid, const RawAddress* bda);
bt_status_t btif_disconnect_queue_disconnect_next(void);
void btif_disconnect_queue_release();

#endif
