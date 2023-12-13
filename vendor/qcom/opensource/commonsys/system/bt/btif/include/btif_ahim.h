/******************************************************************************
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
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
 *
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
 *
 ******************************************************************************/

#pragma once

#include "audio_a2dp_hw/include/audio_a2dp_hw.h"
#include <vendor/qti/hardware/bluetooth_audio/2.0/types.h>
#include "osi/include/thread.h"
#include "btif_av.h"

using vendor::qti::hardware::bluetooth_audio::V2_0::SessionType;
using vendor::qti::hardware::bluetooth_audio::V2_0::SessionParamType;

#define AHIM_ENABLED 1

enum
{
  A2DP = 0x1,
  AUDIO_GROUP_MGR = 0x2,
  BROADCAST = 0x3,
  MAX_CLIENT
};

enum acm_evt{
  BTIF_ACM_PROCESS_HIDL_REQ_EVT = 0x1,
};


typedef void (* ahim_client_cb)(tA2DP_CTRL_CMD cmd);
typedef uint16_t (* ahim_get_sample_rate_callback)(uint8_t direction);
typedef uint8_t (* ahim_get_channel_mode_callback)(uint8_t direction);
typedef uint32_t (* ahim_get_bitrate_callback)(uint8_t direction);
typedef uint32_t (* ahim_get_mtu_callback)(uint32_t bit_rate, uint8_t direction);
typedef uint16_t (* ahim_get_frame_length)(uint8_t direction);
typedef uint8_t (* ahim_get_ch_count_callback)();
typedef bool (* ahim_get_simulcast_status)();
typedef uint16_t (* ahim_get_profile_status)();
typedef bool (* ahim_is_codec_type_lc3q)(uint8_t direction);
typedef uint8_t (* ahim_lc3q_ver)(uint8_t direction);

typedef struct {
    uint8_t mode;
    ahim_client_cb client_cb;
    ahim_get_sample_rate_callback get_sample_rate_cb;
    ahim_get_channel_mode_callback get_channel_mode_cb;
    ahim_get_bitrate_callback get_bitrate_cb;
    ahim_get_mtu_callback get_mtu_cb;
    ahim_get_frame_length get_frame_length_cb;
    ahim_get_ch_count_callback get_ch_count_cb;
    ahim_get_simulcast_status get_simulcast_status_cb;
    ahim_get_profile_status get_profile_status_cb;
    ahim_is_codec_type_lc3q get_is_codec_type_lc3q;
    ahim_lc3q_ver get_lc3q_ver;
}btif_ahim_client_callbacks_t;

extern btif_ahim_client_callbacks_t* pclient_cbs[MAX_CLIENT];

void reg_cb_with_ahim(uint8_t client_id, btif_ahim_client_callbacks_t* pclient_cb);

void btif_ahim_process_request(tA2DP_CTRL_CMD cmd);
void btif_ahim_update_current_profile(uint8_t profile);


bool btif_ahim_init_hal(thread_t *t, uint8_t profile);

void btif_ahim_cleanup_hal();

bool btif_ahim_is_hal_2_0_supported();

bool btif_ahim_is_hal_2_0_enabled();

bool btif_ahim_is_restart_session_needed();

void btif_ahim_update_session_params(SessionParamType param_type);

bool btif_ahim_setup_codec(uint8_t profile);

void btif_ahim_start_session();

void btif_ahim_end_session();

tA2DP_CTRL_CMD btif_ahim_get_pending_command();

void btif_ahim_reset_pending_command(uint8_t profile);

void btif_ahim_update_pending_command(tA2DP_CTRL_CMD cmd, uint8_t profile);

void btif_ahim_ack_stream_started(const tA2DP_CTRL_ACK& ack, uint8_t profile);

void btif_ahim_ack_stream_suspended(const tA2DP_CTRL_ACK& ack, uint8_t profile);

size_t btif_ahim_read(uint8_t* p_buf, uint32_t len);

void btif_ahim_set_remote_delay(uint16_t delay_report);

bool btif_ahim_is_streaming();

SessionType btif_ahim_get_session_type();


