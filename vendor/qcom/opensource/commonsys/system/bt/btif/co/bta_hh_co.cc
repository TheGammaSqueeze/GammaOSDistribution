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

#include <base/logging.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/uhid.h>
#include <linux/version.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/poll.h>
#include <unistd.h>

#include "bta_api.h"
#include "bta_hh_api.h"
#include "bta_hh_co.h"
#include "btif_hh.h"
#include "btif_util.h"
#include "device/include/interop.h"
#include "osi/include/osi.h"
#include "osi/include/socket_utils/sockets.h"
#include "osi/include/properties.h"

const char* dev_path = "/dev/uhid";
const char* hid_3d_audio_path = "/dev/socket/spatialaudio";

#if (BTA_HH_LE_INCLUDED == TRUE)
#include "btif_config.h"
#define BTA_HH_NV_LOAD_MAX 16
static tBTA_HH_RPT_CACHE_ENTRY sReportCache[BTA_HH_NV_LOAD_MAX];
#endif
#define BT_HID_RPT_OFFSET 9

#define REPORT_DESC_REPORT_ID 0x05
#define REPORT_DESC_DIGITIZER_PAGE 0x0D
#define REPORT_DESC_START_COLLECTION 0xA1
#define REPORT_DESC_END_COLLECTION 0xC0

static void remove_digitizer_descriptor(uint8_t* data, uint16_t* length) {
  uint8_t* startDescPtr = data;
  uint8_t* desc = data;

  BTIF_TRACE_DEBUG("remove_digitizer_descriptor");
  /* Parse until complete report descriptor is parsed */
  while (startDescPtr < data + *length) {
    uint8_t item = *startDescPtr++;
    uint8_t usage_page;

    switch (item) {
      case REPORT_DESC_REPORT_ID:  // Report ID
        usage_page = *startDescPtr;
        if (usage_page == REPORT_DESC_DIGITIZER_PAGE) {
          // digitizer usage page
          uint8_t* traversePtr = startDescPtr;
          uint8_t num_of_collections = 0;
          uint8_t num_of_end_collections = 0;
          uint16_t remainingBytesToBeCopied = 0;
          /* increment pointer until digitizer descriptor is parsed
           * completely or start collection matches end collection */
          while ((num_of_collections == 0 ||
                  (num_of_collections != num_of_end_collections)) &&
                 (traversePtr < data + *length)) {
            if (*traversePtr == REPORT_DESC_START_COLLECTION) {
              /* Increment number of collections for
               * digitizer descriptor */
              num_of_collections++;
            }
            if (*traversePtr == REPORT_DESC_END_COLLECTION) {
              /* Increment number of end collections for
               * digitizer descriptor */
              num_of_end_collections++;
            }
            /* increment the pointer to continue parsing
             * the digitizer descriptor */
            traversePtr++;
          }
          remainingBytesToBeCopied = *length - (traversePtr - data);
          BTIF_TRACE_DEBUG("starting point of digitizer desc = %d\n",
                           (startDescPtr - data) - 1);
          BTIF_TRACE_DEBUG(
              "start collection = %d, end collection = "
              " %d\n",
              num_of_collections, num_of_end_collections);
          BTIF_TRACE_DEBUG("end point of digitizer desc = %d\n",
                           (traversePtr - data));
          BTIF_TRACE_DEBUG("length of digitizer desc = %d\n",
                           traversePtr - startDescPtr + 2);
          BTIF_TRACE_DEBUG("bytes remaining to be copied = %d\n",
                           remainingBytesToBeCopied);
          if (remainingBytesToBeCopied) {
            uint32_t i;
            uint8_t* newDescPtr = traversePtr;
            uint32_t digDescStartPoint = (startDescPtr - data) - 1;
            uint32_t digDescEndPoint =
                *length - (traversePtr - startDescPtr) - 1;
            /* copy the remaining bytes in descriptor to the
             * existing place of digitizer descriptor */
            for (i = digDescStartPoint; i < digDescEndPoint; i++) {
              desc[i] = *newDescPtr++;
            }
          }
          /* update the length as digitizer descriptor is removed */
          *length = *length - (traversePtr - startDescPtr) - 1;
          BTIF_TRACE_DEBUG("new length of report desc = %d\n", *length);
          /* Update the start descriptor again to continue parsing
           * for digitizer records assuming more than 1 digitizer
           * record exists in report descriptor */
          startDescPtr--;
        }
        break;

      default:
        /*
         * Since item is not Report Id (0x05), increment start pointer
         * by length pointed by first 2 bits of item (i.e mask of 0x03)
         */
        startDescPtr += (item & 0x03);
        break;
    }
  }
}

void uhid_set_non_blocking(int fd) {
  int opts = fcntl(fd, F_GETFL);
  if (opts < 0)
    APPL_TRACE_ERROR("%s() Getting flags failed (%s)", __func__,
                     strerror(errno));

  opts |= O_NONBLOCK;

  if (fcntl(fd, F_SETFL, opts) < 0)
    APPL_TRACE_EVENT("%s() Setting non-blocking flag failed (%s)", __func__,
                     strerror(errno));
}

/*Internal function to perform UHID write and error checking*/
static int uhid_write(int fd, const struct uhid_event* ev) {
  ssize_t ret;
  OSI_NO_INTR(ret = write(fd, ev, sizeof(*ev)));

  if (ret < 0) {
    int rtn = -errno;
    APPL_TRACE_ERROR("%s: Cannot write to uhid:%s", __func__, strerror(errno));
    return rtn;
  } else if (ret != (ssize_t)sizeof(*ev)) {
    APPL_TRACE_ERROR("%s: Wrong size written to uhid: %zd != %zu", __func__,
                     ret, sizeof(*ev));
    return -EFAULT;
  }

  return 0;
}

/* Internal function to parse the events received from UHID driver*/
static int uhid_read_event(btif_hh_device_t* p_dev) {
  CHECK(p_dev);

  struct uhid_event ev;
  memset(&ev, 0, sizeof(ev));

  ssize_t ret;
  OSI_NO_INTR(ret = read(p_dev->fd, &ev, sizeof(ev)));

  if (ret == 0) {
    APPL_TRACE_ERROR("%s: Read HUP on uhid-cdev %s", __func__, strerror(errno));
    return -EFAULT;
  } else if (ret < 0) {
    APPL_TRACE_ERROR("%s: Cannot read uhid-cdev: %s", __func__,
                     strerror(errno));
    return -errno;
  }

  APPL_TRACE_DEBUG("%s: Event type = %d", __func__, ev.type);
  switch (ev.type) {
    case UHID_START:
      APPL_TRACE_DEBUG("UHID_START from uhid-dev\n");
      p_dev->ready_for_data = true;
      break;
    case UHID_STOP:
      APPL_TRACE_DEBUG("UHID_STOP from uhid-dev\n");
      p_dev->ready_for_data = false;
      break;
    case UHID_OPEN:
      APPL_TRACE_DEBUG("UHID_OPEN from uhid-dev\n");
      p_dev->ready_for_data = true;
      break;
    case UHID_CLOSE:
      APPL_TRACE_DEBUG("UHID_CLOSE from uhid-dev\n");
      p_dev->ready_for_data = false;
      break;
    case UHID_OUTPUT:
      if (ret < (ssize_t)(sizeof(ev.type) + sizeof(ev.u.output))) {
        APPL_TRACE_ERROR("%s: Invalid size read from uhid-dev: %zd < %zu",
                         __func__, ret, sizeof(ev.type) + sizeof(ev.u.output));
        return -EFAULT;
      }

      APPL_TRACE_DEBUG("UHID_OUTPUT: Report type = %d, report_size = %d",
                       ev.u.output.rtype, ev.u.output.size);
      // Send SET_REPORT with feature report if the report type in output event
      // is FEATURE
      if (ev.u.output.rtype == UHID_FEATURE_REPORT)
        btif_hh_setreport(p_dev, BTHH_FEATURE_REPORT, ev.u.output.size,
                          ev.u.output.data);
      else if (ev.u.output.rtype == UHID_OUTPUT_REPORT) {
        if (ev.u.output.size > UHID_DATA_MAX) {
            APPL_TRACE_WARNING("UHID_OUTPUT: Invalid report size %d",
                ev.u.output.size);
            return 0;
        }
        if (!memcmp(&p_dev->last_output_rpt_data, &ev.u.output.data,
            ev.u.output.size)) {
            /* Last output report same as current output report, don't inform to remote
             * device as this could be the case when reports are being sent due to
             * device suspend/resume. If same output report is sent to remote device
             * device which uses UART as transport might not be able to suspend at all
             * leading to higher battery drain.
             */
            APPL_TRACE_VERBOSE("UHID_OUTPUT: data same returning");
            return 0;
        }
        /* Copy new output report data for future tracking */
        memcpy(&p_dev->last_output_rpt_data, &ev.u.output.data, ev.u.output.size);
        btif_hh_setreport(p_dev, BTHH_OUTPUT_REPORT, ev.u.output.size,
                          ev.u.output.data);
      } else
        btif_hh_setreport(p_dev, BTHH_INPUT_REPORT, ev.u.output.size,
                          ev.u.output.data);
      break;
    case UHID_OUTPUT_EV:
      if (ret < (ssize_t)(sizeof(ev.type) + sizeof(ev.u.output_ev))) {
        APPL_TRACE_ERROR("%s: Invalid size read from uhid-dev: %zd < %zu",
                         __func__, ret,
                         sizeof(ev.type) + sizeof(ev.u.output_ev));
        return -EFAULT;
      }
      APPL_TRACE_DEBUG("UHID_OUTPUT_EV from uhid-dev\n");
      break;
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 18, 00))
    case UHID_SET_REPORT: {
      if (ret < (ssize_t)(sizeof(ev.type) + sizeof(ev.u.set_report))) {
        APPL_TRACE_ERROR(
            "%s: UHID_SET_REPORT: Invalid size read from "
            "uhid-dev: %zd < %zu",
            __func__, ret, sizeof(ev.type) + sizeof(ev.u.set_report));
        return -EFAULT;
      }
      APPL_TRACE_DEBUG(
          "UHID_SET_REPORT: Report type = %d, report_size = %d"
          " report id = %d",
          ev.u.set_report.rtype, ev.u.set_report.size, ev.u.set_report.id);
      if (p_dev->set_rpt_id_queue) {
        uint32_t* set_rpt_id = (uint32_t *)osi_malloc(sizeof(uint32_t));
        *set_rpt_id  = ev.u.set_report.id;
        fixed_queue_enqueue(p_dev->set_rpt_id_queue, (void *)set_rpt_id);
      }
      if (ev.u.set_report.rtype == UHID_FEATURE_REPORT)
        btif_hh_setreport(p_dev, BTHH_FEATURE_REPORT, ev.u.set_report.size,
                          ev.u.set_report.data);
      else if (ev.u.set_report.rtype == UHID_OUTPUT_REPORT)
        btif_hh_setreport(p_dev, BTHH_OUTPUT_REPORT, ev.u.set_report.size,
                          ev.u.set_report.data);
      else
        btif_hh_setreport(p_dev, BTHH_INPUT_REPORT, ev.u.set_report.size,
                          ev.u.set_report.data);
    } break;
    case UHID_GET_REPORT:
      if (ret < (ssize_t)(sizeof(ev.type) + sizeof(ev.u.get_report))) {
        APPL_TRACE_ERROR(
            "%s: UHID_GET_REPORT: Invalid size read from "
            "uhid-dev: %zd < %zu",
            __func__, ret, sizeof(ev.type) + sizeof(ev.u.get_report));
        return -EFAULT;
      }
      APPL_TRACE_DEBUG("UHID_GET_REPORT: Report type = %d",
                       ev.u.get_report.rtype);
      if (p_dev->get_rpt_id_queue) {
        uint32_t* get_rpt_id = (uint32_t*)osi_malloc(sizeof(uint32_t));
        *get_rpt_id = ev.u.get_report.id;
        fixed_queue_enqueue(p_dev->get_rpt_id_queue, (void *)get_rpt_id);
      }
      if (ev.u.get_report.rtype == UHID_FEATURE_REPORT)
        btif_hh_getreport(p_dev, BTHH_FEATURE_REPORT, ev.u.get_report.rnum, 0);
      else if (ev.u.get_report.rtype == UHID_OUTPUT_REPORT)
        btif_hh_getreport(p_dev, BTHH_OUTPUT_REPORT, ev.u.get_report.rnum, 0);
      else
        btif_hh_getreport(p_dev, BTHH_INPUT_REPORT, ev.u.get_report.rnum, 0);
      break;
#else   //  (LINUX_VERSION_CODE > KERNEL_VERSION(3,18,00))
    case UHID_FEATURE:
      APPL_TRACE_DEBUG("UHID_FEATURE from uhid-dev\n");
      break;
    case UHID_FEATURE_ANSWER:
      APPL_TRACE_DEBUG("UHID_FEATURE_ANSWER from uhid-dev\n");
      break;
#endif  //  (LINUX_VERSION_CODE > KERNEL_VERSION(3,18,00))
    default:
      APPL_TRACE_DEBUG("Invalid event from uhid-dev: %u\n", ev.type);
  }

  return 0;
}

/*******************************************************************************
 *
 * Function create_thread
 *
 * Description creat a select loop
 *
 * Returns pthread_t
 *
 ******************************************************************************/
static inline pthread_t create_thread(void* (*start_routine)(void*),
                                      void* arg) {
  APPL_TRACE_DEBUG("create_thread: entered");
  pthread_attr_t thread_attr;

  pthread_attr_init(&thread_attr);
  pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);
  pthread_t thread_id = -1;
  if (pthread_create(&thread_id, &thread_attr, start_routine, arg) != 0) {
    APPL_TRACE_ERROR("pthread_create : %s", strerror(errno));
    return -1;
  }
  APPL_TRACE_DEBUG("create_thread: thread created successfully");
  return thread_id;
}

/*******************************************************************************
 *
 * Function btif_hh_poll_event_thread
 *
 * Description the polling thread which polls for event from UHID driver
 *
 * Returns void
 *
 ******************************************************************************/
static void* btif_hh_poll_event_thread(void* arg) {
  btif_hh_device_t* p_dev = (btif_hh_device_t*)arg;
  APPL_TRACE_DEBUG("%s: Thread created fd = %d", __func__, p_dev->fd);
  struct pollfd pfds[1];

  pfds[0].fd = p_dev->fd;
  pfds[0].events = POLLIN;

  // Set the uhid fd as non-blocking to ensure we never block the BTU thread
  uhid_set_non_blocking(p_dev->fd);

  while (p_dev->hh_keep_polling) {
    int ret;
    OSI_NO_INTR(ret = poll(pfds, 1, 50));
    if (ret < 0) {
      APPL_TRACE_ERROR("%s: Cannot poll for fds: %s\n", __func__,
                       strerror(errno));
      break;
    }
    if (p_dev->fd == -1) {
      APPL_TRACE_ERROR("%s: fd is closed, stop the poll thread", __func__);
      p_dev->hh_keep_polling = 0;
      break;
    }
    if (pfds[0].revents & POLLIN) {
      APPL_TRACE_DEBUG("%s: POLLIN", __func__);
      ret = uhid_read_event(p_dev);
      if (ret != 0) break;
    }
  }

  p_dev->hh_poll_thread_id = -1;
  APPL_TRACE_DEBUG("%s: Thread destroyed", __func__);
  return 0;
}

static inline void btif_hh_close_poll_thread(btif_hh_device_t* p_dev) {
  APPL_TRACE_DEBUG("%s", __func__);
  p_dev->hh_keep_polling = 0;
  if (p_dev->hh_poll_thread_id > 0)
    pthread_join(p_dev->hh_poll_thread_id, NULL);

  return;
}

void bta_hh_co_destroy(int fd) {
  struct uhid_event ev;
  memset(&ev, 0, sizeof(ev));
  ev.type = UHID_DESTROY;
  uhid_write(fd, &ev);
  APPL_TRACE_DEBUG("%s: Closing fd=%d", __func__, fd);
  close(fd);
}

int bta_hh_co_write(int fd, uint8_t* rpt, uint16_t len) {
  APPL_TRACE_VERBOSE("%s: UHID write %d", __func__, len);

  struct uhid_event ev;
  memset(&ev, 0, sizeof(ev));
  ev.type = UHID_INPUT;
  ev.u.input.size = len;
  if (len > sizeof(ev.u.input.data)) {
    APPL_TRACE_WARNING("%s: Report size greater than allowed size", __func__);
    return -1;
  }
  memcpy(ev.u.input.data, rpt, len);

  return uhid_write(fd, &ev);
}

/*******************************************************************************
 *
 * Function      bta_hh_co_open
 *
 * Description   When connection is opened, this call-out function is executed
 *               by HH to do platform specific initialization.
 *
 * Returns       void.
 ******************************************************************************/
void bta_hh_co_open(uint8_t dev_handle, uint8_t sub_class,
                    tBTA_HH_ATTR_MASK attr_mask, uint8_t app_id) {
  uint32_t i;
  btif_hh_device_t* p_dev = NULL;

  if (dev_handle == BTA_HH_INVALID_HANDLE) {
    APPL_TRACE_WARNING("%s: Oops, dev_handle (%d) is invalid...", __func__,
                       dev_handle);
    return;
  }

  for (i = 0; i < BTIF_HH_MAX_HID; i++) {
    p_dev = &btif_hh_cb.devices[i];
    if (p_dev->dev_status != BTHH_CONN_STATE_UNKNOWN &&
        p_dev->dev_handle == dev_handle) {
      // We found a device with the same handle. Must be a device reconnected.
      APPL_TRACE_WARNING(
          "%s: Found an existing device with the same handle "
          "dev_status = %d",
          __func__, p_dev->dev_status);
      APPL_TRACE_WARNING("%s:     bd_addr = [%02X:%02X:%02X:%02X:%02X:]",
                         __func__, p_dev->bd_addr.address[0],
                         p_dev->bd_addr.address[1], p_dev->bd_addr.address[2],
                         p_dev->bd_addr.address[3], p_dev->bd_addr.address[4]);
      APPL_TRACE_WARNING(
          "%s:     attr_mask = 0x%04x, sub_class = 0x%02x, app_id = %d",
          __func__, p_dev->attr_mask, p_dev->sub_class, p_dev->app_id);

      if (p_dev->fd < 0) {
        p_dev->fd = open(dev_path, O_RDWR | O_CLOEXEC);
        if (p_dev->fd < 0) {
          APPL_TRACE_ERROR("%s: Error: failed to open uhid, err:%s", __func__,
                           strerror(errno));
          return;
        } else
          APPL_TRACE_DEBUG("%s: uhid fd = %d", __func__, p_dev->fd);
      }

      p_dev->hh_keep_polling = 1;
      p_dev->hh_poll_thread_id =
          create_thread(btif_hh_poll_event_thread, p_dev);
      break;
    }
    p_dev = NULL;
  }

  if (p_dev == NULL) {
    // Did not find a device reconnection case. Find an empty slot now.
    for (i = 0; i < BTIF_HH_MAX_HID; i++) {
      if (btif_hh_cb.devices[i].dev_status == BTHH_CONN_STATE_UNKNOWN) {
        p_dev = &btif_hh_cb.devices[i];
        p_dev->dev_handle = dev_handle;
        p_dev->attr_mask = attr_mask;
        p_dev->sub_class = sub_class;
        p_dev->app_id = app_id;
        p_dev->local_vup = false;
        p_dev->fd_3d_audio = -1;
        p_dev->fd_3d_audio_connected = false;

        btif_hh_cb.device_num++;
        // This is a new device,open the uhid driver now.
        p_dev->fd = open(dev_path, O_RDWR | O_CLOEXEC);
        if (p_dev->fd < 0) {
          APPL_TRACE_ERROR("%s: Error: failed to open uhid, err:%s", __func__,
                           strerror(errno));
          return;
        } else {
          APPL_TRACE_DEBUG("%s: uhid fd = %d", __func__, p_dev->fd);
          p_dev->hh_keep_polling = 1;
          p_dev->hh_poll_thread_id =
              create_thread(btif_hh_poll_event_thread, p_dev);
        }

        break;
      }
    }
  }

  if (p_dev == NULL) {
    APPL_TRACE_ERROR("%s: Error: too many HID devices are connected", __func__);
    return;
  }

  p_dev->dev_status = BTHH_CONN_STATE_CONNECTED;
  memset(&p_dev->last_output_rpt_data, 0, UHID_DATA_MAX);
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 18, 00))
  p_dev->set_rpt_id_queue = fixed_queue_new(SIZE_MAX);
  CHECK(p_dev->set_rpt_id_queue);
  p_dev->get_rpt_id_queue = fixed_queue_new(SIZE_MAX);
  CHECK(p_dev->get_rpt_id_queue);
#endif  //  (LINUX_VERSION_CODE > KERNEL_VERSION(3,18,00))

  APPL_TRACE_DEBUG("%s: Return device status %d", __func__, p_dev->dev_status);
}

/*******************************************************************************
 *
 * Function      bta_hh_co_close
 *
 * Description   When connection is closed, this call-out function is executed
 *               by HH to do platform specific finalization.
 *
 * Parameters    dev_handle  - device handle
 *                  app_id      - application id
 *
 * Returns          void.
 ******************************************************************************/
void bta_hh_co_close(uint8_t dev_handle, uint8_t app_id) {
  uint32_t i;
  btif_hh_device_t* p_dev = NULL;

  APPL_TRACE_WARNING("%s: dev_handle = %d, app_id = %d", __func__, dev_handle,
                     app_id);
  if (dev_handle == BTA_HH_INVALID_HANDLE) {
    APPL_TRACE_WARNING("%s: Oops, dev_handle (%d) is invalid...", __func__,
                       dev_handle);
    return;
  }

  for (i = 0; i < BTIF_HH_MAX_HID; i++) {
    p_dev = &btif_hh_cb.devices[i];
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 18, 00))
    fixed_queue_flush(p_dev->set_rpt_id_queue, osi_free);
    fixed_queue_free(p_dev->set_rpt_id_queue, NULL);
    p_dev->set_rpt_id_queue = NULL;
    fixed_queue_flush(p_dev->get_rpt_id_queue, osi_free);
    fixed_queue_free(p_dev->get_rpt_id_queue, NULL);
    p_dev->get_rpt_id_queue = NULL;
#endif  //  (LINUX_VERSION_CODE > KERNEL_VERSION(3,18,00))
    if (p_dev->dev_status != BTHH_CONN_STATE_UNKNOWN &&
        p_dev->dev_handle == dev_handle) {
      APPL_TRACE_WARNING(
          "%s: Found an existing device with the same handle "
          "dev_status = %d, dev_handle =%d",
          __func__, p_dev->dev_status, p_dev->dev_handle);
      memset(&p_dev->last_output_rpt_data, 0, UHID_DATA_MAX);
      if (p_dev->fd_3d_audio >= 0)
        close(p_dev->fd_3d_audio);
      p_dev->fd_3d_audio = -1;
      p_dev->fd_3d_audio_connected = false;
      btif_hh_close_poll_thread(p_dev);
      break;
    }
  }
}

/*******************************************************************************
 *
 * Function         bta_hh_co_data
 *
 * Description      This function is executed by BTA when HID host receive a
 *                  data report.
 *
 * Parameters       dev_handle  - device handle
 *                  *p_rpt      - pointer to the report data
 *                  len         - length of report data
 *                  mode        - Hid host Protocol Mode
 *                  sub_clas    - Device Subclass
 *                  app_id      - application id
 *
 * Returns          void
 ******************************************************************************/
void bta_hh_co_data(uint8_t dev_handle, uint8_t* p_rpt, uint16_t len,
                    tBTA_HH_PROTO_MODE mode, uint8_t sub_class,
                    uint8_t ctry_code, UNUSED_ATTR const RawAddress& peer_addr,
                    uint8_t app_id) {
  btif_hh_device_t* p_dev;
  uint8_t* p_skt_data = p_rpt;
  uint16_t total_len = 0, count = 0;
  int sent = 0;
  total_len = len;

  APPL_TRACE_DEBUG(
      "%s: dev_handle = %d, subclass = 0x%02X, mode = %d, "
      "ctry_code = %d, app_id = %d",
      __func__, dev_handle, sub_class, mode, ctry_code, app_id);

  p_dev = btif_hh_find_connected_dev_by_handle(dev_handle);
  if (p_dev == NULL) {
    APPL_TRACE_WARNING("%s: Error: unknown HID device handle %d", __func__,
                       dev_handle);
    return;
  }

  // Wait a maximum of MAX_POLLING_ATTEMPTS x POLLING_SLEEP_DURATION in case
  // device creation is pending.
  if (p_dev->fd >= 0) {
    uint32_t polling_attempts = 0;
    while (!p_dev->ready_for_data &&
           polling_attempts++ < BTIF_HH_MAX_POLLING_ATTEMPTS) {
      usleep(BTIF_HH_POLLING_SLEEP_DURATION_US);
    }
  }

  // Send the HID data to the kernel.
  if ((p_dev->fd >= 0) && p_dev->ready_for_data) {
    bta_hh_co_write(p_dev->fd, p_rpt, len);
    if ((btif_hh_cb.hid_3d_audio == true) && (p_dev->attr_mask & HID_3D_AUDIO)) {
      if (p_dev->fd_3d_audio < 0) {
        p_dev->fd_3d_audio = socket(AF_LOCAL, SOCK_SEQPACKET, 0);
        if (p_dev->fd_3d_audio < 0) {
           APPL_TRACE_ERROR("%s: socket creation failed", __func__);
        }
      }
      if (p_dev->fd_3d_audio >= 0) {
        if (p_dev->fd_3d_audio_connected == false) {
          if (osi_socket_local_client_connect(p_dev->fd_3d_audio,
              hid_3d_audio_path, ANDROID_SOCKET_NAMESPACE_FILESYSTEM,
              SOCK_SEQPACKET) < 0) {
            APPL_TRACE_ERROR("%s: socket connect failed", __func__);
            close(p_dev->fd_3d_audio);
            p_dev->fd_3d_audio = -1;
          } else p_dev->fd_3d_audio_connected = true;
        }
        if (p_dev->fd_3d_audio_connected == true) {
           APPL_TRACE_WARNING("%s: Writing to socket, len =%d", __func__, len);
             //write to socket
             while (count < total_len) {
             OSI_NO_INTR(sent = send(p_dev->fd_3d_audio, p_skt_data,
                 total_len - count, MSG_NOSIGNAL | MSG_DONTWAIT));
             if (sent == -1) {
               if (errno != EAGAIN && errno != EWOULDBLOCK) {
                 APPL_TRACE_ERROR("%s: write failed with error: %d",
                     strerror(errno));
                 p_dev->fd_3d_audio_connected = false;
                 close(p_dev->fd_3d_audio);
                 p_dev->fd_3d_audio = -1;
               }
             }
             count += sent;
             p_skt_data = (uint8_t*)p_skt_data + sent;
           }
        }
      }
    }
  } else {
    APPL_TRACE_WARNING("%s: Error: fd = %d, ready %d, len = %d", __func__,
                       p_dev->fd, p_dev->ready_for_data, len);
  }
}

/*******************************************************************************
 *
 * Function         bta_hh_co_send_hid_info
 *
 * Description      This function is called in btif_hh.c to process DSCP
 *                  received.
 *
 * Parameters       dev_handle  - device handle
 *                  dscp_len    - report descriptor length
 *                  *p_dscp     - report descriptor
 *
 * Returns          0 on success else error code
 ******************************************************************************/
int bta_hh_co_send_hid_info(btif_hh_device_t* p_dev, const char* dev_name,
                             uint16_t vendor_id, uint16_t product_id,
                             uint16_t version, uint8_t ctry_code, int dscp_len,
                             uint8_t* p_dscp) {
  int result;
  struct uhid_event ev;

  if (p_dev->fd < 0) {
    APPL_TRACE_WARNING("%s: Error: fd = %d, dscp_len = %d", __func__, p_dev->fd,
                       dscp_len);
    return p_dev->fd;
  }

  APPL_TRACE_WARNING("%s: fd = %d, name = [%s], dscp_len = %d", __func__,
                     p_dev->fd, dev_name, dscp_len);
  APPL_TRACE_WARNING("%s: attr_mask = %04x", __func__, p_dev->attr_mask);
  APPL_TRACE_WARNING(
      "%s: vendor_id = 0x%04x, product_id = 0x%04x, version= 0x%04x,"
      "ctry_code=0x%02x",
      __func__, vendor_id, product_id, version, ctry_code);

  if (interop_match_vendor_product_ids(INTEROP_REMOVE_HID_DIG_DESCRIPTOR,
                                       vendor_id, product_id) ||
      interop_match_name(INTEROP_REMOVE_HID_DIG_DESCRIPTOR, dev_name))
    remove_digitizer_descriptor(p_dscp, (uint16_t*)&dscp_len);

  // Create and send hid descriptor to kernel
  memset(&ev, 0, sizeof(ev));
  ev.type = UHID_CREATE;
  strlcpy((char*)ev.u.create.name, dev_name, sizeof(ev.u.create.name));
  snprintf((char*)ev.u.create.uniq, sizeof(ev.u.create.uniq), "%s",
           p_dev->bd_addr.ToString().c_str());
  ev.u.create.rd_size = dscp_len;
  ev.u.create.rd_data = p_dscp;
  ev.u.create.bus = BUS_BLUETOOTH;
  ev.u.create.vendor = vendor_id;
  ev.u.create.product = product_id;
  ev.u.create.version = version;
  ev.u.create.country = ctry_code;
  result = uhid_write(p_dev->fd, &ev);

  APPL_TRACE_WARNING(
      "%s: wrote descriptor to fd = %d, dscp_len = %d, result = %d", __func__,
      p_dev->fd, dscp_len, result);

  if (result) {
    APPL_TRACE_WARNING("%s: Error: failed to send DSCP, result = %d", __func__,
                       result);
  }

  return result;
}

/*******************************************************************************
 *
 * Function         bta_hh_co_set_rpt_rsp
 *
 * Description      This callout function is executed by HH when Set Report
 *                  Response is received on Control Channel.
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_hh_co_set_rpt_rsp(uint8_t dev_handle, uint8_t status) {
  btif_hh_device_t* p_dev;

  APPL_TRACE_DEBUG("%s: dev_handle = %d, status = %d", __func__, dev_handle,
                     status);

  p_dev = btif_hh_find_connected_dev_by_handle(dev_handle);
  if (p_dev == NULL) {
    APPL_TRACE_WARNING("%s: Error: unknown HID device handle %d", __func__,
                       dev_handle);
    return;
  }
  if (!p_dev->set_rpt_id_queue || p_dev->fd < 0) return;

  if (fixed_queue_is_empty(p_dev->set_rpt_id_queue)) {
      APPL_TRACE_WARNING("%s: Queue is empty", __func__);
      return;
  }

  // Send the HID report to the kernel.
  struct uhid_event ev;
  uint32_t* set_rpt_id =
      (uint32_t*)fixed_queue_try_dequeue(p_dev->set_rpt_id_queue);

  if (set_rpt_id == NULL) {
      APPL_TRACE_WARNING("%s: Unable to dequeue report id", __func__);
      return;
  }

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  memset(&ev, 0, sizeof(ev));
  ev.type = UHID_SET_REPORT_REPLY;
  /* get the report id from queue_start pointer */
  ev.u.set_report_reply.id = *set_rpt_id;
  APPL_TRACE_DEBUG("%s: set_report_reply_id = %d", __func__,
                     ev.u.set_report_reply.id);
  ev.u.set_report_reply.err = status;
  uhid_write(p_dev->fd, &ev);
#endif //OFF_TARGET_TEST_ENABLED
  osi_free(set_rpt_id);
}

/*******************************************************************************
 *
 * Function         bta_hh_co_get_rpt_rsp
 *
 * Description      This callout function is executed by HH when Get Report
 *                  Response is received on Control Channel.
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_hh_co_get_rpt_rsp(uint8_t dev_handle, uint8_t status, uint8_t* p_rpt,
                           uint16_t len) {
  btif_hh_device_t* p_dev;

  APPL_TRACE_DEBUG("%s: dev_handle = %d. status = %d, len = %d", __func__,
                     dev_handle, status, len);

  p_dev = btif_hh_find_connected_dev_by_handle(dev_handle);
  if (p_dev == NULL) {
    APPL_TRACE_WARNING("%s: Error: unknown HID device handle %d", __func__,
                       dev_handle);
    return;
  }
  if (!p_dev->get_rpt_id_queue || p_dev->fd < 0) return;

  if (fixed_queue_is_empty(p_dev->get_rpt_id_queue)) {
      APPL_TRACE_WARNING("%s: Queue is empty", __func__);
      return;
  }

  // Send the HID report to the kernel.
  struct uhid_event ev;
  uint32_t* get_rpt_id =
      (uint32_t*)fixed_queue_try_dequeue(p_dev->get_rpt_id_queue);

  if (get_rpt_id == NULL) {
      APPL_TRACE_WARNING("%s: Unable to dequeue report id", __func__);
      return;
  }

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  memset(&ev, 0, sizeof(ev));
  ev.type = UHID_GET_REPORT_REPLY;
  ev.u.get_report_reply.err = status;
  ev.u.get_report_reply.size = len;
  /* get the report id from queue_start pointer */
  ev.u.get_report_reply.id = *get_rpt_id;
  APPL_TRACE_DEBUG("%s: get_report_reply_id = %d", __func__,
                     ev.u.get_report_reply.id);
  if (len > 0) {
    if (len > UHID_DATA_MAX) {
      APPL_TRACE_WARNING("%s: Report size greater than allowed size", __func__);
      return;
    }
    memcpy(ev.u.get_report_reply.data, p_rpt + BT_HID_RPT_OFFSET, len);
  }
  uhid_write(p_dev->fd, &ev);
#endif
  osi_free(get_rpt_id);
}

#if (BTA_HH_LE_INCLUDED == TRUE)
/*******************************************************************************
 *
 * Function         bta_hh_le_co_rpt_info
 *
 * Description      This callout function is to convey the report information on
 *                  a HOGP device to the application. Application can save this
 *                  information in NV if device is bonded and load it back when
 *                  stack reboot.
 *
 * Parameters       remote_bda  - remote device address
 *                  p_entry     - report entry pointer
 *                  app_id      - application id
 *
 * Returns          void.
 *
 ******************************************************************************/
void bta_hh_le_co_rpt_info(const RawAddress& remote_bda,
                           tBTA_HH_RPT_CACHE_ENTRY* p_entry,
                           UNUSED_ATTR uint8_t app_id) {
  unsigned idx = 0;

  std::string addrstr = remote_bda.ToString();
  const char* bdstr = addrstr.c_str();

  size_t len = btif_config_get_bin_length(bdstr, "HidReport");
  if (len >= sizeof(tBTA_HH_RPT_CACHE_ENTRY) && len <= sizeof(sReportCache)) {
    btif_config_get_bin(bdstr, "HidReport", (uint8_t*)sReportCache, &len);
    idx = len / sizeof(tBTA_HH_RPT_CACHE_ENTRY);
  }

  if (idx < BTA_HH_NV_LOAD_MAX) {
    memcpy(&sReportCache[idx++], p_entry, sizeof(tBTA_HH_RPT_CACHE_ENTRY));
    btif_config_set_bin(bdstr, "HidReport", (const uint8_t*)sReportCache,
                        idx * sizeof(tBTA_HH_RPT_CACHE_ENTRY));
    BTIF_TRACE_DEBUG("%s() - Saving report; dev=%s, idx=%d", __func__, bdstr,
                     idx);
  }
}

/*******************************************************************************
 *
 * Function         bta_hh_le_co_cache_load
 *
 * Description      This callout function is to request the application to load
 *                  the cached HOGP report if there is any. When cache reading
 *                  is completed, bta_hh_le_ci_cache_load() is called by the
 *                  application.
 *
 * Parameters       remote_bda  - remote device address
 *                  p_num_rpt: number of cached report
 *                  app_id      - application id
 *
 * Returns          the acched report array
 *
 ******************************************************************************/
tBTA_HH_RPT_CACHE_ENTRY* bta_hh_le_co_cache_load(const RawAddress& remote_bda,
                                                 uint8_t* p_num_rpt,
                                                 UNUSED_ATTR uint8_t app_id) {
  std::string addrstr = remote_bda.ToString();
  const char* bdstr = addrstr.c_str();

  size_t len = btif_config_get_bin_length(bdstr, "HidReport");
  if (!p_num_rpt || len < sizeof(tBTA_HH_RPT_CACHE_ENTRY)) return NULL;

  if (len > sizeof(sReportCache)) len = sizeof(sReportCache);
  btif_config_get_bin(bdstr, "HidReport", (uint8_t*)sReportCache, &len);
  *p_num_rpt = len / sizeof(tBTA_HH_RPT_CACHE_ENTRY);

  BTIF_TRACE_DEBUG("%s() - Loaded %d reports; dev=%s", __func__, *p_num_rpt,
                   bdstr);

  return sReportCache;
}

/*******************************************************************************
 *
 * Function         bta_hh_le_co_reset_rpt_cache
 *
 * Description      This callout function is to reset the HOGP device cache.
 *
 * Parameters       remote_bda  - remote device address
 *
 * Returns          none
 *
 ******************************************************************************/
void bta_hh_le_co_reset_rpt_cache(const RawAddress& remote_bda,
                                  UNUSED_ATTR uint8_t app_id) {
  std::string addrstr = remote_bda.ToString();
  const char* bdstr = addrstr.c_str();

  btif_config_remove(bdstr, "HidReport");

  BTIF_TRACE_DEBUG("%s() - Reset cache for bda %s", __func__, bdstr);
}

#endif  // (BTA_HH_LE_INCLUDED == TRUE)
