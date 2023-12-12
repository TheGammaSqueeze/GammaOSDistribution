/******************************************************************************
 *
 *  Copyright 1999-2012 Broadcom Corporation
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

#ifndef SMP_API_TYPES_H
#define SMP_API_TYPES_H

#include "bt_target.h"  // Must be first to define build configuration

#include "stack/include/btm_status.h"
#include "types/ble_address_with_type.h"

/* SMP command code */
typedef enum : uint8_t {
  SMP_OPCODE_PAIRING_REQ = 0x01,
  SMP_OPCODE_PAIRING_RSP = 0x02,
  SMP_OPCODE_CONFIRM = 0x03,
  SMP_OPCODE_RAND = 0x04,
  SMP_OPCODE_PAIRING_FAILED = 0x05,
  SMP_OPCODE_ENCRYPT_INFO = 0x06,
  SMP_OPCODE_CENTRAL_ID = 0x07,
  SMP_OPCODE_IDENTITY_INFO = 0x08,
  SMP_OPCODE_ID_ADDR = 0x09,
  SMP_OPCODE_SIGN_INFO = 0x0A,
  SMP_OPCODE_SEC_REQ = 0x0B,
  SMP_OPCODE_PAIR_PUBLIC_KEY = 0x0C,
  SMP_OPCODE_PAIR_DHKEY_CHECK = 0x0D,
  SMP_OPCODE_PAIR_KEYPR_NOTIF = 0x0E,
  SMP_OPCODE_MAX = SMP_OPCODE_PAIR_KEYPR_NOTIF,
  SMP_OPCODE_MIN = SMP_OPCODE_PAIRING_REQ,
  // NOTE: For some reason this is outside the MAX/MIN values
  SMP_OPCODE_PAIR_COMMITM = 0x0F,
} tSMP_OPCODE;

#define CASE_RETURN_TEXT(code) \
  case code:                   \
    return #code

inline std::string smp_opcode_text(const tSMP_OPCODE& opcode) {
  switch (opcode) {
    CASE_RETURN_TEXT(SMP_OPCODE_PAIRING_REQ);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIRING_RSP);
    CASE_RETURN_TEXT(SMP_OPCODE_CONFIRM);
    CASE_RETURN_TEXT(SMP_OPCODE_RAND);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIRING_FAILED);
    CASE_RETURN_TEXT(SMP_OPCODE_ENCRYPT_INFO);
    CASE_RETURN_TEXT(SMP_OPCODE_CENTRAL_ID);
    CASE_RETURN_TEXT(SMP_OPCODE_IDENTITY_INFO);
    CASE_RETURN_TEXT(SMP_OPCODE_ID_ADDR);
    CASE_RETURN_TEXT(SMP_OPCODE_SIGN_INFO);
    CASE_RETURN_TEXT(SMP_OPCODE_SEC_REQ);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIR_PUBLIC_KEY);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIR_DHKEY_CHECK);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIR_KEYPR_NOTIF);
    CASE_RETURN_TEXT(SMP_OPCODE_PAIR_COMMITM);
    default:
      return std::string("UNKNOWN:%hhu", opcode);
  }
}
#undef CASE_RETURN_TEXT

/* SMP event type */
typedef enum : uint8_t {
  SMP_EVT_NONE = 0,           /* Default no event */
  SMP_IO_CAP_REQ_EVT = 1,     /* IO capability request event */
  SMP_SEC_REQUEST_EVT = 2,    /* SMP pairing request */
  SMP_PASSKEY_NOTIF_EVT = 3,  /* passkey notification event */
  SMP_PASSKEY_REQ_EVT = 4,    /* passkey request event */
  SMP_OOB_REQ_EVT = 5,        /* OOB request event */
  SMP_NC_REQ_EVT = 6,         /* Numeric Comparison request event */
  SMP_COMPLT_EVT = 7,         /* SMP complete event */
  SMP_PEER_KEYPR_NOT_EVT = 8, /* Peer keypress notification */

  /* SC OOB request event (both local and peer OOB data can be expected in
   * response) */
  SMP_SC_OOB_REQ_EVT = 9,
  /* SC OOB local data set is created (as result of SMP_CrLocScOobData(...)) */
  SMP_SC_LOC_OOB_DATA_UP_EVT = 10,
  SMP_UNUSED11 = 11,
  SMP_BR_KEYS_REQ_EVT = 12, /* SMP over BR keys request event */
  SMP_UNUSED13 = 13,
  SMP_CONSENT_REQ_EVT = 14, /* Consent request event */
} tSMP_EVT;

/* pairing failure reason code */
typedef enum : uint8_t {
  SMP_SUCCESS = 0,
  SMP_PASSKEY_ENTRY_FAIL = 0x01,
  SMP_OOB_FAIL = 0x02,
  SMP_PAIR_AUTH_FAIL = 0x03,
  SMP_CONFIRM_VALUE_ERR = 0x04,
  SMP_PAIR_NOT_SUPPORT = 0x05,
  SMP_ENC_KEY_SIZE = 0x06,
  SMP_INVALID_CMD = 0x07,
  SMP_PAIR_FAIL_UNKNOWN = 0x08,
  SMP_REPEATED_ATTEMPTS = 0x09,
  SMP_INVALID_PARAMETERS = 0x0A,
  SMP_DHKEY_CHK_FAIL = 0x0B,
  SMP_NUMERIC_COMPAR_FAIL = 0x0C,
  SMP_BR_PARING_IN_PROGR = 0x0D,
  SMP_XTRANS_DERIVE_NOT_ALLOW = 0x0E,
  SMP_MAX_FAIL_RSN_PER_SPEC = SMP_XTRANS_DERIVE_NOT_ALLOW,

  /* self defined error code */
  SMP_PAIR_INTERNAL_ERR = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x01), /* 0x0F */

  /* Unknown IO capability, unable to decide association model */
  SMP_UNKNOWN_IO_CAP = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x02), /* 0x10 */

  SMP_BUSY = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x05),        /* 0x13 */
  SMP_ENC_FAIL = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x06),    /* 0x14 */
  SMP_STARTED = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x07),     /* 0x15 */
  SMP_RSP_TIMEOUT = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x08), /* 0x16 */

  /* Unspecified failure reason */
  SMP_FAIL = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x0A), /* 0x18 */

  SMP_CONN_TOUT = (SMP_MAX_FAIL_RSN_PER_SPEC + 0x0B), /* 0x19 */
} tSMP_STATUS;

/* Device IO capability */
#define SMP_IO_CAP_IO BTM_IO_CAP_IO         /* DisplayYesNo */
#define SMP_IO_CAP_KBDISP BTM_IO_CAP_KBDISP /* Keyboard Display */
#define SMP_IO_CAP_MAX BTM_IO_CAP_MAX
typedef uint8_t tSMP_IO_CAP;

/* OOB data present or not */
enum { SMP_OOB_NONE, SMP_OOB_PRESENT, SMP_OOB_UNKNOWN };
typedef uint8_t tSMP_OOB_FLAG;

/* type of OOB data required from application */
enum { SMP_OOB_INVALID_TYPE, SMP_OOB_PEER, SMP_OOB_LOCAL, SMP_OOB_BOTH };
typedef uint8_t tSMP_OOB_DATA_TYPE;

enum : uint8_t {
  SMP_AUTH_NO_BOND = 0x00,
  /* no MITM, No Bonding, encryption only */
  SMP_AUTH_NB_ENC_ONLY = 0x00,  //(SMP_AUTH_MASK | BTM_AUTH_SP_NO)
  SMP_AUTH_BOND = (1u << 0),
  SMP_AUTH_UNUSED = (1u << 1),
  /* SMP Authentication requirement */
  SMP_AUTH_YN_BIT = (1u << 2),
  SMP_SC_SUPPORT_BIT = (1u << 3),
  SMP_KP_SUPPORT_BIT = (1u << 4),
  SMP_H7_SUPPORT_BIT = (1u << 5),
};

#define SMP_AUTH_MASK                                                          \
  (SMP_AUTH_BOND | SMP_AUTH_YN_BIT | SMP_SC_SUPPORT_BIT | SMP_KP_SUPPORT_BIT | \
   SMP_H7_SUPPORT_BIT)

/* Secure Connections, no MITM, no Bonding */
#define SMP_AUTH_SC_ENC_ONLY (SMP_H7_SUPPORT_BIT | SMP_SC_SUPPORT_BIT)

/* Secure Connections, MITM, Bonding */
#define SMP_AUTH_SC_MITM_GB \
  (SMP_H7_SUPPORT_BIT | SMP_SC_SUPPORT_BIT | SMP_AUTH_YN_BIT | SMP_AUTH_BOND)

typedef uint8_t tSMP_AUTH_REQ;

#define SMP_SEC_NONE 0
#define SMP_SEC_UNAUTHENTICATE (1 << 0)
#define SMP_SEC_AUTHENTICATED (1 << 2)
typedef uint8_t tSMP_SEC_LEVEL;

/* Maximum Encryption Key Size range */
#define SMP_ENCR_KEY_SIZE_MIN 7
#define SMP_ENCR_KEY_SIZE_MAX 16

/* SMP key types */
#define SMP_SEC_KEY_TYPE_ENC (1 << 0)  /* encryption key */
#define SMP_SEC_KEY_TYPE_ID (1 << 1)   /* identity key */
#define SMP_SEC_KEY_TYPE_CSRK (1 << 2) /* peripheral CSRK */
#define SMP_SEC_KEY_TYPE_LK (1 << 3)   /* BR/EDR link key */
typedef uint8_t tSMP_KEYS;

#define SMP_BR_SEC_DEFAULT_KEY \
  (SMP_SEC_KEY_TYPE_ENC | SMP_SEC_KEY_TYPE_ID | SMP_SEC_KEY_TYPE_CSRK)

/* default security key distribution value */
#define SMP_SEC_DEFAULT_KEY                                             \
  (SMP_SEC_KEY_TYPE_ENC | SMP_SEC_KEY_TYPE_ID | SMP_SEC_KEY_TYPE_CSRK | \
   SMP_SEC_KEY_TYPE_LK)

#define SMP_SC_KEY_OUT_OF_RANGE 5 /* out of range */
typedef uint8_t tSMP_SC_KEY_TYPE;

/* data type for BTM_SP_IO_REQ_EVT */
typedef struct {
  tSMP_IO_CAP io_cap;     /* local IO capabilities */
  tSMP_OOB_FLAG oob_data; /* OOB data present (locally) for the peer device */
  tSMP_AUTH_REQ auth_req; /* Authentication required (for local device) */
  uint8_t max_key_size;   /* max encryption key size */
  tSMP_KEYS init_keys;    /* initiator keys to be distributed */
  tSMP_KEYS resp_keys;    /* responder keys */
} tSMP_IO_REQ;

typedef struct {
  tSMP_STATUS reason;
  tSMP_SEC_LEVEL sec_level;
  bool is_pair_cancel;
  bool smp_over_br;
} tSMP_CMPL;

typedef struct {
  BT_OCTET32 x;
  BT_OCTET32 y;
} tSMP_PUBLIC_KEY;

/* the data associated with the info sent to the peer via OOB interface */
typedef struct {
  bool present;
  Octet16 randomizer;
  Octet16 commitment;

  tBLE_BD_ADDR addr_sent_to;
  BT_OCTET32 private_key_used; /* is used to calculate: */
  /* publ_key_used = P-256(private_key_used, curve_p256.G) - send it to the */
  /* other side */
  /* dhkey = P-256(private_key_used, publ key rcvd from the other side) */
  tSMP_PUBLIC_KEY publ_key_used; /* P-256(private_key_used, curve_p256.G) */
} tSMP_LOC_OOB_DATA;

/* the data associated with the info received from the peer via OOB interface */
typedef struct {
  bool present;
  Octet16 randomizer;
  Octet16 commitment;
  tBLE_BD_ADDR addr_rcvd_from;
} tSMP_PEER_OOB_DATA;

typedef struct {
  tSMP_LOC_OOB_DATA loc_oob_data;
  tSMP_PEER_OOB_DATA peer_oob_data;
} tSMP_SC_OOB_DATA;

typedef union {
  uint32_t passkey;
  tSMP_IO_REQ io_req; /* IO request */
  tSMP_CMPL cmplt;
  tSMP_OOB_DATA_TYPE req_oob_type;
  tSMP_LOC_OOB_DATA loc_oob_data;
} tSMP_EVT_DATA;

/* AES Encryption output */
typedef struct {
  uint8_t status;
  uint8_t param_len;
  uint16_t opcode;
  uint8_t param_buf[OCTET16_LEN];
} tSMP_ENC;

/* Security Manager events - Called by the stack when Security Manager related
 * events occur.*/
typedef tBTM_STATUS(tSMP_CALLBACK)(tSMP_EVT event, const RawAddress& bd_addr,
                                   tSMP_EVT_DATA* p_data);

#endif  // SMP_API_TYPES_H
