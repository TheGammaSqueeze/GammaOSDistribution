/******************************************************************************
 *
 *  Copyright (C) 2014 Google, Inc.
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

#define LOG_TAG "bt_snoop"

#include <mutex>

#include <arpa/inet.h>
#include <base/logging.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/uio.h>
#include <unistd.h>
#include <mutex>
#include <unordered_map>
#include <unordered_set>

#include "bt_types.h"
#include "hci/include/btsnoop.h"
#include "hci/include/btsnoop_mem.h"
#include "hci_layer.h"
#include "internal_include/bt_trace.h"
#include "osi/include/log.h"
#include "osi/include/properties.h"
#include "osi/include/time.h"
#include "stack/include/hcimsgs.h"
#include "stack/include/rfcdefs.h"
#include "stack/l2cap/l2c_int.h"
#include "stack_config.h"
#include "l2c_api.h"
#include <poll.h>
#include "buffer_allocator.h"

// The number of of packets per btsnoop file before we rotate to the next
// file. As of right now there are two snoop files that are rotated through.
// The size can be dynamically configured by seting the relevant system
// property
#define DEFAULT_BTSNOOP_SIZE 0xffff
#define HANDLE_MASK 0x0FFF
#define START_PACKET_BOUNDARY 2
#define CONTINUATION_PACKET_BOUNDARY 1
#define GET_BOUNDARY_FLAG(handle) (((handle) >> 12) & 0x0003)

#define IS_DEBUGGABLE_PROPERTY "ro.debuggable"

#define BTSNOOP_LOG_MODE_PROPERTY "persist.bluetooth.btsnooplogmode"
#define BTSNOOP_DEFAULT_MODE_PROPERTY "persist.bluetooth.btsnoopdefaultmode"
#define BTSNOOP_LOG_FILTER_PROFILES_PROPERTY    "persist.bluetooth.snoopfilter.profiles"
#define BTSNOOP_LOG_PROFILE_FILTERMODE_PROPERTY "persist.bluetooth.snoopfilter.mode"
#define BTSNOOP_MODE_DISABLED "disabled"
#define BTSNOOP_MODE_FILTERED "filtered"
#define BTSNOOP_MODE_FULL "full"
#define BTSNOOP_MODE_SNOOPHEADERSFILTERED "snoopheadersfiltered"
#define BTSNOOP_MODE_MEDIAPKTSFILTERED "mediapktsfiltered"
#define BTSNOOP_MODE_PROFILESFILTERED "profilesfiltered"

#define BTSNOOP_PATH_PROPERTY "persist.bluetooth.btsnooppath"
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  #define DEFAULT_BTSNOOP_PATH "/data/misc/bluetooth/logs/btsnoop_hci.log"
#else
  #define DEFAULT_BTSNOOP_PATH "btsnoop_hci.log"
#endif  //OFF_TARGET_TEST_ENABLED
#define BTSNOOP_MAX_PACKETS_PROPERTY "persist.bluetooth.btsnoopsize"

typedef enum {
  kCommandPacket = 1,
  kAclPacket = 2,
  kScoPacket = 3,
  kEventPacket = 4
} packet_type_t;

enum {
  FILTER_MODE_FULLFILTER = 0,
  FILTER_MODE_HEADER,
  FILTER_MODE_MAGIC,
};

// Epoch in microseconds since 01/01/0000.
static const uint64_t BTSNOOP_EPOCH_DELTA = 0x00dcddb30f2f8000ULL;

// Number of bytes into a packet where you can find the value for a channel.
static const size_t ACL_CHANNEL_OFFSET = 0;
static const size_t ACL_LENGTH_OFFSET = 2;
static const size_t L2C_CHANNEL_OFFSET = 6;
static const size_t L2C_LENGTH_OFFSET = 4;
static const size_t RFC_CHANNEL_OFFSET = 8;
static const size_t RFC_EVENT_OFFSET = 9;

// The size of the L2CAP header. All information past this point is removed from
// a filtered packet.
static const uint32_t L2C_HEADER_SIZE = 9;

static int logfile_fd = INVALID_FD;
static std::mutex btsnoop_mutex;
static std::mutex btSnoopFd_mutex;

static int32_t packets_per_file;
static int32_t packet_counter;
static bool sock_snoop_active = false;

extern bt_logger_interface_t *logger_interface;
int64_t gmt_offset;
int64_t tmp_gmt_offset;

static bool pbap_filtered, map_filtered;
static int profile_filter_mode; // fullfilter, header, magic
static const char *payload_fill_magic = "PROHIBITED";
static const char *cpbr_pattern = "\x0d\x0a+CPBR:";

#define PACKET_TYPE_LENGTH 1
#define HCI_HEADER_LENGTH 4
#define L2C_HEADER_LENGTH 4
#define DEFAULT_PACKET_SIZE 0x800
#define EXTRA_BUF_SIZE 0x40

static uint8_t packet[DEFAULT_PACKET_SIZE];

// Channel tracking variables for filtering.

// Keeps track of L2CAP channels that need to be filtered out of the snoop
// logs.
class FilterTracker {
 public:
  // NOTE: 1 is used as a static CID for L2CAP signaling
  std::unordered_set<uint16_t> l2c_local_cid = {1};
  std::unordered_set<uint16_t> l2c_remote_cid = {1};
  uint16_t rfc_local_cid = 0;
  uint16_t rfc_remote_cid = 0;
  std::unordered_set<uint16_t> rfc_channels = {0};

  // Adds L2C channel to whitelist.
  void addL2cCid(uint16_t local_cid, uint16_t remote_cid) {
    l2c_local_cid.insert(local_cid);
    l2c_remote_cid.insert(remote_cid);
  }

  // Sets L2CAP channel that RFCOMM uses.
  void setRfcCid(uint16_t local_cid, uint16_t remote_cid) {
    rfc_local_cid = local_cid;
    rfc_remote_cid = remote_cid;
  }

  // Remove L2C channel from whitelist.
  void removeL2cCid(uint16_t local_cid, uint16_t remote_cid) {
    if (rfc_local_cid == local_cid) {
      rfc_channels.clear();
      rfc_channels.insert(0);
      rfc_local_cid = 0;
      rfc_remote_cid = 0;
    }

    l2c_local_cid.erase(local_cid);
    l2c_remote_cid.erase(remote_cid);
  }

  void addRfcDlci(uint8_t channel) { rfc_channels.insert(channel); }

  bool isWhitelistedL2c(bool local, uint16_t cid) {
    const auto& set = local ? l2c_local_cid : l2c_remote_cid;
    return (set.find(cid) != set.end());
  }

  bool isRfcChannel(bool local, uint16_t cid) {
    const auto& channel = local ? rfc_local_cid : rfc_remote_cid;
    return cid == channel;
  }

  bool isWhitelistedDlci(uint8_t dlci) {
    return rfc_channels.find(dlci) != rfc_channels.end();
  }
};

std::mutex filter_list_mutex;
std::unordered_map<uint16_t, FilterTracker> filter_list;
std::unordered_map<uint16_t, uint16_t> local_cid_to_acl;

typedef enum {
  FILTER_PROFILE_NONE = -1,
  FILTER_PROFILE_PBAP = 0,
  FILTER_PROFILE_HFP_HS,
  FILTER_PROFILE_HFP_HF,
  FILTER_PROFILE_MAP,
  FILTER_PROFILE_MAX,
} profile_type_t;

#define PROFILE_PSM_PBAP 0x1025
#define PROFILE_PSM_MAP  0x1029
#define PROFILE_PSM_RFCOMM 0x0003

#define PROFILE_SCN_PBAP 19
#define PROFILE_SCN_MAP  26

#define PROFILE_UUID_PBAP 0x112f
#define PROFILE_UUID_MAP  0x1132
#define PROFILE_UUID_HFP_HS 0x1112
#define PROFILE_UUID_HFP_HF 0x111f

class ProfilesFilter {
  public:
    ProfilesFilter() {
      for (int i = 0; i < FILTER_PROFILE_MAX; i++) {
        profiles[i].type = (profile_type_t)i;
        profiles[i].enabled = false;
        profiles[i].rfcomm_opened = false;
        profiles[i].l2cap_opened = false;
      }
      if (pbap_filtered) {
        profiles[FILTER_PROFILE_PBAP].enabled =
        profiles[FILTER_PROFILE_HFP_HS].enabled =
        profiles[FILTER_PROFILE_HFP_HF].enabled = true;
      }
      if (map_filtered) {
        profiles[FILTER_PROFILE_MAP].enabled = true;
      }
      ch_rfc_l = ch_rfc_r = ch_last = 0;
    }

    bool isHfpProfile(bool local, uint16_t cid, uint8_t dlci) {
      profile_type_t profile = dlci2profile(local, cid, dlci);

      return profile == FILTER_PROFILE_HFP_HS ||
              profile == FILTER_PROFILE_HFP_HF;
    }

    bool isL2capMatch(bool local, uint16_t cid) {
      return cid2profile(local, cid) != FILTER_PROFILE_NONE;
    }

    bool isL2capFlowExt(bool local, uint16_t cid) {
      profile_type_t profile = cid2profile(local, cid);
      if (profile >= 0)
        return profiles[profile].flow_ext_l2cap;
      return false;
    }

    bool isRfcommMatch(bool local, uint16_t cid, uint8_t dlci) {
      return dlci2profile(local, cid, dlci) != FILTER_PROFILE_NONE;
    }

    bool isRfcommFlowExt(bool local, uint16_t cid, uint8_t dlci) {
      profile_type_t profile = dlci2profile(local, cid, dlci);
      if (profile >= 0)
        return profiles[profile].flow_ext_rfcomm;
      return false;
    }

    profile_type_t cid2profile(bool local, uint16_t cid) {
      uint16_t ch;

      for (int i = 0; i < FILTER_PROFILE_MAX; i++) {
        if(profiles[i].enabled && profiles[i].l2cap_opened) {
          ch = local ? profiles[i].lcid : profiles[i].rcid;
          if (ch == cid)
            return (profile_type_t)i;
        }
      }
      return FILTER_PROFILE_NONE;
    }

    profile_type_t dlci2profile(bool local, uint16_t cid, uint8_t dlci) {
      if (!isRfcChannel(local, cid))
        return FILTER_PROFILE_NONE;

      for (int i = 0; i < FILTER_PROFILE_MAX; i++) {
        if(profiles[i].enabled && profiles[i].l2cap_opened &&
               profiles[i].rfcomm_opened &&
               profiles[i].scn == (dlci>>1))
          return (profile_type_t)i;
      }
      return FILTER_PROFILE_NONE;
    }

    void profile_l2cap_open(profile_type_t profile, uint16_t lcid,
                          uint16_t rcid, uint16_t psm, bool flow_ext) {
      if (profiles[profile].l2cap_opened == true) {
        LOG_INFO(LOG_TAG, "%s: l2cap for %d was already opened. Override it",
                        __func__, profile);
      }
      profiles[profile].lcid = lcid;
      profiles[profile].rcid = rcid;
      profiles[profile].psm  = psm;
      profiles[profile].flow_ext_l2cap = flow_ext;
      profiles[profile].l2cap_opened = true;
    }

    void profile_l2cap_close(profile_type_t profile) {
      if (profile < 0 || profile >= FILTER_PROFILE_MAX)
        return;
      profiles[profile].l2cap_opened = false;
    }

    void profile_rfcomm_open(profile_type_t profile, uint16_t lcid, uint8_t dlci,
                         uint16_t uuid, bool flow_ext) {
      if (profiles[profile].rfcomm_opened == true) {
        LOG_INFO(LOG_TAG, "%s: rfcomm for %d was already opened. Override it",
                       __func__, profile);
      }
      profiles[profile].rfcomm_uuid = uuid;
      profiles[profile].scn = (dlci>>1);
      profiles[profile].flow_ext_rfcomm = flow_ext;
      profiles[profile].l2cap_opened = true;
      profiles[profile].rfcomm_opened = true;
    }

    void profile_rfcomm_close(profile_type_t profile) {
      if (profile < 0 || profile >= FILTER_PROFILE_MAX)
        return;
      profiles[profile].rfcomm_opened = false;
    }

    bool isRfcChannel(bool local, uint16_t cid) {
      uint16_t channel = local ? ch_rfc_l : ch_rfc_r;
      return cid == channel;
    }

    uint16_t ch_rfc_l, ch_rfc_r;  // local & remote L2CAP channel for RFCOMM
    uint16_t ch_last;             // last channel seen for fragment packet

private:
    struct {
      profile_type_t type;
      bool enabled, l2cap_opened, rfcomm_opened;
      bool flow_ext_l2cap, flow_ext_rfcomm;
      uint16_t lcid, rcid, rfcomm_uuid, psm;
      uint8_t scn;
    } profiles[FILTER_PROFILE_MAX];
};

std::mutex profiles_filter_mutex;
std::unordered_map<int16_t, ProfilesFilter> profiles_filter_table;

// Cached value for whether full snoop logs are enabled. So the property isn't
// checked for every packet.
static bool is_btsnoop_enabled;
static bool is_btsnoop_filtered;
bool is_vndbtsnoop_enabled = false;

// TODO(zachoverflow): merge btsnoop and btsnoop_net together
void btsnoop_net_open();
void btsnoop_net_close();
void btsnoop_net_write(const void* data, size_t length);
static bool is_avdt_media_packet(const uint8_t *p, bool is_local_cid);

static void delete_btsnoop_files(bool filtered);
static std::string get_btsnoop_log_path(bool filtered);
static std::string get_btsnoop_last_log_path(std::string log_path);
static void open_next_snoop_file();
static void btsnoop_write_packet(packet_type_t type, uint8_t* packet,
                                 bool is_received, uint64_t timestamp_us);

// Module lifecycle functions

static future_t* start_up() {
  std::array<char, PROPERTY_VALUE_MAX> property = {};
  std::lock_guard<std::mutex> lock(btsnoop_mutex);
  time_t t = time(NULL);
  struct tm tm_cur;
  int len = 0;

  localtime_r (&t, &tm_cur);
  gmt_offset = tm_cur.tm_gmtoff;

  if (gmt_offset < 0) {
    tmp_gmt_offset = -gmt_offset;
  }

  pbap_filtered = map_filtered = false;
  profile_filter_mode = FILTER_MODE_FULLFILTER;

  // Default mode is FILTERED on userdebug/eng build, DISABLED on user build.
  // It can also be overwritten by modifying the global setting.
  int is_debuggable = osi_property_get_int32(IS_DEBUGGABLE_PROPERTY, 0);
  std::string default_mode = BTSNOOP_MODE_DISABLED;
  if (is_debuggable) {
    len = osi_property_get(BTSNOOP_DEFAULT_MODE_PROPERTY, property.data(),
                               BTSNOOP_MODE_FILTERED);
    default_mode = std::string(property.data(), len);
  }

  // Get the actual mode
  len = osi_property_get(BTSNOOP_LOG_MODE_PROPERTY, property.data(),
                             default_mode.c_str());
  std::string btsnoop_mode(property.data(), len);

  if (btsnoop_mode == BTSNOOP_MODE_FILTERED) {
    LOG(INFO) << __func__ << ": Filtered Snoop Logs enabled";
    is_btsnoop_enabled = true;
    is_btsnoop_filtered = true;
    delete_btsnoop_files(false);
  } else if (btsnoop_mode == BTSNOOP_MODE_FULL) {
    LOG(INFO) << __func__ << ": Snoop Logs fully enabled";
    is_btsnoop_enabled = false;
    is_vndbtsnoop_enabled = true;
    is_btsnoop_filtered = false;
    vendor_logging_level = HCI_SNOOP_LOG_FULL | DYNAMIC_LOGCAT_CAPTURE;
    delete_btsnoop_files(true);
  } else if (btsnoop_mode == BTSNOOP_MODE_MEDIAPKTSFILTERED) {
    LOG(INFO) << __func__ << ": media pkts Filtered VndSnoop Logs enabled";
    is_vndbtsnoop_enabled = true;
    is_btsnoop_enabled = false;
    is_btsnoop_filtered = false;
    vendor_logging_level = HCI_SNOOP_LOG_LITE | DYNAMIC_LOGCAT_CAPTURE;
  } else if (btsnoop_mode == BTSNOOP_MODE_SNOOPHEADERSFILTERED) {
    LOG(INFO) << __func__ << ": only headers filtered VndSnoop Logs enabled";
    is_vndbtsnoop_enabled = true;
    is_btsnoop_enabled = false;
    is_btsnoop_filtered = false;
    vendor_logging_level = HCI_SNOOP_ONLY_HEADER | DYNAMIC_LOGCAT_CAPTURE;
  } else if (btsnoop_mode == BTSNOOP_MODE_PROFILESFILTERED) {
    if (is_debuggable) {
      LOG(INFO) << __func__ << ": Profiles filter works only for user build";
    } else {
      LOG(INFO) << __func__ << ": Profile filtered Logs enabled";
      is_vndbtsnoop_enabled = true;
      vendor_logging_level = HCI_SNOOP_LOG_PROFILEFILTER | DYNAMIC_LOGCAT_CAPTURE;
    }
    is_btsnoop_enabled = false;
    is_btsnoop_filtered = false;
  } else {
    LOG(INFO) << __func__ << ": Snoop Logs disabled";
    is_btsnoop_enabled = false;
    is_btsnoop_filtered = false;
    is_vndbtsnoop_enabled = false;
    delete_btsnoop_files(true);
    delete_btsnoop_files(false);
  }

  if (btsnoop_mode == BTSNOOP_MODE_PROFILESFILTERED && !is_debuggable) {
    len = osi_property_get(BTSNOOP_LOG_PROFILE_FILTERMODE_PROPERTY,
                           property.data(), "fullfilter");
    std::string filter_mode(property.data(), len);
    if (filter_mode == "header") {
      profile_filter_mode = FILTER_MODE_HEADER;
    } else if (filter_mode == "magic") {
      profile_filter_mode = FILTER_MODE_MAGIC;
    } else {
      profile_filter_mode = FILTER_MODE_FULLFILTER;
    }
    LOG(INFO) << __func__ << ": profile filter mode " << profile_filter_mode;
    len = osi_property_get(BTSNOOP_LOG_FILTER_PROFILES_PROPERTY,
                           property.data(), "");

    char *token, *saved_token;
    token = strtok_r((char *)property.data(), ",", &saved_token);
    while (token != NULL) {
      if (strcmp(token, "pbap") == 0) {
        pbap_filtered = true;
      } else if (strcmp(token, "map") == 0) {
        map_filtered = true;
      } else {
        LOG(INFO) << token << " not supported";
      }
      token = strtok_r(NULL, ",", &saved_token);
    }
    LOG(INFO) << __func__ << "pbap_filtered=" << pbap_filtered
              << " map_filtered=" << map_filtered;
  }

  if (is_vndbtsnoop_enabled) {
    osi_property_set("persist.bluetooth.btsnoopenable", "true");
  } else {
    osi_property_set("persist.bluetooth.btsnoopenable", "");
  }

  if (is_btsnoop_enabled || is_vndbtsnoop_enabled) {
    open_next_snoop_file();
    packets_per_file = (//osi_property_get_int32(BTSNOOP_MAX_PACKETS_PROPERTY,
                                              DEFAULT_BTSNOOP_SIZE);
    btsnoop_net_open();
    START_SNOOP_LOGGING();
  }
  LOG_DEBUG(LOG_TAG, "%s: vendor_logging_level values is %d ", __func__, vendor_logging_level);

  return NULL;
}

static future_t* shut_down(void) {
  std::lock_guard<std::mutex> lock(btsnoop_mutex);
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  if (is_btsnoop_enabled) {
    if (is_btsnoop_filtered) {
      delete_btsnoop_files(false);
    } else {
      delete_btsnoop_files(true);
    }
  } else {
    delete_btsnoop_files(true);
    delete_btsnoop_files(false);
  }
#endif

  if (logfile_fd != INVALID_FD) close(logfile_fd);
  logfile_fd = INVALID_FD;

  if(is_vndbtsnoop_enabled) STOP_SNOOP_LOGGING();
  if (is_btsnoop_enabled) btsnoop_net_close();

  return NULL;
}

EXPORT_SYMBOL extern const module_t btsnoop_module = {
    .name = BTSNOOP_MODULE,
    .init = NULL,
    .start_up = start_up,
    .shut_down = shut_down,
    .clean_up = NULL,
    .dependencies = {STACK_CONFIG_MODULE, NULL}};

// Interface functions
static void capture(const BT_HDR* buffer, bool is_received) {
  uint8_t *p = 0;

  if (vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER &&
        (profile_filter_mode == FILTER_MODE_MAGIC ||
          profile_filter_mode == FILTER_MODE_HEADER)) {

    if (buffer->len + EXTRA_BUF_SIZE <= DEFAULT_PACKET_SIZE) {
      p = packet;
    } else {
      // Add additional bytes for magic string in case
      //  payload length is less than the length of magic string.
      p = (uint8_t *)buffer_allocator_get_interface()->alloc(buffer->len + EXTRA_BUF_SIZE);
      if (!p) {
        LOG_ERROR(LOG_TAG, "%s: no enough memory", __func__);
        return;
      }
    }
    memcpy(p, buffer->data + buffer->offset, buffer->len);
  } else {
    p = const_cast<uint8_t*>(buffer->data + buffer->offset);
  }

  std::lock_guard<std::mutex> lock(btsnoop_mutex);

  struct timespec ts_now = {};
  clock_gettime(CLOCK_REALTIME, &ts_now);
  uint64_t timestamp_us =
      ((uint64_t)ts_now.tv_sec * 1000000L) + ((uint64_t)ts_now.tv_nsec / 1000);

  if (gmt_offset >= 0) {
    timestamp_us  += ((uint64_t) gmt_offset * 1000000LL);
  } else {
    /* when gmt_offset negative, adding offset to timestamp leads to
     * integer overflow , we need to subtract positive offset to avoid overflow
     */
    timestamp_us -= ((uint64_t) tmp_gmt_offset * 1000000LL);
  }

  btsnoop_mem_capture(buffer, timestamp_us);

  if (logfile_fd == INVALID_FD) return;

  switch (buffer->event & MSG_EVT_MASK) {
    case MSG_HC_TO_STACK_HCI_EVT:
      btsnoop_write_packet(kEventPacket, p, false, timestamp_us);
      break;
    case MSG_HC_TO_STACK_HCI_ACL:
    case MSG_STACK_TO_HC_HCI_ACL:
      btsnoop_write_packet(kAclPacket, p, is_received, timestamp_us);
      break;
    case MSG_HC_TO_STACK_HCI_SCO:
    case MSG_STACK_TO_HC_HCI_SCO:
      btsnoop_write_packet(kScoPacket, p, is_received, timestamp_us);
      break;
    case MSG_STACK_TO_HC_HCI_CMD:
      btsnoop_write_packet(kCommandPacket, p, true, timestamp_us);
      break;
  }

  if (vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER &&
          (profile_filter_mode == FILTER_MODE_MAGIC ||
            profile_filter_mode == FILTER_MODE_HEADER) && p != packet) {
    buffer_allocator_get_interface()->free(p);
  }
}

static void whitelist_l2c_channel(uint16_t conn_handle, uint16_t local_cid,
                                  uint16_t remote_cid) {
  LOG(INFO) << __func__
            << ": Whitelisting l2cap channel. conn_handle=" << conn_handle
            << " cid=" << local_cid << ":" << remote_cid;
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(filter_list_mutex);
#else
  std::lock_guard<std::mutex> lock(filter_list_mutex);
#endif  //OFF_TARGET_TEST_ENABLED

  // This will create the entry if there is no associated filter with the
  // connection.
  filter_list[conn_handle].addL2cCid(local_cid, remote_cid);
}

static void whitelist_rfc_dlci(uint16_t local_cid, uint8_t dlci) {
  LOG(INFO) << __func__
            << ": Whitelisting rfcomm channel. L2CAP CID=" << local_cid
            << " DLCI=" << dlci;
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(filter_list_mutex);
#else
  std::lock_guard<std::mutex> lock(filter_list_mutex);
#endif

  tL2C_CCB* p_ccb = l2cu_find_ccb_by_cid(nullptr, local_cid);
  if(p_ccb) {
    filter_list[p_ccb->p_lcb->handle].addRfcDlci(dlci);
  }
}

static void add_rfc_l2c_channel(uint16_t conn_handle, uint16_t local_cid,
                                uint16_t remote_cid) {
  LOG(INFO) << __func__
            << ": rfcomm data going over l2cap channel. conn_handle="
            << conn_handle << " cid=" << local_cid << ":"
            << remote_cid;
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(filter_list_mutex);
#else
  std::lock_guard<std::mutex> lock(filter_list_mutex);
#endif

  filter_list[conn_handle].setRfcCid(local_cid, remote_cid);
  local_cid_to_acl.insert({local_cid, conn_handle});
}

static void clear_l2cap_whitelist(uint16_t conn_handle, uint16_t local_cid,
                                  uint16_t remote_cid) {
  LOG(INFO) << __func__
            << ": Clearing whitelist from l2cap channel. conn_handle="
            << conn_handle << " cid=" << local_cid << ":" << remote_cid;

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(filter_list_mutex);
#else
  std::lock_guard<std::mutex> lock(filter_list_mutex);
#endif
  filter_list[conn_handle].removeL2cCid(local_cid, remote_cid);
}

static uint32_t payload_strip(uint8_t  *packet, uint32_t hdr_len, uint32_t pl_len) {
  uint32_t len = 0, maglen;
  uint8_t *stream = packet + ACL_LENGTH_OFFSET;

  switch (profile_filter_mode) {
    case FILTER_MODE_FULLFILTER:
      return 0;
    case FILTER_MODE_HEADER:
      len = hdr_len;

      UINT16_TO_STREAM(stream, (hdr_len - L2C_HEADER_LENGTH));
      UINT16_TO_STREAM(stream, (hdr_len - (HCI_HEADER_LENGTH + L2C_HEADER_LENGTH)));
      break;
    case FILTER_MODE_MAGIC:
      maglen = strlen(payload_fill_magic);
      memcpy(&packet[hdr_len], payload_fill_magic, maglen);
      UINT16_TO_STREAM(stream, (hdr_len + maglen - L2C_HEADER_LENGTH));
      UINT16_TO_STREAM(stream, (hdr_len + maglen - (HCI_HEADER_LENGTH + L2C_HEADER_LENGTH)));
      len = hdr_len + maglen;
      break;
  }
  return len + PACKET_TYPE_LENGTH; // including packet type byte
}

static uint32_t profiles_filter(bool is_received, uint8_t *packet) {
  uint8_t *stream = packet;
  bool frag;
  uint16_t handle, l2c_chan, l2c_ctl;
  uint32_t length, totlen, offset;

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(profiles_filter_mutex);
#else
  std::lock_guard<std::mutex> lock(profiles_filter_mutex);
#endif

  STREAM_TO_UINT16(handle, stream);
  frag = (GET_BOUNDARY_FLAG(handle) == CONTINUATION_PACKET_BOUNDARY);
  handle = handle & HANDLE_MASK;
  STREAM_TO_UINT16(length, stream);
  totlen = length + HCI_HEADER_LENGTH;
  length += PACKET_TYPE_LENGTH + HCI_HEADER_LENGTH; // Additional byte is added for packet type

  STREAM_SKIP_UINT16(stream);
  STREAM_TO_UINT16(l2c_chan, stream);

  auto &filters = profiles_filter_table[handle];
  if (frag) {
    l2c_chan = filters.ch_last;
  } else {
    filters.ch_last = l2c_chan;
  }
  if (l2c_chan != 0x1 && handle != 0x0edc) {
    if (filters.isL2capFlowExt(is_received, l2c_chan)) {
      STREAM_TO_UINT16(l2c_ctl, stream);
      if (!(l2c_ctl & 1)) { // I-Frame
        if (((l2c_ctl >> 14) & 0x3) == 0x01) { // Start of L2CAP SDU
          STREAM_SKIP_UINT16(stream); // skip L2CAP SDU length
        }
      }
    }
    offset = stream - packet;
    if (filters.isL2capMatch(is_received, l2c_chan)) {
      if (frag) {
        return PACKET_TYPE_LENGTH + HCI_HEADER_LENGTH;
      }
      length = payload_strip(packet, offset, totlen - offset);
    } else {
      if (filters.isRfcChannel(is_received, l2c_chan)) {
        uint8_t addr, ctrl, pf;

        STREAM_TO_UINT8(addr, stream);
        STREAM_TO_UINT8(ctrl, stream);
        pf = ctrl & 0x10;
        ctrl = ctrl & 0xef;
        addr >>= 2;
        if(ctrl != RFCOMM_UIH) {
          return length;
        }
        if(filters.isRfcommMatch(is_received, l2c_chan, addr)) {
          uint16_t len;
          uint8_t ea;

          len = *stream++;
          ea = len & 1;
          len = len >> 1;
          if (!ea) {
            len += *stream++ << 7;
          }
          if (filters.isRfcommFlowExt(is_received, l2c_chan, addr) && pf) {
            stream ++; // credit byte
          }
          offset = stream - packet;
          if (filters.isHfpProfile(is_received, l2c_chan, addr)) {
            uint32_t pat_len = strlen(cpbr_pattern);

            if ((totlen - offset) > pat_len) {
              if (memcmp(&packet[offset], cpbr_pattern, pat_len) == 0) {
                length = offset + pat_len + 1;
                packet[ACL_LENGTH_OFFSET] = offset + pat_len - L2C_HEADER_LENGTH;
                packet[L2C_LENGTH_OFFSET] = offset + pat_len -
                                              (HCI_HEADER_LENGTH + L2C_HEADER_LENGTH);
              }
            }
          } else {
            length = payload_strip(packet, offset, totlen - offset);
          }
        }
      }
    }
  }

  return length;
}

static void set_rfc_port_open(uint16_t handle, uint16_t local_cid,
                          uint8_t dlci, uint16_t uuid, bool flow) {

  if (!(vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER))
    return;

  profile_type_t profile = FILTER_PROFILE_NONE;
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(profiles_filter_mutex);
#else
  std::lock_guard<std::mutex> lock(profiles_filter_mutex);
#endif
  auto &filters = profiles_filter_table[handle];

  LOG_INFO(LOG_TAG, "RFCOMM port is opened: handle=%d(0x%x),"
                    " lcid=%d(0x%x), dlci=%d(0x%x), uuid=%d(0x%x)%s",
                    handle, handle, local_cid, local_cid, dlci, dlci, uuid,
                    uuid, flow ? " Credit Based Flow Control enabled" : "");

  if (uuid == PROFILE_UUID_PBAP || (dlci>>1) == PROFILE_SCN_PBAP) {
    profile = FILTER_PROFILE_PBAP;
  } else if (uuid == PROFILE_UUID_MAP || (dlci>>1) == PROFILE_SCN_MAP) {
    profile = FILTER_PROFILE_MAP;
  } else if (uuid == PROFILE_UUID_HFP_HS) {
    profile = FILTER_PROFILE_HFP_HS;
  } else if (uuid == PROFILE_UUID_HFP_HF) {
    profile = FILTER_PROFILE_HFP_HF;
  }

  if (profile >= 0) {
    filters.profile_rfcomm_open(profile, local_cid, dlci, uuid, flow);
  }
}

static void set_rfc_port_close(uint16_t handle, uint16_t local_cid,
                           uint8_t dlci, uint16_t uuid) {

  if (!(vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER))
    return;

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(profiles_filter_mutex);
#else
  std::lock_guard<std::mutex> lock(profiles_filter_mutex);
#endif
  auto &filters = profiles_filter_table[handle];
  LOG_INFO(LOG_TAG, "RFCOMM port is closed: handle=%d(0x%x),"
                    " lcid=%d(0x%x), dlci=%d(0x%x), uuid=%d(0x%x)", handle,
                    handle, local_cid, local_cid, dlci, dlci, uuid, uuid);

  filters.profile_rfcomm_close(filters.dlci2profile(true, local_cid, dlci));
}

static void set_l2cap_channel_open(uint16_t handle, uint16_t local_cid,
                               uint16_t remote_cid, uint16_t psm, bool flow) {

  if (!(vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER))
    return;

  profile_type_t profile = FILTER_PROFILE_NONE;
#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(profiles_filter_mutex);
#else
  std::lock_guard<std::mutex> lock(profiles_filter_mutex);
#endif
  auto &filters = profiles_filter_table[handle];

  LOG_INFO(LOG_TAG, "L2CAP channel is opened: handle=%d(0x%x), lcid=%d(0x%x),"
                    " rcid=%d(0x%x), psm=0x%x%s", handle, handle, local_cid,
                    local_cid, remote_cid, remote_cid, psm,
                        flow ? " Standard or Enhanced Control enabled" : "");

  if (psm == PROFILE_PSM_RFCOMM) {
    filters.ch_rfc_l = local_cid;
    filters.ch_rfc_r = remote_cid;
  } else if (psm == PROFILE_PSM_PBAP) {
    profile = FILTER_PROFILE_PBAP;
  } else if (psm == PROFILE_PSM_MAP) {
    profile = FILTER_PROFILE_MAP;
  }

  if (profile >= 0) {
    filters.profile_l2cap_open(profile, local_cid, remote_cid, psm, flow);
  }
}

static void set_l2cap_channel_close(uint16_t handle, uint16_t local_cid, uint16_t remote_cid) {

  if (!(vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER))
    return;

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(profiles_filter_mutex);
#else
  std::lock_guard<std::mutex> lock(profiles_filter_mutex);
#endif
  auto &filters = profiles_filter_table[handle];

  LOG_INFO(LOG_TAG, "L2CAP channel is closed: handle=%d(0x%x), lcid=%d(0x%x),"
                    " rcid=%d(0x%x)", handle, handle, local_cid, local_cid,
                    remote_cid, remote_cid);

  filters.profile_l2cap_close(filters.cid2profile(true, local_cid));
}

static const btsnoop_t interface = {capture, whitelist_l2c_channel,
                                    whitelist_rfc_dlci, add_rfc_l2c_channel,
                                    clear_l2cap_whitelist
                                    ,set_rfc_port_open
                                    ,set_rfc_port_close
                                    ,set_l2cap_channel_open
                                    ,set_l2cap_channel_close
                                    };

const btsnoop_t* btsnoop_get_interface() { return &interface; }

static void delete_btsnoop_files(bool filtered) {
  LOG(INFO) << __func__
            << ": Deleting snoop logs if they exist. filtered = " << filtered;
  auto log_path = get_btsnoop_log_path(filtered);
  remove(log_path.c_str());
  remove(get_btsnoop_last_log_path(log_path).c_str());
}

std::string get_btsnoop_log_path(bool filtered) {
  char btsnoop_path[PROPERTY_VALUE_MAX];
  osi_property_get(BTSNOOP_PATH_PROPERTY, btsnoop_path, DEFAULT_BTSNOOP_PATH);
  std::string result(btsnoop_path);
  if (filtered) result = result.append(".filtered");

  return result;
}

std::string get_btsnoop_last_log_path(std::string btsnoop_path) {
  return btsnoop_path.append(".last");
}

static void open_next_snoop_file() {
  packet_counter = 0;

  std::lock_guard<std::mutex> lock(btSnoopFd_mutex);
  if(sock_snoop_active)
    return;

  if (logfile_fd != INVALID_FD) {
    close(logfile_fd);
    logfile_fd = INVALID_FD;
  }

  auto log_path = get_btsnoop_log_path(is_btsnoop_filtered);
  auto last_log_path = get_btsnoop_last_log_path(log_path);

  if (rename(log_path.c_str(), last_log_path.c_str()) != 0 && errno != ENOENT)
    LOG(ERROR) << __func__ << ": unable to rename '" << log_path << "' to '"
               << last_log_path << "' : " << strerror(errno);

  mode_t prevmask = umask(0);
  logfile_fd = open(log_path.c_str(), O_WRONLY | O_CREAT | O_TRUNC,
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  umask(prevmask);
  if (logfile_fd == INVALID_FD) {
    LOG(ERROR) << __func__ << ": unable to open '" << log_path
               << "' : " << strerror(errno);
    return;
  }

  write(logfile_fd, "btsnoop\0\0\0\0\1\0\0\x3\xea", 16);
}

typedef struct {
  uint32_t length_original;
  uint32_t length_captured;
  uint32_t flags;
  uint32_t dropped_packets;
  uint64_t timestamp;
  uint8_t type;
} __attribute__((__packed__)) btsnoop_header_t;

static uint64_t htonll(uint64_t ll) {
  const uint32_t l = 1;
  if (*(reinterpret_cast<const uint8_t*>(&l)) == 1)
    return static_cast<uint64_t>(htonl(ll & 0xffffffff)) << 32 |
           htonl(ll >> 32);

  return ll;
}

static void calculate_acl_packet_length(uint32_t *length, uint8_t* packet, bool is_received) {
  uint32_t def_len = (packet[3] << 8) + packet[2] + 5;
  static const size_t HCI_ACL_HEADER_SIZE = 4;
  static const size_t MAX_HCI_ACL_LEN = 14;
  static const size_t L2CAP_CID_OFFSET = (HCI_ACL_HEADER_SIZE + 2);
  static const uint16_t L2CAP_SIGNALING_CID = 0x0001;
  // Assigning to zero
  *length = 0;

  if (vendor_logging_level & HCI_SNOOP_LOG_FULL) {
    *length = def_len;
  } else if (vendor_logging_level & HCI_SNOOP_ONLY_HEADER) {
    uint8_t* stream = packet;
    uint16_t handle;

    STREAM_TO_UINT16(handle, stream);
    uint8_t boundary_flag = GET_BOUNDARY_FLAG(handle);
    handle = handle & HANDLE_MASK;

    if (boundary_flag == START_PACKET_BOUNDARY) {
      uint16_t l2cap_cid =
         stream[L2CAP_CID_OFFSET] | (stream[L2CAP_CID_OFFSET + 1] << 8);
      if (l2cap_cid == L2CAP_SIGNALING_CID || handle == 0x0edc) {
        *length = def_len;
      } else {
        if(def_len < MAX_HCI_ACL_LEN) {
          *length = def_len;
        } else {
          // Otherwise, return as much as we reasonably can
          *length = MAX_HCI_ACL_LEN;
        }
      }
    }
  } else if (vendor_logging_level & HCI_SNOOP_LOG_LITE) {
     if(!is_avdt_media_packet(packet, is_received))
       *length = def_len;
  } else if (vendor_logging_level & HCI_SNOOP_LOG_PROFILEFILTER) {
     *length = profiles_filter(is_received, packet);
  }
}
static bool should_filter_log(bool is_received, uint8_t* packet) {
  uint16_t acl_handle =
      HCID_GET_HANDLE((((uint16_t)packet[ACL_CHANNEL_OFFSET + 1]) << 8) +
                      packet[ACL_CHANNEL_OFFSET]);

#if (OFF_TARGET_TEST_ENABLED == FALSE)
  std::lock_guard lock(filter_list_mutex);
#else
  std::lock_guard<std::mutex> lock(filter_list_mutex);
#endif
  auto& filters = filter_list[acl_handle];
  uint16_t l2c_channel =
      (packet[L2C_CHANNEL_OFFSET + 1] << 8) + packet[L2C_CHANNEL_OFFSET];
  if (filters.isRfcChannel(is_received, l2c_channel)) {
    uint8_t rfc_event = packet[RFC_EVENT_OFFSET] & 0b11101111;
    if (rfc_event == RFCOMM_SABME || rfc_event == RFCOMM_UA) {
      return false;
    }

    uint8_t rfc_dlci = packet[RFC_CHANNEL_OFFSET] >> 2;
    if (!filters.isWhitelistedDlci(rfc_dlci)) {
      return true;
    }
  } else if (!filters.isWhitelistedL2c(is_received, l2c_channel)) {
    return true;
  }

  return false;
}

static void btsnoop_write_packet(packet_type_t type, uint8_t* packet,
                                 bool is_received, uint64_t timestamp_us) {
  uint32_t length_he = 0;
  uint32_t flags = 0;
  int status = 0;

  switch (type) {
    case kCommandPacket:
      length_he = packet[2] + 4;
      flags = 2;
      break;
    case kAclPacket:
      calculate_acl_packet_length(&length_he, packet, is_received);
      flags = is_received;
      break;
    case kScoPacket:
      length_he = packet[2] + 4;
      flags = is_received;
      break;
    case kEventPacket:
      length_he = packet[1] + 3;
      flags = 3;
      break;
  }

  if (!length_he)
    return;

  btsnoop_header_t header;
  header.length_original = htonl(length_he);

  bool blacklisted = false;
  if (is_btsnoop_filtered && type == kAclPacket) {
    blacklisted = should_filter_log(is_received, packet);
  }

  header.length_captured =
      blacklisted ? htonl(L2C_HEADER_SIZE) : header.length_original;
  if (blacklisted) length_he = L2C_HEADER_SIZE;
  header.flags = htonl(flags);
  header.dropped_packets = 0;
  header.timestamp = htonll(timestamp_us + BTSNOOP_EPOCH_DELTA);
  header.type = type;

  btsnoop_net_write(&header, sizeof(btsnoop_header_t));
  btsnoop_net_write(packet, length_he - 1);

  if (logfile_fd != INVALID_FD) {
    packet_counter++;
    if (!sock_snoop_active && packet_counter > packets_per_file) {
      open_next_snoop_file();
    }

    struct pollfd fds;
    fds.fd = logfile_fd;
    fds.events = POLLOUT;
    iovec iov[] = {{&header, sizeof(btsnoop_header_t)},
                   {reinterpret_cast<void*>(packet), length_he - 1}};

    status = poll(&fds, 1, 0);
    if(status > 0 && fds.revents & POLLOUT) {
      TEMP_FAILURE_RETRY(writev(logfile_fd, iov, 2));
    } else if (status == 0) {
      LOG_WARN(LOG_TAG, "%s poll() timeout", __func__);
    } else if (status == -1) {
      LOG_ERROR(LOG_TAG, "%s poll failed errno %d (%s)",
                    __func__, errno, strerror(errno));
    }
  }
}

void update_snoop_fd(int snoop_fd) {
  std::lock_guard<std::mutex> lock(btSnoopFd_mutex);
  LOG_INFO(LOG_TAG, "%s Now writing to server socket", __func__);
  sock_snoop_active = true;
  logfile_fd = snoop_fd;
}

static bool is_avdt_media_packet(const uint8_t *p, bool is_received) {
  uint16_t cid, handle;
  bool is_local_cid = is_received;
  /*is_received signifies Rx packet so packet will have local_cid at offset 6
   * Tx packet with is_received as false and have remote_cid at the offset*/

  handle = (uint16_t)((p[0] + (p[1] << 8)) & 0x0FFF);
  cid =  (uint16_t)(p[6] + (p[7] << 8));

  return L2CA_isMediaChannel(handle, cid, is_local_cid);
}
