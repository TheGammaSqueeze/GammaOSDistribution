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

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "bt_types.h"
#include "bt_vendor_lib.h"
#include "hci_internals.h"
#include "hci_layer.h"

#define HCI_BT_SOC_CRASHED_OGF    0xfc
#define HCI_BT_SOC_CRASHED_OCF    0x00

#define HCI_CRASH_MESSAGE_SIZE    (60)

typedef enum {
  VENDOR_CHIP_POWER_CONTROL = BT_VND_OP_POWER_CTRL,
  VENDOR_OPEN_USERIAL = BT_VND_OP_USERIAL_OPEN,
  VENDOR_CLOSE_USERIAL = BT_VND_OP_USERIAL_CLOSE,
  VENDOR_GET_LPM_IDLE_TIMEOUT = BT_VND_OP_GET_LPM_IDLE_TIMEOUT,
  VENDOR_SET_LPM_WAKE_STATE = BT_VND_OP_LPM_WAKE_SET_STATE,
  VENDOR_SET_AUDIO_STATE = BT_VND_OP_SET_AUDIO_STATE
} vendor_opcode_t;

typedef enum {
  VENDOR_CONFIGURE_FIRMWARE = BT_VND_OP_FW_CFG,
  VENDOR_CONFIGURE_SCO = BT_VND_OP_SCO_CFG,
  VENDOR_SET_LPM_MODE = BT_VND_OP_LPM_SET_MODE,
  VENDOR_DO_EPILOG = BT_VND_OP_EPILOG,
  VENDOR_A2DP_OFFLOAD_START = BT_VND_OP_A2DP_OFFLOAD_START,
  VENDOR_A2DP_OFFLOAD_STOP = BT_VND_OP_A2DP_OFFLOAD_STOP,
  VENDOR_LAST_OP
} vendor_async_opcode_t;

typedef void (*vendor_cb)(bool success);

typedef struct vendor_t {
  // Opens the vendor-specific library and sets the Bluetooth
  // address of the adapter to |local_bdaddr|. |hci_interface| is
  // used to send commands on behalf of the vendor library.
  bool (*open)(const uint8_t* local_bdaddr, const hci_t* hci_interface);

  // Closes the vendor-specific library and frees all associated resources.
  // Only |vendor_open| may be called after |vendor_close|.
  void (*close)(void);

  // Sends a vendor-specific command to the library.
  int (*send_command)(vendor_opcode_t opcode, void* param);

  // Sends an asynchronous vendor-specific command to the library.
  int (*send_async_command)(vendor_async_opcode_t opcode, void* param);

  // Registers a callback for an asynchronous vendor-specific command.
  void (*set_callback)(vendor_async_opcode_t opcode, vendor_cb callback);
} vendor_t;

const vendor_t* vendor_get_interface();

typedef enum {
  BT_SOC_REASON_DEFAULT        =  0x00,
  // SoC Crash Reasons
  BT_SOC_REASON_UNKNOWN        =  0x81,
  BT_SOC_REASON_SW_REQUESTED   =  0x82,
  BT_SOC_REASON_STACK_OVERFLOW =  0x83,
  BT_SOC_REASON_EXCEPTION      =  0x84,
  BT_SOC_REASON_ASSERT         =  0x85,
  BT_SOC_REASON_TRAP           =  0x86,
  BT_SOC_REASON_OS_FATAL       =  0x87,
  BT_SOC_REASON_HCI_RESET      =  0x88,
  BT_SOC_REASON_PATCH_RESET    =  0x89,
  BT_SOC_REASON_ABT            =  0x8A,
  BT_SOC_REASON_RAMMASK        =  0x8B,
  BT_SOC_REASON_PREBARK        =  0x8C,
  BT_SOC_REASON_BUSERROR       =  0x8D,
  BT_SOC_REASON_IO_FATAL       =  0x8E,
  BT_SOC_REASON_SSR_CMD        =  0x8F,
  BT_SOC_REASON_POWERON        =  0x90,
  BT_SOC_REASON_WATCHDOG       =  0x91,
  BT_SOC_REASON_RAMMASK_RGN1   =  0x92,
  BT_SOC_REASON_RAMMASK_RGN0   =  0x93,
  BT_SOC_REASON_Q6_WATCHDOG    =  0x94,
  BT_SOC_REASON_ZEALIS_RAM_MASK_RGN0 =  0x95,
  BT_SOC_REASON_ZEALIS_RAM_MASK_RGN1 =  0x96,
  BT_SOC_REASON_APSS_RESET           =  0x97,
  BT_SOC_REASON_TIME_RESET           =  0x98,
  BT_SOC_REASON_AUDIOSS_RESET        =  0x99,
  BT_SOC_REASON_HOST_WARMRESET       =  0x9A,
  BT_SOC_REASON_HOST_NMI_INIT        =  0x9B,
  BT_SOC_REASON_TX_RX_INVALID_PKT_FATAL = 0xC0,
  BT_SOC_REASON_TX_RX_INVALID_LEN_FATAL = 0xC1,
  BT_SOC_REASON_INVALID_STACK  =  0xF0,

  // Transport Driver Crash Reasons
  BT_HOST_REASON_SOC_CRASH            = 0x01,
  BT_HOST_REASON_SOC_CRASH_DIAG_SSR   = 0x02,
  BT_HOST_REASON_INIT_FAIL            = 0x03,
  BT_HOST_REASON_CLOSE_DURING_INIT    = 0x04,
  BT_HOST_REASON_ERR_READING_DATA_FROM_UART   = 0x05,
  BT_HOST_REASON_WRITE_FAILED_SPCL_BUFF_CRASH_SOC = 0x06,
  BT_HOST_REASON_RXTHREAD_STUCK         = 0x07,
  BT_HOST_REASON_SSR_CMD_TIMEOUT        = 0x08,
  BT_HOST_REASON_SSR_SPURIOUS_WAKE_UP   = 0x09,
  BT_HOST_REASON_SSR_INVALID_BYTES_RECV = 0x0A,
  BT_HOST_REASON_SSR_RECV_LARGE_PKT_FROM_SOC       = 0x0B,
  BT_HOST_REASON_SSR_UNABLE_TO_WAKE_UP_SOC         = 0x0C,
  BT_HOST_REASON_CMD_TIMEOUT_SOCWAIT_TIMEOUT       = 0x0D,
  BT_HOST_REASON_SPURIOUS_WAKE_UP_SOCWAIT_TIMEOUT  = 0x0E,
  BT_HOST_REASON_INV_BYTES_SOCWAIT_TIMEOUT         = 0x0F,
  BT_HOST_REASON_SOC_WAKEUP_FAILED_SOCWAIT_TIMEOUT    = 0x10,
  BT_HOST_REASON_SOC_CRASHED_DIAG_SSR_SOCWAIT_TIMEOUT = 0x11,
  BT_HOST_REASON_NONE_SOCWAIT_TIMEOUT                 = 0x12,
  BT_HOST_REASON_SOC_DE_INIT_STUCK                    = 0x13,
  BT_HOST_REASON_SSR_INTERNAL_COMMAND_TIMEDOUT        = 0x14,
  BT_HOST_REASON_FAILED_TO_SEND_INTERNAL_COMMAND      = 0x15,
  BT_HOST_REASON_SSR_SLEEP_IND_NOT_RECV               = 0x16,
  BT_HOST_REASON_UARTINIT_STUCK        =  0x17,
  BT_HOST_REASON_GETVER_SEND_STUCK     =  0x18,
  BT_HOST_REASON_GETVER_NO_RSP_RCVD    =  0x19,
  BT_HOST_REASON_SETBAUDRATE_CMD_STUCK =  0x1A,
  BT_HOST_REASON_PATCH_DNLD_STUCK      =  0x1B,
  BT_HOST_REASON_GETBOARDID_CMD_STUCK  =  0x1C,
  BT_HOST_REASON_NVM_DNLD_STUCK        =  0x1D,
  BT_HOST_REASON_HCI_RESET_STUCK       =  0x1E,
  BT_HOST_REASON_GETBLDINFO_CMD_STUCK  =  0x1F,
  BT_HOST_REASON_ADDONFEAT_CMD_STUCK   =  0x20,
  BT_HOST_REASON_ENHLOG_CMD_STUCK      =  0x21,
  BT_HOST_REASON_DIAGINIT_STUCK        =  0x22,
  BT_HOST_REASON_DIAGDEINIT_STUCK      =  0x23,
  BT_HOST_REASON_XMEM_NVM_DNLD_STUCK   =  0x24,
  BT_HOST_REASON_XMEM_PATCH_DNLD_STUCK =  0x25,
  BT_HOST_REASON_SECURE_BRIDGE_CMD_STUCK = 0x26,
  BT_HOST_REASON_FAILED_TO_SEND_CMD              =  0x27,
  BT_HOST_REASON_HCI_RESET_CC_NOT_RCVD           =  0x28,
  BT_HOST_REASON_HCI_PRE_SHUTDOWN_CC_NOT_RCVD    =  0x29,
  BT_HOST_REASON_HCI_SET_BD_ADDRESS_CC_NOT_RCVD  =  0x2A,
  BT_HOST_REASON_FAILED_TO_RECEIVE_SLEEP_IND     =  0x2B,
  BT_HOST_REASON_POWER_ON_REGS_STUCK             =  0x2C,
  BT_HOST_REASON_RX_THREAD_START_STUCK           =  0x2D,
  BT_HOST_REASON_GET_LOCALADDR_STUCK             =  0x2E,
  BT_HOST_REASON_OTP_INFO_GET_CMD_STUCK          =  0x2F,
  BT_HOST_REASON_FILE_SYSTEM_CALL_STUCK          =  0x30,
  BT_HOST_REASON_PROPERTY_GET_STUCK              =  0x31,
  BT_HOST_REASON_PROPERTY_SET_STUCK              =  0x32,
  BT_HOST_REASON_RAM_PATCH_READ_STUCK            =  0x33,
  BT_HOST_REASON_NVM_PATCH_READ_STUCK            =  0x34,
  BT_HOST_REASON_UART_IOCTL_STUCK                =  0x35,
  BT_HOST_REASON_POWER_IOCTL_STUCK               =  0x36,
  BT_HOST_REASON_PATCH_CONFIG_CMD_STUCK          =  0x37,
  BT_HOST_REASON_GET_APP_VER_CMD_STUCK           =  0x38,
  BT_HOST_REASON_DIAG_LOG_API_STUCK              =  0x39,
  BT_HOST_REASON_SOC_NAME_UNKOWN                 =  0x3A,
  // Exception in HOST reason, below is actually related to SoC.
  SOC_REASON_START_TX_IOS_SOC_RFR_HIGH_DURING_INIT = 0x3B,
  BT_HOST_REASON_GETVER_CMD_FAILED               = 0x3C,
  BT_HOST_REASON_BAUDRATE_CHANGE_FAILED          = 0x3D,
  BT_HOST_REASON_TLV_DOWNLOAD_FAILED             = 0x3E,
  BT_HOST_REASON_FW_BUILD_INFO_CMD_FAILED        = 0x3F,
  BT_HOST_REASON_HCI_RESET_CMD_FAILED            = 0x40,
  BT_HOST_REASON_UART_INIT_FAILED                = 0x41,
  BT_HOST_REASON_MEMORY_ALLOCATION_FAILED        = 0x42,
  BT_HOST_REASON_READ_THREAD_START_FAILED        = 0x43,
  BT_HOST_REASON_HW_FLOW_ON_FAILED               = 0x44,
  BT_HOST_REASON_NVM_FILE_NOT_FOUND              = 0x45,
  BT_HOST_REASON_UART_BAUDRATE_CHANGE_FAILED     = 0x46,
  BT_HOST_REASON_PATCH_CONFIG_FAILED             = 0x47,
  // UART driver crash reasons
  UART_REASON_DEFAULT                            =  0x51,
  UART_REASON_INVALID_FW_LOADED                  =  0x52,
  UART_REASON_CLK_GET_FAIL                       =  0x53,
  UART_REASON_SE_CLK_RATE_FIND_FAIL              =  0x54,
  UART_REASON_SE_RESOURCES_INIT_FAIL             =  0x55,
  UART_REASON_SE_RESOURCES_ON_FAIL               =  0x56,
  UART_REASON_SE_RESOURCES_OFF_FAIL              =  0x57,
  UART_REASON_TX_DMA_MAP_FAIL                    =  0x58,
  UART_REASON_TX_CANCEL_FAIL                     =  0x59,
  UART_REASON_TX_ABORT_FAIL                      =  0x5A,
  UART_REASON_TX_FSM_RESET_FAIL                  =  0x5B,
  UART_REASON_RX_CANCEL_FAIL                     =  0x5C,
  UART_REASON_RX_ABORT_FAIL                      =  0x5D,
  UART_REASON_RX_FSM_RESET_FAIL                  =  0x5E,
  UART_REASON_RX_TTY_INSET_FAIL                  =  0x5F,
  UART_REASON_ILLEGAL_INTERRUPT                  =  0x60,
  UART_REASON_BUFFER_OVERRUN                     =  0x61,
  UART_REASON_RX_PARITY_REASON                   =  0x62,
  UART_REASON_RX_BREAK_REASON                    =  0x63,
  UART_REASON_RX_SBE_REASON                      =  0x64,
  SOC_REASON_START_TX_IOS_SOC_RFR_HIGH           =  0x65,
} soc_crash_reason_e;

typedef struct {
  soc_crash_reason_e reason;
  char reasonstr[HCI_CRASH_MESSAGE_SIZE];
} secondary_reason;

static secondary_reason secondary_crash_reason [] = {
{ BT_SOC_REASON_DEFAULT                 ,    "Default"},
{ BT_SOC_REASON_UNKNOWN                 ,    "Unknown"},
{ BT_SOC_REASON_TX_RX_INVALID_PKT_FATAL ,    "Tx/Rx invalid packet fatal error"},
{ BT_SOC_REASON_TX_RX_INVALID_LEN_FATAL ,    "Tx/Rx invalid length fatal error"},
{ BT_SOC_REASON_SW_REQUESTED            ,    "SW Requested"},
{ BT_SOC_REASON_STACK_OVERFLOW          ,    "Stack Overflow"},
{ BT_SOC_REASON_EXCEPTION               ,    "Exception"},
{ BT_SOC_REASON_ASSERT                  ,    "Assert"},
{ BT_SOC_REASON_TRAP                    ,    "Trap"},
{ BT_SOC_REASON_OS_FATAL                ,    "OS Fatal"},
{ BT_SOC_REASON_HCI_RESET               ,    "HCI Reset"},
{ BT_SOC_REASON_PATCH_RESET             ,    "Patch Reset"},
{ BT_SOC_REASON_ABT                     ,    "SoC Abort"},
{ BT_SOC_REASON_RAMMASK                 ,    "RAM MASK"},
{ BT_SOC_REASON_PREBARK                 ,    "PREBARK"},
{ BT_SOC_REASON_BUSERROR                ,    "Bus error"},
{ BT_SOC_REASON_IO_FATAL                ,    "IO fatal eror"},
{ BT_SOC_REASON_SSR_CMD                 ,    "SSR CMD"},
{ BT_SOC_REASON_POWERON                 ,    "Power ON"},
{ BT_SOC_REASON_WATCHDOG                ,    "Watchdog"},
{ BT_SOC_REASON_RAMMASK_RGN1            ,    "RAMMASK RGN1"},
{ BT_SOC_REASON_RAMMASK_RGN0            ,    "RAMMASK RGN0"},
{ BT_SOC_REASON_Q6_WATCHDOG             ,    "Q6 Watchdog"},
{ BT_SOC_REASON_ZEALIS_RAM_MASK_RGN0    ,    "ZEALIS RAM MASK RGN0"},
{ BT_SOC_REASON_ZEALIS_RAM_MASK_RGN1    ,    "ZEALIS RAM MASK RGN1"},
{ BT_SOC_REASON_APSS_RESET              ,    "APSS reset"},
{ BT_SOC_REASON_TIME_RESET              ,    "Time reset"},
{ BT_SOC_REASON_AUDIOSS_RESET           ,    "Audioss reset"},
{ BT_SOC_REASON_HOST_WARMRESET          ,    "Host warm reset"},
{ BT_SOC_REASON_HOST_NMI_INIT           ,    "Host NMI init"},
{ BT_SOC_REASON_INVALID_STACK           ,    "Invalid Stack"},
{ BT_HOST_REASON_SOC_CRASH              ,    "SOC crashed"},
{ BT_HOST_REASON_SOC_CRASH_DIAG_SSR     ,    "SOC crashed with diag initiated SSR"},
{ BT_HOST_REASON_INIT_FAIL              ,    "Init failed"},
{ BT_HOST_REASON_CLOSE_DURING_INIT                ,    "Close received from stack during SOC init"},
{ BT_HOST_REASON_ERR_READING_DATA_FROM_UART       ,    "Error reading data from UART"},
{ BT_HOST_REASON_WRITE_FAILED_SPCL_BUFF_CRASH_SOC ,    "Failed to write special bytes to crash SOC"},
{ BT_HOST_REASON_RXTHREAD_STUCK                   ,    "Rx Thread Stuck"},
{ BT_HOST_REASON_SSR_CMD_TIMEOUT                  ,    "SSR due to command timed out"},
{ BT_HOST_REASON_SSR_SPURIOUS_WAKE_UP             ,    "SSR due to spurious wakeup"},
{ BT_HOST_REASON_SSR_INVALID_BYTES_RECV           ,    "Invalid HCI cmd type received"},
{ BT_HOST_REASON_SSR_RECV_LARGE_PKT_FROM_SOC      ,    "Large packet received from SOC"},
{ BT_HOST_REASON_SSR_UNABLE_TO_WAKE_UP_SOC        ,    "Unable to wake SOC"},
{ BT_HOST_REASON_CMD_TIMEOUT_SOCWAIT_TIMEOUT      ,    "Command timedout and SOC crash wait timeout"},
{ BT_HOST_REASON_SPURIOUS_WAKE_UP_SOCWAIT_TIMEOUT ,    "Spurious wake and SOC crash wait timeout"},
{ BT_HOST_REASON_INV_BYTES_SOCWAIT_TIMEOUT        ,    "Invalid bytes received and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_WAKEUP_FAILED_SOCWAIT_TIMEOUT   , "SOC Wakeup failed and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_CRASHED_DIAG_SSR_SOCWAIT_TIMEOUT, "SOC crashed with diag initiated SSR and SOC wait timeout"},
{ BT_HOST_REASON_NONE_SOCWAIT_TIMEOUT                , "Invalid Reason and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_DE_INIT_STUCK                   , "SOC DeInit Stuck"},
{ BT_HOST_REASON_SSR_INTERNAL_COMMAND_TIMEDOUT       , "SSR due to internal Command timeout"},
{ BT_HOST_REASON_FAILED_TO_SEND_INTERNAL_COMMAND     , "Failed to send internal command"},
{ BT_HOST_REASON_SSR_SLEEP_IND_NOT_RECV              , "Failed to receive SLEEP IND during close"},
{ BT_HOST_REASON_UARTINIT_STUCK              ,    "UartInitStuck"},
{ BT_HOST_REASON_GETVER_SEND_STUCK           ,    "GetVerSendStuck"},
{ BT_HOST_REASON_GETVER_NO_RSP_RCVD          ,    "GetVerNoRspRcvd"},
{ BT_HOST_REASON_SETBAUDRATE_CMD_STUCK       ,    "SetBaudRateStuck"},
{ BT_HOST_REASON_PATCH_DNLD_STUCK            ,    "PatchDnldStuck"},
{ BT_HOST_REASON_GETBOARDID_CMD_STUCK        ,    "GetBoardIdStuck"},
{ BT_HOST_REASON_NVM_DNLD_STUCK              ,    "NvmDnldStuck"},
{ BT_HOST_REASON_HCI_RESET_STUCK             ,    "HciResetStuck"},
{ BT_HOST_REASON_GETBLDINFO_CMD_STUCK        ,    "GetBldInfoCmdStuck"},
{ BT_HOST_REASON_ADDONFEAT_CMD_STUCK         ,    "AddOnFeatCmdStuck"},
{ BT_HOST_REASON_ENHLOG_CMD_STUCK            ,    "EnhLogCmdStuck"},
{ BT_HOST_REASON_DIAGINIT_STUCK              ,    "DiagInitStuck"},
{ BT_HOST_REASON_DIAGDEINIT_STUCK            ,    "DiagDeinitStuck"},
{ BT_HOST_REASON_XMEM_NVM_DNLD_STUCK         ,    "XMEM NVM Download stuck"},
{ BT_HOST_REASON_XMEM_PATCH_DNLD_STUCK       ,    "XMEM patch download stuck"},
{ BT_HOST_REASON_SECURE_BRIDGE_CMD_STUCK     ,    "Secure bridge cmd stuck"},
{ BT_HOST_REASON_FAILED_TO_SEND_CMD          ,    "Failed to send internal cmd"},
{ BT_HOST_REASON_HCI_RESET_CC_NOT_RCVD       ,    "HCI Reset Cmd CC Not Rcvd"},
{ BT_HOST_REASON_HCI_PRE_SHUTDOWN_CC_NOT_RCVD    ,  "HCI Pre shutdown Cmd CC not Rcvd"},
{ BT_HOST_REASON_HCI_SET_BD_ADDRESS_CC_NOT_RCVD  ,  "HCI BD address CC not Rcvd"},
{ BT_HOST_REASON_FAILED_TO_RECEIVE_SLEEP_IND     ,  "Failed to receive SLEEP IND from SoC"},
{ BT_HOST_REASON_POWER_ON_REGS_STUCK             ,  "SoC Power ON Sequence stuck"},
{ BT_HOST_REASON_POWER_IOCTL_STUCK               ,  "Power driver IOCTL stuck"},
{ BT_HOST_REASON_RX_THREAD_START_STUCK           ,  "RX thread start stuck"},
{ BT_HOST_REASON_GET_LOCALADDR_STUCK             ,  "Get local BD address stuck"},
{ BT_HOST_REASON_OTP_INFO_GET_CMD_STUCK          ,  "Get OTP info. cmd stuck"},
{ BT_HOST_REASON_FILE_SYSTEM_CALL_STUCK          ,  "FILE system call stuck"},
{ BT_HOST_REASON_PROPERTY_GET_STUCK              ,  "Property get call stuck"},
{ BT_HOST_REASON_PROPERTY_SET_STUCK              ,  "Property set call stuck"},
{ BT_HOST_REASON_RAM_PATCH_READ_STUCK            ,  "RAM patch open/read stuck"},
{ BT_HOST_REASON_NVM_PATCH_READ_STUCK            ,  "NVM file open/read stuck"},
{ BT_HOST_REASON_UART_IOCTL_STUCK                ,  "UART IOCTL stuck"},
{ BT_HOST_REASON_PATCH_CONFIG_CMD_STUCK          ,  "Patch config cmd stuck"},
{ BT_HOST_REASON_GET_APP_VER_CMD_STUCK           ,  "Get APP version cmd stuck"},
{ BT_HOST_REASON_DIAG_LOG_API_STUCK              ,  "DIAG log API stuck"},
{ BT_HOST_REASON_SOC_NAME_UNKOWN                 ,  "SoC name unkown"},
{ SOC_REASON_START_TX_IOS_SOC_RFR_HIGH_DURING_INIT, "SoC RFR high during INIT"},
{ BT_HOST_REASON_GETVER_CMD_FAILED               ,  "Get Version cmd failed"},
{ BT_HOST_REASON_BAUDRATE_CHANGE_FAILED          ,  "Baudrate change failed"},
{ BT_HOST_REASON_TLV_DOWNLOAD_FAILED             ,  "TLV download failed"},
{ BT_HOST_REASON_FW_BUILD_INFO_CMD_FAILED        ,  "FW build info. cmd failed"},
{ BT_HOST_REASON_HCI_RESET_CMD_FAILED            ,  "HCI reset cmd failed"},
{ BT_HOST_REASON_UART_INIT_FAILED                ,  "UART INIT failed"},
{ BT_HOST_REASON_MEMORY_ALLOCATION_FAILED        ,  "Memory allocation failed"},
{ BT_HOST_REASON_READ_THREAD_START_FAILED        ,  "Read thread start failed"},
{ BT_HOST_REASON_HW_FLOW_ON_FAILED               ,  "HW flow ON failed"},
{ BT_HOST_REASON_NVM_FILE_NOT_FOUND              ,  "NVM File not found"},
{ BT_HOST_REASON_UART_BAUDRATE_CHANGE_FAILED     ,  "UART Baudrate change failed"},
{ BT_HOST_REASON_PATCH_CONFIG_FAILED             ,  "Patch config cmd failed"},
  // UART driver crash reasons
{ UART_REASON_DEFAULT                            ,  "UART reason Default"},
{ UART_REASON_INVALID_FW_LOADED                  ,  "UART invalid FW loaded"},
{ UART_REASON_CLK_GET_FAIL                       ,  "UART CLK get failed"},
{ UART_REASON_SE_CLK_RATE_FIND_FAIL              ,  "UART CLK rate find failed"},
{ UART_REASON_SE_RESOURCES_INIT_FAIL             ,  "UART resources init failed"},
{ UART_REASON_SE_RESOURCES_ON_FAIL               ,  "UART resources ON failed"},
{ UART_REASON_SE_RESOURCES_OFF_FAIL              ,  "UART resources OFF failed"},
{ UART_REASON_TX_DMA_MAP_FAIL                    ,  "UART DMA map failed"},
{ UART_REASON_TX_CANCEL_FAIL                     ,  "UART tx cancel failed"},
{ UART_REASON_TX_ABORT_FAIL                      ,  "UART tx abort failed"},
{ UART_REASON_TX_FSM_RESET_FAIL                  ,  "UART tx FSM reset failed"},
{ UART_REASON_RX_CANCEL_FAIL                     ,  "UART rx cancel failed"},
{ UART_REASON_RX_ABORT_FAIL                      ,  "UART rx abort failed"},
{ UART_REASON_RX_FSM_RESET_FAIL                  ,  "UART rx FSM reset failed"},
{ UART_REASON_RX_TTY_INSET_FAIL                  ,  "UART rx tty inset failed"},
{ UART_REASON_ILLEGAL_INTERRUPT                  ,  "UART illegal interrupt"},
{ UART_REASON_BUFFER_OVERRUN                     ,  "UART buffer overrun"},
{ UART_REASON_RX_PARITY_REASON                   ,  "UART rx parity error"},
{ UART_REASON_RX_BREAK_REASON                    ,  "UART rx break error"},
{ UART_REASON_RX_SBE_REASON                      ,  "UART rx SBE error"},
{ SOC_REASON_START_TX_IOS_SOC_RFR_HIGH           ,  "SoC RFR high"}
};

enum host_crash_reason_e  {
  BT_HOST_REASON_DEFAULT_NONE  = 0x00,                         //INVALID REASON
  BT_HOST_REASON_SOC_CRASHED = 0x01,                           //SOC WAS CRASHED
  BT_HOST_REASON_SOC_CRASHED_DIAG_SSR = 0x02,                  //SOC CRASHED DIAG INITIATED SSR
  BT_HOST_REASON_INIT_FAILED = 0x03,                           //HOST INITIALIZATION FAILED
  BT_HOST_REASON_CLOSE_RCVD_DURING_INIT = 0x04,                //CLOSE RECEIVED FROM STACK DURING SOC INIT
  BT_HOST_REASON_ERROR_READING_DATA_FROM_UART = 0x05,          //ERROR READING DATA FROM UART
  BT_HOST_REASON_WRITE_FAIL_SPCL_BUFF_CRASH_SOC = 0x06,        //FAILED TO WRITE SPECIAL BYTES TO CRASH SOC
  BT_HOST_REASON_RX_THREAD_STUCK = 0x07,                       //RX THREAD STUCK
  BT_HOST_REASON_SSR_CMD_TIMEDOUT = 0x08,                      //SSR DUE TO CMD TIMED OUT
  BT_HOST_REASON_SSR_SPURIOUS_WAKEUP = 0x09,                   //SSR DUE TO SPURIOUS WAKE UP
  BT_HOST_REASON_SSR_INVALID_BYTES_RCVD = 0x0A,                //INVALID HCI CMD TYPE RECEIVED
  BT_HOST_REASON_SSR_RCVD_LARGE_PKT_FROM_SOC = 0x0B,           //SSR DUE TO LARGE PKT RECVIVED FROM SOC
  BT_HOST_REASON_SSR_UNABLE_TO_WAKEUP_SOC = 0x0C,              //UNABLE TO WAKE UP SOC
  BT_HOST_REASON_CMD_TIMEDOUT_SOC_WAIT_TIMEOUT = 0x0D,         //COMMAND TIMEOUT AND SOC CRASH WAIT TIMEOUT
  BT_HOST_REASON_SPURIOUS_WAKEUP_SOC_WAIT_TIMEOUT = 0x0E,      //SPURIOUS WAKE AND SOC CRASH WAIT TIMEOUT
  BT_HOST_REASON_INV_BYTES_SOC_WAIT_TIMEOUT = 0x0F,            //INVALID BYTES AND SOC CRASH WAIT TIMEOUT
  BT_HOST_REASON_SOC_WAKEUP_FAILED_SOC_WAIT_TIMEOUT = 0x10,    //SOC WAKEUP FAILURE AND SOC CRASH WAIT TIMEOUT
  BT_HOST_REASON_SOC_CRASHED_DIAG_SSR_SOC_WAIT_TIMEOUT = 0x11, //SOC CRASHED DIAG INITIATED SSR CRASH WAIT TIMEOUT
  BT_HOST_REASON_NONE_SOC_WAIT_TIMEOUT = 0x12,                 //INVALID FAILURE AND SOC CRASH WAIT TIMEOUT
  BT_HOST_REASON_SOC_DEINIT_STUCK = 0x13,                      //SOC DEINIT STUCK
  BT_HOST_REASON_SSR_INTERNAL_CMD_TIMEDOUT = 0x14,             //SSR DUE TO CMD INTERNAL TIMED OUT
  BT_HOST_REASON_FAILED_TO_SEND_INTERNAL_CMD = 0x15,           //FAILED TO SEND INTERNAL CMD
  BT_HOST_REASON_SSR_SLEEP_IND_NOT_RCVD = 0x16,                //SOC DID NOT RCVD SLEEP IND DURING CLOSE
};

typedef struct {
  host_crash_reason_e reason;
  char reasonstr[HCI_CRASH_MESSAGE_SIZE];
} primary_reason;

static primary_reason primary_crash_reason [] = {
{ BT_HOST_REASON_DEFAULT_NONE                         , "Invalid reason"},
{ BT_HOST_REASON_SOC_CRASHED                          , "SOC crashed"},
{ BT_HOST_REASON_SOC_CRASHED_DIAG_SSR                 , "SOC crashed with diag initiated SSR"},
{ BT_HOST_REASON_INIT_FAILED                          , "Init failed"},
{ BT_HOST_REASON_CLOSE_RCVD_DURING_INIT               , "Close received from stack during SOC init"},
{ BT_HOST_REASON_ERROR_READING_DATA_FROM_UART         , "Error reading data from UART"},
{ BT_HOST_REASON_WRITE_FAIL_SPCL_BUFF_CRASH_SOC       , "Failed to write special bytes to crash SOC"},
{ BT_HOST_REASON_RX_THREAD_STUCK                      , "Rx Thread Stuck"},
{ BT_HOST_REASON_SSR_CMD_TIMEDOUT                     , "SSR due to command timed out"},
{ BT_HOST_REASON_SSR_SPURIOUS_WAKEUP                  , "SSR due to spurious wakeup"},
{ BT_HOST_REASON_SSR_INVALID_BYTES_RCVD               , "Invalid HCI cmd type received"},
{ BT_HOST_REASON_SSR_RCVD_LARGE_PKT_FROM_SOC          , "Large packet received from SOC"},
{ BT_HOST_REASON_SSR_UNABLE_TO_WAKEUP_SOC             , "Unable to wake SOC"},
{ BT_HOST_REASON_CMD_TIMEDOUT_SOC_WAIT_TIMEOUT        , "Command timedout and SOC crash wait timeout"},
{ BT_HOST_REASON_SPURIOUS_WAKEUP_SOC_WAIT_TIMEOUT     , "Spurious wake and SOC crash wait timeout"},
{ BT_HOST_REASON_INV_BYTES_SOC_WAIT_TIMEOUT           , "Invalid bytes received and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_WAKEUP_FAILED_SOC_WAIT_TIMEOUT   , "SOC Wakeup failed and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_CRASHED_DIAG_SSR_SOC_WAIT_TIMEOUT, "SOC crashed with diag initiated SSR and SOC wait timeout"},
{ BT_HOST_REASON_NONE_SOC_WAIT_TIMEOUT                , "Invalid Reason and SOC crash wait timeout"},
{ BT_HOST_REASON_SOC_DEINIT_STUCK                     , "SOC DeInit Stuck"},
{ BT_HOST_REASON_SSR_INTERNAL_CMD_TIMEDOUT            , "SSR due to internal Command timeout"},
{ BT_HOST_REASON_FAILED_TO_SEND_INTERNAL_CMD          , "Failed to send internal command"},
{ BT_HOST_REASON_SSR_SLEEP_IND_NOT_RCVD               , "Failed to receive SLEEP IND during close"},
};

void decode_crash_reason(uint8_t* p, uint8_t evt_len);
char *get_secondary_reason_str(soc_crash_reason_e reason);
char *get_primary_reason_str(host_crash_reason_e reason);

