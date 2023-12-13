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

#include "audio_hal_interface/a2dp_encoding.h"

#if AHIM_ENABLED

uint8_t cur_active_profile = A2DP;

btif_ahim_client_callbacks_t* pclient_cbs[MAX_CLIENT] = {NULL};

void reg_cb_with_ahim(uint8_t client_id, btif_ahim_client_callbacks_t* pclient_cb)
{
  BTIF_TRACE_IMP("%s, registering callback for client id %u with AHIM", __func__, client_id);
  // No need to register call back for A2DP.
   if (client_id <= A2DP|| client_id >= MAX_CLIENT)
   {
      // invalid call back registration. return.
      BTIF_TRACE_ERROR("%s, invalid client id %u", __func__, client_id);
      return;
   }

   pclient_cbs[client_id - 1] = pclient_cb;
}

void btif_ahim_update_current_profile(uint8_t profile)
{
  switch(profile)
  {
     case A2DP:
       FALLTHROUGH;
     case AUDIO_GROUP_MGR:
       FALLTHROUGH;
     case BROADCAST:
       cur_active_profile = profile;
       break;
     default:
       BTIF_TRACE_WARNING("%s, unsupported active profile, resetting to A2DP"
                          , __func__);
       cur_active_profile = A2DP;
       break;
  }

  BTIF_TRACE_IMP("%s: current active profile is %u", __func__, cur_active_profile);
}

void btif_ahim_process_request(tA2DP_CTRL_CMD cmd)
{
  switch(cur_active_profile)
  {
    case A2DP:
      BTIF_TRACE_IMP("%s: sending HIDL request to AV", __func__);
      btif_dispatch_sm_event(BTIF_AV_PROCESS_HIDL_REQ_EVT, (char*)&cmd, sizeof(cmd));
      break;
    case AUDIO_GROUP_MGR:
      BTIF_TRACE_IMP("%s: sending HIDL request to Audio Group Manager", __func__);
      if (pclient_cbs[cur_active_profile - 1] && pclient_cbs[cur_active_profile - 1]->client_cb) {
        BTIF_TRACE_IMP("%s: calling call back for Audio Group Manager", __func__);
        pclient_cbs[cur_active_profile - 1]->client_cb(cmd);
      }
      else
        BTIF_TRACE_ERROR("%s, Audio Group Manager is not registered with AHIM", __func__);
      break;
    case BROADCAST:
      BTIF_TRACE_IMP("%s: sending HIDL request to BROADCAST", __func__);
      if (pclient_cbs[cur_active_profile - 1] && pclient_cbs[cur_active_profile - 1]->client_cb) {
        BTIF_TRACE_IMP("%s: calling call back for BROADCAST", __func__);
        pclient_cbs[cur_active_profile - 1]->client_cb(cmd);
      }
      else
        BTIF_TRACE_ERROR("%s, BROADCAST is not registered with AHIM", __func__);
      break;
  }
}

bool btif_ahim_init_hal(thread_t *t, uint8_t profile) {
  return bluetooth::audio::a2dp::init(t, profile);
}

void btif_ahim_cleanup_hal() {
  bluetooth::audio::a2dp::cleanup();
}

bool btif_ahim_is_hal_2_0_supported() {
  return bluetooth::audio::a2dp::is_hal_2_0_supported();
}

bool btif_ahim_is_hal_2_0_enabled() {
  return bluetooth::audio::a2dp::is_hal_2_0_enabled();
}

bool btif_ahim_is_restart_session_needed() {
  return bluetooth::audio::a2dp::is_restart_session_needed();
}

void btif_ahim_update_session_params(SessionParamType param_type) {
  bluetooth::audio::a2dp::update_session_params(param_type);
}

bool btif_ahim_setup_codec(uint8_t profile) {
  return bluetooth::audio::a2dp::setup_codec(profile);
}

void btif_ahim_start_session() {
  bluetooth::audio::a2dp::start_session();
}

void btif_ahim_end_session() {
  bluetooth::audio::a2dp::end_session();
}

tA2DP_CTRL_CMD btif_ahim_get_pending_command() {
  return bluetooth::audio::a2dp::get_pending_command();
}

void btif_ahim_reset_pending_command(uint8_t profile) {
  if (cur_active_profile == profile)
    bluetooth::audio::a2dp::reset_pending_command();
  else
    BTIF_TRACE_WARNING("%s, reset pending cmd ignored from inactive profile", __func__);
}

void btif_ahim_update_pending_command(tA2DP_CTRL_CMD cmd, uint8_t profile) {
  if (cur_active_profile == profile)
    bluetooth::audio::a2dp::update_pending_command(cmd);
  else
    BTIF_TRACE_WARNING("%s, update pending cmd ignored from inactive profile", __func__);
}

void btif_ahim_ack_stream_started(const tA2DP_CTRL_ACK& ack, uint8_t profile) {
  if (cur_active_profile == profile)
    bluetooth::audio::a2dp::ack_stream_started(ack);
  else
    BTIF_TRACE_WARNING("%s, ACK ignored from inactive profile", __func__);
}

void btif_ahim_ack_stream_suspended(const tA2DP_CTRL_ACK& ack, uint8_t profile) {
  if (cur_active_profile == profile)
    bluetooth::audio::a2dp::ack_stream_suspended(ack);
  else
    BTIF_TRACE_WARNING("%s, ACK ignored from inactive profile", __func__);
}

size_t btif_ahim_read(uint8_t* p_buf, uint32_t len) {
  return bluetooth::audio::a2dp::read(p_buf, len);
}

void btif_ahim_set_remote_delay(uint16_t delay_report) {
  bluetooth::audio::a2dp::set_remote_delay(delay_report);
}

bool btif_ahim_is_streaming() {
  return bluetooth::audio::a2dp::is_streaming();
}


SessionType btif_ahim_get_session_type() {
  return bluetooth::audio::a2dp::get_session_type();
}

#endif // #if AHIM_ENABLED
