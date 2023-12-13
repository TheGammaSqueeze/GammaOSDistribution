/* st_hw_session_pcm.h
 *
 * Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
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
 */
#include <pthread.h>
#include <tinyalsa/asoundlib.h>
#include <audio_route/audio_route.h>

#include "sound_trigger_platform.h"
#include "st_hw_session.h"
#include "st_common_defs.h"

struct sound_trigger_device;


#define ST_FFV_CONFIG_FILE_NAME "BF_1out.cfg"
#define FFV_LIB_NAME "libffv.so"
#define ESP_LIB_NAME "libesp.so"

#define SOUND_TRIGGER_MAX_EVNT_PAYLOAD_SIZE (256)

#define SOUND_TRIGGER_PCM_MAX_RETRY (10)
#define SOUND_TRIGGER_PCM_SLEEP_WAIT (1000)

#define SOUND_TRIGGER_PCM_PERIOD_COUNT (8)
#define SOUND_TRIGGER_PCM_PERIOD_SIZE \
    ((((SOUND_TRIGGER_SAMPLING_RATE_16000 * SOUND_TRIGGER_PCM_BUFFER_DURATION_MS) \
       /(SOUND_TRIGGER_PCM_PERIOD_COUNT * 1000)) + 0x1f) & ~0x1f)

#define ST_EC_REF_LOOPBACK_DEVICE_MONO "ec-ref-loopback-mono"
#define ST_EC_REF_LOOPBACK_DEVICE_STEREO "ec-ref-loopback-stereo"
#define ST_EC_REF_LOOPBACK_DEVICE_QUAD "ec-ref-loopback-quad"


#define NUM_PROCESS_BUFS 4
#define ST_ESP_FRAME_LENGTH_MS 16

enum det_event_keys {
    KWD_CONFIDENCE_LEVEL = 0x0,
    KWD_INDEX,
    KWD_MAX
};

struct process_buf {
    void *data;
    int length;
    int16_t *in_buf_ptr;
    int16_t *ec_ref_buf_ptr;
    int16_t *out_buf_ptr;
};

struct process_buf_queue {
    struct process_buf_queue *next;
    struct process_buf buffer;
};

struct st_hw_session_pcm {
    st_hw_session_t common;

    void *handle; /* handle to ffv library object */
    void *esp_handle; /* handle to esp library object */

    pthread_t callback_thread;
    bool exit_callback_thread;

    pthread_t capture_thread;
    bool exit_capture_thread;

    int pcm_id;
    struct pcm *pcm;
    struct pcm_config capture_config;
    struct pcm_config out_config;
    struct pcm_config lab_config;

    int ec_ref_pcm_id;
    struct pcm *ec_ref_pcm;
    struct pcm_config ec_ref_config;
    unsigned int ec_ref_use_case_idx;

    bool use_topology_intf;

    struct st_hw_session *transit_ses;

    unsigned char *in_buf; /* buffer received from pcm read */
    unsigned int in_buf_size;

    unsigned char *ec_ref_buf; /* ec ref data received from pcm read */
    unsigned int ec_ref_buf_size;

    unsigned char *split_in_buf; /* in buffer post ec ref split */
    unsigned int split_in_buf_size;

    unsigned char *out_buf; /* ffv library output buffer */
    unsigned int out_buf_size;

    unsigned char *bsp_out_buf; /* ffv library bsp output buffer */
    unsigned int bsp_out_buf_size;

    pthread_mutex_t callback_thread_lock;
    pthread_mutex_t capture_thread_lock;

    bool buffers_allocated;
    bool lab_buffers_allocated;
    size_t read_buf_len;

    /* Buffers used for LAB*/
    unsigned char *lab_cap_buf; /* small buffer to hold one chunk received from library */
    unsigned int lab_cap_buf_size;
    unsigned char *lab_out_buf; /* larger buffer that stores samples pulled from library
                                   this buffer should hold enough samples to handle the
                                   delay from generating the recognition event until
                                   upper layers start pulling data */
    unsigned int lab_out_buf_size;
    unsigned int lab_out_buf_unread_bytes;
    unsigned char *lab_out_buf_start_ptr;
    unsigned char *lab_out_buf_end_ptr;
    unsigned char *lab_out_buf_wr_ptr;
    unsigned char *lab_out_buf_rd_ptr;
    pthread_cond_t lab_out_buf_cond;
    pthread_mutex_t lab_out_buf_lock;

    bool exit_lab_processing;

    struct listnode ev_list;
    pthread_cond_t ev_cond;

    pthread_t st_ffv_process_thread;
    pthread_mutex_t st_ffv_process_lock;
    bool exit_st_ffv_process_thread;
    bool st_ffv_process_thread_started;
    pthread_cond_t st_ffv_process_cond;
    pthread_cond_t st_ffv_capture_cond;
    void *process_buf_data;
    struct process_buf_queue *process_buf_free;
    struct process_buf_queue *process_buf;
    struct process_buf_queue process_buf_nodes[NUM_PROCESS_BUFS];

    char *ec_ref_dev_name;
    bool session_restart_done;
    bool capture_thread_started;
};

typedef struct st_hw_session_pcm st_hw_session_pcm_t;

#ifdef ST_ARM_ENABLED
int st_hw_sess_pcm_init(st_hw_session_t *const p_ses,
   hw_ses_event_callback_t cb, void *cookie, st_exec_mode_t exec_mode,
   struct st_vendor_info *v_info, sound_model_handle_t sm_handle,
   struct sound_trigger_device *stdev);
void st_hw_sess_pcm_deinit(st_hw_session_t *const p_ses);
int st_hw_pcm_init(void);
void st_hw_pcm_deinit(void);
#else
#define st_hw_sess_pcm_init(p_ses, cb, cookie, exec_mode, v_info, \
                            sm_handle, stdev) (0)
#define st_hw_sess_pcm_deinit(p_ses) (0)
#define st_hw_pcm_init() (0)
#define st_hw_pcm_deinit() (0)
#endif
