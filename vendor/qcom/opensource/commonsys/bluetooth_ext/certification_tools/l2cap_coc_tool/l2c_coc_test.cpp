/******************************************************************************
 ** Copyright (c) 2014-2015, 2020 The Linux Foundation. All rights reserved.
 *
 *  Not a Contribution.
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


/************************************************************************************
 *
 *  Filename:      l2c_coc_test.cpp
 *
 *  Description:   L2CAP COC Test application
 *
 ***********************************************************************************/
#include<iostream>
#include <stdio.h>
#include <stdint.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/capability.h>
#include <map>
#include "bt_target.h"
#include "l2c_api.h"
#include "bta_api.h"
#include "l2c_int.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <private/android_filesystem_config.h>
#include <android/log.h>

#include <hardware/hardware.h>
#include <hardware/bluetooth.h>
#include <hardware/vendor.h>
#include <hardware/bt_gatt.h>
#include <hardware/bt_gatt_client.h>
#include <hardware/bt_gatt_server.h>
#include <hardware/bt_gatt_types.h>
//#include "../../osi/include/allocator.h"
#include <bt_testapp.h>

#include <signal.h>
#include <time.h>

#include <base/bind.h>
#include <base/callback.h>

using bluetooth::Uuid;


#ifdef TEST_APP_INTERFACE
/************************************************************************************
**  Constants & Macros
************************************************************************************/

#ifndef TRUE
#define     TRUE       1
#endif
#ifndef FALSE
#define     FALSE      0
#endif

#define PID_FILE "/data/.bdt_pid"

#ifndef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif

#define CASE_RETURN_STR(const) case const: return #const;


#define INTERVAL_LOW     1
#define INTERVAL_MEDIUM  2
#define INTERVAL_HIGH    3

#define L2CAP_LE_DEFAULT_MTU 512
#define L2CAP_LE_DEFAULT_MPS 251
#define L2CAP_LE_MAX_CREDIT 65535
#define L2CAP_LE_DEFAULT_CREDIT 1

/************************************************************************************
**  Local type definitions
************************************************************************************/
static void register_client_cb(int status, int client_if, const Uuid& app_uuid);

static void register_server_cb(int status, int server_if, const Uuid& app_uuid);

/************************************************************************************
**  Static variables
************************************************************************************/

static unsigned char main_done = 0;
static int status;
typedef struct
{
    uint16_t      result;                 /* Only used in confirm messages */
    uint16_t      credits;                /* used to send the outstanding credits */
    uint16_t      le_psm;
    uint16_t      le_mps;
    uint16_t      le_mtu;
    uint16_t      init_credits;          /* initial credits */
} tL2CAP_LE_CONN_INFO;

typedef struct
{
    bool                 in_use;
    uint16_t                  psm;
    uint16_t                  lcid;
    tL2CAP_LE_CONN_INFO     loc_conn_info;
    tL2CAP_LE_CONN_INFO     rmt_conn_info;
    bool                 is_server;
} t_le_chnl_info;

t_le_chnl_info le_chnl_conn_info[MAX_L2CAP_CLIENTS];
#define LE_ACL_MAX_BUFF_SIZE 4096
static int num_frames = 1;
static unsigned long g_delay = 1; /* Default delay before data transfer */
static int count = 1;
static uint16_t g_BleEncKeySize = 16;
//static int g_omps = 0;
//static int rcv_count = 0;
static int g_le_coc_if = 0;
static int rcv_itration = 0;
static volatile bool cong_status = FALSE;
/* Control channel LE-L2CAP default options */
static tL2CAP_LE_CONN_INFO le_conn_info;
static tL2CAP_COC_CFG_INFO local_coc_cfg;

/* Main API */
const bt_interface_t* sBtInterface = NULL;

static gid_t groups[] = { AID_NET_BT, AID_INET, AID_NET_BT_ADMIN,
                          AID_SYSTEM, AID_MISC, AID_SDCARD_RW,
                          AID_NET_ADMIN, AID_VPN};

enum {
    DISCONNECT,
    CONNECTING,
    CONNECTED,
    DISCONNECTING
};
static unsigned char bt_enabled = 0;
static int  g_ConnectionState   = DISCONNECT;
static int  g_AdapterState      = BT_STATE_OFF;
static int  g_PairState         = BT_BOND_STATE_NONE;

static int  g_conn_id        = 0;
static int  g_client_if      = 0;
static int  g_server_if      = 0;
static int  g_client_if_scan = 0;
static int  g_server_if_scan = 0;

const btgatt_test_interface_t     *sGattInterface = NULL;
const  btgatt_interface_t   *sGattIfaceScan = NULL;
const btgap_interface_t    *sGapInterface         = NULL;
const btl2cap_interface_t *sL2capInterface = NULL;
const btvendor_interface_t *btvendorInterface = NULL;


int  Btif_gatt_layer = TRUE;
RawAddress* remote_bd_address;

static uint16_t g_SecLevel = 0;
static bool g_ConnType = TRUE;//DUT is initiating connection
static bool g_Fcr_Present = FALSE;
static uint8_t g_Fcr_Mode = L2CAP_FCR_BASIC_MODE;
static uint8_t g_Ertm_AllowedMode = (L2CAP_FCR_CHAN_OPT_BASIC | L2CAP_FCR_CHAN_OPT_ERTM | L2CAP_FCR_CHAN_OPT_STREAM);

//GATT server UUIDs
std::string IMMEDIATE_ALERT_UUID = "00001802-0000-1000-8000-00805f9b34fb";
std::string ALERT_LEVEL_UUID = "00002a06-0000-1000-8000-00805f9b34fb";

//Decscriptors
std::string ClientCharConfigUUID = "00002902-0000-1000-8000-00805f9b34fb";

/* Default mtu */
static int g_imtu = 672;
static int g_omtu = 0;
uint16_t g_peer_mtu = 0;

int start_advertising_set_advertiser_id = -1;
int start_advertising_set_tx_power = -1;
int start_advertising_set_status = -1;

enum {
L2CAP_NOT_CONNECTED,
L2CAP_CONN_SETUP,
L2CAP_CONNECTED
};

static tL2CAP_CFG_INFO tl2cap_cfg_info;
static long data_size = -1;
static uint16_t           g_PSM           = 0;
static uint16_t           g_lcid          = 0;


enum {
    SEND,
    RECEIVE,
    WAITANDSEND,
    PAIR,
    PING,
    CONNECT,
};


/* Control channel eL2CAP default options */
tL2CAP_FCR_OPTS ertm_fcr_opts_def = {
    L2CAP_FCR_ERTM_MODE,
    3, /* Tx window size */
    20, /* Maximum transmissions before disconnecting */
    2000, /* Retransmission timeout (2 secs) */
    12000, /* Monitor timeout (12 secs) */
    100 /* MPS segment size */
};

tL2CAP_FCR_OPTS stream_fcr_opts_def = {
    L2CAP_FCR_STREAM_MODE,
    3,/* Tx window size */
    20, /* Maximum transmissions before disconnecting */
    2000, /* Retransmission timeout (2 secs) */
    12000, /* Monitor timeout (12 secs) */
    100 /* MPS segment size */
};
static tL2CAP_ERTM_INFO t_ertm_info = {0, 0, 0, 0, 0, 0};

uint8_t g_bd_name[249];
void get_str_1(char **p, char *Buffer);

/************************************************************************************
**  Static functions
************************************************************************************/

static void process_cmd(char *p, unsigned char is_job);
//static void job_handler(void *param);
static void bdt_log(const char *fmt_str, ...);
static void l2c_connect(RawAddress bd_addr);
static uint16_t do_l2cap_connect(RawAddress bd_addr);

int GetBdAddr(char *p, RawAddress* pbd_addr);
int reg_inst_id = -1;
int reg_status = -1;
/* LE L2CAP functions */
static t_le_chnl_info *le_allocate_conn_info(uint16_t psm, bool is_server);
static t_le_chnl_info *le_get_conn_info(uint16_t psm, bool is_server);
static t_le_chnl_info *le_get_conn_info_by_lcid(uint16_t lcid);
static bool le_release_conn_info(t_le_chnl_info *le_conn_info);
uint8_t do_l2cap_DataWrite(uint16_t chnl_id, char *p , uint32_t len);
static int Send_Data(char *p);
static int send_file(char *p);
static void le_l2cap_coc_connect(char *svr);
uint16_t do_le_l2cap_coc_connect(char *p);
static void le_l2cap_coc_flow_ctrl(char *p);
uint16_t do_le_l2cap_coc_flow_ctrl(char *p);
static void do_le_coc_disconnect(char *p);
int GetFileName(char *p, char *filename);
static void le_l2cap_listen(char *p);
static void do_start_advertisment(char *p);
static int send_file(char *p);
static void send_data_on_le_coc(char *svr);
static void do_send_file(char *svr);
static void ecfc_l2cap_listen(char *p);
static void ecfc_l2cap_connect(char *p);
static void ecfc_l2cap_reconfig(char *p);
static void do_ecfc_listen(char *p);
static void do_ecfc_start(char *p);
int Send_Data_ecfc(uint16_t lcid, uint16_t mtu);
static void send_coc_data(char *p);
static void ecfc_reconfig_rsp(char *p);

uint8_t ecfc_reconfig_rsp_code = 0;

/************************************************************************************
**  GATT Client Callbacks
************************************************************************************/
static void register_client_cb(int status, int client_if, const Uuid& app_uuid)
{
    printf("%s:: status=%d, client_if=%d \n", __FUNCTION__, status, client_if);
    if(0 == status)    g_client_if_scan = client_if;
}

static void connect_cb(int conn_id, int status, int client_if, const RawAddress& remote_bd_addr)
{
    printf("%s:: remote_bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, conn_id=0x%x, status=%d, client_if=%d\n",  __FUNCTION__,
    remote_bd_addr.address[0], remote_bd_addr.address[1], remote_bd_addr.address[2],
    remote_bd_addr.address[3], remote_bd_addr.address[4], remote_bd_addr.address[5], conn_id, status, client_if);

    g_conn_id = conn_id;
    sGapInterface->Gap_BleAttrDBUpdate(remote_bd_addr.address, 50, 70, 0, 1000);

}

static btgatt_client_callbacks_t sGattClient_cb =
{
    register_client_cb,
    connect_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL, //register_for_notification_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

static void GetFieldByType_2(const uint8_t* ad, size_t ad_len,
                                        uint8_t type, uint8_t* p_length,
                                        uint8_t* rem_char) {
    size_t position = 0;

    while (position < ad_len) {
        uint8_t len = ad[position];

        if (len == 0) break;
        if (position + len >= ad_len) break;

        uint8_t adv_type = ad[position + 1];

        if (adv_type == type) {
            /* length doesn't include itself */
            *p_length = len - 1; /* minus the length of type */
            memcpy(rem_char, (ad + position + 2), *p_length);
            return;
        }

        position += len + 1; /* skip the length of data */
    }

    *p_length = 0;
    return;
}


static void GetFieldByType(std::vector<uint8_t> const& ad,
                                       uint8_t type, uint8_t* p_length,
                                       uint8_t* rem_char) {
       GetFieldByType_2(ad.data(), ad.size(), type, p_length, rem_char);
}

/************************************************************************************
**  Scanner Callbacks
************************************************************************************/

static void scan_result_cb(uint16_t event_type, uint8_t addr_type,
                           RawAddress *bda, uint8_t primary_phy,
                           uint8_t secondary_phy,
                           uint8_t advertising_sid, int8_t tx_power,
                           int8_t rssi, uint16_t periodic_adv_int,
                           std::vector<uint8_t> adv_data)
{

    uint8_t len;
    uint8_t p_eir_remote_name[249] = {0};
    GetFieldByType(std::move(adv_data), 9, &len, p_eir_remote_name);
    if (len == 0) {
      GetFieldByType(std::move(adv_data), 8, &len, p_eir_remote_name);
    }
    if (len != 0) {
      if(!strncmp((char *)p_eir_remote_name, (char *)g_bd_name, len)) {
        printf("BD_Matches:  %s and stop scans \n", p_eir_remote_name);
        printf("%s:: event_type=%d, bda=%02x%02x%02x%02x%02x%02x \n", __FUNCTION__, event_type, bda->address[0],
                 bda->address[1], bda->address[2], bda->address[3], bda->address[4], bda->address[5]);
        sGattIfaceScan->scanner->Scan(false);
      }
    }
}

static btgatt_scanner_callbacks_t  sScanner_cb =
{
    scan_result_cb,
    NULL,
    NULL,
    NULL
};

/************************************************************************************
**  GATT Server Callbacks
************************************************************************************/
static void register_server_cb(int status, int server_if, const Uuid& app_uuid)
{
    printf("%s:: status=%d, server_if=%d \n", __FUNCTION__, status, server_if);
    if(0 == status)    g_server_if_scan = server_if;

    int  Ret = 0;
    bool is_valid = false;

    std::vector<btgatt_db_element_t> service1;
    //1st service
    btgatt_db_element_t svc1 = {};
    svc1.uuid = Uuid::FromString(IMMEDIATE_ALERT_UUID, &is_valid);
    svc1.type = BTGATT_DB_PRIMARY_SERVICE;
    service1.push_back(svc1);

    //1st char
    btgatt_db_element_t char1 = {};
    char1.uuid = Uuid::FromString(ALERT_LEVEL_UUID, &is_valid);
    char1.type = BTGATT_DB_CHARACTERISTIC;
    char1.properties = 58;
    char1.permissions = 17;
    //use shortByteValue byte array for this char
    service1.push_back(char1);

    //1st desc
    btgatt_db_element_t desc1 = {};
    desc1.uuid = Uuid::FromString(ClientCharConfigUUID, &is_valid);
    desc1.type = BTGATT_DB_DESCRIPTOR;
    desc1.permissions = 17;
    //use shortByteValue byte array for this desc
    service1.push_back(desc1);

    Ret = sGattIfaceScan->server->add_service(g_server_if_scan, service1);
    printf("%s:: Ret=%d \n", __FUNCTION__,Ret );
}

static void server_connection_cb(int conn_id, int server_if, int connected, const RawAddress& bda)
{
    printf("%s:: conn_id=%d, server_if=%d \n", __FUNCTION__, conn_id, server_if);
    g_conn_id = conn_id;
}

static btgatt_server_callbacks_t     sGattServer_cb =
{
    register_server_cb,
    server_connection_cb, //connection_callback             connection_cb;
    NULL, //service_added_callback          service_added_cb;
    NULL, //included_service_added_callback included_service_added_cb;
    NULL, //characteristic_added_callback   characteristic_added_cb;
    NULL, // request_read_callback           request_read_characteristic_cb
    NULL, // request_read_callback           request_read_characteristic_cb
    NULL, //request_write_callback          request_write_cb;
    NULL, //request_write_callback          request_write_cb;
    NULL, // request_exec_write_callback     request_exec_write_cb;
    NULL, //response_confirmation_callback  response_confirmation_cb;
    NULL, // indication_sent_callback        indication_sent_cb;
    NULL,
    NULL,
    NULL,
    NULL
};

static void Connection_cb (tGATT_IF gatt_if, const RawAddress& bda, uint16_t conn_id, bool connected, tGATT_DISCONN_REASON reason,tBT_TRANSPORT transport)
{
    printf("%s:: remote_bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, conn_id=0x%x, connected=%d, reason=%d, gatt_if=%d \n", __FUNCTION__,
            bda.address[0], bda.address[1], bda.address[2], bda.address[3], bda.address[4], bda.address[5],
            conn_id, connected, reason, gatt_if);
    g_conn_id = conn_id;
}

static tGATT_CBACK sGattCB =
{
    Connection_cb,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

/************************************************************************************
**  Shutdown helper functions
************************************************************************************/

static void bdt_shutdown(void)
{
    bdt_log("shutdown bdroid test app\n");
    main_done = 1;
}


/*****************************************************************************
** Android's init.rc does not yet support applying linux capabilities
*****************************************************************************/

static void config_permissions(void)
{
    struct __user_cap_header_struct header;
    struct __user_cap_data_struct cap[2];

    bdt_log("set_aid_and_cap : pid %d, uid %d gid %d", getpid(), getuid(), getgid());

    header.pid = 0;

    prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0);

    setuid(AID_BLUETOOTH);
    setgid(AID_BLUETOOTH);

    header.version = _LINUX_CAPABILITY_VERSION_3;

    cap[CAP_TO_INDEX(CAP_NET_RAW)].permitted |= CAP_TO_MASK(CAP_NET_RAW);
    cap[CAP_TO_INDEX(CAP_NET_ADMIN)].permitted |= CAP_TO_MASK(CAP_NET_ADMIN);
    cap[CAP_TO_INDEX(CAP_NET_BIND_SERVICE)].permitted |= CAP_TO_MASK(CAP_NET_BIND_SERVICE);
    cap[CAP_TO_INDEX(CAP_SYS_RAWIO)].permitted |= CAP_TO_MASK(CAP_SYS_RAWIO);
    cap[CAP_TO_INDEX(CAP_SYS_NICE)].permitted |= CAP_TO_MASK(CAP_SYS_NICE);
    cap[CAP_TO_INDEX(CAP_SETGID)].permitted |= CAP_TO_MASK(CAP_SETGID);
    cap[CAP_TO_INDEX(CAP_WAKE_ALARM)].permitted |= CAP_TO_MASK(CAP_WAKE_ALARM);

    cap[CAP_TO_INDEX(CAP_NET_RAW)].effective |= CAP_TO_MASK(CAP_NET_RAW);
    cap[CAP_TO_INDEX(CAP_NET_ADMIN)].effective |= CAP_TO_MASK(CAP_NET_ADMIN);
    cap[CAP_TO_INDEX(CAP_NET_BIND_SERVICE)].effective |= CAP_TO_MASK(CAP_NET_BIND_SERVICE);
    cap[CAP_TO_INDEX(CAP_SYS_RAWIO)].effective |= CAP_TO_MASK(CAP_SYS_RAWIO);
    cap[CAP_TO_INDEX(CAP_SYS_NICE)].effective |= CAP_TO_MASK(CAP_SYS_NICE);
    cap[CAP_TO_INDEX(CAP_SETGID)].effective |= CAP_TO_MASK(CAP_SETGID);
    cap[CAP_TO_INDEX(CAP_WAKE_ALARM)].effective |= CAP_TO_MASK(CAP_WAKE_ALARM);

    capset(&header, &cap[0]);
    setgroups(sizeof(groups)/sizeof(groups[0]), groups);
}


/*****************************************************************************
**   Logger API
*****************************************************************************/

void bdt_log(const char *fmt_str, ...)
{
    static char buffer[1024];
    va_list ap;

    va_start(ap, fmt_str);
    vsnprintf(buffer, 1024, fmt_str, ap);
    va_end(ap);

    fprintf(stdout, "%s\n", buffer);
}

/*******************************************************************************
 ** Misc helper functions
 *******************************************************************************/
static const char* dump_bt_status(int status)
{
    switch(status)
    {
        CASE_RETURN_STR(BT_STATUS_SUCCESS)
        CASE_RETURN_STR(BT_STATUS_FAIL)
        CASE_RETURN_STR(BT_STATUS_NOT_READY)
        CASE_RETURN_STR(BT_STATUS_NOMEM)
        CASE_RETURN_STR(BT_STATUS_BUSY)
        CASE_RETURN_STR(BT_STATUS_UNSUPPORTED)

        default:
            return "unknown status code";
    }
}


/*******************************************************************************
 ** Console helper functions
 *******************************************************************************/

void skip_blanks(char **p)
{
    while (**p == ' ')
    (*p)++;
}

uint32_t get_int(char **p, int DefaultValue)
{
    uint32_t Value = 0;
    unsigned char   UseDefault;

    UseDefault = 1;
    skip_blanks(p);

    while ( ((**p)<= '9' && (**p)>= '0') )
    {
        Value = Value * 10 + (**p) - '0';
        UseDefault = 0;
        (*p)++;
    }
   if (UseDefault)
       return DefaultValue;
   else
       return Value;
}

int get_signed_int(char **p, int DefaultValue)
{
    int    Value = 0;
    unsigned char   UseDefault;
    unsigned char  NegativeNum = 0;

    UseDefault = 1;
    skip_blanks(p);

    if ((**p) == '-')
    {
        NegativeNum = 1;
        (*p)++;
    }
    while ( ((**p)<= '9' && (**p)>= '0') )
    {
        Value = Value * 10 + (**p) - '0';
        UseDefault = 0;
        (*p)++;
    }

    if (UseDefault)
        return DefaultValue;
    else
        return ((NegativeNum == 0)? Value : -Value);
}

void get_str_1(char **p, char *Buffer)
{
    skip_blanks(p);
    while (**p != 0 && **p != '\0')
    {
        *Buffer = **p;
        (*p)++;
        Buffer++;
    }

    *Buffer = 0;
}

void get_str(char **p, char *Buffer)
{
    skip_blanks(p);
    while (**p != 0 && **p != ' ')
    {
        *Buffer = **p;
        (*p)++;
        Buffer++;
    }

    *Buffer = 0;
}

uint32_t get_hex_any(char **p, int DefaultValue, unsigned int NumOfNibble)
{
    uint32_t Value = 0;
    unsigned char   UseDefault;

    UseDefault = 1;
    skip_blanks(p);

    while ((NumOfNibble) && (((**p)<= '9' && (**p)>= '0') ||
          ((**p)<= 'f' && (**p)>= 'a') ||
          ((**p)<= 'F' && (**p)>= 'A')) )
    {
        if (**p >= 'a')
            Value = Value * 16 + (**p) - 'a' + 10;
        else if (**p >= 'A')
            Value = Value * 16 + (**p) - 'A' + 10;
        else
        Value = Value * 16 + (**p) - '0';
        UseDefault = 0;
        (*p)++;
        NumOfNibble--;
    }

    if (UseDefault)
        return DefaultValue;
    else
        return Value;
}
uint32_t get_hex(char **p, int DefaultValue)
{
    return (get_hex_any(p, DefaultValue, 8));
}
uint32_t get_hex_byte(char **p, int DefaultValue)
{
    return (get_hex_any(p, DefaultValue, 2));
}

std::string get_uuid_str(char **p, int uuid_len_bytes)
{
    std::string uuid_str, temp;
    skip_blanks(p);
    switch(uuid_len_bytes)
    {
        case 2: //16 bit uuid
            for(int i=0; i<4; i++)
            {
                temp = temp + (**p);
                (*p)++;
            }
            uuid_str = "0000"+temp+"-0000-1000-8000-00805F9B34FB";
            break;

        case 4: //32 bit uuid
            for(int i=0; i<8; i++)
            {
                temp = temp + (**p);
                (*p)++;
            }
            uuid_str = temp+"-0000-1000-8000-00805F9B34FB";
            break;

        case 16: //128 bit uuid
            for(int i=0; i<32; i++)
            {
                temp = temp + (**p);
                (*p)++;
                if (i == 7 || i == 11 || i == 15 || i == 19)
                    temp = temp + "-";
            }
            uuid_str = temp;
            break;

        default:
            printf("%s:: ERROR: no matching uuid \n", __FUNCTION__);
    }
    printf("%s:: uuid_str = %s \n", __FUNCTION__, uuid_str.c_str());
    return uuid_str;
}

#define is_cmd(str) ((strlen(str) == strlen(cmd)) && strncmp((const char *)&cmd, str, strlen(str)) == 0)
#define if_cmd(str)  if (is_cmd(str))

typedef void (t_console_cmd_handler) (char *p);

typedef struct {
    const char *name;
    t_console_cmd_handler *handler;
    const char *help;
    unsigned char is_job;
} t_cmd;

void do_help(char *p);
void do_quit(char *p);
void do_init(char *p);
void do_enable(char *p);
void do_disable(char *p);
void do_dut_mode_configure(char *p);
void do_le_test_mode(char *p);
void do_cleanup(char *p);
void do_le_client_register(char *p);
void do_le_client_deregister(char *p);
void do_le_client_connect (char *p);
void do_le_client_disconnect (char *p);
void do_le_client_scan_start (char *p);
void do_le_client_scan_stop (char *p);
void do_le_server_register(char *p);
void do_le_server_deregister(char *p);
void do_le_server_connect (char *p);
void do_le_server_disconnect (char *p);
void do_pairing(char *p);
void do_l2cap_send_data_cid(char *p);
static void do_set_localname(char *p);
void do_start_adv_set(char *p);
void do_unregister_adv_set(char *p);
void do_le_scan_filter_name(char *p);

/*******************************************************************
 *
 *  CONSOLE COMMAND TABLE
 *
*/

const t_cmd console_cmd_list[] =
{
    /*
     * INTERNAL
     */

    { "help", do_help, "lists all available console commands", 0 },
    { "quit", do_quit, "", 0},

    /*
     * API CONSOLE COMMANDS
     */

     /* Init and Cleanup shall be called automatically */
    { "enable", do_enable, ":: enables bluetooth", 0 },
    { "disable", do_disable, ":: disables bluetooth", 0 },
    { "dut_mode_configure", do_dut_mode_configure, ":: DUT mode - 1 to enter,0 to exit", 0 },
    { "c_register", do_le_client_register, "::UUID: 1<1111..> 2<12323..> 3<321111..>", 0 },
    { "c_deregister", do_le_client_deregister, "::UUID: 1<1111..> 2<12323..> 3<321111..>", 0 },
    { "c_connect", do_le_client_connect, ":: transport-type<0,1...> , BdAddr<00112233445566>", 0 },
    { "c_disconnect", do_le_client_disconnect, ":: transport-type<0,1...>, BdAddr<00112233445566>", 0 },
    { "filter_name", do_le_scan_filter_name, "::filter_name ", 0 },
    { "c_scan_start", do_le_client_scan_start, "::", 0 },
    { "c_scan_stop", do_le_client_scan_stop, "::", 0 },

    { "s_register", do_le_server_register, "::UUID: 1<1111..> 2<12323..> 3<321111..>", 0 },
    { "s_connect", do_le_server_connect, ":: transport, BdAddr<00112233445566>", 0 },
    { "s_disconnect", do_le_server_disconnect, ":: transport, BdAddr<00112233445566>", 0 },

    { "pair", do_pairing, ":: BdAddr<00112233445566>", 0 },

    { "l2cap_send_data_cid", do_l2cap_send_data_cid, ":: BdAddr<00112233445566>, CID<>", 0 },

    { "set_local_name", do_set_localname, ":: setName<name>", 0 },

    { "start_adv_set", do_start_adv_set, ":: adv_evt_properties(hex eg:13 for connectable and scannable legacy adv), "
            "\n interval(1-interval low, 2-interval medium, 3-interval high),"
            "\n primary phy(1 for LE 1M, 3 for LE Coded),"
            "\n secondary phy (1 for LE 1M, 2 for LE 2M and 3 for LE Coded)", 0 },
    { "unregister_advertiser", do_unregister_adv_set, ":: UnregisterAdvertiser", 0 },

     /* LE-L2CAP cmds */
    { " ", NULL, "\n\t\t\033[0m\033[34mLE L2CAP CoC Commands\033[0m", 0 },
    { " ", NULL, "\033[0m\033[34mCommands\t\t\tParameters\033[0m", 0 },

    { "start_adv", do_start_advertisment, "\t\t::\tuuid [0 - register"\
        "none (or) 1 - register uuid] , \n\t\t\t\tflag [0- stop adv (or) "\
        "1 - start adv] \n  " , 0},

    { "le_l2cap_listen", le_l2cap_listen, "\t::\tle_psm [1 to 255], "\
        "\n\t\t\t\tle_mtu [23 to 65535], \n\t\t\t\tle_mps [23 to 65533],"\
        " \n\t\t\t\tinit_credits [0 to 65535], \n\t\t\t\tsec_level "\
        "[0 - None, 1 - Authentication, 2 - Auth and Encryption]", 0},

    { "le_l2cap_coc_connect", le_l2cap_coc_connect, "\t::\tle_psm [128 to 255],"\
        "\n\t\t\t\tle_mtu [23 to 65535], \n\t\t\t\tle_mps [23 to 65533], "\
        "\n\t\t\t\tinit_credits [0 to 65535], \n\t\t\t\tsec_level [0 - None,"\
        " 1 - Authentication, 2 - Encryption], \n\t\t\t\tbd_addr [001122334455] ", 0},

    { "le_l2cap_coc_flow_ctrl", le_l2cap_coc_flow_ctrl, "\t::\tchnl_id [chnl id"\
        "info from conn_ind or conn_cnf], \n\t\t\t\tcredits [1 to 65535]", 0},

    { "send_data_on_le_coc", send_data_on_le_coc, "\t::\tchnl_id [chnl id info "\
        "from conn_ind or conn_cnf] , \n\t\t\t\tdata_type [0 - Unsegmented data ,"\
        "1 - Segmented data]", 0},
    
    { "ecfc_l2cap_listen", ecfc_l2cap_listen, "\t::\tpsm [1 to 255], "\
      "\n\t\t\t\tmtu [64 to 65535], \n\t\t\t\tsec_levl[0 - None, 1 - Authentication, 2 - Auth and Encryption], \n\t\t\t\tresult_code", 0},

    { "ecfc_l2cap_connect", ecfc_l2cap_connect, "\t::\tpsm [128 to 255],"\
        "\n\t\t\t\tmtu [23 to 65535], \n\t\t\t\tnum_chnls [1 to 5], "\
        "\n\t\t\t\tranport [0 to 1], \n\t\t\t\tsec_level [0 - None,"\
        " 1 - Authentication, 2 - Encryption], \n\t\t\t\tresult_code, \n\t\t\t\tbd_addr [001122334455] ", 0},
    
    { "ecfc_l2cap_reconfig", ecfc_l2cap_reconfig, "\t::\tnum_chnls [1 to 5], "\
      "\n\t\t\t\tmtu [64 to 65535] ", 0},

    { "send_file", do_send_file, "\t\t::\tchnl_id [chnl_id info from conn_ind"\
        "or conn_cnf], \n\t\t\t\tfile_name", 0},

    { "le_coc_disconnect", do_le_coc_disconnect, "\t::\tchnl_id [chnl_id info"\
        "from conn_ind or conn_cnf]", 0},
    { "ecfc_listen", do_ecfc_listen, ":: ecfc listening", 0},
    { "ecfc_start", do_ecfc_start, ":: ecfc starting", 0},
    { "send_coc_data_mtu", send_coc_data, "\t::\tchnl_id [chnl id info "\
        "from conn_ind or conn_cnf] \n\t\t\t\tmtu/mps [64 to 65535] \n\t\t\t\tNumOfPackets[1 to 65535] ", 0},
    { "reconfigure_Response", ecfc_reconfig_rsp, "\t::\tresult [chnl id info "\
        "result code] \n\t\t\t\tmtu/mps [64 to 65535] ", 0},
    /* last entry */
    {NULL, NULL, "", 0},
};


static int console_cmd_maxlen = 0;

static void *cmdjob_handler(void *param)
{
    char *job_cmd = (char*)param;

    bdt_log("cmdjob starting (%s)", job_cmd);

    process_cmd(job_cmd, 1);

    bdt_log("cmdjob terminating");

    free(job_cmd);
    return NULL;
}

static int create_cmdjob(char *cmd)
{
    pthread_t thread_id;
    char *job_cmd;

    job_cmd = (char*)calloc(1, strlen(cmd)+1); /* freed in job handler */
    if (job_cmd) {
       strlcpy(job_cmd, cmd,(strlen(cmd)+1));
       if (pthread_create(&thread_id, NULL, cmdjob_handler, (void *)job_cmd) != 0)
      /*if (pthread_create(&thread_id, NULL,
                       (void*)cmdjob_handler, (void*)job_cmd) !=0)*/
         perror("pthread_create");
      return 0;
    }
    else
       perror("create_Cmdjob malloc failed ");
    return -1;
}

/*******************************************************************************
 ** Load stack lib
 *******************************************************************************/
#define BLUETOOTH_LIBRARY_NAME "libbluetooth_qti.so"
int load_bt_lib(const bt_interface_t** interface) {
  const char* sym = BLUETOOTH_INTERFACE_STRING;
  bt_interface_t* itf = nullptr;

  // Always try to load the default Bluetooth stack on GN builds.
  const char* path = BLUETOOTH_LIBRARY_NAME;
  void* handle = dlopen(path, RTLD_NOW);
  if (!handle) {
    //const char* err_str = dlerror();
    printf("failed to load Bluetooth library\n");
    goto error;
  }

  // Get the address of the bt_interface_t.
  itf = (bt_interface_t*)dlsym(handle, sym);
  if (!itf) {
    printf("failed to load symbol from Bluetooth library\n");
    goto error;
  }

  // Success.
  printf(" loaded HAL Success\n");
  *interface = itf;
  return 0;

error:
  *interface = NULL;
  if (handle) dlclose(handle);

  return -EINVAL;
}

int HAL_load(void)
{
    if (load_bt_lib((bt_interface_t const**)&sBtInterface)) {
        printf("No Bluetooth Library found\n");
        return -1;
    }
    return 0;
}

int HAL_unload(void)
{
    int err = 0;

    bdt_log("Unloading HAL lib");

    sBtInterface = NULL;

    bdt_log("HAL library unloaded (%s)", strerror(err));

    return err;
}

/*******************************************************************************
 ** HAL test functions & callbacks
 *******************************************************************************/

void setup_test_env(void)
{
    int i = 0;

    while (console_cmd_list[i].name != NULL)
    {
        console_cmd_maxlen = MAX(console_cmd_maxlen, (int)strlen(console_cmd_list[i].name));
        i++;
    }
}

void check_return_status(int status)
{
    if (status != BT_STATUS_SUCCESS)
    {
        bdt_log("HAL REQUEST FAILED status : %d (%s)", status, dump_bt_status(status));
    }
    else
    {
        bdt_log("HAL REQUEST SUCCESS");
    }
}

static void do_set_localname(char *p)
{
    printf("set name in progress: %s\n", p);
    bt_property_t property = {BT_PROPERTY_BDNAME, static_cast<int>(strlen(p)), p};
    status =  sBtInterface->set_adapter_property(&property);
}

static void adapter_state_changed(bt_state_t state)
{
    int V1 = 1000, V2=2;
    char V3[] = "GATTTOOL";
    bt_property_t property = {(bt_property_type_t)9 /*BT_PROPERTY_DISCOVERY_TIMEOUT*/, 4, &V1};
    bt_property_t property1 = {(bt_property_type_t)7 /*SCAN*/, 2, &V2};
    bt_property_t property2 ={(bt_property_type_t)1,9, &V3};
    printf("ADAPTER STATE UPDATED : %s\n", (state == BT_STATE_OFF)?"OFF":"ON");

    g_AdapterState = state;

    if (state == BT_STATE_ON) {
        bt_enabled = 1;
        status = sBtInterface->set_adapter_property(&property1);
        status = sBtInterface->set_adapter_property(&property);
        status = sBtInterface->set_adapter_property(&property2);
    } else {
        bt_enabled = 0;
    }
}

static void adapter_properties_changed(bt_status_t status, int num_properties, bt_property_t *properties)
{
 char Bd_addr[15] = {0};
    if(NULL == properties)
    {
        printf("properties is null\n");
        return;
    }
    switch(properties->type)
    {
    case BT_PROPERTY_BDADDR:
        memcpy(Bd_addr, properties->val, properties->len);
        break;
    default:
        printf("property type not used\n");
    }
    return;
}

static void discovery_state_changed(bt_discovery_state_t state)
{
    printf("Discovery State Updated : %s\n", (state == BT_DISCOVERY_STOPPED)?"STOPPED":"STARTED");
}


static void pin_request_cb(RawAddress* remote_bd_addr, bt_bdname_t *bd_name, uint32_t cod, bool min_16_digit )
{
    remote_bd_address = remote_bd_addr;
    //bt_pin_code_t pincode = {{0x31, 0x32, 0x33, 0x34}};
    printf("Enter the pin key displayed in the remote device and terminate the key entry with .\n");

    /*if(BT_STATUS_SUCCESS != sBtInterface->pin_reply(remote_bd_addr, TRUE, 4, &pincode))
    {
        printf("Pin Reply failed\n");
    }*/
}
static void ssp_request_cb(RawAddress* remote_bd_addr, bt_bdname_t *bd_name,
                           uint32_t cod, bt_ssp_variant_t pairing_variant, uint32_t pass_key)
{
    printf("ssp_request_cb : name=%s variant=%d passkey=%u\n", bd_name->name, pairing_variant, pass_key);
    if(BT_STATUS_SUCCESS != sBtInterface->ssp_reply(remote_bd_addr, pairing_variant, TRUE, pass_key))
    {
        printf("SSP Reply failed\n");
    }
}

static void bond_state_changed_cb(bt_status_t status, RawAddress* remote_bd_addr, bt_bond_state_t state)
{
    g_PairState = state;
}

static void acl_state_changed(bt_status_t status, RawAddress* remote_bd_addr, bt_acl_state_t state,
                              bt_hci_error_code_t hci_reason)
{
    printf("acl_state_changed : remote_bd_addr=%02x:%02x:%02x:%02x:%02x:%02x, acl status=%s \n",
    remote_bd_addr->address[0], remote_bd_addr->address[1], remote_bd_addr->address[2],
    remote_bd_addr->address[3], remote_bd_addr->address[4], remote_bd_addr->address[5],
    (state == BT_ACL_STATE_CONNECTED)?"ACL Connected" :"ACL Disconnected"
    );
}
static void dut_mode_recv(uint16_t opcode, uint8_t *buf, uint8_t len)
{
    bdt_log("DUT MODE RECV : NOT IMPLEMENTED");
}

static void le_test_mode(bt_status_t status, uint16_t packet_count)
{
    bdt_log("LE TEST MODE END status:%s number_of_packets:%d", dump_bt_status(status), packet_count);
}

extern int timer_create (clockid_t, struct sigevent *__restrict, timer_t *__restrict);
extern int timer_settime (timer_t, int, const struct itimerspec *__restrict, struct itimerspec *__restrict);

static bool set_wake_alarm(uint64_t delay_millis, bool should_wake, alarm_cb cb, void *data)
{

   static timer_t timer;
   static bool timer_created;

   if (!timer_created) {
      struct sigevent sigevent;
      memset(&sigevent, 0, sizeof(sigevent));
      sigevent.sigev_notify = SIGEV_THREAD;
      sigevent.sigev_notify_function = (void (*)(union sigval))cb;
      sigevent.sigev_value.sival_ptr = data;
      timer_create(CLOCK_MONOTONIC, &sigevent, &timer);
      timer_created = true;
   }

   struct itimerspec new_value;
   new_value.it_value.tv_sec = delay_millis / 1000;
   new_value.it_value.tv_nsec = (delay_millis % 1000) * 1000 * 1000;
   new_value.it_interval.tv_sec = 0;
   new_value.it_interval.tv_nsec = 0;
   timer_settime(timer, 0, &new_value, NULL);

  return TRUE;
}

static int acquire_wake_lock(const char *lock_name)
{
    return BT_STATUS_SUCCESS;
}

static int release_wake_lock(const char *lock_name)
{
    return BT_STATUS_SUCCESS;
}

static bt_callbacks_t bt_callbacks = {
    sizeof(bt_callbacks_t),
    adapter_state_changed,
    adapter_properties_changed, /*adapter_properties_cb */
    NULL, /* remote_device_properties_cb */
    NULL, /* device_found_cb */
    discovery_state_changed, /* discovery_state_changed_cb */
    pin_request_cb, /* pin_request_cb  */
    ssp_request_cb, /* ssp_request_cb  */
    bond_state_changed_cb, /*bond_state_changed_cb */
    acl_state_changed, /* acl_state_changed_cb */
    NULL, /* thread_evt_cb */
    dut_mode_recv, /*dut_mode_recv_cb */
    le_test_mode, /* le_test_mode_cb */
    NULL      /*energy_info_cb*/
};

static bt_os_callouts_t bt_os_callbacks = {
     sizeof(bt_os_callouts_t),
     set_wake_alarm,
     acquire_wake_lock,
     release_wake_lock
};

static void l2test_l2c_connect_ind_cb(const RawAddress& bd_addr, uint16_t lcid, uint16_t psm, uint8_t id)
{

    uint16_t result;

    local_coc_cfg.credits = L2CAP_LE_DEFAULT_CREDIT;
    local_coc_cfg.mtu = L2CAP_LE_DEFAULT_MTU;
    local_coc_cfg.mps = L2CAP_LE_DEFAULT_MPS;
    /* Verify if LE PSM  */
   if (L2C_IS_VALID_COC_PSM(psm))
   {
       if (psm == 200)
       {
           printf("No Resources Available\n");
           result = L2CAP_LE_RESULT_NO_RESOURCES;
           sL2capInterface->LeConnectRsp (bd_addr, id, lcid, result,L2CAP_LE_RESULT_CONN_OK,&local_coc_cfg);
       }
       else if(psm == 201)
       {
           printf("L2CAP_LE_CONN_INSUFFI_AUTHORIZATION \n");
           result = L2CAP_LE_RESULT_INSUFFICIENT_AUTHORIZATION;
           sL2capInterface->LeConnectRsp (bd_addr, id, lcid, result,L2CAP_LE_RESULT_CONN_OK,&local_coc_cfg);
       }
       else
       {

           result = L2CAP_LE_RESULT_CONN_OK;
           sL2capInterface->LeConnectRsp (bd_addr, id, lcid, result,L2CAP_LE_RESULT_CONN_OK,&local_coc_cfg);
       }
       return;
   }
    if((L2CAP_FCR_ERTM_MODE == g_Fcr_Mode) || (L2CAP_FCR_STREAM_MODE == g_Fcr_Mode)) {
        sL2capInterface->ErtmConnectRsp(bd_addr, id, lcid, L2CAP_CONN_OK, L2CAP_CONN_OK, &t_ertm_info);
    } else {
        sL2capInterface->ConnectRsp(bd_addr, id, lcid, L2CAP_CONN_OK, L2CAP_CONN_OK);
    }
    {
        tL2CAP_CFG_INFO cfg;
        memcpy (&cfg ,&tl2cap_cfg_info,sizeof(tl2cap_cfg_info));
        if ((!sL2capInterface->ConfigReq (lcid, &cfg)) && cfg.fcr_present
              && cfg.fcr.mode != L2CAP_FCR_BASIC_MODE) {
            cfg.fcr.mode = L2CAP_FCR_BASIC_MODE;
            cfg.fcr_present = FALSE;
            sL2capInterface->ConfigReq (lcid, &cfg);
        }
    }
    g_ConnectionState = CONNECT;
    g_lcid = lcid;
}

static void l2test_l2c_connect_cfm_cb(uint16_t lcid, uint16_t result)
{
    t_le_chnl_info *le_conn_info = le_get_conn_info_by_lcid(lcid);
    if (le_conn_info&&L2C_IS_VALID_COC_PSM(le_conn_info->psm))
    {

        if (result == L2CAP_LE_RESULT_CONN_OK) {
            g_ConnectionState = CONNECT;
        }
        else if(le_conn_info && !le_conn_info->is_server)
        {
            le_release_conn_info(le_conn_info);
        }
        return;
    }
}

static void l2test_l2c_connect_pnd_cb(uint16_t lcid)
{
    g_ConnectionState = CONNECTING;
}
static void l2test_l2c_config_ind_cb(uint16_t lcid, tL2CAP_CFG_INFO *p_cfg)
{
    p_cfg->result = L2CAP_CFG_OK;
    p_cfg->fcr_present = FALSE;
    if(p_cfg->mtu_present) g_omtu = p_cfg->mtu;
    else g_omtu = L2CAP_DEFAULT_MTU;
    sL2capInterface->ConfigRsp (lcid, p_cfg);
    return;
}

static void l2test_l2c_config_cfm_cb(uint16_t lcid, tL2CAP_CFG_INFO *p_cfg)
{

    /* For now, always accept configuration from the other side */
    if (p_cfg->result == L2CAP_CFG_OK) {
        printf("\nl2test_l2c_config_cfm_cb Success\n");
    } else {

     /* If peer has rejected FCR and suggested basic then try basic */
    if (p_cfg->fcr_present) {
        tL2CAP_CFG_INFO cfg;
        memcpy (&cfg ,&tl2cap_cfg_info,sizeof(tl2cap_cfg_info));
        cfg.fcr_present = FALSE;
        sL2capInterface->ConfigReq (lcid, &cfg);
        // Remain in configure state
        return;
    }
    sL2capInterface->DisconnectReq(lcid);
    }
    if(0 == g_omtu) g_omtu = L2CAP_DEFAULT_MTU;
}

static void l2test_l2c_disconnect_ind_cb(uint16_t lcid, bool ack_needed)
{
    t_le_chnl_info *le_conn_info = le_get_conn_info_by_lcid(lcid);
    /* release the conn info entry if it'a  client */
    if(le_conn_info &&  !le_conn_info->is_server)
    {
        le_release_conn_info(le_conn_info);
    }
    printf("l2test_le_l2c_disconnect_ind_cb, cid=0x%x, acks=%d\n", lcid, ack_needed);
    if (ack_needed)
    {
        /* send L2CAP disconnect response */
        sL2capInterface->DisconnectRsp(lcid);
    }
    g_ConnectionState = DISCONNECTING;
    g_lcid = 0;
}

static void ecfc_l2c_disconnect_ind_cb(uint16_t lcid, bool ack_needed)
{
    printf("ecfc_le_l2c_disconnect_ind_cb, cid=0x%x, acks=%d\n", lcid, ack_needed);
    if (ack_needed)
    {
        /* send L2CAP disconnect response */
        sL2capInterface->DisconnectRsp(lcid);
    }
    g_ConnectionState = DISCONNECTING;
    g_lcid = 0;
    g_peer_mtu = 0;
}

static void ecfc_l2c_disconnect_cfm_cb(uint16_t lcid, uint16_t result)
{

    printf("ecfc_l2c_disconnect_cfm_cb, cid=0x%x, result=%d\n", lcid, result);
    g_ConnectionState = DISCONNECT;
    g_lcid = 0;
    g_peer_mtu = 0;
}

static void l2test_l2c_disconnect_cfm_cb(uint16_t lcid, uint16_t result)
{
    t_le_chnl_info *le_conn_info = le_get_conn_info_by_lcid(lcid);
    /* release the conn info entry if it'a  client */
    if(le_conn_info &&  !le_conn_info->is_server)
    {
        le_release_conn_info(le_conn_info);
    }

    printf("l2test_le_l2c_disconnect_cfm_cb, cid=0x%x, result=%d\n", lcid, result);
    g_ConnectionState = DISCONNECT;
    g_lcid = 0;
}
static void l2test_l2c_QoSViolationInd(const RawAddress& bd_addr)
{
    printf("l2test_l2c_QoSViolationInd\n");
}
static void l2test_l2c_data_ind_cb(uint16_t lcid)
{
    rcv_itration++;
    time_t start, ending;
    time(&start);
    //printf("l2test_l2c_data_ind_cb:: CID : %d \n", lcid);
    BT_HDR* p_buf = NULL;

    p_buf = sL2capInterface->ReadData(lcid);

    if (p_buf) {
        //printf("l2test_l2c_data_ind_cb:: recv_iteration %d "\
        //        "\n", rcv_itration);
        #if 0
        printf("Length : %d\n", p_buf->len);
        printf("\n ==========================\n");
        for (int i = 0; i < p_buf->len ; i++) {
            printf("0x%x   ", p_buf->data[i]);
        }
        printf("\n ==========================\n");
        #endif
    } else {
		printf("l2test_l2c_data_ind_cb:: CID : %d FAILED FROM READDATA \n", lcid);
	}
    time(&ending);
    std::cout << "Total time required = "
         << difftime(ending, start) << std::endl;
    sL2capInterface->LeFreeBuf(p_buf);
}

static void l2test_l2c_congestion_ind_cb(uint16_t lcid, bool is_congested)
{
    cong_status = is_congested;
    printf("l2test_l2c_congestion_ind_cb is_congested %d\n ", is_congested);
}

static void send_coc_data(char *p) {
    uint16_t lcid = get_int(&p, -1);
    uint16_t mtu = get_int(&p, -1);
    uint64_t num_itr = get_int(&p, -1);
    for (uint64_t i = 0; i < num_itr; i++) {
        Send_Data_ecfc(lcid, mtu);
        usleep(050000);
        //Send_Data_ecfc(lcid + 1, mtu);
        //usleep(100000);
    }
}

static void ecfc_reconfig_rsp(char *p) {
    ecfc_reconfig_rsp_code = get_int(&p, -1);
}

int Send_Data_ecfc(uint16_t lcid, uint16_t mtu)
{
    char tmpBuffer_1[] = {
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F
    };

    //printf("Sending Segmented data...\nData written len %d...MTU size %d\n",
     //           sizeof(tmpBuffer_1), mtu);
    if (mtu < sizeof(tmpBuffer_1)) {
        do_l2cap_DataWrite(lcid, tmpBuffer_1, mtu);
    } else {
        do_l2cap_DataWrite(lcid, tmpBuffer_1, sizeof(tmpBuffer_1));
    }
    return TRUE;
}
static int global_lcid = 64;
static uint64_t global_cnt_data_pks = 0;
static void l2test_l2c_tx_complete_cb (uint16_t lcid, uint16_t NoOfSDU)
{
    printf("l2test_l2c_tx_complete_cb, cid=0x%x, SDUs=%u\n", lcid, NoOfSDU);
    if (global_cnt_data_pks > 100000) {
        return;
    }
}

/* L2CAP callback function structure */
static tL2CAP_APPL_INFO l2test_l2c_appl = {
  //  sizeof(l2test_l2c_appl),
    l2test_l2c_connect_ind_cb,
    l2test_l2c_connect_cfm_cb,
    l2test_l2c_connect_pnd_cb,
    l2test_l2c_config_ind_cb,
    l2test_l2c_config_cfm_cb,
    l2test_l2c_disconnect_ind_cb,
    l2test_l2c_disconnect_cfm_cb,
    l2test_l2c_QoSViolationInd,
    NULL,
    l2test_l2c_congestion_ind_cb,
    l2test_l2c_tx_complete_cb
};


void bdt_init(void)
{
    bdt_log("INIT BT ");
    status = sBtInterface->init(&bt_callbacks, false, false, 0, nullptr, false);
    if (status == BT_STATUS_SUCCESS) {
        // Get Vendor Interface
        btvendorInterface = (btvendor_interface_t *)sBtInterface->get_profile_interface(BT_PROFILE_VENDOR_ID);
        if (!btvendorInterface) {
            bdt_log("Error in loading vendor interface ");
            exit(0);
        }
        //status = (bt_status_t)sBtInterface->set_os_callouts(&callouts);
        status = sBtInterface->set_os_callouts(&bt_os_callbacks);
    }
    check_return_status(status);
}

void bdt_enable(void)
{
    bdt_log("ENABLE BT");
    if (bt_enabled) {
        bdt_log("Bluetooth is already enabled");
        return;
    }
    status = sBtInterface->enable();

    check_return_status(status);
}

void bdt_disable(void)
{
    bdt_log("DISABLE BT");
    if (!bt_enabled) {
        bdt_log("Bluetooth is already disabled");
        return;
    }
    status = sBtInterface->disable();

    check_return_status(status);
}

void do_pairing(char *p)
{
    RawAddress bd_addr = {{0}};
    int transport = GATT_TRANSPORT_LE;
    if(FALSE == GetBdAddr(p, &bd_addr))    return;    // arg1
    if(BT_STATUS_SUCCESS != sBtInterface->create_bond(&bd_addr, transport))
    {
        printf("Failed to Initiate Pairing \n");
        return;
    }
}

void bdt_dut_mode_configure(char *p)
{
    int32_t mode = -1;

    bdt_log("BT DUT MODE CONFIGURE");
    if (!bt_enabled) {
        bdt_log("Bluetooth must be enabled for test_mode to work.");
        return;
    }
    mode = get_signed_int(&p, mode);
    if ((mode != 0) && (mode != 1)) {
        bdt_log("Please specify mode: 1 to enter, 0 to exit");
        return;
    }
    status = sBtInterface->dut_mode_configure(mode);

    check_return_status(status);
}

#define HCI_LE_RECEIVER_TEST_OPCODE 0x201D
#define HCI_LE_TRANSMITTER_TEST_OPCODE 0x201E
#define HCI_LE_END_TEST_OPCODE 0x201F

void bdt_le_test_mode(char *p)
{
    int cmd;
    unsigned char buf[3];
    int arg1, arg2, arg3;

    bdt_log("BT LE TEST MODE");
    if (!bt_enabled) {
        bdt_log("Bluetooth must be enabled for le_test to work.");
        return;
    }

    memset(buf, 0, sizeof(buf));
    cmd = get_int(&p, 0);
    switch (cmd)
    {
        case 0x1: /* RX TEST */
           arg1 = get_int(&p, -1);
           if (arg1 < 0) bdt_log("%s Invalid arguments", __FUNCTION__);
           buf[0] = arg1;
           status = sBtInterface->le_test_mode(HCI_LE_RECEIVER_TEST_OPCODE, buf, 1);
           break;
        case 0x2: /* TX TEST */
            arg1 = get_int(&p, -1);
            arg2 = get_int(&p, -1);
            arg3 = get_int(&p, -1);
            if ((arg1 < 0) || (arg2 < 0) || (arg3 < 0))
                bdt_log("%s Invalid arguments", __FUNCTION__);
            buf[0] = arg1;
            buf[1] = arg2;
            buf[2] = arg3;
            status = sBtInterface->le_test_mode(HCI_LE_TRANSMITTER_TEST_OPCODE, buf, 3);
           break;
        case 0x3: /* END TEST */
            status = sBtInterface->le_test_mode(HCI_LE_END_TEST_OPCODE, buf, 0);
           break;
        default:
            bdt_log("Unsupported command");
            return;
            break;
    }
    if (status != BT_STATUS_SUCCESS)
    {
        bdt_log("%s Test 0x%x Failed with status:0x%x", __FUNCTION__, cmd, status);
    }
    return;
}

void bdt_cleanup(void)
{
    bdt_log("CLEANUP");
    sBtInterface->cleanup();
}

/*******************************************************************************
 ** Console commands
 *******************************************************************************/

void do_help(char *p)
{
    int i = 0;
    char line[128];
//    int pos = 0;

    while (console_cmd_list[i].name != NULL)
    {
        snprintf(line, 128,"%s", (char*)console_cmd_list[i].name);
        bdt_log("%s %s\n", (char*)line, (char*)console_cmd_list[i].help);
        i++;
    }
}

void do_quit(char *p)
{
    bdt_shutdown();
}

/*******************************************************************
 *
 *  BT TEST  CONSOLE COMMANDS
 *
 *  Parses argument lists and passes to API test function
 *
*/

void do_init(char *p)
{
    bdt_init();
}

void do_enable(char *p)
{
    bdt_enable();
}

void do_disable(char *p)
{
    bdt_disable();
}
void do_dut_mode_configure(char *p)
{
    bdt_dut_mode_configure(p);
}

void do_le_test_mode(char *p)
{
    bdt_le_test_mode(p);
}

void do_cleanup(char *p)
{
    bdt_cleanup();
}


void do_le_client_register(char *p)
{
    bt_status_t        Ret;
    int Idx;
    Uuid uuid;
    Uuid bt_uuid;
    bool is_valid = false;

    skip_blanks(&p);
    Idx = atoi(p);

    switch(Idx)
    {
    case 1:
        uuid = Uuid::FromString("0000A00C-0000-0000-01234-56789ABCDEF", &is_valid);//0000A00C-0000-0000-0123-456789ABCDEF
        bt_uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid); //0000A00C-0000-0000-0123-456789ABCDEF
        break;
    case 2:
        uuid = Uuid::FromString("1122A00C-0000-0000-0123-456789ABCDEF", &is_valid);//1122A00C-0000-0000-0123-456789ABCDEF
        bt_uuid = Uuid::FromString("1122A00C-0000-0000-0123-456789ABCDEF", &is_valid);//1122A00C-0000-0000-0123-456789ABCDEF*/
        break;
    default:
        printf("%s:: ERROR: no matching uuid \n", __FUNCTION__);
        return;
    }
    if(Btif_gatt_layer)
    {
        Ret = sGattIfaceScan->client->register_client(bt_uuid, false);
        printf("%s:: ret value %d\n", __FUNCTION__,Ret);
    }
    else
    {
        g_client_if = sGattInterface->Register(uuid, &sGattCB, false);
        sleep(2);
        sGattInterface->StartIf(g_client_if);
    }
}

void do_le_client_deregister(char *p)
{
    bt_status_t        Ret;

    if(Btif_gatt_layer)
    {
        if(0 == g_client_if_scan)
        {
            printf("%s:: ERROR: no application registered\n", __FUNCTION__);
            return;
        }
        Ret = sGattIfaceScan->client->unregister_client(g_client_if_scan);
        printf("%s:: Ret=%d\n", __FUNCTION__, Ret);
    }
    else
    {
        if(0 == g_client_if)
        {
            printf("%s:: ERROR: no application registered\n", __FUNCTION__);
            return;
        }
        sGattInterface->Deregister(g_client_if);
    }
}

void do_le_client_connect(char *p)
{
    bool        Ret = false;
    RawAddress  bd_addr = {{0}};
    int transport = BT_TRANSPORT_BR_EDR;
    transport = get_int(&p, -1);
    if(FALSE == GetBdAddr(p, &bd_addr))    return;

    if(Btif_gatt_layer)
    {
        //TODO need to add phy parameter as 0x07 for connection to all types of Phys
        Ret = sGattIfaceScan->client->connect(g_client_if_scan, bd_addr, TRUE, transport, FALSE, 0x01);
    }
    else if(transport == BT_TRANSPORT_BR_EDR) {
        //Outgoing Connection

        //    g_SecLevel |= BTM_SEC_OUT_AUTHENTICATE;
        //     g_SecLevel |= BTM_SEC_OUT_ENCRYPT ;
        g_PSM= 1;
        g_SecLevel = 0;
        printf("g_SecLevel = %d \n", g_SecLevel);
        sL2capInterface->RegisterPsm(g_PSM, g_ConnType, g_SecLevel );
        sleep(3);

        l2c_connect(bd_addr);
    }
    else
    {
        Ret = sGattInterface->Connect(g_client_if, bd_addr.address, TRUE, transport);
    }
    printf("%s:: Ret=%d \n", __FUNCTION__, Ret);
}

void do_le_client_disconnect (char *p)
{
    int        Ret = -1;
    bool return_status;
    RawAddress bd_addr = {{0}};
    int transport = BT_TRANSPORT_BR_EDR;
    transport = get_int(&p, -1);
    if(FALSE == GetBdAddr(p, &bd_addr))    return;

    if(Btif_gatt_layer)
    {
        Ret = sGattIfaceScan->client->disconnect(g_client_if_scan, bd_addr, g_conn_id);
    }
    else if(transport == BT_TRANSPORT_BR_EDR)
    {
        return_status = sL2capInterface->DisconnectReq(g_lcid);
    }
    else
    {
        Ret = sGattInterface->Disconnect(g_conn_id);
    }
    printf("%s:: Ret=%d \n", __FUNCTION__,Ret );
}

void do_le_client_scan_start(char *p)
{
    sGattIfaceScan->scanner->Scan(true);
}

void do_le_scan_filter_name(char *p)
{
  get_str_1(&p, (char *)g_bd_name);
  printf("the name %s\n ", g_bd_name);
}

void do_le_client_scan_stop(char *p)
{
    sGattIfaceScan->scanner->Scan(false);
}

void DoNothing2(uint8_t, uint8_t) {}

void StartAdvertisingSetCb(uint8_t advertiser_id, int8_t tx_power,
                                uint8_t status) {
        start_advertising_set_advertiser_id = advertiser_id;
        start_advertising_set_tx_power = tx_power;
        start_advertising_set_status = status;
}

void do_start_adv_set(char *p)
{
    AdvertiseParameters params;
    PeriodicAdvertisingParameters periodic_params;
    periodic_params.enable = false;
    std::vector<uint8_t> periodic_data;
    int interval;

    //Adv params
    params.advertising_event_properties = get_hex(&p, -1);
    interval = get_int(&p, -1);

    switch(interval)
    {
        case INTERVAL_LOW:
            params.min_interval = 160;
            params.max_interval = 210;
            break;
        case INTERVAL_MEDIUM:
            params.min_interval = 400;
            params.max_interval = 450;
            break;
        case INTERVAL_HIGH:
            params.min_interval = 1600;
            params.max_interval = 1650;
            break;
    }

    params.primary_advertising_phy = get_int(&p, -1);
    params.secondary_advertising_phy = get_int(&p, -1);
    params.channel_map = 0x07;
    params.tx_power = -7;

    params.scan_request_notification_enable = false;

    //adv data
    uint8_t arr[] ={10,9,'G','A','T','T','-','T','O','O','L'};
    std::vector<uint8_t> adv_data(arr, arr + (sizeof(arr)/sizeof(arr[0])));
    std::vector<uint8_t> scan_resp;
    scan_resp = adv_data;

    sGattIfaceScan->advertiser->StartAdvertisingSet(reg_inst_id, base::Bind(&StartAdvertisingSetCb),
            params, adv_data, scan_resp, periodic_params, periodic_data,
            0 , 0 ,  base::Bind(DoNothing2));
}
void do_unregister_adv_set(char *p)
{
    sGattIfaceScan->advertiser->Unregister(start_advertising_set_advertiser_id);
}


/*******************************************************************************
 ** GATT SERVER API commands
 *******************************************************************************/
void do_le_server_register(char *p)
{
    bt_status_t        Ret;
    bool is_valid = false;
    int Idx;
    Uuid uuid;
    Uuid bt_uuid;
    skip_blanks(&p);
    Idx = atoi(p);
    switch(Idx)
    {
    case 1:
        uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid);//0000A00C-0000-0000-0123-456789ABCDEF
        bt_uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid); //0000A00C-0000-0000-0123-456789ABCDEF
        break;
    case 2:
        uuid = Uuid::FromString("1122A00C-0000-0000-0123-456789ABCDEF", &is_valid);//1122A00C-0000-0000-0123-456789ABCDEF
        bt_uuid = Uuid::FromString("1122A00C-0000-0000-0123-456789ABCDEF", &is_valid);//1122A00C-0000-0000-0123-456789ABCDEF*/
        break;
    default:
        printf("%s:: ERROR: no matching uuid \n", __FUNCTION__);
        return;
    }

    if(Btif_gatt_layer)
    {
        Ret = sGattIfaceScan->server->register_server(bt_uuid, false);
        printf("%s:: Ret=%d \n", __FUNCTION__, Ret);
    }
    else
    {
        g_server_if = sGattInterface->Register(uuid, &sGattCB, false);
        printf("%s:: g_server_if=%d \n", __FUNCTION__, g_server_if);
    }
}

void do_le_server_deregister(char *p)
{
    bt_status_t        Ret;
    if(0 == g_server_if)
    {
        printf("%s:: ERROR: no application registered\n", __FUNCTION__);
        return;
    }
    sGattInterface->Deregister(g_server_if);
    Ret = sGattIfaceScan->server->unregister_server(g_server_if_scan);
    printf("%s::Ret = %d\n", __FUNCTION__,Ret);
}

void do_le_server_connect(char *p)
{
    bool        Ret;
    RawAddress bd_addr = {{0}};
    int transport = BT_TRANSPORT_BR_EDR;
    transport = get_int(&p, -1);
    if(FALSE == GetBdAddr(p, &bd_addr))    return;
    Ret = sGattIfaceScan->server->connect(g_server_if_scan, bd_addr, TRUE, transport);
    printf("%s:: Ret=%d \n", __FUNCTION__,Ret );
}

void do_le_server_disconnect(char *p)
{
    bt_status_t        Ret;
    RawAddress bd_addr = {{0}};
    int transport = BT_TRANSPORT_BR_EDR;
    transport = get_int(&p, -1);
    if(FALSE == GetBdAddr(p, &bd_addr))    return;
    Ret = sGattIfaceScan->server->disconnect(g_server_if_scan, bd_addr, g_conn_id);
    printf("%s:: Ret=%d \n", __FUNCTION__,Ret );
}

void do_l2cap_init(char *p)
{
    memset(&tl2cap_cfg_info, 0, sizeof(tl2cap_cfg_info));
    memset(&le_conn_info, 0, sizeof(le_conn_info));
    //Use macros for the constants
    tl2cap_cfg_info.mtu_present = TRUE;
    tl2cap_cfg_info.mtu = g_imtu;
    tl2cap_cfg_info.flush_to_present = TRUE;
    tl2cap_cfg_info.flush_to = 0xffff;
    //use other param if needed
    tl2cap_cfg_info.fcr_present = g_Fcr_Present;
    tl2cap_cfg_info.fcr.mode = g_Fcr_Mode;
    tl2cap_cfg_info.fcs = 0;
    tl2cap_cfg_info.fcs_present = 1;
    le_conn_info.init_credits = L2CAP_LE_MAX_CREDIT;
    le_conn_info.le_mtu = L2CAP_LE_DEFAULT_MTU;
    le_conn_info.le_mps = L2CAP_LE_DEFAULT_MPS;
    le_conn_info.le_psm = 0x80; //dynamic le psm starts from 0x80
    if(L2CAP_FCR_ERTM_MODE == tl2cap_cfg_info.fcr.mode)
    {
        tl2cap_cfg_info.fcr = ertm_fcr_opts_def;
    }
    else if(L2CAP_FCR_STREAM_MODE == tl2cap_cfg_info.fcr.mode)
    {
        tl2cap_cfg_info.fcr = stream_fcr_opts_def;
    }
    else if(NULL == sL2capInterface)
    {
        printf("Get L2cap testapp interfaces\n");
        sL2capInterface = (btl2cap_interface_t *)btvendorInterface->get_testapp_interface(TEST_APP_L2CAP);
    }
    tl2cap_cfg_info.fcr.tx_win_sz = 3;
    //Initialize ERTM Parameters
    t_ertm_info.preferred_mode = g_Fcr_Mode;
    t_ertm_info.allowed_modes = g_Ertm_AllowedMode;
    t_ertm_info.user_rx_buf_size = BT_DEFAULT_BUFFER_SIZE;
    t_ertm_info.user_tx_buf_size = BT_DEFAULT_BUFFER_SIZE;
    t_ertm_info.fcr_rx_buf_size = BT_DEFAULT_BUFFER_SIZE;
    t_ertm_info.fcr_tx_buf_size = BT_DEFAULT_BUFFER_SIZE;
    //Load L2cap Interface
    sL2capInterface->Init(&l2test_l2c_appl);
}

static uint16_t do_l2cap_connect(RawAddress bd_addr)
{

    if((L2CAP_FCR_STREAM_MODE == g_Fcr_Mode) || (L2CAP_FCR_ERTM_MODE == g_Fcr_Mode)) {
        return sL2capInterface->ErtmConnectReq(g_PSM, bd_addr, &t_ertm_info);
    } else {
        return sL2capInterface->Connect(g_PSM, &bd_addr);
    }
}

static void l2c_connect(RawAddress bd_addr)
{
    do_l2cap_connect(bd_addr);
}

/* LE-L2CAP functionalities */
static t_le_chnl_info *le_allocate_conn_info(uint16_t psm, bool is_server)
{
    t_le_chnl_info    *p_le_chnl_info = &le_chnl_conn_info[0];
    uint16_t      i;

    for (i = 0; i < MAX_L2CAP_CLIENTS; i++, p_le_chnl_info++)
    {
        if (!p_le_chnl_info->in_use)
        {
            p_le_chnl_info->in_use = TRUE;
            p_le_chnl_info->is_server = is_server;
            p_le_chnl_info->psm    = psm;
            return p_le_chnl_info;
        }
    }
    return (NULL);
}

static t_le_chnl_info *le_get_conn_info(uint16_t psm, bool is_server)
{
    t_le_chnl_info    *p_le_chnl_info = &le_chnl_conn_info[0];
    uint16_t      i;

    for (i = 0; i < MAX_L2CAP_CLIENTS; i++, p_le_chnl_info++)
    {
        if ((p_le_chnl_info->in_use) && (p_le_chnl_info->psm == psm)
                && (is_server == p_le_chnl_info->is_server))
        {
            return p_le_chnl_info;
        }
    }
    return NULL;
}

static t_le_chnl_info *le_get_conn_info_by_lcid(uint16_t lcid)
{
    t_le_chnl_info    *p_le_chnl_info = &le_chnl_conn_info[0];
    uint16_t      i;

    for (i = 0; i < MAX_L2CAP_CLIENTS; i++, p_le_chnl_info++)
    {
        if ((p_le_chnl_info->in_use) && (p_le_chnl_info->lcid == lcid))
        {
            return p_le_chnl_info;
        }
    }
    return NULL;
}

static bool le_release_conn_info(t_le_chnl_info *le_conn_info)
{
    if (le_conn_info && (le_conn_info->in_use))
    {
        le_conn_info->in_use = FALSE;
        le_conn_info->is_server = 0;
        le_conn_info->psm    = 0;
        memset(le_conn_info, 0, sizeof(tL2CAP_LE_CONN_INFO));
        return TRUE;
    }
    return FALSE;
}

static void do_start_advertisment(char *p)
{
	Uuid uuid;
    int option = get_int(&p, -1);
    int start = get_int(&p, -1);
    RawAddress bd_addr = {{0}};
	bool is_valid = false;

	// 128 bit UUID: 1122A00D-0000-0000-0123-456789ABCDEF
    uuid = Uuid::FromString("1122A00D-0000-0000-0123-456789ABCDEF", &is_valid);//1122A00D-0000-0000-0123-456789ABCDEF

    if ((g_le_coc_if == 0) && option)
        g_le_coc_if = sGattInterface->Register(uuid, &sGattCB, false);
    printf("Gatt Registration Done\n");

    if( option)
    {
        if (start == 1)
            status = sGattInterface->Listen(g_le_coc_if, start, bd_addr);
        else if (start == 0)
            status = sGattInterface->Listen(g_le_coc_if, start, bd_addr);
        else
        {
            printf("Unknown parameter\n");
            return;
        }
    }
    else
    {
        if (start == 1)
            status = sGattInterface->Listen(g_server_if_scan, start, bd_addr);
        else if (start == 0)
            status = sGattInterface->Listen(g_server_if_scan, start, bd_addr);
        else
        {
            printf("Unknown parameter\n");
            return;
        }
    }
    printf("Gatt Listen status is %d\n", status);
}

uint16_t do_le_l2cap_coc_flow_ctrl(char *p)
{
    uint16_t lcid = (uint16_t)get_int(&p, -1);

    uint16_t credits = (uint16_t)get_int(&p, -1);

    printf("\ndo_le_l2cap_coc_flow_ctrl lcid = %d, credits = %d\n", lcid, credits);
    return sL2capInterface->LeFlowControl(lcid, credits);
}
static void le_l2cap_coc_flow_ctrl(char *p)
{
    printf("In le_l2cap_coc_flow_ctrl\n");
    do_le_l2cap_coc_flow_ctrl(p);
}

uint16_t do_le_l2cap_coc_connect(char *p)
{
    int le_initiator_sec_level;
    uint16_t le_coc_seclevel = 0;
    RawAddress bd_addr = {{0}};
    uint16_t le_psm = (uint16_t)get_int(&p, -1);


    t_le_chnl_info *le_conn_info = le_allocate_conn_info(le_psm, FALSE);

    if(le_conn_info)
    {
        le_conn_info->loc_conn_info.le_psm = le_psm;
        le_conn_info->loc_conn_info.le_mtu = get_int(&p, -1);
        le_conn_info->loc_conn_info.le_mps = get_int(&p, -1);
        le_conn_info->loc_conn_info.init_credits = get_int(&p, -1);
        le_initiator_sec_level = get_int(&p, -1);
        if(FALSE == GetBdAddr(p, &bd_addr))    return FALSE;
    }
    else
        return FALSE;

    if (le_initiator_sec_level == 0)
    {
        le_coc_seclevel |= BTM_SEC_NONE;
    }
    else if (le_initiator_sec_level == 1)
    {
        le_coc_seclevel |= BTM_SEC_OUT_AUTHENTICATE;
    }
    else if (le_initiator_sec_level == 2)
    {
        le_coc_seclevel |= BTM_SEC_OUT_ENCRYPT;
        le_coc_seclevel |= BTM_SEC_OUT_AUTHENTICATE;
    }
    else
    {
        printf("Security level not supported");
        return FALSE;
    }

    printf("g_SecLevel = %d \n", le_coc_seclevel);
    sL2capInterface->RegisterLePsm(le_conn_info->loc_conn_info.le_psm, TRUE,
            le_coc_seclevel, g_BleEncKeySize);
    sleep(3);
    local_coc_cfg.credits = le_conn_info->loc_conn_info.init_credits;
    local_coc_cfg.mtu = le_conn_info->loc_conn_info.le_mtu;
    local_coc_cfg.mps = le_conn_info->loc_conn_info.le_mps;
    printf("\ndo_l2cap_connect:::::::: psm %d mtu %d mps %d init_credit %d \n",
            le_conn_info->loc_conn_info.le_psm, le_conn_info->loc_conn_info.le_mtu,
            le_conn_info->loc_conn_info.le_mps, le_conn_info->loc_conn_info.init_credits);

    return sL2capInterface->LeConnect(le_conn_info->loc_conn_info.le_psm, bd_addr, &local_coc_cfg);
}

static void le_l2cap_coc_connect(char *svr)
{
    do_le_l2cap_coc_connect(svr);
}

static void le_l2cap_listen(char *p)
{
    int le_rspndr_sec_level;
    uint16_t le_coc_seclevel = 0;
    uint16_t le_psm = get_int(&p, -1);
    t_le_chnl_info *le_conn_info = le_get_conn_info(le_psm, TRUE);

    if(!le_conn_info)
    {
        le_conn_info = le_allocate_conn_info(le_psm, TRUE);
    }
    else
    {
        printf("ALready listening on same channel");
        return;
    }

    if(le_conn_info)
    {
        le_conn_info->loc_conn_info.le_psm = le_psm;
        le_conn_info->loc_conn_info.le_mtu = get_int(&p, -1);
        le_conn_info->loc_conn_info.le_mps = get_int(&p, -1);
        le_conn_info->loc_conn_info.init_credits = get_int(&p, -1);
        le_rspndr_sec_level = get_int(&p, -1);
    }
    else
        return;

    if (le_rspndr_sec_level == 0)
    {
        le_coc_seclevel |= BTM_SEC_NONE;
    }
    else if (le_rspndr_sec_level == 1)
    {
        le_coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else if (le_rspndr_sec_level == 2)
    {
        le_coc_seclevel |= BTM_SEC_IN_ENCRYPT;
        le_coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else
    {
        printf("Security level not supported");
        return ;
    }
    printf("g_SecLevel = %d \n", le_coc_seclevel);

    sL2capInterface->RegisterLePsm(le_conn_info->loc_conn_info.le_psm, FALSE,
                                           le_coc_seclevel, g_BleEncKeySize);

    printf("Waiting for Incoming connection for LE PSM %d... \n",
                              le_conn_info->loc_conn_info.le_psm);
}

uint8_t do_l2cap_DataWrite(uint16_t chnl_id, char *p , uint32_t len)
{
    printf("do_l2cap_DataWrite \n");
    return sL2capInterface->DataWrite(chnl_id, p, len);
}

static int send_file(char *p)
{
    uint32_t seq = 0, itration = 1;
    int fd, size;
    char filename[] = {0};
    char tmpBuf[LE_ACL_MAX_BUFF_SIZE];
    uint16_t lcid;

    lcid = (uint16_t)get_int(&p, -1);
    t_le_chnl_info *le_conn_info = le_get_conn_info_by_lcid(lcid);
    GetFileName(p, filename);

    if(!le_conn_info)
    {
        printf("No conn info, exit \n");
        return FALSE;
    }

    g_omtu =  le_conn_info->rmt_conn_info.le_mtu;

    if(g_omtu < LE_ACL_MAX_BUFF_SIZE)
        data_size = g_omtu;
    else
        data_size = LE_ACL_MAX_BUFF_SIZE;

    printf("data_size(max patload size) = %ld, g_omtu(max ttansmission unit) = %d",
            data_size, g_omtu);

    printf("Filename for input data = %s \n", filename);

    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        printf("Open failed: %s (%d)\n", strerror(errno), errno);
        exit(1);
    }
    while (1)
    {
        while(cong_status)
        {
            usleep(50 * 1000);
        }
        if((size = read(fd, tmpBuf, data_size)) <= 0)
        {
            printf("\n File end ");
            break;
        }
        printf("Sending data :: itration %d, omtu %d, writing data size %d\n",
                itration, g_omtu, size);
        do_l2cap_DataWrite(lcid, tmpBuf, size);
        itration++;
    }

    if (num_frames && g_delay && count && !(seq % count))
        usleep(g_delay);
    return TRUE;
}


static int Send_Data(char *p)
{
    //uint32_t seq =0;
    int send_mode;
    uint16_t lcid;

    lcid = (uint16_t)get_int(&p, -1);
    send_mode = get_int(&p, -1);

    char tmpBuffer_1[] = {
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
    };
    char tmpBuffer_2[] = {
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,
        0x7F,0x7F,0x7F
    };

    if(send_mode == 1)  // segmented
    {
        printf("Sending Segmented data...\nData written len %d...\n",
                sizeof(tmpBuffer_1) );
        do_l2cap_DataWrite(lcid, tmpBuffer_1, sizeof(tmpBuffer_1));
    }
    else if( send_mode == 0) // unsegmented
    {
        printf("Sending Unsegmented data...\nData written len %d...\n",
                sizeof(tmpBuffer_2) );
        do_l2cap_DataWrite(lcid, tmpBuffer_2, sizeof(tmpBuffer_2));
    }
    return TRUE;
}

static void send_data_on_le_coc(char *svr)
{
    printf("Sending data on LE L2CAP CoC...\n");
    Send_Data(svr);
}
static void do_send_file(char *svr)
{
    printf("Sending file on LE L2CAP CoC...\n");
    send_file(svr);
}

bool le_coc_disc(char *p)
{
    uint16_t cid = (uint16_t)get_int(&p, -1);
    return sL2capInterface->DisconnectReq(cid);
}

static void do_le_coc_disconnect(char *p)
{
    le_coc_disc(p);
}

int g_result_ecfc = 0;
/* L2CAP callback function structure */
void l2test_ecfc_connect_ind_cb (tL2CAP_COC_CONN_REQ *p_conn_req,
                                         uint16_t l2cap_id,
                                         uint16_t result,
                                         uint16_t status) {
    //ECFC CONNECTION INDICATION
    printf("l2test_ecfc_connect_ind_cb	 Bd_addr %s \n"
                                       "num_chnls %d \t l2cap_id %d \n",
            p_conn_req->p_bd_addr.ToString().c_str(), p_conn_req->num_chnls, l2cap_id);
    for (int i = 0; i < p_conn_req->num_chnls; i++) {
        printf("Local CID  %d \t", p_conn_req->sr_cids[i]);
    }
    printf("\n");
    if (result != 0) {
        g_result_ecfc = result;
    }
#if 0
    printf("Enter the Result(0- Accepting/ 6- InsuffAuthrization/ "
           "11- Unacceptable Params) \n");

    char tmp[10] = {0};
    int len = read(0, &tmp, 9);
    char *p_tmp;
    p_tmp = &tmp[0];
    g_result_ecfc = get_int(&p_tmp, -1);

    if (g_result_ecfc == -1) g_result_ecfc = 0;

    printf(" Enter the Mtu Size (64 to 65525) \n");
    len = read(0, &tmp, 9);
    g_peer_mtu = get_int(&p_tmp, -1);

    if (g_peer_mtu < 64) g_peer_mtu = 64;
#endif
    p_conn_req->mtu = g_peer_mtu;
    printf("\n MTU size ---------- %d  and result %d\n", p_conn_req->mtu,
            g_result_ecfc);
    sL2capInterface->ConnectCocRsp(p_conn_req, l2cap_id, g_result_ecfc, status);
}

void l2test_ecfc_connect_cfm_cb (RawAddress &p_bd_addr,
                                 tL2CAP_COC_CHMAP_INFO  *chmap_info,
                                 uint16_t p_mtu,
                                 uint16_t result,
                                 uint16_t status) {
    g_peer_mtu = p_mtu;
    printf("peer mtu %d\n", g_peer_mtu);
    //ECFC CONNECTION CONFIRMATION
    printf("l2test_ecfc_connect_cfm_cb p_mtu %d, num_chnls %d, "
    " result %d status 0x%04x\n", p_mtu, chmap_info->num_chnls, result, status);

    for (int i = 0; i < chmap_info->num_chnls; i++) {
        printf("Local CID  %d \t", chmap_info->sr_cids[i]);
    }
}

int g_count_reconfig = 0;

void l2test_ecfc_reconfig_ind_cb (tL2CAP_COC_CHMAP_INFO* chmap_info,
                                          uint16_t p_mtu) {

    printf("l2test_ecfc_reconfig_ind_cb num_chnls %d, peer_mtu %d, \n",
          chmap_info->num_chnls, p_mtu);
    for (int i = 0; i < chmap_info->num_chnls; i++) {
        printf("Local CID  %d \t", chmap_info->sr_cids[i]);
    }
    printf("\n");

    sL2capInterface->ReconfigCocRsp(chmap_info, ecfc_reconfig_rsp_code);
}

void l2test_ecfc_reconfig_cfm_cb (tL2CAP_COC_CHMAP_INFO* chmap_info,
                                          uint16_t result) {

    printf("l2test_ecfc_reconfig_cfm_cb num_chnls %d "
    " result %d \n", chmap_info->num_chnls, result);
}

static tL2CAP_COC_APPL_INFO l2test_l2c_ecfc_appl = {
  //  sizeof(l2test_l2c_appl),
    l2test_ecfc_connect_ind_cb,
    l2test_ecfc_connect_cfm_cb,
    l2test_ecfc_reconfig_ind_cb,
    l2test_ecfc_reconfig_cfm_cb,
    ecfc_l2c_disconnect_ind_cb,
    ecfc_l2c_disconnect_cfm_cb,
    l2test_l2c_data_ind_cb,
    l2test_l2c_congestion_ind_cb,
    l2test_l2c_tx_complete_cb,
    NULL
};

static void ecfc_l2cap_listen(char *p)
{
    int ecfc_rspndr_sec_level;
    uint16_t coc_seclevel = 0;
    uint16_t ecfc_psm = get_int(&p, -1);
    tL2CAP_COC_CONN_REQ conn_req;

    sGattInterface->cSetVisibility(1,1);
    g_peer_mtu = get_int(&p, -1);
    ecfc_rspndr_sec_level = get_int(&p, -1);
    g_result_ecfc = get_int(&p, -1);

    if (ecfc_rspndr_sec_level == 0)
    {
        coc_seclevel |= BTM_SEC_NONE;
    }
    else if (ecfc_rspndr_sec_level == 1)
    {
        coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else if (ecfc_rspndr_sec_level == 2)
    {
        coc_seclevel |= BTM_SEC_IN_ENCRYPT;
        coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else
    {
        printf("Security level not supported %d", ecfc_rspndr_sec_level);
        return ;
    }
    printf("g_SecLevel = %d \n", coc_seclevel);

    sL2capInterface->RegisterCocPsm(ecfc_psm, &l2test_l2c_ecfc_appl,
                                        coc_seclevel, 16, false);

    printf("Waiting for Incoming connection for COC PSM %d... \n",
                              ecfc_psm);
}

tL2CAP_COC_CONN_REQ g_ecfc_conn_req = {};
static void ecfc_l2cap_reconfig(char *p) {
    tL2CAP_COC_CHMAP_INFO chmap_info = {};
    
    chmap_info.num_chnls = get_int(&p, -1);
    chmap_info.sr_cids[0] = get_int(&p, -1);
    chmap_info.sr_cids[1] = get_int(&p, -1);
    chmap_info.sr_cids[2] = get_int(&p, -1);
    chmap_info.sr_cids[3] = get_int(&p, -1);
    chmap_info.sr_cids[4] = get_int(&p, -1);

    uint16_t mtu = get_int(&p, -1);;
    printf("ecfc_l2cap_reconfig \n");
    printf("\n");

    g_count_reconfig++;
    sL2capInterface->ReconfigCocReq(&chmap_info, mtu);
}

uint16_t g_sr_id = 0;
static void ecfc_l2cap_connect(char *p) {
    uint16_t coc_seclevel = 0;
    RawAddress bd_addr = {{0}};

    g_ecfc_conn_req.psm = get_int(&p, -1);
    g_ecfc_conn_req.mtu = get_int(&p, -1);
    g_ecfc_conn_req.num_chnls = get_int(&p, -1);
    g_ecfc_conn_req.transport = get_int(&p, -1);
    uint16_t sec_level = get_int(&p, -1);
    g_result_ecfc = get_int(&p, -1);
	if(FALSE == GetBdAddr(p, &bd_addr))
		return ;

    g_ecfc_conn_req.p_bd_addr = bd_addr;
    if (sec_level == 0)
    {
        coc_seclevel |= BTM_SEC_NONE;
    }
    else if (sec_level == 1)
    {
        coc_seclevel |= BTM_SEC_OUT_AUTHENTICATE;
    }
    else if (sec_level == 2)
    {
        coc_seclevel |= BTM_SEC_OUT_ENCRYPT;
        coc_seclevel |= BTM_SEC_OUT_AUTHENTICATE;
    }
    else
    {
        printf("Security level not supported");
        //return ;
    }
    printf("g_SecLevel = %d \n", coc_seclevel);
    //TODO hardcorded security level.
    sL2capInterface->RegisterCocPsm(g_ecfc_conn_req.psm, &l2test_l2c_ecfc_appl, coc_seclevel, 16, true);
    sleep(3);
    printf(" ecfc_l2cap_connect:::::::: \n");
    int8_t status = sL2capInterface->ConnectCocReq(&g_ecfc_conn_req);
    printf(" Connection command status %d  Num chnls %d \n", status, g_ecfc_conn_req.num_chnls);
    printf(" ===========================\n ");
    for (int i = 0; i < g_ecfc_conn_req.num_chnls; i++) {
        printf(" Assigned CID %d \t", g_ecfc_conn_req.sr_cids[i]);
    }
    printf(" ===========================\n ");

}


static void do_ecfc_start(char* p) {
    bt_status_t Ret;
    Uuid uuid;
    Uuid bt_uuid;
    bool is_valid = false;

    uuid = Uuid::FromString("0000A00C-0000-0000-01234-56789ABCDEF", &is_valid);//0000A00C-0000-0000-0123-456789ABCDEF
    bt_uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid); //0000A00C-0000-0000-0123-456789ABCDEF

    if(Btif_gatt_layer)
    {
        Ret = sGattIfaceScan->client->register_client(bt_uuid, false);
        printf("%s:: ret value %d\n", __FUNCTION__,Ret);
    }
    else
    {
        g_client_if = sGattInterface->Register(uuid, &sGattCB, false);
        sleep(2);
        sGattInterface->StartIf(g_client_if);
    }
    sleep(2);
    printf("%s:: starting scan \n", __FUNCTION__);
    sGattIfaceScan->scanner->Scan(true);
}

void ecfc_start_adv() {
    std::vector<uint8_t> scan_resp;
    AdvertiseParameters params;
    PeriodicAdvertisingParameters periodic_params;
    periodic_params.enable = false;
    std::vector<uint8_t> periodic_data;
    int interval;

    //Adv params
    params.advertising_event_properties = 0x13;
    interval = 1;

    switch(interval)
    {
        case INTERVAL_LOW:
            params.min_interval = 160;
            params.max_interval = 210;
            break;
        case INTERVAL_MEDIUM:
            params.min_interval = 400;
            params.max_interval = 450;
            break;
        case INTERVAL_HIGH:
            params.min_interval = 1600;
            params.max_interval = 1650;
            break;
    }

    params.primary_advertising_phy = 1;
    params.secondary_advertising_phy = 1;
    params.channel_map = 0x07;
    params.tx_power = -7;

    params.scan_request_notification_enable = false;

    //adv data
    uint8_t arr[] ={10,9,'G','A','T','T','-','T','O','O','L'};
    std::vector<uint8_t> adv_data(arr, arr + (sizeof(arr)/sizeof(arr[0])));

    sGattIfaceScan->advertiser->StartAdvertisingSet(reg_inst_id, base::Bind(&StartAdvertisingSetCb),
            params, adv_data, scan_resp, periodic_params, periodic_data,
            0 , 0 ,  base::Bind(DoNothing2));
}

static void ecfc_l2cap_server()
{
    int ecfc_rspndr_sec_level;
    uint16_t coc_seclevel = 0;
    uint16_t ecfc_psm = 39;
    tL2CAP_COC_CONN_REQ conn_req;

    sGattInterface->cSetVisibility(1,1);
    conn_req.mtu = 400;
    conn_req.transport = BT_TRANSPORT_LE;
    ecfc_rspndr_sec_level = 0;

    if (ecfc_rspndr_sec_level == 0)
    {
        coc_seclevel |= BTM_SEC_NONE;
    }
    else if (ecfc_rspndr_sec_level == 1)
    {
        coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else if (ecfc_rspndr_sec_level == 2)
    {
        coc_seclevel |= BTM_SEC_IN_ENCRYPT;
        coc_seclevel |= BTM_SEC_IN_AUTHENTICATE;
    }
    else
    {
        printf("Security level not supported %d", ecfc_rspndr_sec_level);
        return ;
    }
    printf("g_SecLevel = %d \n", coc_seclevel);

    sL2capInterface->RegisterCocPsm(ecfc_psm, &l2test_l2c_ecfc_appl,
                                        coc_seclevel, 16, false);

    printf("Waiting for Incoming connection for COC PSM %d... \n",
                              ecfc_psm);
}

static void do_ecfc_listen(char* p) {
    bt_status_t        Ret;
    bool is_valid = false;
    Uuid uuid;
    Uuid bt_uuid;
    uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid);//0000A00C-0000-0000-0123-456789ABCDEF
    bt_uuid = Uuid::FromString("0000A00C-0000-0000-0123-456789ABCDEF", &is_valid); //0000A00C-0000-0000-0123-456789ABCDEF

    if(Btif_gatt_layer)
    {
        Ret = sGattIfaceScan->server->register_server(bt_uuid, false);
        printf("%s:: Ret=%d \n", __FUNCTION__, Ret);
    }
    else
    {
        g_server_if = sGattInterface->Register(uuid, &sGattCB, false);
        printf("%s:: g_server_if=%d \n", __FUNCTION__, g_server_if);
    }
    sleep(2);
    ecfc_start_adv();
    sleep(2);
    ecfc_l2cap_server();
}


void do_l2cap_send_data_cid(char *p)
{
    uint16_t        cid        = 0;
    BT_HDR        bt_hdr;
    uint16_t         Ret = 0;
    RawAddress bd_addr = {{0}};
    if(FALSE == GetBdAddr(p, &bd_addr))    return; //arg1
    cid = (uint16_t)get_int(&p, -1); // arg2

    bt_hdr.event     = 0;
    bt_hdr.len         = 1;
    bt_hdr.offset     = 0;
    bt_hdr.layer_specific = 0;


    Ret = sL2capInterface->SendFixedChnlData(cid, bd_addr.address, &bt_hdr);
    printf("%s:: Ret=%d \n", __FUNCTION__, Ret);

}

/*
 * Main console command handler
*/

static void process_cmd(char *p, unsigned char is_job)
{
    char cmd[2048];
    int i = 0;
    bt_pin_code_t pincode;
    char *p_saved = p;

    get_str(&p, cmd);

    /* table commands */
    while (console_cmd_list[i].name != NULL)
    {
        if (is_cmd(console_cmd_list[i].name))
        {
            if (!is_job && console_cmd_list[i].is_job)
                create_cmdjob(p_saved);
            else
            {
                console_cmd_list[i].handler(p);
            }
            return;
        }
        i++;
    }
    //pin key
    if(cmd[6] == '.') {
        for(i=0; i<6; i++) {
            pincode.pin[i] = cmd[i];
        }
        if(BT_STATUS_SUCCESS != sBtInterface->pin_reply(remote_bd_address, TRUE, strlen((const char*)pincode.pin), &pincode)) {
            printf("Pin Reply failed\n");
        }
        //flush the char for pinkey
        cmd[6] = 0;
    }
    else {
        bdt_log("%s : unknown command\n", p_saved);
        do_help(NULL);
    }
}

int main ()
{
    static btgatt_callbacks_t    sGatt_cb = {sizeof(btgatt_callbacks_t), &sGattClient_cb, &sGattServer_cb, &sScanner_cb};

    config_permissions();
    bdt_log("\n:::::::::::::::::::::::::::::::::::::::::::::::::::");
    bdt_log(":: Bluedroid test app starting");

    if ( HAL_load() < 0 ) {
        perror("HAL failed to initialize, exit\n");
        unlink(PID_FILE);
        exit(0);
    }

    setup_test_env();

    /* Automatically perform the init */
    bdt_init();
    sleep(5);
    bdt_enable();
    sleep(5);
    bdt_log("Get SMP IF BT Interface = %x \n", sBtInterface);
    sGattInterface   = (btgatt_test_interface_t *)btvendorInterface->get_testapp_interface(TEST_APP_GATT);

    bdt_log("Get GAP IF");
    sGapInterface    = (btgap_interface_t *)btvendorInterface->get_testapp_interface(TEST_APP_GAP);

    bdt_log("Get GATT IF");
    sGattIfaceScan     = (btgatt_interface_t *)sBtInterface->get_profile_interface(BT_PROFILE_GATT_ID);

    bdt_log("Get L2CAP IF");
    sL2capInterface        = (btl2cap_interface_t *)btvendorInterface->get_testapp_interface(TEST_APP_L2CAP);

    sGattIfaceScan->init(&sGatt_cb);
    bdt_log("GATT IF INIT Done");

    printf("\n Before l2cap init\n");
    do_l2cap_init(NULL);
    printf("\n after l2cap init\n");

    while(!main_done)
    {
        char line[2048];

        /* command prompt */
        printf( ">" );
        fflush(stdout);

        fgets (line, 2048, stdin);

        if (line[0]!= '\0')
        {
            /* remove linefeed */
            line[strlen(line)-1] = 0;

            process_cmd(line, 0);
            memset(line, '\0', 2048);
        }
    }
    HAL_unload();

    bdt_log(":: Bluedroid test app terminating");

    return 0;
}
int GetFileName(char *p, char *filename)
{
//    uint8_t  i;
    int len;

    skip_blanks(&p);

    printf("Input file name = %s\n", p);

    if (p == NULL)
    {
        printf("\nInvalid File Name... Please enter file name\n");
        return FALSE;
    }
    len = strlen(p);

    memcpy(filename, p, len);
    filename[len] = '\0';

    return TRUE;
}
int GetBdAddr(char *p, RawAddress* pbd_addr)
{
    char Arr[13] = {0};
    char *pszAddr = NULL;
    uint8_t k1 = 0;
    uint8_t k2 = 0;
    uint8_t  i;

    skip_blanks(&p);

    printf("Input=%s\n", p);

    if(12 > strlen(p))
    {
        printf("\nInvalid Bd Address. Format[112233445566]\n");
        return FALSE;
    }
    memcpy(Arr, p, 12);

    for(i=0; i<12; i++)
    {
        Arr[i] = tolower(Arr[i]);
    }
    pszAddr = Arr;

    for(i=0; i<6; i++)
    {
        k1 = (uint8_t) ( (*pszAddr >= 'a') ? ( 10 + (uint8_t)( *pszAddr - 'a' )) : (*pszAddr - '0') );
        pszAddr++;
        k2 = (uint8_t) ( (*pszAddr >= 'a') ? ( 10 + (uint8_t)( *pszAddr - 'a' )) : (*pszAddr - '0') );
        pszAddr++;

        if ( (k1>15)||(k2>15) )
        {
            return FALSE;
        }
        pbd_addr->address[i] = (k1<<4 | k2);
    }
    return TRUE;
}
#endif //TEST_APP_INTERFACE
