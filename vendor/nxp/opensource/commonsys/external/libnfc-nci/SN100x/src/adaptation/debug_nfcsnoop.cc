/******************************************************************************
 *
 *  Copyright (C) 2017 Google Inc.
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
 *  The original Work has been changed by NXP.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright 2020 NXP
 *
 ******************************************************************************/

#include <android-base/logging.h>
#include <android-base/stringprintf.h>
#include <resolv.h>
#include <zlib.h>
#include <mutex>

#include <ringbuffer.h>

#include <cutils/properties.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "bt_types.h"
#include "include/debug_nfcsnoop.h"
#include "nfc_int.h"

#define USEC_PER_SEC 1000000ULL

#define DEFAULT_NFCSNOOP_PATH "/data/misc/nfc/logs/nfcsnoop_nci_logs"
#define DEFAULT_NFCSNOOP_FILE_SIZE 32 * 1024 * 1024

// Total nfcsnoop memory log buffer size
#ifndef NFCSNOOP_MEM_BUFFER_SIZE
static const size_t NFCSNOOP_MEM_BUFFER_SIZE = (256 * 1024);
#endif

#define NFCSNOOP_MEM_BUFFER_THRESHOLD 1024

// Block size for copying buffers (for compression/encoding etc.)
static const size_t BLOCK_SIZE = 16384;

// Maximum line length in bugreport (should be multiple of 4 for base64 output)
static const uint8_t MAX_LINE_LENGTH = 128;

static std::mutex buffer_mutex;
static ringbuffer_t* buffer = nullptr;
static uint64_t last_timestamp_ms = 0;
static bool isDebuggable = false;

using android::base::StringPrintf;

static void nfcsnoop_cb(const uint8_t* data, const size_t length,
                        bool is_received, const uint64_t timestamp_us) {
  nfcsnooz_header_t header;

  std::lock_guard<std::mutex> lock(buffer_mutex);

  // Make room in the ring buffer

  while (ringbuffer_available(buffer) < (length + sizeof(nfcsnooz_header_t))) {
    ringbuffer_pop(buffer, (uint8_t*)&header, sizeof(nfcsnooz_header_t));
    ringbuffer_delete(buffer, header.length);
  }

  // Insert data
  header.length = length;
  header.is_received = is_received ? 1 : 0;

  uint64_t delta_time_ms = 0;
  if (last_timestamp_ms) {
    __builtin_sub_overflow(timestamp_us, last_timestamp_ms, &delta_time_ms);
  }
  header.delta_time_ms = delta_time_ms;

  last_timestamp_ms = timestamp_us;

  ringbuffer_insert(buffer, (uint8_t*)&header, sizeof(nfcsnooz_header_t));
  ringbuffer_insert(buffer, data, length);
}

static bool nfcsnoop_compress(ringbuffer_t* rb_dst, ringbuffer_t* rb_src) {
  CHECK(rb_dst != nullptr);
  CHECK(rb_src != nullptr);

  z_stream zs;
  zs.zalloc = Z_NULL;
  zs.zfree = Z_NULL;
  zs.opaque = Z_NULL;

  if (deflateInit(&zs, Z_DEFAULT_COMPRESSION) != Z_OK) return false;

  bool rc = true;
#if (NXP_EXTNS == TRUE)
  std::unique_ptr<uint8_t> block_src(new uint8_t[BLOCK_SIZE]);
  std::unique_ptr<uint8_t> block_dst(new uint8_t[BLOCK_SIZE]);
#else
  uint8_t block_src[BLOCK_SIZE];
  uint8_t block_dst[BLOCK_SIZE];
#endif

  const size_t num_blocks =
      (ringbuffer_size(rb_src) + BLOCK_SIZE - 1) / BLOCK_SIZE;
  for (size_t i = 0; i < num_blocks; ++i) {
    zs.avail_in =
#if (NXP_EXTNS == TRUE)
        ringbuffer_peek(rb_src, i * BLOCK_SIZE, block_src.get(), BLOCK_SIZE);
    zs.next_in = block_src.get();
#else
        ringbuffer_peek(rb_src, i * BLOCK_SIZE, block_src, BLOCK_SIZE);
    zs.next_in = block_src;
#endif

    do {
      zs.avail_out = BLOCK_SIZE;
#if (NXP_EXTNS == TRUE)
      zs.next_out = block_dst.get();
#else
      zs.next_out = block_dst;
#endif
      int err = deflate(&zs, (i == num_blocks - 1) ? Z_FINISH : Z_NO_FLUSH);
      if (err == Z_STREAM_ERROR) {
        rc = false;
        break;
      }

      const size_t length = BLOCK_SIZE - zs.avail_out;
#if (NXP_EXTNS == TRUE)
      ringbuffer_insert(rb_dst, block_dst.get(), length);
#else
      ringbuffer_insert(rb_dst, block_dst, length);
#endif
    } while (zs.avail_out == 0);
  }

  deflateEnd(&zs);
  return rc;
}

void nfcsnoop_capture(const NFC_HDR* packet, bool is_received) {
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  uint64_t timestamp = static_cast<uint64_t>(tv.tv_sec) * USEC_PER_SEC +
                       static_cast<uint64_t>(tv.tv_usec);
  uint8_t* p = (uint8_t*)(packet + 1) + packet->offset;
  uint8_t mt = (*(p)&NCI_MT_MASK) >> NCI_MT_SHIFT;
  if (isDebuggable &&
      ringbuffer_available(buffer) < NFCSNOOP_MEM_BUFFER_THRESHOLD) {
    if (storeNfcSnoopLogs(DEFAULT_NFCSNOOP_PATH, DEFAULT_NFCSNOOP_FILE_SIZE)) {
      std::lock_guard<std::mutex> lock(buffer_mutex);
      // Free the buffer after the content is stored in log file
      ringbuffer_free(buffer);
      buffer = nullptr;
      // Allocate new buffer to store new NCI logs
      debug_nfcsnoop_init();
    }
  }
  if (mt == NCI_MT_DATA) {
    nfcsnoop_cb(p, NCI_DATA_HDR_SIZE, is_received, timestamp);
  } else if (packet->len > 2) {
    nfcsnoop_cb(p, p[2] + NCI_MSG_HDR_SIZE, is_received, timestamp);
  }
}

void debug_nfcsnoop_init(void) {
  if (buffer == nullptr) buffer = ringbuffer_init(NFCSNOOP_MEM_BUFFER_SIZE);
  isDebuggable = property_get_int32("ro.debuggable", 0);
}

void debug_nfcsnoop_dump(int fd) {
  if (buffer == nullptr) {
    dprintf(fd, "%s Nfcsnoop is not ready\n", __func__);
    return;
  }
  ringbuffer_t* ringbuffer = ringbuffer_init(NFCSNOOP_MEM_BUFFER_SIZE);
  if (ringbuffer == nullptr) {
    dprintf(fd, "%s Unable to allocate memory for compression", __func__);
    return;
  }

  // Prepend preamble

  nfcsnooz_preamble_t preamble;
  preamble.version = NFCSNOOZ_CURRENT_VERSION;
  preamble.last_timestamp_ms = last_timestamp_ms;
  ringbuffer_insert(ringbuffer, (uint8_t*)&preamble,
                    sizeof(nfcsnooz_preamble_t));

  // Compress data

  uint8_t b64_in[3] = {0};
  char b64_out[5] = {0};

  size_t line_length = 0;

  bool rc;
  {
    std::lock_guard<std::mutex> lock(buffer_mutex);
    dprintf(fd, "--- BEGIN:NFCSNOOP_LOG_SUMMARY (%zu bytes in) ---\n",
            ringbuffer_size(buffer));
    rc = nfcsnoop_compress(ringbuffer, buffer);
  }

  if (rc == false) {
    dprintf(fd, "%s Log compression failed", __func__);
    goto error;
  }

  // Base64 encode & output

  while (ringbuffer_size(ringbuffer) > 0) {
    size_t read = ringbuffer_pop(ringbuffer, b64_in, 3);
    if (line_length >= MAX_LINE_LENGTH) {
      dprintf(fd, "\n");
      line_length = 0;
    }
    line_length += b64_ntop(b64_in, read, b64_out, 5);
    dprintf(fd, "%s", b64_out);
  }

  dprintf(fd, "\n--- END:NFCSNOOP_LOG_SUMMARY ---\n");

error:
  ringbuffer_free(ringbuffer);
}

bool storeNfcSnoopLogs(std::string filepath, off_t maxFileSize) {
  int fileStream;
  off_t fileSize;
  // check file size
  struct stat st;
  if (stat(filepath.c_str(), &st) == 0) {
    fileSize = st.st_size;
  } else {
    fileSize = 0;
  }

  mode_t prevmask = umask(0);
  if (fileSize >= maxFileSize) {
    fileStream = open(filepath.c_str(), O_RDWR | O_CREAT | O_TRUNC,
                      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  } else {
    fileStream = open(filepath.c_str(), O_RDWR | O_CREAT | O_APPEND,
                      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  }
  umask(prevmask);

  if (fileStream >= 0) {
    debug_nfcsnoop_dump(fileStream);
    close(fileStream);
    return true;
  } else {
    LOG(ERROR) << StringPrintf("%s: fail to create, error = %d", __func__,
                               errno);
    return false;
  }
}
