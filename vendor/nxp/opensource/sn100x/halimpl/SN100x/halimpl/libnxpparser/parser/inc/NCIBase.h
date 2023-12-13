/*
 * Copyright (C) 2017-2018 NXP Semiconductors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NCIBASE_H_
#define NCIBASE_H_

#ifdef __cplusplus
extern "C" {
#endif

class NCI_Base {

public:
typedef enum
{
   NCI_STATUS_OK                                  = 0x00,    /**< NCI common status code */
   NCI_STATUS_REJECTED,
   NCI_STATUS_RF_FRAME_CORRUPTED,
   NCI_STATUS_FAILED,
   NCI_STATUS_NOT_INITIALIZED,
   NCI_STATUS_SYNTAX_ERROR,
   NCI_STATUS_SEMANTIC_ERROR,
   NCI_STATUS_UNKNOWN_GID,
   NCI_STATUS_UNKNOWN_OID,
   NCI_STATUS_INVALID_PARAM,
   NCI_STATUS_MESSAGE_SIZE_EXCEEDED,
   NCI_STATUS_OK_1BIT                             = 0x11,    //!< NCI 1.1 : NCI_STATUS_OK_1BIT to
   NCI_STATUS_OK_2BIT,
   NCI_STATUS_OK_3BIT,
   NCI_STATUS_OK_4BIT,
   NCI_STATUS_OK_5BIT,
   NCI_STATUS_OK_6BIT,
   NCI_STATUS_OK_7BIT,                                       //!< NCI 1.1 : NCI_STATUS_OK_7BIT
   NCI_STATUS_DISCOVERY_ALREADY_STARTED           = 0xA0,
   NCI_STATUS_DISCOVERY_TARGET_ACTIVATION_FAILED,
   NCI_STATUS_DISCOVERY_TEAR_DOWN,
   NCI_STATUS_DISCOVERY_DETUNING_DETECTED,
   NCI_STATUS_RF_TRANSMISSION_ERROR               = 0xB0,
   NCI_STATUS_RF_PROTOCOL_ERROR,
   NCI_STATUS_RF_TIMEOUT_ERROR,
   NCI_STATUS_RF_UNEXPECTED_DATA,
   NCI_STATUS_NFCEE_INTERFACE_ACTIVATION_FAILED   = 0xC0,
   NCI_STATUS_NFCEE_TRANSMISSION_ERROR,
   NCI_STATUS_NFCEE_PROTOCOL_ERROR,
   NCI_STATUS_NFCEE_TIMEOUT_ERRROR,
   NCI_STATUS_DO_NOT_REPLY                        = 0xE0,    //Status to not reply on wrong packet
   NCI_STATUS_BOOT_TRIM_CORRUPTED,
   NCI_STATUS_PMU_TXLDO_OVERCURRENT               = 0xE3,
   NCI_STATUS_EMVCO_PCD_COLLISION,
   NCI_STATUS_WIRED_SESSION_ABORTED,
   NCI_STATUS_WIRED_SESSION_ABORT_TO,
   NCI_STATUS_END_PARAMETER                       = 0xF1
} eNciStatusCodes_t;

typedef enum
{
   NCI_MT_DATA_PKT,                               /*000b*/
   NCI_MT_CONTROL_PKT_CMD,                        /*001b*/
   NCI_MT_CONTROL_PKT_RSP,                        /*010b*/
   NCI_MT_CONTROL_PKT_NTF,                        /*011b*/
   NCI_MT_RFU                                     /*100b to 111b*/
} eNciMsgType_t;

typedef enum
{
   NCI_CONN_STATIC_FR_ID             = 0x00, //RFU due to Static
   NCI_CONN_NFCC_LOOP_BACK_ID,
   NCI_CONN_REMOTE_NFC_END_POINT_ID,
   NCI_CONN_NFCEE_ID,
   NCI_CONN_NFCEE_NDEF_ID            = 0x05
} eNciConnIdentifier_t;

typedef enum
{
   NCI_GID_CORE,
   NCI_GID_RF_MNGT,
   NCI_GID_NFCEE_MNGT,
   NCI_GID_PROPRIETARY = 0xF,
   NCI_NUMBER_OF_GID
} eNciGroupIdentifier_t;

typedef enum
{
   NCI_OID_CORE_RESET,                            /* 000000b */
   NCI_OID_CORE_INIT,                             /* 000001b */
   NCI_OID_CORE_SET_CONFIG,                       /* 000010b */
   NCI_OID_CORE_GET_CONFIG,                       /* 000011b */
   NCI_OID_CORE_CONN_CREATE,                      /* 000100b */
   NCI_OID_CORE_CONN_CLOSE,                       /* 000101b */
   NCI_OID_CORE_CONN_CREDITS,                     /* 000110b */
   NCI_OID_CORE_GENERIC_ERROR,                    /* 000111b */
   NCI_OID_CORE_INTERFACE_ERROR,                  /* 001000b */
   NCI_OID_CORE_SET_POWER_SUB_STATE,              /* 001001b */
   NCI_NUMBER_OF_CORE_OID
} eNciCoreOpcodeIdentifier_t;

typedef enum
{
   NCI_OID_RF_DISCOVER_MAP                  = 0x00,     /* 000000b */
   NCI_OID_RF_SET_LISTEN_MODE_ROUTING,                  /* 000001b */
   NCI_OID_RF_GET_LISTEN_MODE_ROUTING,                  /* 000010b */
   NCI_OID_RF_DISCOVER,                                 /* 000011b */
   NCI_OID_RF_DISCOVER_SELECT,                          /* 000100b */
   NCI_OID_RF_INTF_ACTIVATE,                            /* 000101b */
   NCI_OID_RF_DEACTIVATE,                               /* 000110b */
   NCI_OID_RF_FIELD_INFO,                               /* 000111b */
   NCI_OID_RF_T3T_POLLING,                              /* 001000b */
   NCI_OID_RF_NFCEE_ACTION,                             /* 001001b */
   NCI_OID_RF_NFCEE_DISCOVERY_REQ,                      /* 001010b */
   NCI_OID_RF_PARAMETER_UPDATE,                         /* 001011b */
   NCI_OID_RF_INTF_EXT_START,                           /* 001100b */
   NCI_OID_RF_INTF_EXT_STOP,                            /* 001101b */
   NCI_OID_RF_EXT_AGG_ABORT,                            /* 001110b */
   NCI_OID_RF_NDEF_ABORT,                               /* 001111b */
   NCI_OID_RF_ISO_DEP_NAK_PRESENCE_CMD,                 /* 010000b */
   NCI_OID_RF_SET_FORCED_NFCEE_ROUTING_CMD,             /* 010001b */
   NCI_OID_RF_VAS_NTF                       = 0x20,     /* 010000b */
   NCI_OID_RF_PLL_UNLOCKED_NTF              = 0x21,     /* 010001b */
   NCI_OID_RF_RAPDU_SENT_NTF                = 0x22,     /* 010010b */
   NCI_OID_RF_TXLDO_ERROR_NTF               = 0x23
} eNciRfMgmtOpcodeIdentifier_t;

typedef enum
{
   NCI_OID_NFCEE_DISCOVER,                /* 000000b */
   NCI_OID_NFCEE_MODE_SET,                /* 000001b */
   NCI_OID_NFCEE_STATUS,                  /* 000010b */
   NCI_OID_NFCEE_POWER_AND_LINK_CNTRL,    /* 000011b */
   NCI_OID_NFCEE_MODE_SET_SINGLE = 0x3C,  /* 111100b */
   NCI_OID_NFCEE_MODE_SET_HCI_NWK_ENABLE, /* 111101b */
   NCI_OID_NFCEE_MODE_SET_DISABLE,        /* 111110b */
   NCI_OID_NFCEE_END_PARAMETER            /* 111111b */
} eNciNfceeOpcodeIdentifier_t;

NCI_Base();
virtual ~NCI_Base();

private:
typedef enum
{
   NCI_OID_SYSTEM_SET_POWERMGT,
   NCI_OID_SYSTEM_GET_POWERMGT,
   NCI_OID_SYSTEM_PROPRIETARY_ACT                       = 0x02,
   NCI_OID_SYSTEM_CHANGE_HSU_BAUDRATE                   = 0x03,
   NCI_OID_SYSTEM_FW_DEBUG                              = 0x04,
   NCI_OID_SYSTEM_RF_ISO_DEP_PRES_CHECK                 = 0x11,
   NCI_OID_SYSTEM_RF_MF_PLUS_PROX_CHECK                 = 0x12,
   NCI_OID_SYSTEM_RF_TAG_DETECTOR                       = 0x13,
   NCI_OID_SYSTEM_RF_GET_RF_TRANSITION                  = 0x14,
   NCI_OID_SYSTEM_PHONE_SCREEN_STATE                    = 0x15,
   NCI_OID_SYSTEM_RFU1                                  = 0x16,
   NCI_OID_SYSTEM_WTX                                   = 0x17,
   NCI_OID_SYSTEM_NFCEE_MODESET_DISABLE_NTF             = 0x18,
   NCI_OID_SYSTEM_EOOP                                  = 0x20,
   NCI_OID_SYSTEM_TEST_FAKE_WAKE_ON_RF_FIELD            = 0x28,
   NCI_OID_SYSTEM_KEEP_NFCEE_POWERED_ON                 = 0x29,
   NCI_OID_SYSTEM_TEST_PRBS                             = 0x30,
   NCI_OID_SYSTEM_TEST_TESTBUS_CONFIG                   = 0x31,
   NCI_OID_SYSTEM_SVDD_PWRREQ_CONTROL                   = 0x31,
   NCI_OID_SYSTEM_TEST_READ_RF_INTERNAL_REGISTER        = 0x32,
   NCI_OID_SYSTEM_MANUFACTURING_BUILD_TESTS_API         = 0x33,
   NCI_OID_SYSTEM_ENABLE_READER_MODE_LM_DECODING_NTF    = 0x34,
   NCI_OID_SYSTEM_DEBUG_STATE_L1_MESSAGE                = 0x35,
   NCI_OID_SYSTEM_DEBUG_STATE_L2_MESSAGE,
   NCI_OID_SYSTEM_DEBUG_STATE_L3_MESSAGE,
   NCI_OID_SYSTEM_TEST_CORE_DUMP                        = 0x3B, /* NFCC6872 */
   NCI_OID_SYSTEM_STAG_GET_RFSTATUS                     = 0x39,
   NCI_OID_SYSTEM_STAG_STOP_AUTH                        = 0x3A,
   NCI_OID_SYSTEM_STAG_START_AUTH_XCHG                  = 0x3B,
   NCI_OID_SYSTEM_STAG_START_AUTH                       = 0x3C,
   NCI_OID_SYSTEM_TEST_ANTENNA                          = 0x3D,
   NCI_OID_SYSTEM_TEST_SWP_INTERFACE                    = 0x3E,
   NCI_OID_SYSTEM_RF_DEBUG                              = 0x3F,
   NCI_OID_SYSTEM_END_PARAMETER                         = 0x40
} eNciSystemPropOpcodeIdentifier_t;
};

#ifdef __cplusplus
} // extern
#endif

#endif /* NCIBASE_H_ */
