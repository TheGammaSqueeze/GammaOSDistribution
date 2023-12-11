/* st_hw_session_pcm.c
 *
 * This file implements the hw session functionality of SVA using capture path
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

#define LOG_TAG "sound_trigger_hw"
/* #define LOG_NDEBUG 0 */
#define LOG_NDDEBUG 0

#include <errno.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <sched.h>
#include <sys/resource.h>
#include <sys/prctl.h>
#include <sys/ioctl.h>
#include <cutils/log.h>
#include <cutils/atomic.h>
#include <system/thread_defs.h>

#include <stdarg.h>
#include <unistd.h>

#include "st_common_defs.h"
#include "sound_trigger_platform.h"
#include "st_hw_session_pcm.h"
#include "sound_trigger_hw.h"
#include "ffv_interface.h"
#include "esp_api.h"

/* uncomment if process buffers need to be queued */
//#define QUEUE_PROCESS_BUFFERS

typedef struct {
    struct listnode node;
    FfvEventType event_type;
    void *ev_payload;
} callback_event_t;

typedef union {
    ffv_history_buffer_length_param_t buffer_length_params;
    ffv_src_tracking_param_t src_tracking_params;
    ffv_target_channel_index_param_t ch_index_params;
    esp_energy_levels_t esp_energy_levels_params;
} st_get_param_payload_t;

static int reg_sm(st_hw_session_t* p_ses, void *sm_data,
    unsigned int sm_size, uint32_t model_id);
static int reg_sm_params(st_hw_session_t* p_ses, unsigned int recognition_mode,
    bool capture_requested, struct sound_trigger_recognition_config *rc_config);

static int dereg_sm(st_hw_session_t* p_ses,uint32_t model_id __unused);
static int dereg_sm_params(st_hw_session_t* p_ses);
static int start(st_hw_session_t* p_ses);
static int stop(st_hw_session_t* p_ses);
static int stop_buffering(st_hw_session_t* p_ses);
static int set_device(st_hw_session_t *p_ses,
    bool enable);
static int disable_device(st_hw_session_t *p_ses, bool setting_device);
static int enable_device(st_hw_session_t *p_ses, bool setting_device);
static void process_lab_capture(st_hw_session_t *p_ses);
static int restart(st_hw_session_t* p_ses, unsigned int recognition_mode,
    struct sound_trigger_recognition_config *rc_config __unused);
static int read_pcm(st_hw_session_t *p_ses,
    unsigned char *buf,
    unsigned int bytes);
static int allocate_buffers(st_hw_session_pcm_t* p_ses);
static int deallocate_buffers(st_hw_session_pcm_t* p_ses);
static int get_param_data(st_hw_session_t* p_ses, const char *param,
    void *payload, size_t payload_size, size_t *param_data_size);
static void st_event_callback(void *cb_data, void *handle, FfvEventType event_type,
                              void *event_payload, size_t event_payload_size);

static FfvStatusType (*ffv_init_fn)(void** handle, int num_tx_in_ch,
    int num_out_ch, int num_ec_ref_ch, int frame_len, int sample_rate,
    const char *config_file_name, char *svaModelBuffer,
    uint32_t svaModelSize, int* totMemSize, int product_id, const char* license);
static void (*ffv_deinit_fn)(void* handle);
static void (*ffv_process_fn)(void *handle, const int16_t *in_pcm,
    int16_t *out_pcm, const int16_t *ec_ref_pcm);
static void (*ffv_process_v2_fn)(void *handle, const int16_t *in_pcm,
    int16_t *out_pcm, int16_t *bsp_out_pcm, const int16_t *ec_ref_pcm);
static int (*ffv_read_fn)(void* handle, int16_t *buf_pcm,
    int max_buf_len);
static FfvStatusType (*ffv_get_param_fn)(void *handle, char *params_buffer_ptr,
    int param_id, int buffer_size, int *param_size_ptr);
static FfvStatusType (*ffv_set_param_fn)(void *handle, char *params_buffer_ptr,
    int param_id, int param_size);
static FfvStatusType (*ffv_register_event_callback_fn)(void *handle,
    ffv_event_callback_fn_t fun_ptr, void *cb_data);

static EspStatusType (*esp_init_fn)(void **handle, int frame_len_ms,
    int sample_rate, int* totMemSize);
static void (*esp_deinit_fn)(void *handle);
static void (*esp_process_fn)(void *handle, const int16 *in_pcm);
static EspStatusType (*esp_get_param_fn)(void *handle, char *params_buffer_ptr,
    int param_id, int buffer_size, int *param_size_ptr);
static int send_detection_request(st_hw_session_t *p_ses __unused);

static struct pcm_config stdev_arm_pcm_config = {
    .channels = SOUND_TRIGGER_CHANNEL_MODE_MONO,
    .rate = SOUND_TRIGGER_SAMPLING_RATE_16000,
    .period_size = SOUND_TRIGGER_PCM_PERIOD_SIZE,
    .period_count = SOUND_TRIGGER_PCM_PERIOD_COUNT,
    .format = PCM_FORMAT_S16_LE,
};

struct st_session_fptrs pcm_fptrs = {
    .reg_sm = reg_sm,
    .reg_sm_params = reg_sm_params,
    .dereg_sm = dereg_sm,
    .dereg_sm_params = dereg_sm_params,
    .start = start,
    .restart = restart,
    .stop = stop,
    .stop_buffering = stop_buffering,
    .set_device = set_device,
    .read_pcm = read_pcm,
    .process_lab_capture = process_lab_capture,
    .disable_device = disable_device,
    .enable_device = enable_device,
    .get_param_data = get_param_data,
    .send_detection_request = send_detection_request,
};

struct st_hw_pcm_data {
    void *ffv_lib_handle;
    void *esp_lib_handle;
};

static struct st_hw_pcm_data pcm_data = {.ffv_lib_handle = NULL, .esp_lib_handle = NULL};

#if LINUX_ENABLED
#define restart_session(p_ses) (0)
#else
/*
 * While running FFV with barge-in usecase, there is a timestamp
 * discontinuity observed in one of the sessions (capture/EC capture)
 * randomly. So encoder is dropping data which has timestamp discontinuity
 * in one of the sessions. This leads to EC convergence issue where one of
 * the sessions has old data and other has new data which is leading to
 * zero detections.
 * Restart both the sessions once, to flush out the data after setting up
 * FFV session to fix the issue.
 */
static int restart_session(st_hw_session_t* p_ses)
{
    int status = 0;
    status = stop(p_ses);
    if (status) {
        ALOGE("%s: failed to stop err %d", __func__, status);
        goto exit;
    }

    status = start(p_ses);
    if (status)
        ALOGE("%s: failed to start err %d", __func__, status);

exit:
    return status;
}
#endif

#ifndef SOUND_TRIGGER_CPU_AFFINITY_SET
#define st_cpu_affinity_set(p_pcm_ses) (0)
#else
/* affine soundtrigger thread to CPU core one */
static void st_cpu_affinity_set(st_hw_session_pcm_t *p_pcm_ses)
{
    cpu_set_t cpuset;
    struct sched_param sched_param;
    int policy = SCHED_FIFO, rc = 0;

    ALOGV("%s: Set CPU affinity for SVA thread, pcm_ses %p", __func__, p_pcm_ses);
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
#ifdef LINUX_ENABLED
    if (pthread_setaffinity_np(p_pcm_ses->capture_thread, sizeof(cpuset),
        &cpuset) != 0)
#else
    if (sched_setaffinity(0, sizeof(cpuset), &cpuset) != 0)
#endif
        ALOGE("%s: CPU Affinity allocation failed for Capture thread",
               __func__);

    sched_param.sched_priority = sched_get_priority_min(policy);
    rc = sched_setscheduler(0, policy, &sched_param);
    if (rc != 0)
         ALOGE("%s: Failed to set realtime priority", __func__);
}
#endif

static void get_lib_path(char * lib_path, int path_size)
{
#ifdef LINUX_ENABLED
#ifdef __LP64__
    /* libs are stored in /usr/lib64 */
    snprintf(lib_path, path_size, "%s", "/usr/lib64");
#else
    /* libs are stored in /usr/lib */
    snprintf(lib_path, path_size, "%s", "/usr/lib");
#endif
#else
#ifdef __LP64__
    /* libs are stored in /vendor/lib64 */
    snprintf(lib_path, path_size, "%s", "/vendor/lib64");
#else
    /* libs are stored in /vendor/lib */
    snprintf(lib_path, path_size, "%s", "/vendor/lib");
#endif
#endif
}

static size_t get_ffv_read_buffer_len(st_hw_session_pcm_t *p_ses)
{
    st_get_param_payload_t *params_buffer_ptr;
    int param_id, buffer_size, param_size;
    size_t buf_size = 0;
    FfvStatusType status_type;

    buffer_size = sizeof(st_get_param_payload_t);
    params_buffer_ptr = (st_get_param_payload_t *)calloc(1, buffer_size);
    if (!params_buffer_ptr) {
        ALOGE("%s: ERROR. Can not allocate buffer size %d", __func__, buffer_size);
        goto exit;
    }
    param_id = FFV_HISTORY_BUFFER_LENGTH_PARAM;
    status_type = ffv_get_param_fn(p_ses->handle, (char *)params_buffer_ptr,
                     param_id, buffer_size, &param_size);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_get_param_fn ret %d", __func__, status_type);
        goto exit;
    }
    if (param_size != sizeof(ffv_history_buffer_length_param_t)) {
        ALOGE("%s: ERROR. Invalid param size returned %d", __func__, param_size);
        goto exit;
    }
    buf_size = params_buffer_ptr->buffer_length_params.bufSize;

exit:
    ALOGD("%s: read buffer len %zu", __func__, buf_size);
    return buf_size;
}

static int check_and_set_ec_ref_device(st_hw_session_t *p_ses, bool enable)
{
    char st_device_name[DEVICE_NAME_MAX_SIZE];
    struct st_vendor_info* v_info = p_ses->vendor_uuid_info;
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;
    FfvStatusType status_type;
    ffv_quadrx_use_dwnmix_param_t quad_downmix;


    if (v_info->split_ec_ref_data) {
        ALOGV("%s: Ignore ec ref set device %p", __func__, p_ses);
        return 0;
    }

    if (enable) {
        if (v_info->ec_ref_channel_cnt == SOUND_TRIGGER_CHANNEL_MODE_MONO) {
            strlcpy(st_device_name, ST_EC_REF_LOOPBACK_DEVICE_MONO,
                    DEVICE_NAME_MAX_SIZE);
        } else if (v_info->ec_ref_channel_cnt == SOUND_TRIGGER_CHANNEL_MODE_STEREO) {
                strlcpy(st_device_name, ST_EC_REF_LOOPBACK_DEVICE_STEREO,
                    DEVICE_NAME_MAX_SIZE);
    } else if (v_info->ec_ref_channel_cnt == SOUND_TRIGGER_CHANNEL_MODE_QUAD) {
            strlcpy(st_device_name, ST_EC_REF_LOOPBACK_DEVICE_QUAD,
                    DEVICE_NAME_MAX_SIZE);
            quad_downmix.quadrx_dwnmix_enable = true;
            ALOGD("set param for 4 ch ec");
            status_type = ffv_set_param_fn(p_pcm_ses->handle,
                            (char *)&quad_downmix,
                            FFV_QUADRX_USE_DWNMIX_PARAM,
                            sizeof(ffv_quadrx_use_dwnmix_param_t));
            if (status_type) {
                ALOGE("%s: ERROR. ffv_set_param_fn for quad channel ec ref %d",
                    __func__, status_type);
                return -EINVAL;
            }
        } else {
            ALOGE("%s: Invalid ec ref channel count %d",
                   __func__, v_info->ec_ref_channel_cnt);
            return -EINVAL;
        }

        if (platform_stdev_compare_device_type(p_ses->stdev->ec_ref_dev,
            AUDIO_DEVICE_OUT_LINE))
            strlcat(st_device_name, " lineout",  DEVICE_NAME_MAX_SIZE);

        ALOGD("%s: enable device = %s", __func__,
                st_device_name);
        audio_route_apply_and_update_path(p_ses->stdev->audio_route,
                                          st_device_name);
        p_pcm_ses->ec_ref_dev_name = strdup(st_device_name);
    } else {
        if (!p_pcm_ses->ec_ref_dev_name) {
            ALOGE("%s: Invalid ec ref device name", __func__);
            return -EINVAL;
        }
        ALOGD("%s: disable device  = %s", __func__,
               p_pcm_ses->ec_ref_dev_name);
        audio_route_reset_and_update_path(p_ses->stdev->audio_route,
                                          p_pcm_ses->ec_ref_dev_name);
        free(p_pcm_ses->ec_ref_dev_name);
        p_pcm_ses->ec_ref_dev_name = NULL;
    }

    return 0;
}

static int check_and_start_ec_ref_ses(st_hw_session_t *p_ses, bool start)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;
    int status = 0;
    int retry_num = 0;

    if (p_ses->vendor_uuid_info->split_ec_ref_data) {
        ALOGV("%s:[%d] Ignore ec ref start", __func__, p_pcm_ses->common.sm_handle);
        return status;
    }

    if (!p_pcm_ses->ec_ref_pcm) {
        ALOGW("%s: ec ref pcm NULL", __func__);
        return status;
    }

    if (start) {
        status = pcm_start(p_pcm_ses->ec_ref_pcm);
        while (status && (retry_num < SOUND_TRIGGER_PCM_MAX_RETRY)) {
               usleep(SOUND_TRIGGER_PCM_SLEEP_WAIT);
               retry_num++;
               ALOGI("%s: pcm_start retrying..status %d errno %d, retry cnt %d",
                      __func__, status, errno, retry_num);
               status = pcm_start(p_pcm_ses->ec_ref_pcm);
        }
        if (status) {
            ALOGE("%s: ERROR. pcm_start failed, returned status %d, err=%s",
                   __func__, status, pcm_get_error(p_pcm_ses->ec_ref_pcm));
        }
        ALOGD("%s: ec ref session started", __func__);
    } else {
        pcm_stop(p_pcm_ses->ec_ref_pcm);
    }

    return status;
}

static int check_and_enable_ec_ref_use_case(bool enable, st_hw_session_t *p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;
    char use_case[USECASE_STRING_SIZE];
    audio_devices_t capture_device;
    int status = 0;

    if (p_ses->vendor_uuid_info->split_ec_ref_data) {
        ALOGV("%s:[%d] Ignore ec ref enable usecase", __func__, p_pcm_ses->common.sm_handle);
        return status;
    }

    strlcpy(use_case,
            p_ses->stdev->arm_pcm_use_cases[p_pcm_ses->ec_ref_use_case_idx].use_case,
            USECASE_STRING_SIZE);

    if (enable) {
        ALOGD("%s: enable use case = %s", __func__, use_case);
        audio_route_apply_and_update_path(p_ses->stdev->audio_route, use_case);
        /* send device calibration for ec ref session */
        capture_device = platform_stdev_get_capture_device(p_ses->stdev->platform);
        platform_stdev_send_calibration(p_ses->stdev->platform,
                capture_device,
                p_ses->exec_mode,
                p_ses->vendor_uuid_info,
                SOUND_TRIGGER_DEVICE_DEFAULT_APP_TYPE,
                false, ST_DEVICE_CAL);
        status = pcm_prepare(p_pcm_ses->ec_ref_pcm);
        if (status < 0) {
            ALOGE("%s: pcm_prepare returned %s", __func__,
                   pcm_get_error(p_pcm_ses->ec_ref_pcm));
            return status;
        }
    } else {
        ALOGD("%s: disable use case = %s", __func__, use_case);
        audio_route_reset_and_update_path(p_ses->stdev->audio_route, use_case);
    }

    return status;
}

static int enable_use_case(bool enable, st_hw_session_t *p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;
    char use_case[USECASE_STRING_SIZE];
    int status = 0;

    strlcpy(use_case,
            p_ses->stdev->arm_pcm_use_cases[p_ses->use_case_idx].use_case,
            USECASE_STRING_SIZE);

    if (enable) {
        ALOGD("%s: enable use case = %s", __func__, use_case);
        audio_route_apply_and_update_path(p_ses->stdev->audio_route, use_case);
        status = pcm_prepare(p_pcm_ses->pcm);
        if (status < 0) {
            ALOGE("%s: pcm_prepare returned %s", __func__,
                   pcm_get_error(p_pcm_ses->pcm));
            return status;
        }
    } else {
        ALOGD("%s: disable use case = %s", __func__, use_case);
        audio_route_reset_and_update_path(p_ses->stdev->audio_route, use_case);
    }

    return status;
}

#ifdef QUEUE_PROCESS_BUFFERS
static void process_buf_queue_push(struct process_buf_queue **queue,
                                  struct process_buf_queue *node)
{
    struct process_buf_queue *iter;

    node->next = NULL;
    if ((*queue) == NULL) {
        *queue = node;
    } else {
        iter = *queue;
        while (iter->next) {
            iter = iter->next;
        }
        iter->next = node;
    }
}

static struct process_buf_queue *process_buf_queue_pop(struct process_buf_queue **queue)
{
    struct process_buf_queue *node = (*queue);

    if (node != NULL) {
        *queue = node->next;
        node->next = NULL;
    }

    return node;
}

static int init_process_buffers(st_hw_session_pcm_t *p_pcm_ses)
{
    unsigned int data_size, in_buf_size, i;
    bool split_ec_ref_data = p_pcm_ses->common.vendor_uuid_info->split_ec_ref_data;

    in_buf_size = split_ec_ref_data ? p_pcm_ses->split_in_buf_size : p_pcm_ses->in_buf_size;
    data_size = in_buf_size + p_pcm_ses->ec_ref_buf_size + p_pcm_ses->out_buf_size;

    p_pcm_ses->process_buf_data = (void *)calloc(data_size, NUM_PROCESS_BUFS);
    if (p_pcm_ses->process_buf_data == NULL) {
        ALOGE("%s: failed to allocate process buf data %d", __func__, data_size);
        return -ENOMEM;
    }

    p_pcm_ses->process_buf = NULL;
    p_pcm_ses->process_buf_free = NULL;

    for (i = 0; i < NUM_PROCESS_BUFS; i++) {
        struct process_buf_queue *buf = &p_pcm_ses->process_buf_nodes[i];
        buf->buffer.data = &(((char *)p_pcm_ses->process_buf_data)[i * data_size]);
        buf->buffer.length = data_size;
        buf->buffer.in_buf_ptr = (int16_t *)buf->buffer.data;
        buf->buffer.ec_ref_buf_ptr = (int16_t *) ((char *)buf->buffer.data + in_buf_size);
        buf->buffer.out_buf_ptr = (int16_t *)((char *)buf->buffer.data + p_pcm_ses->ec_ref_buf_size);
        process_buf_queue_push(&p_pcm_ses->process_buf_free, buf);
    }

    return 0;
}

static int deinit_process_buffers(st_hw_session_pcm_t *p_pcm_ses)
{
    if(p_pcm_ses->process_buf_data != NULL)
       free(p_pcm_ses->process_buf_data);
    p_pcm_ses->process_buf_data = NULL;
    p_pcm_ses->process_buf = NULL;
    p_pcm_ses->process_buf_free = NULL;
}

static void *st_ffv_process_thread_loop(void *context)
{
    st_hw_session_pcm_t *p_pcm_ses =
                                 (st_hw_session_pcm_t *)context;
    bool split_ec_ref_data = p_pcm_ses->common.vendor_uuid_info->split_ec_ref_data;
    unsigned int in_buf_size =
        split_ec_ref_data ? p_pcm_ses->split_in_buf_size : p_pcm_ses->in_buf_size;
    struct process_buf_queue *p_buf;

    if (p_pcm_ses == NULL) {
        ALOGE("%s: ERROR: invalid context", __func__);
        return NULL;
    }

    if (p_pcm_ses->common.stdev->enable_debug_dumps) {
        ST_DBG_DECLARE(FILE *fptr_cap = NULL; static int file_cnt = 0);
        ST_DBG_FILE_OPEN_WR(fptr_cap, ST_DEBUG_DUMP_LOCATION,
                            "ffv_capture_data", "pcm", file_cnt++);

        ST_DBG_DECLARE(FILE *fptr_ec = NULL; static int file_cnt_2 = 0);
        ST_DBG_FILE_OPEN_WR(fptr_ec, ST_DEBUG_DUMP_LOCATION,
                            "ffv_ec_ref_data", "pcm", file_cnt_2++);

        ST_DBG_DECLARE(FILE *fptr_out = NULL; static int file_cnt_3 = 0);
        ST_DBG_FILE_OPEN_WR(fptr_out, ST_DEBUG_DUMP_LOCATION,
                            "ffv_out_data", "pcm", file_cnt_3++);
    }

    setpriority(PRIO_PROCESS, 0, ANDROID_PRIORITY_AUDIO);
    prctl(PR_SET_NAME, (unsigned long)"sound trigger process", 0, 0, 0);

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    pthread_mutex_lock(&p_pcm_ses->st_ffv_process_lock);
    init_process_buffers(p_pcm_ses);
    while (!p_pcm_ses->exit_st_ffv_process_thread) {
        struct process_buf_queue *p_buf;
        int16_t *process_in_ptr, *process_out_ptr, *process_ec_ref_ptr;
        if (p_pcm_ses->process_buf == NULL) {
            ALOGV("%s: waiting for buffer", __func__);
            pthread_cond_wait(&p_pcm_ses->st_ffv_process_cond,
                              &p_pcm_ses->st_ffv_process_lock);
        }
        if (p_pcm_ses->exit_st_ffv_process_thread)
            break;
        p_buf = process_buf_queue_pop(&p_pcm_ses->process_buf);
        pthread_mutex_unlock(&p_pcm_ses->st_ffv_process_lock);
        process_in_ptr = p_buf->buffer.in_buf_ptr;
        process_ec_ref_ptr = p_buf->buffer.ec_ref_buf_ptr;
        process_out_ptr = p_buf->buffer.out_buf_ptr;

        if (p_pcm_ses->common.stdev->enable_debug_dumps) {
            ST_DBG_FILE_WRITE(fptr_cap, process_in_ptr, in_buf_size);
            ST_DBG_FILE_WRITE(fptr_ec, process_ec_ref_ptr,
                              p_pcm_ses->ec_ref_buf_size);
        }
        ffv_process_fn(p_pcm_ses->handle, process_in_ptr,
            process_out_ptr, process_ec_ref_ptr);
        if (p_pcm_ses->common.stdev->enable_debug_dumps) {
            ST_DBG_FILE_WRITE(fptr_out, process_out_ptr,
                              p_pcm_ses->out_buf_size);
        }
        pthread_mutex_lock(&p_pcm_ses->st_ffv_process_lock);
        process_buf_queue_push(&p_pcm_ses->process_buf_free, p_buf);
        pthread_cond_signal(&p_pcm_ses->st_ffv_capture_cond);
    }

exit:
    p_pcm_ses->st_ffv_process_thread_started = false;
    deinit_process_buffers(p_pcm_ses);
    pthread_mutex_unlock(&p_pcm_ses->st_ffv_process_lock);
    if (p_pcm_ses->common.stdev->enable_debug_dumps) {
        ST_DBG_FILE_CLOSE(fptr_cap);
        ST_DBG_FILE_CLOSE(fptr_ec);
        ST_DBG_FILE_CLOSE(fptr_out);
    }
    ALOGD("%s: Exit", __func__);
    return NULL;
}

static int push_process_buffers(st_hw_session_pcm_t *p_pcm_ses, int16_t *in_pcm,
    int16_t *out_pcm, int16_t *ec_ref_pcm, unsigned int in_buf_size)
{
    struct process_buf_queue *p_buf;

    pthread_mutex_lock(&p_pcm_ses->st_ffv_process_lock);
    if (!p_pcm_ses->st_ffv_process_thread_started) {
        ALOGE("%s: ERROR. process thread not started", __func__);
        return -EINVAL;
    }

    if (p_pcm_ses->process_buf_free == NULL) {
        ALOGD("%s: waiting for process buffer free", __func__);
        pthread_cond_wait(&p_pcm_ses->st_ffv_capture_cond,
            &p_pcm_ses->st_ffv_process_lock);
        if (p_pcm_ses->process_buf_free == NULL) {
            pthread_mutex_unlock(&p_pcm_ses->st_ffv_process_lock);
            ALOGE("%s: failed to acquire buffers", __func__);
            return -EINVAL;
        }
    }
    p_buf = process_buf_queue_pop(&p_pcm_ses->process_buf_free);
    memcpy(p_buf->buffer.in_buf_ptr, in_pcm, in_buf_size);
    memcpy(p_buf->buffer.ec_ref_buf_ptr, ec_ref_pcm, p_pcm_ses->ec_ref_buf_size);
    memcpy(p_buf->buffer.out_buf_ptr, out_pcm, p_pcm_ses->out_buf_size);
    process_buf_queue_push(&p_pcm_ses->process_buf, p_buf);

    pthread_cond_signal(&p_pcm_ses->st_ffv_process_cond);
    pthread_mutex_unlock(&p_pcm_ses->st_ffv_process_lock);
    return 0;
}

#else
static void *st_ffv_process_thread_loop(void *context __unused)
{
    return NULL;
}

#endif

static void *capture_thread_loop(void *context)
{
    st_hw_session_pcm_t *p_pcm_ses =
                                 (st_hw_session_pcm_t *)context;
    int status = 0;
    int16_t *in_ptr = NULL, *process_in_ptr = NULL, *process_out_ptr = NULL;
    int16_t *process_bsp_out_ptr = NULL;
    int16_t *process_ec_ref_ptr = NULL;
    int i, ch;
    int total_in_ch, in_ch, ec_ref_ch;
    unsigned int in_buf_size;
    static bool write_1 = true;
    if (p_pcm_ses->common.stdev->enable_debug_dumps) {
        ST_DBG_DECLARE(FILE *fptr_cap = NULL; static int file_cnt = 0);
        ST_DBG_DECLARE(FILE *fptr_ec = NULL; static int file_cnt_2 = 0);
        ST_DBG_DECLARE(FILE *fptr_split = NULL; static int file_cnt_3 = 0);
        ST_DBG_DECLARE(FILE *fptr_out = NULL; static int file_cnt_4 = 0);
        ST_DBG_DECLARE(FILE *fptr_bsp_out = NULL; static int file_cnt_5 = 0);
    }

    if (p_pcm_ses == NULL) {
        ALOGE("%s: ERROR: invalid context", __func__);
        goto exit;
    }

    if (p_pcm_ses->common.stdev->enable_debug_dumps) {
        ST_DBG_FILE_OPEN_WR(fptr_cap, ST_DEBUG_DUMP_LOCATION,
                            "st_capture_data", "pcm", file_cnt++);

        ST_DBG_FILE_OPEN_WR(fptr_ec, ST_DEBUG_DUMP_LOCATION,
                            "st_ec_ref_data", "pcm", file_cnt_2++);

        ST_DBG_FILE_OPEN_WR(fptr_split, ST_DEBUG_DUMP_LOCATION,
                            "st_split_capture_data", "pcm", file_cnt_3++);

        ST_DBG_FILE_OPEN_WR(fptr_out, ST_DEBUG_DUMP_LOCATION,
                            "st_out_data", "pcm", file_cnt_4++);

        ST_DBG_FILE_OPEN_WR(fptr_bsp_out, ST_DEBUG_DUMP_LOCATION,
                            "st_bsp_out_data", "pcm", file_cnt_5++);
    }

    st_cpu_affinity_set(p_pcm_ses);
    setpriority(PRIO_PROCESS, 0, ANDROID_PRIORITY_AUDIO);
    prctl(PR_SET_NAME, (unsigned long)"sound trigger capture", 0, 0, 0);
    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    ALOGV("%s:[%d] split ec ref %s", __func__, p_pcm_ses->common.sm_handle,
           p_pcm_ses->common.vendor_uuid_info->split_ec_ref_data ? "set" : "not set");
    pthread_mutex_lock(&p_pcm_ses->capture_thread_lock);
    while (!p_pcm_ses->exit_capture_thread) {
        pthread_mutex_unlock(&p_pcm_ses->capture_thread_lock);
        ALOGVV("%s: pcm_read reading bytes=%d", __func__, p_pcm_ses->in_buf_size);
        status = pcm_read(p_pcm_ses->pcm, p_pcm_ses->in_buf, p_pcm_ses->in_buf_size);
        ALOGVV("%s: pcm_read done", __func__);

        if (p_pcm_ses->common.stdev->enable_debug_dumps) {
            ST_DBG_FILE_WRITE(fptr_cap, p_pcm_ses->in_buf,
                p_pcm_ses->in_buf_size);
        }

        if (status) {
            ALOGE("%s: pcm read failed status %d - %s", __func__, status,
                  pcm_get_error(p_pcm_ses->pcm));
            p_pcm_ses->exit_capture_thread = true;
            goto exit;
        }

        if (!p_pcm_ses->common.vendor_uuid_info->split_ec_ref_data) {
            /* read EC ref data */
            ALOGVV("%s: pcm_read reading bytes=%d", __func__, p_pcm_ses->ec_ref_buf_size);
            status = pcm_read(p_pcm_ses->ec_ref_pcm, p_pcm_ses->ec_ref_buf, p_pcm_ses->ec_ref_buf_size);
            ALOGVV("%s: pcm_read done", __func__);

            if (p_pcm_ses->common.stdev->enable_debug_dumps) {
                ST_DBG_FILE_WRITE(fptr_ec, p_pcm_ses->ec_ref_buf,
                                  p_pcm_ses->ec_ref_buf_size);
            }

            if (status) {
                ALOGE("%s: ec ref pcm read failed status %d - %s", __func__, status,
                       pcm_get_error(p_pcm_ses->ec_ref_pcm));
                p_pcm_ses->exit_capture_thread = true;
                goto exit;
            }
            process_in_ptr = (int16_t *)p_pcm_ses->in_buf;
            process_ec_ref_ptr = (int16_t *)p_pcm_ses->ec_ref_buf;
            in_buf_size = p_pcm_ses->in_buf_size;
        } else {
            /* split input buffer into actual input channels and EC ref channels */
            in_ptr = (int16_t *)p_pcm_ses->in_buf;
            process_in_ptr = (int16_t *)p_pcm_ses->split_in_buf;
            process_ec_ref_ptr = (int16_t *)p_pcm_ses->ec_ref_buf;
            total_in_ch = p_pcm_ses->capture_config.channels;
            ec_ref_ch = p_pcm_ses->ec_ref_config.channels;
            in_ch = total_in_ch - ec_ref_ch;
            for (i = 0; i < (int) p_pcm_ses->capture_config.period_size; i++) {
                for (ch = 0; ch < in_ch; ch++) {
                    process_in_ptr[i*in_ch+ch] =
                              in_ptr[i*total_in_ch+ch];
                }
                for (ch = 0; ch < ec_ref_ch; ch++) {
                    process_ec_ref_ptr[i*ec_ref_ch+ch] =
                              in_ptr[i*total_in_ch+in_ch+ch];
                }
            }
            if (p_pcm_ses->common.stdev->enable_debug_dumps) {
                ST_DBG_FILE_WRITE(fptr_split, p_pcm_ses->split_in_buf,
                                  p_pcm_ses->split_in_buf_size);
                ST_DBG_FILE_WRITE(fptr_ec, p_pcm_ses->ec_ref_buf,
                                  p_pcm_ses->ec_ref_buf_size);
            }
            in_buf_size = p_pcm_ses->split_in_buf_size;
        }
        process_out_ptr = (int16_t *)p_pcm_ses->out_buf;
        process_bsp_out_ptr = (int16_t *)p_pcm_ses->bsp_out_buf;

#ifdef QUEUE_PROCESS_BUFFERS
        status = push_process_buffers(p_pcm_ses, process_in_ptr,
            process_out_ptr, process_ec_ref_ptr, in_buf_size);
        if (status) {
            ALOGE("%s: failed to push process buffers %d", __func__, status);
            p_pcm_ses->exit_capture_thread = true;
            goto exit;
        }
#else
        if (ffv_process_v2_fn) {
            if (write_1)
                ALOGD("%s: calling ffv_process_v2_fn", __func__);
            ffv_process_v2_fn(p_pcm_ses->handle, process_in_ptr,
                process_out_ptr, process_bsp_out_ptr, process_ec_ref_ptr);
            if (p_pcm_ses->esp_handle)
                esp_process_fn(p_pcm_ses->esp_handle, process_bsp_out_ptr);
        } else {
            if (write_1)
                ALOGD("%s: calling ffv_process_fn", __func__);
            ffv_process_fn(p_pcm_ses->handle, process_in_ptr,
                process_out_ptr, process_ec_ref_ptr);
        }

        if (write_1) {
            ALOGD("%s: return from ffv_process(_v2)_fn", __func__);
            write_1 = false;
        }

        if (p_pcm_ses->common.stdev->enable_debug_dumps) {
            ST_DBG_FILE_WRITE(fptr_out, process_out_ptr,
                              p_pcm_ses->out_buf_size);
            ST_DBG_FILE_WRITE(fptr_bsp_out, process_bsp_out_ptr,
                              p_pcm_ses->bsp_out_buf_size);
        }
#endif
        pthread_mutex_lock(&p_pcm_ses->capture_thread_lock);
    }
    pthread_mutex_unlock(&p_pcm_ses->capture_thread_lock);

exit:
    ALOGD("%s: Exit status=%d", __func__, status);
    p_pcm_ses->capture_thread_started = false;
    write_1 = true;
    if (p_pcm_ses->common.stdev->enable_debug_dumps) {
        ST_DBG_FILE_CLOSE(fptr_cap);
        ST_DBG_FILE_CLOSE(fptr_ec);
        ST_DBG_FILE_CLOSE(fptr_split);
        ST_DBG_FILE_CLOSE(fptr_out);
        ST_DBG_FILE_CLOSE(fptr_bsp_out);
    }
    return NULL;
}

static void st_event_callback(void *cb_data, void *handle, FfvEventType event_type,
                              void *event_payload, size_t event_payload_size __unused)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)cb_data;
    callback_event_t *ev = NULL;

    ALOGD("%s: handle %p", __func__, handle);
    if (!handle || !event_payload) {
        ALOGE("%s: ERROR. NULL params", __func__);
        return;
    }
    if (!p_pcm_ses) {
        ALOGE("%s: ERROR. NULL session", __func__);
        return;
    }

    ALOGD("%s: sm handle [%d]", __func__, p_pcm_ses->common.sm_handle);
    ev= (callback_event_t *)calloc(1, sizeof(callback_event_t));
    if (!ev) {
        ALOGE("%s: failed to allocate mem for event", __func__);
        goto exit;
    }

    ev->event_type = event_type;
    ev->ev_payload = event_payload;

exit:
    pthread_mutex_lock(&p_pcm_ses->callback_thread_lock);
    if (!ev)
        p_pcm_ses->exit_callback_thread = true;
    else
        list_add_tail(&p_pcm_ses->ev_list, &ev->node);
    pthread_cond_signal(&p_pcm_ses->ev_cond);
    pthread_mutex_unlock(&p_pcm_ses->callback_thread_lock);
}

/*
* Print detection event payload for non LE case only as
* client/test app is parsing/printing the payload in LE case.
*/
#if LINUX_ENABLED
#define print_detection_event(hw_sess_event) (0)
#else
static void print_detection_event(st_hw_sess_event_t sess_info)
{
    uint32_t *payload_32 = NULL;
    uint32_t version, key, key_version, key_size;
    int k;

    payload_32 = (uint32_t *)sess_info.payload.detected.detect_payload;
    version = *payload_32++;
    ALOGVV("%s: version %d", __func__, version);
    if (version == 0x1) {
        for (k = 0; k < KWD_MAX; k++) {
            key = *payload_32++;
            key_version = *payload_32++;
            key_size = *payload_32++;
            if (key == KWD_INDEX) {
                /* parse payload for key == KWD_INDEX */
                if (key_version != 0x1) {
                    ALOGE("%s: Invalid version for keyword index key %d",
                        __func__, key_version);
                    goto exit;
                }
                ALOGD("%s: keyword start index %d", __func__, *payload_32++);
                ALOGD("%s: keyword stop index %d", __func__, *payload_32++);
            } else {
                payload_32 = (uint32_t *)((char *)payload_32 + key_size);
            }
        }
    } else {
        ALOGE("%s: Invalid version for detection event payload %d",
            __func__, version);
        goto exit;
    }
exit:
    return;
}
#endif

static void *callback_thread_loop(void *context)
{
    st_hw_session_pcm_t *p_pcm_ses =
                                 (st_hw_session_pcm_t *)context;
    int event_status;
    st_hw_sess_event_t hw_sess_event; /* used to report event to st_session */
    void *payload;
    int payload_size;
    struct listnode *item;
    callback_event_t *ev = NULL;
    uint64_t timestamp;
    ffv_keyword_detection_status_t *ev_payload;
    bool send_event;

    if (p_pcm_ses == NULL) {
        ALOGE("%s: ERROR. null context.. exiting", __func__);
        return NULL;
    }
    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);

    setpriority(PRIO_PROCESS, 0, ANDROID_PRIORITY_DEFAULT);
    prctl(PR_SET_NAME, (unsigned long)"sound trigger callback", 0, 0, 0);

    pthread_mutex_lock(&p_pcm_ses->callback_thread_lock);
    while (!p_pcm_ses->exit_callback_thread) {
        if (list_empty(&p_pcm_ses->ev_list)) {
            ALOGI("%s:[%d] Waiting for event",
               __func__, p_pcm_ses->common.sm_handle);
            pthread_cond_wait(&p_pcm_ses->ev_cond, &p_pcm_ses->callback_thread_lock);
        }
        if (p_pcm_ses->exit_callback_thread)
            break;

        send_event = false;
        item = list_head(&p_pcm_ses->ev_list);
        ev = node_to_item(item, callback_event_t, node);
        list_remove(item);

        ALOGD("%s: processing event type %d", __func__, ev->event_type);
        switch (ev->event_type) {
        case EVENT_KEYWORD_DETECTION:
            ev_payload = (ffv_keyword_detection_status_t *)ev->ev_payload;
            timestamp = ((uint64_t)ev_payload->timestamp_msw << 32) |
                         ev_payload->timestamp_lsw;
            payload_size = ev_payload->payload_size;
            payload = (char *)ev_payload + sizeof(ffv_keyword_detection_status_t);
            ALOGD("%s: detection status %d", __func__, ev_payload->detection_status);
            switch(ev_payload->detection_status) {
            case KWD_STATUS_DETECTED:
            case KWD_STATUS_IN_DISCOVERY:
            case KWD_STATUS_IN_PROCESS:
                event_status = RECOGNITION_STATUS_SUCCESS;
                send_event = true;
                break;
            case KWD_STATUS_END_SPEECH:
            case KWD_STATUS_REJECTED:
                event_status = RECOGNITION_STATUS_FAILURE;
                send_event = true;
                break;
            case KWD_STATUS_NONE:
            default:
                break;
            }
            break;
        default:
            break;
        }
        free(ev);
        if (!send_event)
            continue;

        ALOGI("%s:[%d] Recognition event %d",
              __func__, p_pcm_ses->common.sm_handle, event_status);
        /* inform st_session of the event */
        hw_sess_event.event_id = ST_HW_SESS_EVENT_DETECTED;
        hw_sess_event.payload.detected.timestamp = timestamp;
        hw_sess_event.payload.detected.detect_status = event_status;
        hw_sess_event.payload.detected.detect_payload = payload;
        hw_sess_event.payload.detected.payload_size = payload_size;
        print_detection_event(hw_sess_event);
        p_pcm_ses->common.callback_to_st_session(&hw_sess_event,
                p_pcm_ses->common.cookie);
    }

    while (!list_empty(&p_pcm_ses->ev_list)) {
        item = list_head(&p_pcm_ses->ev_list);
        list_remove(item);
        free(node_to_item(item, callback_event_t, node));
    }
    pthread_mutex_unlock(&p_pcm_ses->callback_thread_lock);
    ALOGD("%s:[%d] Exit", __func__, p_pcm_ses->common.sm_handle);
    return NULL;
}

static int deallocate_lab_buffers(st_hw_session_pcm_t* p_ses)
{
    ALOGVV("%s:[%d] Enter", __func__, p_ses->common.sm_handle);
    if (p_ses->lab_out_buf) {
        free(p_ses->lab_out_buf);
        p_ses->lab_out_buf = NULL;
    }
    if (p_ses->lab_cap_buf) {
        free(p_ses->lab_cap_buf);
        p_ses->lab_cap_buf = NULL;
    }
    p_ses->lab_buffers_allocated = false;
    return 0;
}

static int allocate_lab_buffers(st_hw_session_pcm_t* p_ses)
{
    int status = 0;

    ALOGVV("%s:[%d] Enter", __func__, p_ses->common.sm_handle);

    p_ses->lab_cap_buf_size = p_ses->lab_config.period_size * p_ses->lab_config.channels *
                              (pcm_format_to_bits(p_ses->lab_config.format) >> 3);
    p_ses->lab_cap_buf = (unsigned char *) calloc(1, p_ses->lab_cap_buf_size);
    if (!p_ses->lab_cap_buf) {
        ALOGE("%s: ERROR. Can not allcoate lab buffer size %d", __func__, p_ses->lab_cap_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGV("%s: Allocated lab buffer period size bytes =%d",
          __func__, p_ses->lab_cap_buf_size);

    /* Allocate lab out buffer to hold library read buffer length returned
     * by ffv library which includes history buffer latency + read latency
     * of ffv/st_hal client.
     * This helps to avoid overrun in library/HAL by the time client initiates
     * read of LAB.
     */
    p_ses->read_buf_len = get_ffv_read_buffer_len(p_ses);
    if (p_ses->read_buf_len == 0) {
        ALOGE("%s: ERROR. Invalid read buffer length", __func__);
        status = -ENOMEM;
        goto error_exit;
    }
    p_ses->lab_out_buf_size = p_ses->read_buf_len;
    p_ses->lab_out_buf = (unsigned char *) calloc(1, p_ses->lab_out_buf_size);
    if (!p_ses->lab_out_buf) {
        ALOGE("%s: ERROR. Can not allcoate out buffer size %d",
              __func__, p_ses->lab_out_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGV("%s: Allocated out buffer size=%d", __func__, p_ses->lab_out_buf_size);
    p_ses->lab_buffers_allocated = true;
    return 0;

error_exit:
    deallocate_lab_buffers(p_ses);
    return status;
}

static int deallocate_buffers(st_hw_session_pcm_t* p_ses)
{
    ALOGVV("%s:[%d] Enter", __func__, p_ses->common.sm_handle);

    if (p_ses->in_buf) {
        free(p_ses->in_buf);
        p_ses->in_buf = NULL;
    }

    if (p_ses->ec_ref_buf) {
        free(p_ses->ec_ref_buf);
        p_ses->ec_ref_buf = NULL;
    }

    if (p_ses->split_in_buf) {
        free(p_ses->split_in_buf);
        p_ses->split_in_buf = NULL;
    }

    if (p_ses->out_buf) {
        free(p_ses->out_buf);
        p_ses->out_buf = NULL;
    }

    if (p_ses->bsp_out_buf) {
        free(p_ses->bsp_out_buf);
        p_ses->bsp_out_buf = NULL;
    }

    p_ses->buffers_allocated = false;
    return 0;
}

static int allocate_buffers(st_hw_session_pcm_t* p_ses)
{
    int status = 0;

    ALOGVV("%s:[%d] Enter", __func__, p_ses->common.sm_handle);

    /* in_buf - buffer read from capture session */
    p_ses->in_buf_size = pcm_frames_to_bytes(p_ses->pcm, p_ses->capture_config.period_size);
    p_ses->in_buf = (unsigned char *)calloc(1, p_ses->in_buf_size);
    if (!p_ses->in_buf) {
        ALOGE("%s: ERROR. Can not allocate in buffer size %d", __func__, p_ses->in_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGD("%s: Allocated in buffer size bytes =%d",
          __func__, p_ses->in_buf_size);

    if (!p_ses->common.vendor_uuid_info->split_ec_ref_data) {
        p_ses->ec_ref_buf_size = pcm_frames_to_bytes(p_ses->ec_ref_pcm, p_ses->ec_ref_config.period_size);
    } else {
        p_ses->ec_ref_buf_size = p_ses->ec_ref_config.period_size * p_ses->ec_ref_config.channels *
                                  (pcm_format_to_bits(p_ses->ec_ref_config.format) >> 3);
        /* split_in_buf - split buffer when ec ref and mic data is packed */
        p_ses->split_in_buf_size = p_ses->in_buf_size - p_ses->ec_ref_buf_size;
        p_ses->split_in_buf = (unsigned char *)calloc(1, p_ses->split_in_buf_size);
        if (!p_ses->split_in_buf) {
            ALOGE("%s: ERROR. Can not allocate split in buffer size %d",
                   __func__, p_ses->split_in_buf_size);
            status = -ENOMEM;
            goto error_exit;
        }
        ALOGD("%s: Allocated split in buffer size bytes =%d",
              __func__, p_ses->split_in_buf_size);
    }

    /* ec_buf - buffer read from ec ref capture session */
    p_ses->ec_ref_buf = (unsigned char *)calloc(1, p_ses->ec_ref_buf_size);
    if (!p_ses->ec_ref_buf) {
        ALOGE("%s: ERROR. Can not allocate ec ref buffer size %d",
               __func__, p_ses->ec_ref_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGD("%s: Allocated ec ref buffer size bytes =%d chann %d",
          __func__, p_ses->ec_ref_buf_size, p_ses->ec_ref_config.channels);

    /* out_buf - output buffer from FFV + SVA library */
    p_ses->out_buf_size = p_ses->out_config.period_size * p_ses->out_config.channels *
                              (pcm_format_to_bits(p_ses->out_config.format) >> 3);
    p_ses->out_buf = (unsigned char *)calloc(1, p_ses->out_buf_size);
    if (!p_ses->out_buf) {
        ALOGE("%s: ERROR. Can not allocate out buffer size %d", __func__, p_ses->out_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGD("%s: Allocated out buffer size bytes =%d",
          __func__, p_ses->out_buf_size);

    /* bsp_out_buf - bsp output buffer from ESP library */
    p_ses->bsp_out_buf_size = p_ses->out_config.period_size * p_ses->out_config.channels *
                              (pcm_format_to_bits(p_ses->out_config.format) >> 3);
    p_ses->bsp_out_buf = (unsigned char *)calloc(1, p_ses->bsp_out_buf_size);
    if (!p_ses->bsp_out_buf) {
        ALOGE("%s: ERROR. Can not allocate out buffer size %d", __func__, p_ses->bsp_out_buf_size);
        status = -ENOMEM;
        goto error_exit;
    }
    ALOGD("%s: Allocated bsp out buffer size bytes =%d",
          __func__, p_ses->bsp_out_buf_size);

    p_ses->buffers_allocated = true;
    return 0;

error_exit:
    deallocate_buffers(p_ses);
    return status;
}

static int sound_trigger_set_device
(
   st_hw_session_t* p_ses,
   bool enable
)
{
    char st_device_name[DEVICE_NAME_MAX_SIZE] = { 0 };
    int ref_cnt_idx = 0, ref_cnt = 0;
    int status = 0;
    st_device_t st_device = 0;
    audio_devices_t capture_device = 0;
    int app_type = 0;
    st_profile_type_t profile_type = 0;
    bool is_hwmad_device = false;

    is_hwmad_device = platform_stdev_is_hwmad_backend(p_ses->stdev->platform,
        p_ses->st_device, p_ses->exec_mode);

    profile_type = p_ses->vendor_uuid_info->profile_type;
    if (enable) {
        capture_device = platform_stdev_get_capture_device(p_ses->stdev->platform);
        st_device = platform_stdev_get_device(p_ses->stdev->platform,
            p_ses->vendor_uuid_info, capture_device, p_ses->exec_mode);

        if (platform_stdev_get_device_name(p_ses->stdev->platform, p_ses->exec_mode,
                st_device, st_device_name) < 0) {
            ALOGE("%s: Invalid sound trigger device name returned", __func__);
            return -EINVAL;
        }

        pthread_mutex_lock(&p_ses->stdev->ref_cnt_lock);
        ref_cnt_idx = (p_ses->exec_mode * ST_DEVICE_MAX) + st_device;
        ref_cnt = ++(p_ses->stdev->dev_ref_cnt[ref_cnt_idx]);
        if (1 == ref_cnt) {
            app_type = platform_stdev_get_device_app_type(p_ses->stdev->platform,
                                                          profile_type);

            status = platform_stdev_send_calibration(p_ses->stdev->platform,
                capture_device,
                p_ses->exec_mode,
                p_ses->vendor_uuid_info,
                app_type,
                false, ST_DEVICE_CAL);

            if (!status) {
                /*
                 * If no dedicated path, make sure to disable device first and then
                 * enable with conc enabled to handle below scenario:
                 * 1. STHAL and AHAL runs concurrently with conc capture enabled
                 * 2. STHAL session closed then it will not disable device as AHAL
                 * usecase is going on. Then AHAL disables device when it closes session
                 * 3. If STHAL is started again then device will not be enabled as stdev
                 * mixer value in audio route is not reset, so detections won't work
                 * 4. To fix this call audio reset then enable device
                 */
                if (!platform_stdev_is_dedicated_sva_path(p_ses->stdev->platform) &&
                    p_ses->stdev->conc_capture_supported &&
                    p_ses->stdev->reset_backend &&
                    !is_hwmad_device) {
                    check_and_set_ec_ref_device(p_ses, 0);
                    audio_route_reset_and_update_path(p_ses->stdev->audio_route,
                        st_device_name);
                }
                ALOGD("%s: enable device (%x) = %s", __func__, st_device,
                      st_device_name);
                audio_route_apply_and_update_path(p_ses->stdev->audio_route,
                                                  st_device_name);
                check_and_set_ec_ref_device(p_ses, enable);
            } else {
                --(p_ses->stdev->dev_ref_cnt[ref_cnt_idx]);
                ALOGE("%s: failed to send calibration %d", __func__, status);
            }
        }
        pthread_mutex_unlock(&p_ses->stdev->ref_cnt_lock);
        p_ses->st_device = st_device;
        p_ses->st_device_name = strdup(st_device_name);
    } else {
        if (!p_ses->st_device_name) {
            ALOGE("%s: Invalid sound trigger device name", __func__);
            return -EINVAL;
        }

        ref_cnt_idx = (p_ses->exec_mode * ST_DEVICE_MAX) + p_ses->st_device;
        pthread_mutex_lock(&p_ses->stdev->ref_cnt_lock);
        ref_cnt = p_ses->stdev->dev_ref_cnt[ref_cnt_idx];
        if (0 < ref_cnt) {
            ref_cnt = --(p_ses->stdev->dev_ref_cnt[ref_cnt_idx]);
        } else {
            ALOGV("%s: ref_cnt = %d", __func__, ref_cnt);
            pthread_mutex_unlock(&p_ses->stdev->ref_cnt_lock);
            return status;
        }

        if (0 == ref_cnt) {
            if(p_ses->stdev->reset_backend || is_hwmad_device) {
                ALOGD("%s: disable device (%x) = %s", __func__, p_ses->st_device,
                      p_ses->st_device_name);
                check_and_set_ec_ref_device(p_ses, enable);
                audio_route_reset_and_update_path(p_ses->stdev->audio_route,
                                                  p_ses->st_device_name);
            } else {
                ALOGD("%s: Non-hwmad device, concurrent capture on, do not disable", __func__);
            }
        }
        pthread_mutex_unlock(&p_ses->stdev->ref_cnt_lock);
        free(p_ses->st_device_name);
    }
    return status;
}

static int reg_sm(st_hw_session_t *p_ses, void *sm_data,
    unsigned int sm_size, uint32_t model_id __unused)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses =
        (st_hw_session_pcm_t*)p_ses;
    struct st_vendor_info *v_info = p_ses->vendor_uuid_info;
    pthread_attr_t attr;
    int num_tx_in_ch, num_out_ch, num_ec_ref_ch;
    int frame_len;
    int sample_rate;
    char vendor_config_path[MIXER_PATH_MAX_LENGTH];
    char st_ffv_config_file[MIXER_PATH_MAX_LENGTH];
    const char *config_file_path;
    FfvStatusType status_type;
    EspStatusType esp_status_type;
    int total_mem_size;
    int frame_len_ms = ST_ESP_FRAME_LENGTH_MS;

    int product_id = 0;
    char product_license[ST_LICENSE_STR_MAX_LENGTH + 1] = {0};
    ALOGD("%s:[%d] Enter", __func__, p_ses->sm_handle);

    p_pcm_ses->pcm_id =
        platform_arm_get_pcm_device_id(p_ses->stdev->platform,
                                            &p_ses->use_case_idx,
                                            false);
    if (p_pcm_ses->pcm_id < 0)
        return -ENODEV;

    p_pcm_ses->common.config = stdev_arm_pcm_config;
    p_pcm_ses->out_config = p_pcm_ses->common.config;
    p_pcm_ses->capture_config = p_pcm_ses->common.config;
    p_pcm_ses->lab_config = p_pcm_ses->common.config;
    platform_stdev_check_and_update_pcm_config(&p_pcm_ses->capture_config,
                                               v_info);

    p_pcm_ses->capture_config.period_size =
               CALCULATE_PERIOD_SIZE(SOUND_TRIGGER_PCM_BUFFER_DURATION_MS,
                                     p_pcm_ses->capture_config.rate,
                                     SOUND_TRIGGER_PCM_PERIOD_COUNT, 32);

    platform_stdev_get_vendor_config_path(vendor_config_path,
        sizeof(vendor_config_path));
    /* Get path for st_ffv_config_file_name in vendor */
    snprintf(st_ffv_config_file, sizeof(st_ffv_config_file),
            "%s/%s", vendor_config_path, ST_FFV_CONFIG_FILE_NAME);
    config_file_path = st_ffv_config_file;
    ALOGD("%s: opening pcm device=%d ", __func__, p_pcm_ses->pcm_id);
    ALOGV("%s: config: channels=%d rate=%d, period_size=%d, period_cnt=%d, format=%d",
          __func__, p_pcm_ses->capture_config.channels, p_pcm_ses->capture_config.rate,
          p_pcm_ses->capture_config.period_size, p_pcm_ses->capture_config.period_count,
          p_pcm_ses->capture_config.format);

    p_pcm_ses->pcm = pcm_open(p_ses->stdev->snd_card, p_pcm_ses->pcm_id,
                          PCM_IN, &p_pcm_ses->capture_config);
    if (!p_pcm_ses->pcm) {
        ALOGE("%s: ERROR. pcm_open failed", __func__);
        status = -ENODEV;
        goto sm_error_1;
    }
    if (!pcm_is_ready(p_pcm_ses->pcm)) {
        ALOGE("%s: ERROR. pcm_is_ready failed err=%s", __func__,
              pcm_get_error(p_pcm_ses->pcm));
        status = -ENODEV;
        goto sm_error_1;
    }

    /* Set up EC ref session for the corresponding pcm session */
    p_pcm_ses->ec_ref_config = p_pcm_ses->common.config;
    platform_stdev_check_and_update_ec_ref_config(p_ses->stdev->platform,
                                      v_info, &p_pcm_ses->ec_ref_config);

    p_pcm_ses->ec_ref_config.period_size =
               CALCULATE_PERIOD_SIZE(SOUND_TRIGGER_PCM_BUFFER_DURATION_MS,
                                     p_pcm_ses->ec_ref_config.rate,
                                     SOUND_TRIGGER_PCM_PERIOD_COUNT, 32);
    ALOGV("%s: config: channels=%d rate=%d, period_size=%d, period_cnt=%d, format=%d",
          __func__, p_pcm_ses->ec_ref_config.channels, p_pcm_ses->ec_ref_config.rate,
          p_pcm_ses->ec_ref_config.period_size, p_pcm_ses->ec_ref_config.period_count,
          p_pcm_ses->ec_ref_config.format);

    if (!p_ses->vendor_uuid_info->split_ec_ref_data) {
        p_pcm_ses->ec_ref_pcm_id =
            platform_arm_get_pcm_device_id(p_ses->stdev->platform,
                                           &p_pcm_ses->ec_ref_use_case_idx,
                                           true);
        if (p_pcm_ses->ec_ref_pcm_id < 0) {
            status = -ENODEV;
            goto sm_error_1;
        }

        ALOGD("%s: opening pcm device=%d ", __func__, p_pcm_ses->ec_ref_pcm_id);
        p_pcm_ses->ec_ref_pcm = pcm_open(p_ses->stdev->snd_card, p_pcm_ses->ec_ref_pcm_id,
                              PCM_IN, &p_pcm_ses->ec_ref_config);
        if (!p_pcm_ses->ec_ref_pcm) {
            ALOGE("%s: ERROR. EC ref pcm_open failed", __func__);
            status = -ENODEV;
            goto sm_error;
        }
        if (!pcm_is_ready(p_pcm_ses->ec_ref_pcm)) {
            ALOGE("%s: ERROR. EC ref pcm_is_ready failed err=%s", __func__,
                  pcm_get_error(p_pcm_ses->ec_ref_pcm));
            status = -ENODEV;
            goto sm_error;
        }
    }

    num_ec_ref_ch = p_pcm_ses->ec_ref_config.channels;
    num_tx_in_ch = p_ses->vendor_uuid_info->split_ec_ref_data ?
                    (p_pcm_ses->capture_config.channels - num_ec_ref_ch) :
                     p_pcm_ses->capture_config.channels;
    num_out_ch = p_pcm_ses->out_config.channels;
    frame_len = p_pcm_ses->capture_config.period_size;
    sample_rate = p_pcm_ses->capture_config.rate;
    ALOGD("%s: ec_ref_ch %d, tx_in_ch %d, out_ch %d, frame_len %d, sample_rate %d",
           __func__, num_ec_ref_ch, num_tx_in_ch, num_out_ch, frame_len, sample_rate);
    ALOGD("%s: config file path %s", __func__, config_file_path);

    status = platform_stdev_get_license_by_product(p_ses->stdev->platform,
       PRODUCT_FFV, &product_id, product_license);
    ALOGD("%s: LICENSE[%s] key[%d]", __func__, product_license, product_id);

    status_type = ffv_init_fn(&p_pcm_ses->handle, num_tx_in_ch, num_out_ch, num_ec_ref_ch,
                      frame_len, sample_rate, config_file_path, (char *)sm_data, sm_size,
                      &total_mem_size, product_id, product_license);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_init returned %d", __func__, status_type);
        status = -EINVAL;
        goto sm_error;
    }
    ALOGD("%s: ffv_init success %p", __func__, p_pcm_ses->handle);

    status_type = ffv_register_event_callback_fn(p_pcm_ses->handle,
                                                 st_event_callback,
                                                 p_pcm_ses);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_reg_event_callback returned %d", __func__, status_type);
        status = -EINVAL;
        goto sm_error;
    }

    if (pcm_data.esp_lib_handle) {
        esp_status_type = esp_init_fn(&p_pcm_ses->esp_handle, frame_len_ms,
                                      sample_rate, &total_mem_size);
        if (esp_status_type) {
            ALOGE("%s: ERROR. esp_init returned %d", __func__, esp_status_type);
            p_pcm_ses->esp_handle = NULL;
        } else {
            ALOGD("%s: esp_init success %p", __func__, p_pcm_ses->esp_handle);
        }
    }
    p_pcm_ses->session_restart_done = false;
    /* Callback thread to wait on event detection */
    p_pcm_ses->exit_callback_thread = false;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_create(&p_pcm_ses->callback_thread, &attr,
                        callback_thread_loop, p_pcm_ses);

    ALOGD("%s:[%d] Exit, status=%d", __func__, p_pcm_ses->common.sm_handle,
        status);

    return 0;

sm_error:
    if (!p_ses->vendor_uuid_info->split_ec_ref_data) {
        if (p_pcm_ses->ec_ref_pcm) {
            pcm_close(p_pcm_ses->ec_ref_pcm);
            p_pcm_ses->ec_ref_pcm = NULL;
        }
        platform_arm_free_pcm_device_id(p_ses->stdev->platform,
                                        p_pcm_ses->ec_ref_pcm_id,
                                        true);
    }

sm_error_1:
    if (p_pcm_ses->pcm) {
        pcm_close(p_pcm_ses->pcm);
        p_pcm_ses->pcm = NULL;
    }
    platform_arm_free_pcm_device_id(p_ses->stdev->platform,
                                    p_pcm_ses->pcm_id,
                                    false);

    ALOGD("%s:[%d] Exit, status=%d", __func__,
        p_pcm_ses->common.sm_handle, status);
    return status;
}

static int dereg_sm(st_hw_session_t *p_ses, uint32_t model_id __unused)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);

    if (!p_pcm_ses->pcm) {
        ALOGV("%s: pcm NULL", __func__);
        return status;
    }

    /* Exit the callback thread waiting on event detection */
    pthread_mutex_lock(&p_pcm_ses->callback_thread_lock);
    p_pcm_ses->exit_callback_thread = true;
    pthread_cond_signal(&p_pcm_ses->ev_cond);
    pthread_mutex_unlock(&p_pcm_ses->callback_thread_lock);

    pthread_join(p_pcm_ses->callback_thread, (void **) NULL);

    ffv_deinit_fn(p_pcm_ses->handle);
    if (p_pcm_ses->esp_handle)
        esp_deinit_fn(p_pcm_ses->esp_handle);

    if (!p_ses->vendor_uuid_info->split_ec_ref_data) {
        if (p_pcm_ses->ec_ref_pcm) {
            pcm_close(p_pcm_ses->ec_ref_pcm);
            p_pcm_ses->ec_ref_pcm = NULL;
        }
        platform_arm_free_pcm_device_id(p_ses->stdev->platform,
                                        p_pcm_ses->ec_ref_pcm_id,
                                        true);
    }

    if (p_pcm_ses->pcm) {
        pcm_close(p_pcm_ses->pcm);
        p_pcm_ses->pcm = NULL;
    }
    platform_arm_free_pcm_device_id(p_ses->stdev->platform,
                                    p_pcm_ses->pcm_id,
                                    false);

    /* Deallocate buffers allocated during start_recognition */
    if (p_ses->lab_enabled) {
        if (p_pcm_ses->lab_buffers_allocated) {
            deallocate_lab_buffers(p_pcm_ses);
        }
    }
    if (p_pcm_ses->buffers_allocated)
        deallocate_buffers(p_pcm_ses);

    ALOGD("%s:[%d] Exit, status=%d", __func__, p_pcm_ses->common.sm_handle,
        status);
    return status;
}

static int reg_sm_params(st_hw_session_t* p_ses, unsigned int recognition_mode __unused,
    bool capture_requested, struct sound_trigger_recognition_config *rc_config __unused)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses =
        (st_hw_session_pcm_t*)p_ses;

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    if (!p_pcm_ses->buffers_allocated) {
        status = allocate_buffers(p_pcm_ses);
        if (status) {
            ALOGE("%s: buffer allocation failed %d", __func__, status);
            goto error;
        }
    }

    if (capture_requested) {
        if (!p_pcm_ses->lab_buffers_allocated)
            status = allocate_lab_buffers(p_pcm_ses);
    }
    p_ses->lab_enabled = capture_requested;

error:
    ALOGD("%s:[%d] Exit, status=%d", __func__,
        p_pcm_ses->common.sm_handle, status);
    return status;
}

static int dereg_sm_params(st_hw_session_t* p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    return 0;
}

static int start(st_hw_session_t* p_ses)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;
    int retry_num = 0;
    pthread_attr_t attr, attr_2;
    char *params_buffer_ptr = NULL;
    int param_id = FFV_RESET_AEC_PARAM;
    int param_size = 0;
    FfvStatusType status_type;

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    if (!p_pcm_ses->pcm) {
        ALOGW("%s: pcm NULL", __func__);
        status = -ENODEV;
        return status;
    }
    status = enable_use_case(true, p_ses);
    if (status) {
        ALOGE("%s: enable use case returned %d", __func__, status);
        return status;
    }

    status = check_and_enable_ec_ref_use_case(true, p_ses);
    if (status) {
        ALOGE("%s: enable ec ref use case returned %d", __func__, status);
        return status;
    }

    /* notify library to reset AEC during each start */
    status_type = ffv_set_param_fn(p_pcm_ses->handle, params_buffer_ptr,
                      param_id, param_size);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_set_param_fn ret %d", __func__, status_type);
        status = -EINVAL;
        return status;
    }

    status = pcm_start(p_pcm_ses->pcm);
    while (status && (retry_num < SOUND_TRIGGER_PCM_MAX_RETRY)) {
        usleep(SOUND_TRIGGER_PCM_SLEEP_WAIT);
        retry_num++;
        ALOGI("%s: pcm_start retrying..status %d errno %d, retry cnt %d",
              __func__, status, errno, retry_num);
        status = pcm_start(p_pcm_ses->pcm);
    }
    if (status) {
        ALOGE("%s: ERROR. pcm_start failed, returned status %d, err=%s",
              __func__, status, pcm_get_error(p_pcm_ses->pcm));
        return status;
    }
    ALOGD("%s: capture session started", __func__);

    status = check_and_start_ec_ref_ses(p_ses, true /* start */);
    if (status) {
        ALOGE("%s: ERROR. ec ref pcm_start failed, returned status %d",
              __func__, status);
        return status;
    }

    if (p_pcm_ses->session_restart_done == false) {
        p_pcm_ses->session_restart_done = true;
        restart_session(p_ses);
    }

    if (p_pcm_ses->st_ffv_process_thread_started == false) {
        /* init process threadloop */
        pthread_attr_init(&attr_2);
        pthread_attr_setdetachstate(&attr_2, PTHREAD_CREATE_JOINABLE);
        p_pcm_ses->exit_st_ffv_process_thread = false;
        status = pthread_create(&p_pcm_ses->st_ffv_process_thread, &attr_2,
                            st_ffv_process_thread_loop, p_pcm_ses);
        if (status) {
            ALOGE("%s: ERROR. failed to start process thread status %d",
                  __func__, status);
            return status;
        }
        p_pcm_ses->st_ffv_process_thread_started = true;
    }

    if (p_pcm_ses->capture_thread_started == false) {
        /* init capture threadloop */
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        p_pcm_ses->exit_capture_thread = false;

        status = pthread_create(&p_pcm_ses->capture_thread, &attr,
                            capture_thread_loop, p_pcm_ses);

        if (status) {
            ALOGE("%s: ERROR. failed to start capture thread, status %d",
                  __func__, status);
            return status;
        }
        p_pcm_ses->capture_thread_started = true;
    }
    ALOGD("%s:[%d] Exit, status=%d", __func__, p_pcm_ses->common.sm_handle,
        status);
    return status;
}

static int stop(st_hw_session_t* p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;
    int param_id = FFV_STOP_VOICE_RECOGNITION_PARAM;
    char *params_buffer_ptr = NULL;
    int param_size = 0;
    FfvStatusType status_type;
    int status = 0;

    ALOGD("%s:[%d] Enter", __func__, p_pcm_ses->common.sm_handle);
    if (!p_pcm_ses->pcm) {
        ALOGW("%s: pcm NULL", __func__);
        status = -ENODEV;
        return status;
    }

    pthread_mutex_lock(&p_pcm_ses->capture_thread_lock);
    p_pcm_ses->exit_capture_thread = true;
    pthread_cond_signal(&p_pcm_ses->st_ffv_capture_cond);
    pthread_mutex_unlock(&p_pcm_ses->capture_thread_lock);
    if (p_pcm_ses->capture_thread)
        pthread_join(p_pcm_ses->capture_thread, (void **) NULL);
    p_pcm_ses->capture_thread_started = false;

    pthread_mutex_lock(&p_pcm_ses->st_ffv_process_lock);
    p_pcm_ses->exit_st_ffv_process_thread = true;
    pthread_cond_signal(&p_pcm_ses->st_ffv_process_cond);
    pthread_mutex_unlock(&p_pcm_ses->st_ffv_process_lock);
    if (p_pcm_ses->st_ffv_process_thread)
        pthread_join(p_pcm_ses->st_ffv_process_thread, (void **) NULL);
    p_pcm_ses->st_ffv_process_thread_started = false;

    /* notify library on voice recognition stop */
    status_type = ffv_set_param_fn(p_pcm_ses->handle, params_buffer_ptr, param_id,
                                   param_size);
    if (status_type)
        ALOGE("%s: ERROR. ffv_set_param_fn ret %d", __func__, status_type);

    check_and_start_ec_ref_ses(p_ses, false /* stop */);
    check_and_enable_ec_ref_use_case(false, p_ses);

    pcm_stop(p_pcm_ses->pcm);
    enable_use_case(false, p_ses);
    ALOGD("%s:[%d] Exit, status=%d", __func__, p_pcm_ses->common.sm_handle,
        status);
    return status;
}

static int pcm_stop_buffering(st_hw_session_t* p_ses)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;

    ALOGD("%s:[%d] Enter pcm %p", __func__, p_pcm_ses->common.sm_handle,
        p_pcm_ses->pcm);

    if (p_ses->lab_enabled) {
        pthread_mutex_lock(&p_pcm_ses->lab_out_buf_lock);
        pthread_cond_broadcast(&p_pcm_ses->lab_out_buf_cond);
        pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);
    }

    ALOGD("%s:[%d] Exit, status=%d", __func__, p_ses->sm_handle, status);
    return status;
}

static void check_and_exit_lab(st_hw_session_t *p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses =
        (st_hw_session_pcm_t *)p_ses;

    if ((p_pcm_ses->lab_buffers_allocated && !p_pcm_ses->exit_lab_processing) &&
        CHECK_STATE(p_pcm_ses->common.state, SES_BUFFERING)) {

        pthread_mutex_lock(&p_pcm_ses->lab_out_buf_lock);
        p_pcm_ses->exit_lab_processing = true;
        pthread_cond_signal(&p_pcm_ses->lab_out_buf_cond);
        pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);
    }
}

static int stop_buffering(st_hw_session_t* p_ses)
{
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;
    int status = 0;

    ALOGD("%s:[%d] Enter pcm %p", __func__, p_pcm_ses->common.sm_handle,
        p_pcm_ses->pcm);

    if (!CHECK_STATE(p_ses->state, SES_BUFFERING)) {
        return status;
    }

    check_and_exit_lab(p_ses);
    status = pcm_stop_buffering(p_ses);
    CLEAR_STATE(p_ses->state, SES_BUFFERING);

    return status;
}

static int restart(st_hw_session_t* p_ses, unsigned int recognition_mode __unused,
   struct sound_trigger_recognition_config *rc_config __unused)
{
    st_hw_session_pcm_t *p_pcm_ses =
       (st_hw_session_pcm_t *)p_ses;
    char *params_buffer_ptr = NULL;
    int param_id;
    int param_size = 0;
    FfvStatusType status_type;

    /* notify library on voice recognition stop to restart detections*/
    param_id = FFV_STOP_VOICE_RECOGNITION_PARAM;
    status_type = ffv_set_param_fn(p_pcm_ses->handle, params_buffer_ptr, param_id,
                                   param_size);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_set_param_fn ret %d", __func__, status_type);
        return -EINVAL;
    }

    /* notify library to reset AEC */
    param_id = FFV_RESET_AEC_PARAM;
    status_type = ffv_set_param_fn(p_pcm_ses->handle, params_buffer_ptr, param_id,
                                   param_size);
    if (status_type) {
        ALOGE("%s: ERROR. ffv_set_param_fn ret %d", __func__, status_type);
        return -EINVAL;
    }

    return 0;
}

static int read_pcm_data(st_hw_session_pcm_t *p_ses,
                     unsigned char *buf,
                     unsigned int bytes)
{
    unsigned int copy_bytes, read_bytes;
    unsigned char *updated_rd_ptr;
    struct timespec tspec;
    int ret = 0;

    pthread_mutex_lock(&p_ses->lab_out_buf_lock);
    ALOGVV("%s: bytes=%d, unread_bytes=%d size=%d", __func__,
            bytes, p_ses->lab_out_buf_unread_bytes, p_ses->lab_out_buf_size);

    while (!p_ses->exit_lab_processing && (bytes > 0)) {
        if (!p_ses->lab_out_buf_unread_bytes) {
            ALOGVV("%s: waiting on cond, bytes=%d", __func__, bytes);
            /* Time out to unblock read thread in case if write thread is
               stuck filling the buffers */
            clock_gettime(CLOCK_MONOTONIC, &tspec);
            tspec.tv_sec += ST_READ_WAIT_TIME_OUT_SEC;
            ret = pthread_cond_timedwait(&p_ses->lab_out_buf_cond,
                                         &p_ses->lab_out_buf_lock, &tspec);
            ALOGVV("%s: done waiting on cond", __func__);
            if (ret) {
                ALOGE("%s: ERROR. read wait timed out, ret %d", __func__, ret);
                p_ses->exit_lab_processing = true;
                ret = -EIO;
                goto exit;
            }
            if (p_ses->exit_lab_processing) {
                 ALOGVV("%s: buffering stopped while waiting on cond, exiting",
                    __func__);
                ret = -EIO;
                goto exit;
            }
        }
        read_bytes = MIN(bytes, p_ses->lab_out_buf_unread_bytes);

        if (p_ses->lab_out_buf_end_ptr < (p_ses->lab_out_buf_rd_ptr + read_bytes)) {
            copy_bytes = p_ses->lab_out_buf_end_ptr - p_ses->lab_out_buf_rd_ptr;
            memcpy(buf, p_ses->lab_out_buf_rd_ptr, copy_bytes);
            memcpy(buf + copy_bytes, p_ses->lab_out_buf_start_ptr, read_bytes - copy_bytes);
            updated_rd_ptr = p_ses->lab_out_buf_start_ptr + (read_bytes - copy_bytes);
            p_ses->lab_out_buf_rd_ptr = updated_rd_ptr;
            p_ses->lab_out_buf_unread_bytes -= read_bytes;
        } else {
            memcpy(buf, p_ses->lab_out_buf_rd_ptr, read_bytes);
            p_ses->lab_out_buf_rd_ptr += read_bytes;
            p_ses->lab_out_buf_unread_bytes -= read_bytes;
        }
        pthread_cond_signal(&p_ses->lab_out_buf_cond);
        bytes -= read_bytes;
        buf += read_bytes;
    }

exit:
    pthread_mutex_unlock(&p_ses->lab_out_buf_lock);
    return 0;
}

static int write_pcm_data(st_hw_session_pcm_t *p_pcm_ses,
                     unsigned char *buf,
                     unsigned int bytes)
{
    unsigned int free_bytes, write_bytes;
    unsigned int copy_bytes;
    unsigned char *updated_wr_ptr;

    pthread_mutex_lock(&p_pcm_ses->lab_out_buf_lock);
    ALOGVV("%s: bytes=%d, unread_bytes=%d size=%d", __func__,
       bytes, p_pcm_ses->lab_out_buf_unread_bytes, p_pcm_ses->lab_out_buf_size);

    while (!p_pcm_ses->exit_lab_processing && (bytes > 0)) {
        free_bytes = p_pcm_ses->lab_out_buf_size - p_pcm_ses->lab_out_buf_unread_bytes;
        if (!free_bytes) {
            ALOGVV("%s: waiting on cond, bytes=%d", __func__, bytes);
            /* wait till space is avaialable to write */
            pthread_cond_wait(&p_pcm_ses->lab_out_buf_cond, &p_pcm_ses->lab_out_buf_lock);
            if (p_pcm_ses->exit_lab_processing) {
                 ALOGVV("%s: buffering stopped while waiting on cond, exiting", __func__);
                pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);
                return -EIO;
            }
        }
        write_bytes = MIN(bytes, free_bytes);

        if (p_pcm_ses->lab_out_buf_end_ptr < (p_pcm_ses->lab_out_buf_wr_ptr + write_bytes)) {
            copy_bytes = p_pcm_ses->lab_out_buf_end_ptr - p_pcm_ses->lab_out_buf_wr_ptr;
            memcpy(p_pcm_ses->lab_out_buf_wr_ptr, buf, copy_bytes);
            memcpy(p_pcm_ses->lab_out_buf_start_ptr,
                   buf + copy_bytes, write_bytes - copy_bytes);
            updated_wr_ptr = p_pcm_ses->lab_out_buf_start_ptr + (write_bytes - copy_bytes);
            p_pcm_ses->lab_out_buf_wr_ptr = updated_wr_ptr;
            p_pcm_ses->lab_out_buf_unread_bytes += write_bytes;
        } else {
            memcpy(p_pcm_ses->lab_out_buf_wr_ptr, buf, write_bytes);
            p_pcm_ses->lab_out_buf_wr_ptr += write_bytes;
            p_pcm_ses->lab_out_buf_unread_bytes += write_bytes;
        }
        ALOGVV("%s: about to signal condition", __func__);
        pthread_cond_signal(&p_pcm_ses->lab_out_buf_cond);
        bytes -= write_bytes;
        buf += write_bytes;
    }
    pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);
    return 0;
}

static void process_lab_capture(st_hw_session_t *p_ses)
{
    int bytes = 0, status = 0;

    SET_STATE(p_ses->state, SES_BUFFERING);
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;

    pthread_mutex_lock(&p_pcm_ses->lab_out_buf_lock);
    p_pcm_ses->exit_lab_processing = false;
    pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);

    if (p_ses->stdev->enable_debug_dumps) {
        ST_DBG_DECLARE(FILE *fptr_lab = NULL; static int file_cnt = 0);
        ST_DBG_FILE_OPEN_WR(fptr_lab, ST_DEBUG_DUMP_LOCATION,
                            "st_lab_capture_data", "pcm", file_cnt++);
    }

    /* Initialize pcm output buffer pointers */
    p_pcm_ses->lab_out_buf_start_ptr = p_pcm_ses->lab_out_buf;
    p_pcm_ses->lab_out_buf_end_ptr = p_pcm_ses->lab_out_buf + p_pcm_ses->lab_out_buf_size;
    p_pcm_ses->lab_out_buf_wr_ptr = p_pcm_ses->lab_out_buf;
    p_pcm_ses->lab_out_buf_rd_ptr = p_pcm_ses->lab_out_buf;
    p_pcm_ses->lab_out_buf_unread_bytes = 0;

    while (!p_pcm_ses->exit_lab_processing) {
        ALOGVV("%s: ffv_read reading bytes=%d", __func__, p_pcm_ses->lab_cap_buf_size);
        bytes = ffv_read_fn(p_pcm_ses->handle, (int16_t *)p_pcm_ses->lab_cap_buf,
                                    p_pcm_ses->lab_cap_buf_size);
        ALOGVV("%s: ffv_read done", __func__);
        if (!bytes || (bytes == -1)) {
            ALOGE("%s: ERROR. ffv_read returned %d", __func__, bytes);
            p_pcm_ses->exit_lab_processing = true;
            p_pcm_ses->common.fptrs->stop_buffering(&p_pcm_ses->common, true);
            break;
        }
        if (p_ses->stdev->enable_debug_dumps)
            ST_DBG_FILE_WRITE(fptr_lab, p_pcm_ses->lab_cap_buf, bytes);

        status = write_pcm_data(p_pcm_ses, p_pcm_ses->lab_cap_buf, p_pcm_ses->lab_cap_buf_size);
        if (status)
                break;
    }

    if (p_ses->stdev->enable_debug_dumps)
        ST_DBG_FILE_CLOSE(fptr_lab);
    ALOGVV("%s: Exit status=%d", __func__, status);
    return;
}

static int read_pcm(st_hw_session_t *p_ses,
                        unsigned char *buf,
                        unsigned int bytes)
{
    int status = 0;
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;

    pthread_mutex_lock(&p_pcm_ses->lab_out_buf_lock);
    if (p_pcm_ses->exit_lab_processing) {
        ALOGE("%s: No active buffering", __func__);
        pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);
        return -EIO;
    }
    pthread_mutex_unlock(&p_pcm_ses->lab_out_buf_lock);

    status = read_pcm_data(p_pcm_ses, buf, bytes);
    return status;
}

static int set_device(st_hw_session_t *p_ses,
                                bool enable)
{
    return sound_trigger_set_device(p_ses, enable);
}

static int disable_device(st_hw_session_t *p_ses __unused,
                        bool setting_device __unused)
{
    ALOGV("%s: Unsupported", __func__);
    return 0;
}

static int enable_device(st_hw_session_t *p_ses __unused,
                        bool setting_device __unused)
{
    ALOGV("%s: Unsupported", __func__);
    return 0;
}

static int get_param_data(st_hw_session_t *p_ses, const char *param,
                          void *payload, size_t payload_size,
                          size_t *param_data_size)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;
    int ret = 0;
    st_get_param_payload_t *params_buffer_ptr;
    int param_id, buffer_size;
    int param_size = 0;
    FfvStatusType status_type;
    EspStatusType esp_status_type;

    if (!param || !payload || !param_data_size) {
        ALOGE("%s: Invalid params", __func__);
        return -EINVAL;
    }

    buffer_size = sizeof(st_get_param_payload_t);
    params_buffer_ptr = (st_get_param_payload_t *)calloc(1, buffer_size);
    if (!params_buffer_ptr) {
        ALOGE("%s: ERROR. Can not allocate buffer size %d", __func__, buffer_size);
        goto exit;
    }

    ALOGD("%s:[%d] Enter param %s", __func__, p_pcm_ses->common.sm_handle, param);
    if (!strncmp(param, QSTHW_PARAMETER_DIRECTION_OF_ARRIVAL,
            sizeof(QSTHW_PARAMETER_DIRECTION_OF_ARRIVAL))) {
        param_id = FFV_SRC_TRACKING_PARAM;
        status_type = ffv_get_param_fn(p_pcm_ses->handle, (char *)params_buffer_ptr,
                          param_id, buffer_size, &param_size);
        if (status_type) {
            ALOGE("%s: ERROR. ffv_get_param_fn ret %d", __func__, status_type);
            ret = -EINVAL;
            goto exit;
        }
        if (param_size != sizeof(ffv_src_tracking_param_t)) {
            ALOGE("%s: ERROR. Invalid param size returned %d", __func__, param_size);
            ret = -EINVAL;
            goto exit;
        }
        if (payload_size < (size_t) param_size) {
            ALOGE("%s: ERROR. Invalid payload size %zu", __func__, payload_size);
            ret = -EINVAL;
            goto exit;
        }
    } else if (!strncmp(param, QSTHW_PARAMETER_CHANNEL_INDEX,
            sizeof(QSTHW_PARAMETER_CHANNEL_INDEX))) {
        param_id = FFV_TARGET_CHANNEL_INDEX_PARAM;
        status_type = ffv_get_param_fn(p_pcm_ses->handle, (char *)params_buffer_ptr,
                          param_id, buffer_size, &param_size);
        if (status_type) {
            ALOGE("%s: ERROR. ffv_get_param_fn ret %d", __func__, status_type);
            goto exit;
        }
        if (param_size != sizeof(ffv_target_channel_index_param_t)) {
            ALOGE("%s: ERROR. Invalid param size returned %d", __func__, param_size);
            ret = -EINVAL;
            goto exit;
        }
        if (payload_size < (size_t) param_size) {
            ALOGE("%s: ERROR. Invalid payload size %zu", __func__, payload_size);
            ret = -EINVAL;
            goto exit;
        }
    } else if (!strncmp(param, QSTHW_PARAMETER_ESP_ENERGY_LEVELS,
            sizeof(QSTHW_PARAMETER_ESP_ENERGY_LEVELS))) {
        if (!p_pcm_ses->esp_handle) {
            ALOGE("%s: ERROR. ESP not enabled for session", __func__);
            ret = -EINVAL;
            goto exit;
        }

        param_id = ESP_ENERGY_LEVELS_PARAM;
        esp_status_type = esp_get_param_fn(p_pcm_ses->esp_handle,
            (char *)params_buffer_ptr, param_id, buffer_size, &param_size);
        if (esp_status_type) {
            ALOGE("%s: ERROR. esp_get_param_fn ret %d", __func__, esp_status_type);
            goto exit;
        }
        if (param_size != sizeof(esp_energy_levels_t)) {
            ALOGE("%s: ERROR. Invalid param size returned %d", __func__, param_size);
            ret = -EINVAL;
            goto exit;
        }
        if (payload_size < (size_t) param_size) {
            ALOGE("%s: ERROR. Invalid payload size %zu", __func__, payload_size);
            ret = -EINVAL;
            goto exit;
        }
    } else {
        ALOGE("%s: ERROR. Unsupported param %s", __func__, param);
        ret = -EINVAL;
        goto exit;
    }

    /* copy params retrieved to payload */
    memcpy(payload, params_buffer_ptr, param_size);
    *param_data_size = param_size;
exit:
    return ret;
}

static int send_detection_request(st_hw_session_t *p_ses __unused)
{
    ALOGV("%s: Unsupported", __func__);
    return -ENOSYS;
}

int st_hw_sess_pcm_init(st_hw_session_t *const p_ses,
    hw_ses_event_callback_t cb, void* cookie, st_exec_mode_t exec_mode,
    struct st_vendor_info* v_info, sound_model_handle_t sm_handle,
    sound_trigger_device_t *stdev)
{
    int status = 0;
    pthread_condattr_t attr;
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;

    p_ses->exec_mode = exec_mode;
    p_ses->fptrs = &pcm_fptrs;

    p_ses->callback_to_st_session = cb;
    p_ses->cookie = cookie;
    p_ses->vendor_uuid_info = v_info;
    p_ses->sm_handle = sm_handle;
    p_ses->stdev = stdev;

    list_init(&p_pcm_ses->ev_list);
    pthread_cond_init(&p_pcm_ses->ev_cond, (const pthread_condattr_t *) NULL);
    pthread_cond_init(&p_pcm_ses->st_ffv_process_cond, (const pthread_condattr_t *) NULL);
    pthread_cond_init(&p_pcm_ses->st_ffv_capture_cond, (const pthread_condattr_t *) NULL);

    pthread_mutex_init(&p_pcm_ses->callback_thread_lock, NULL);
    pthread_mutex_init(&p_pcm_ses->capture_thread_lock, NULL);
    pthread_mutex_init(&p_pcm_ses->st_ffv_process_lock, NULL);

    pthread_mutex_init(&p_pcm_ses->lab_out_buf_lock,
        (const  pthread_mutexattr_t *) NULL);
    pthread_condattr_init(&attr);
    pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
    pthread_cond_init(&p_pcm_ses->lab_out_buf_cond, &attr);

    return status;

}

void st_hw_sess_pcm_deinit(st_hw_session_t *const p_ses __unused)
{
    st_hw_session_pcm_t *p_pcm_ses = (st_hw_session_pcm_t *)p_ses;

    pthread_cond_destroy(&p_pcm_ses->ev_cond);
    pthread_cond_destroy(&p_pcm_ses->st_ffv_process_cond);
    pthread_cond_destroy(&p_pcm_ses->st_ffv_capture_cond);
    pthread_mutex_destroy(&p_pcm_ses->callback_thread_lock);
    pthread_mutex_destroy(&p_pcm_ses->capture_thread_lock);
    pthread_mutex_destroy(&p_pcm_ses->st_ffv_process_lock);
    pthread_cond_destroy(&p_pcm_ses->lab_out_buf_cond);
    pthread_mutex_destroy(&p_pcm_ses->lab_out_buf_lock);
}

int st_hw_pcm_init()
{
    int status = 0;
    char lib_path[MIXER_PATH_MAX_LENGTH];
    char ffv_lib_file[MIXER_PATH_MAX_LENGTH];
    char esp_lib_file[MIXER_PATH_MAX_LENGTH];

    /* Get path for libs */
    get_lib_path(lib_path, sizeof(lib_path));

    /* Get path for ffv_lib_file */
    snprintf(ffv_lib_file, sizeof(ffv_lib_file), "%s/%s", lib_path, FFV_LIB_NAME);
    /* load FFV + SVA library */
    pcm_data.ffv_lib_handle = dlopen(ffv_lib_file, RTLD_NOW);
    if (!pcm_data.ffv_lib_handle) {
        ALOGE("%s: Unable to open %s, error %s", __func__, ffv_lib_file,
            dlerror());
        status = -ENOENT;
        goto exit;
    }

    DLSYM(pcm_data.ffv_lib_handle, ffv_init_fn, ffv_init, status);
    if (status)
        goto exit;
    DLSYM(pcm_data.ffv_lib_handle, ffv_deinit_fn, ffv_deinit, status);
    if (status)
        goto exit;
    DLSYM(pcm_data.ffv_lib_handle, ffv_process_v2_fn, ffv_process_v2, status);
    if (status) {
        DLSYM(pcm_data.ffv_lib_handle, ffv_process_fn, ffv_process, status);
        if (status)
            goto exit;
    }
    DLSYM(pcm_data.ffv_lib_handle, ffv_read_fn, ffv_read, status);
    if (status)
        goto exit;
    DLSYM(pcm_data.ffv_lib_handle, ffv_get_param_fn, ffv_get_param, status);
    if (status)
        goto exit;
    DLSYM(pcm_data.ffv_lib_handle, ffv_set_param_fn, ffv_set_param, status);
    if (status)
        goto exit;
    DLSYM(pcm_data.ffv_lib_handle, ffv_register_event_callback_fn,
          ffv_register_event_callback, status);
    if (status)
        goto exit;

    /* Get path for esp_lib_file */
    snprintf(esp_lib_file, sizeof(esp_lib_file), "%s/%s", lib_path, ESP_LIB_NAME);

    /* load ESP library */
    pcm_data.esp_lib_handle = dlopen(esp_lib_file, RTLD_NOW);
    if (!pcm_data.esp_lib_handle) {
        ALOGE("%s: Unable to open %s, error %s", __func__, esp_lib_file,
            dlerror());
        status = -ENOENT;
        goto exit_1;
    }

    dlerror(); /* clear errors */
    DLSYM(pcm_data.esp_lib_handle, esp_init_fn, esp_init, status);
    if (status)
        goto exit_1;
    DLSYM(pcm_data.esp_lib_handle, esp_deinit_fn, esp_deinit, status);
    if (status)
        goto exit_1;
    DLSYM(pcm_data.esp_lib_handle, esp_process_fn, esp_process, status);
    if (status)
        goto exit_1;
    DLSYM(pcm_data.esp_lib_handle, esp_get_param_fn, esp_get_param, status);
    if (status)
        goto exit_1;

    return 0;
exit_1:
    /*
     * Do not treat esp failures as init error.
     * Instead dlclose esp lib handle and return success.
     */
    if (pcm_data.esp_lib_handle) {
        dlclose(pcm_data.esp_lib_handle);
        pcm_data.esp_lib_handle = NULL;
    }

    return 0;

exit:
    if (pcm_data.ffv_lib_handle)
        dlclose(pcm_data.ffv_lib_handle);
    pcm_data.ffv_lib_handle = NULL;

    return status;
}

void st_hw_pcm_deinit()
{
    if (pcm_data.ffv_lib_handle)
        dlclose(pcm_data.ffv_lib_handle);
    pcm_data.ffv_lib_handle = NULL;

    if (pcm_data.esp_lib_handle)
        dlclose(pcm_data.esp_lib_handle);
    pcm_data.esp_lib_handle = NULL;
}
