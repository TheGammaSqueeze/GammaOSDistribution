/*
 * Copyright (C) 2017 The Android Open Source Project
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
#ifndef __CROS_EC_INCLUDE_APP_NUGGET_H
#define __CROS_EC_INCLUDE_APP_NUGGET_H
#include "application.h"

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/*
 * APP_ID_NUGGET uses the Transport API
 */
/****************************************************************************/

/* App-specific errors (across all commands) */
enum {
  NUGGET_ERROR_LOCKED = APP_SPECIFIC_ERROR,
  NUGGET_ERROR_RETRY,
};

/****************************************************************************/
/* Application functions */

#define NUGGET_PARAM_VERSION 0x0000
/*
 * Return the one-line version string of the running image
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        Null-terminated ASCII string
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

/****************************************************************************/
/* Firmware upgrade stuff */

#define NP_FLASH_BLOCK_SIZE 2048
struct nugget_app_flash_block {
  uint32_t block_digest;                 /* first 4 bytes of sha1 of the rest */
  uint32_t offset;                       /* from start of flash */
  uint8_t payload[NP_FLASH_BLOCK_SIZE];  /* data to write */
} __packed;

#define NUGGET_PARAM_FLASH_BLOCK 0x0001
/*
 * Erase and write a single flash block.
 *
 * @param args         struct nugget_app_flash_block
 * @param arg_len      sizeof(struct nugget_app_flash_block)
 * @param reply        <none>
 * @param reply_len    0
 *
 * @errors             NUGGET_ERROR_LOCKED, NUGGET_ERROR_RETRY
 */

#define NUGGET_PARAM_REBOOT 0x0002
/*
 * Reboot Citadel
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        <none>
 * @param reply_len    0
 */

/*********
 * Firmware updates are written to flash with invalid headers. If an update
 * password exists, headers can only be marked valid by providing that
 * password.
 */

/*
 * An unassigned password is defined to be all 0xff, with a don't-care digest.
 * Anything else must have a valid digest over all password bytes. The password
 * length is chosen arbitrarily for now, but should always be a fixed size with
 * all bytes used, to resist brute-force guesses.
 */
#define NUGGET_UPDATE_PASSWORD_LEN 32
struct nugget_app_password {
  uint32_t digest;      /* first 4 bytes of sha1 of password (little endian) */
  uint8_t password[NUGGET_UPDATE_PASSWORD_LEN];
} __packed;


enum NUGGET_ENABLE_HEADER {
  NUGGET_ENABLE_HEADER_RO = 0x01,
  NUGGET_ENABLE_HEADER_RW = 0x02,
};
struct nugget_app_enable_update {
  struct nugget_app_password  password;
  uint8_t which_headers;                        /* bit 0 = RO, bit 1 = RW */
} __packed;
#define NUGGET_PARAM_ENABLE_UPDATE 0x0003
/*
 * Mark the specified image header(s) as valid, if the provided password
 * matches. Returns true if either header was CHANGED to valid, which is an
 * indication that the AP should request a reboot so that it can take effect.
 *
 * @param args         struct nugget_app_enable_update
 * @param arg_len      sizeof(struct nugget_app_enable_update)
 * @param reply        0 or 1
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */


struct nugget_app_change_update_password {
  struct nugget_app_password  old_password;
  struct nugget_app_password  new_password;
} __packed;
#define NUGGET_PARAM_CHANGE_UPDATE_PASSWORD 0x0004
/*
 * Change the update password.
 *
 * @param args         struct nugget_app_change_update_password
 * @param arg_len      sizeof(struct nugget_app_change_update_password)
 * @param reply        <none>
 * @param reply_len    0
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

#define NUGGET_PARAM_NUKE_FROM_ORBIT 0x0005
#define ERASE_CONFIRMATION 0xc05fefee
/*
 * This will erase ALL user secrets and reboot.
 *
 * @param args         uint32_t containing the ERASE_CONFIRMATION value
 * @param arg_len      sizeof(uint32_t)
 * @param reply        <none>
 * @param reply_len    0
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

#define NUGGET_PARAM_DEVICE_ID 0x0006
/*
 * Get the device ID of the chip.
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        Null-terminated ASCII string
 * @param reply_len    Max length to return
 */


#define NUGGET_PARAM_LONG_VERSION 0x0007
/*
 * Return the multi-line description of all images
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        Null-terminated ASCII string
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

#define NUGGET_PARAM_HEADER_RO_A 0x0008
/*
 * Return the signature header for RO_A
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct SignedHeader
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

#define NUGGET_PARAM_HEADER_RO_B 0x0009
/*
 * Return the signature header for RO_B
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct SignedHeader
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

#define NUGGET_PARAM_HEADER_RW_A 0x000a
/*
 * Return the signature header for RW_A
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct SignedHeader
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

#define NUGGET_PARAM_HEADER_RW_B 0x000b
/*
 * Return the signature header for RW_B
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct SignedHeader
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

#define NUGGET_PARAM_REPO_SNAPSHOT 0x000c
/*
 * Return the multi-line repo snapshot info for the current image
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        Null-terminated ASCII string
 * @param reply_len    Max length to return
 *
 * @errors             APP_ERROR_TOO_MUCH
 */

enum nugget_ap_uart_passthru_cfg {
  NUGGET_AP_UART_OFF,                   /* off */
  NUGGET_AP_UART_IS_USB,                /* USB CCD is in use over SBU */
  NUGGET_AP_UART_ENABLED,               /* AP UART is on SBU lines */
  NUGGET_AP_UART_SSC_UART,              /* This doesn't actually exist */
  NUGGET_AP_UART_CITADEL_UART,          /* Citadel UART on SBU lines (ew) */

  NUGGET_AP_UART_NUM_CFGS,
};
#define NUGGET_PARAM_AP_UART_PASSTHRU 0x000d
/*
 * Enable/Disable the AP UART PASSTHRU function
 *
 * This always returns the current state of the AP UART passthru feature. Even
 * if the AP UART is disabled, a SuzyQable may connected to use the SBU lines.
 *
 * The AP can only request that the AP UART passthru feature be enabled
 * (NUGGET_AP_UART_ENABLED), or disabled (NUGGET_AP_UART_OFF). The other enums
 * are for internal testing.
 *
 * @param args         <none>  OR  enum nugget_ap_uart_passthru_cfg
 * @param arg_len        0     OR   1 byte
 * @param reply        enum nugget_param_ap_uart_passthru
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

#define NUGGET_PARAM_RDD_CFG 0x000e
/*
 * Enable/Disable the RDD SuzyQable Detection
 *
 * This always returns the current state of the RDD SuzyQable detection
 * feature.
 *
 * The AP can request that the RDD SuzyQable detection to be disabled (0) or
 * enabled (1).
 *
 * @param args         0     OR   1
 * @param arg_len      0     OR   1 byte
 * @param reply        current state (0 or 1)
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

#define NUGGET_PARAM_BOARD_ID 0x000f
/*
 * Set / Get Board ID
 *
 * This sets or gets the Board ID of the device.
 *
 * @param args         <none>  OR   nugget_app_board_id
 * @param arg_len      0       OR   sizeof nugget_app_board_id
 * @param reply        struct nugget_app_board_id
 * @param reply_len    sizeof struct nugget_app_board_id
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */
struct nugget_app_board_id {
  uint32_t type;
  uint32_t flag;
  uint32_t inv;                         /* must equal ~type when setting */
} __packed;

#define NUGGET_PARAM_GET_EVENT_RECORD 0x0010
/*
 * This retrieves one pending event_record (defined in citadel_events.h).
 * If none are pending, it returns nothing.
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct event_record
 * @param reply_len    sizeof struct event_record  OR  0
 */

#define NUGGET_PARAM_AP_IS_REBOOTING 0x0011
/*
 * This can be used to replace the GPIO signal for some boards, if the
 * communication path is trusted. If not, it has no effect.
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        <none>
 * @param reply_len    0
 */

#define FILE_ID_NUGGET_PERSIST 0
#define NUGGET_PERSIST_VERSION_1 1
struct nugget_persist_t {
	uint8_t version;
	uint8_t user_consent;
	uint8_t reserved[2];
};

enum nugget_sjtag_user_consent_cfg {
  NUGGET_SJTAG_USER_CONSENT_DISALLOW,             /* DISALLOW */
  NUGGET_SJTAG_USER_CONSENT_ALLOW,                /* ALLOW */

  NUGGET_SJTAG_USER_CONSENT_NUM_CFGS,
};

#define NUGGET_PARAM_SJTAG_USER_CONSENT 0x0012
/*
 * Set/Get the SJTAG USER CONSENT function
 *
 * This always returns the current state of the SJTAG USER CONSENT feature.
 *
 * @param args         <none>  OR  enum nugget_sjtag_user_consent_cfg
 * @param arg_len        0     OR   1 byte
 * @param reply        enum nugget_sjtag_user_consent_cfg
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

enum nugget_sjtag_avb_boot_lock_result {
   AVB_BOOT_LOCK_DISABLED,
   AVB_BOOT_LOCK_ENABLED,
   AVB_BOOT_LOCK_ERROR,
};

#define NUGGET_PARAM_SJTAG_ALLOW 0x0013
/*
 * Get the SJTAG ALLOW
 *
 * This always returns the current state of the SJTAG ALLOW feature.
 *
 * @param args         <none>
 * @param arg_len        0
 * @param reply        0(DISALLOW) OR 1(ALLOW)
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

/*
 * Persistent storage of arbitrary data, up to
 * (FS_MAX_FILE_SIZE - sizeof(struct nugget_app_data)) bytes.
 */
struct nugget_app_storage {
  uint32_t flags; /* TBD, use zero for now */
#ifndef __cplusplus
  uint8_t data[]; /* Zero or more bytes */
#endif
} __packed;

#define NUGGET_PARAM_STORAGE_WRITE 0x0014
/*
 * Write arbitrary data.
 *
 * The current storage is erased, then new data (if any) is saved.
 *
 * .flags meaning is not yet defined; for now it must be 0x00000000
 *        Possible usage could restrict reading to the bootloader,
 *        erase data after N reads or reboots, etc.
 *
 * @param args         struct nugget_app_storage + zero or more bytes
 * @param arg_len      To write: >  sizeof(struct nugget_app_storage)
 *                     To erase: <= sizeof(struct nugget_app_storage)
 * @param reply        <none>
 * @param reply_len    0
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */
#define NUGGET_PARAM_STORAGE_READ 0x0015
/*
 * Read arbitrary data.
 *
 * On success, struct nugget_app_storage is returned, followed by zero
 * or more bytes of .data
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct nugget_app_storage + zero or more bytes
 * @param reply_len    <varies>
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

/****************************************************************************/
/* Test related commands */

#define NUGGET_PARAM_CYCLES_SINCE_BOOT 0x0100
/*
 * Get the number of cycles since boot
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        uint32_t cycles
 * @param reply_len    sizeof(uint32_t)
 */

enum nugget_app_selftest_cmd {
	/* Generic */
	NUGGET_APP_SELFTEST_CMD_DEFAULT = 0,
	NUGGET_APP_SELFTEST_CMD_HELP,

	/* Application SelfTests */
	NUGGET_APP_SELFTEST_CMD_TRNG = 0x10,
};

#define NUGGET_PARAM_SELFTEST 0x0101
/*
 * Run an intentionally vaguely specified internal test.
 *
 * This accepts arbitrary args and returns arbitrary results, as defined by the
 * Citadel firmware. To allow changes to Nugget OS without requiring
 * simultaneous changes to the AP, calling this with no args will run a default
 * set of tests and return a null-terminated string with the result.
 *
 * @param args         zero or more null-terminated strings, concatenated
 * @param arg_len      number of bytes in args
 * @param reply        null-terminated string (usually)
 * @param reply_len    number of bytes in reply (including trailing '\0')
 */

/****************************************************************************/
/* Support for Power 1.1 HAL */

/*
 * This struct is specific to Citadel and Nugget OS, but it's enough for the
 * AP-side implementation to translate into the info required for the power
 * stats service.
 */
#define NUGGET_APP_LOW_POWER_STATS_MAGIC 0xC0DEACE1
struct nugget_app_low_power_stats { /* version 1 */
  /* All times in usecs */
  uint64_t hard_reset_count;                    /* Cleared by power loss */
  uint64_t time_since_hard_reset;
  /* Below are only since the last hard reset */
  uint64_t wake_count;
  uint64_t time_at_last_wake;
  uint64_t time_spent_awake;
  uint64_t deep_sleep_count;
  uint64_t time_at_last_deep_sleep;
  uint64_t time_spent_in_deep_sleep;
  uint64_t time_at_ap_reset;
  uint64_t time_at_ap_bootloader_done;
  /*
   * New fields for v1, used by factory tests. The caller can tell whether the
   * firmare supports these fields by checking the v1_magic value.
   */
  uint32_t v1_magic; /* NUGGET_APP_LOW_POWER_STATS_MAGIC */
  uint32_t temp;
  struct {
    unsigned int phone_on_l : 1;
    unsigned int vol_up_l : 1;
    unsigned int vol_dn_l : 1;
    unsigned int _padding : 29; /* pad to 32 bits */
  } signals;
} __packed;

#define NUGGET_PARAM_GET_LOW_POWER_STATS 0x200
/*
 * Return information regarding deep sleep transitions
 *
 * @param args         <none>
 * @param arg_len      0
 * @param reply        struct nugget_param_get_low_power_stats
 * @param reply_len    sizeof(struct nugget_param_get_low_power_stats)
 */

/* UNIMPLEMENTED */
/* Reseved just in case we decide we need it */
#define NUGGET_PARAM_CLEAR_LOW_POWER_STATS 0x201
/* UNIMPLEMENTED */

/****************************************************************************/
/* Commands for code coverage and quality assurance */

#define NUGGET_GET_COVERAGE_COUNTERS 0x0300
/**
 * Returns the counters back to the master
 *
 * @param args         module counter
 * @param arg_len      1
 * @param reply        buffer containing coverage data in utf-8 format
 * @param reply_len    depends on the counters in the file
 */

/*
 * Error returned if coverage data didn't fit in the buffer.
 *
 * TODO: Should really have a second arg which is an offset in the coverage
 * data.  That way we could call repeatedly to return data too big to return in
 * a single command.
 */
enum {
  NUGGET_ERROR_COVERAGE_OVERFLOW = APP_SPECIFIC_ERROR + 0x300,
};

/****************************************************************************/
/* These are bringup / debug functions only. */

#define NUGGET_PARAM_READ32 0xF000
/*
 * Read a 32-bit value from memory.
 *
 * DANGER, WILL ROBINSON! DANGER! There is NO sanity checking on this AT ALL.
 * Read the wrong address, and Bad Things(tm) WILL happen.
 *
 * @param args         uint32_t address
 * @param arg_len      sizeof(uint32_t)
 * @param reply        uint32_t value
 * @param reply_len    sizeof(uint32_t)
 */

struct nugget_app_write32 {
  uint32_t address;
  uint32_t value;
} __packed;

#define NUGGET_PARAM_WRITE32 0xF001
/*
 * Write a 32-bit value to memory
 *
 * DANGER, WILL ROBINSON! DANGER! There is NO sanity checking on this AT ALL.
 * Write the wrong values to the wrong address, and Bad Things(tm) WILL happen.
 *
 * @param args         struct nugget_app_write32
 * @param arg_len      sizeof(struct nugget_app_write32)
 * @param reply        <none>
 * @param reply_len    0
 */

#define NUGGET_PARAM_CONSOLE 0xF002
/*
 * Send optional command, return recent console output
 *
 * @param args         command, if any
 * @param arg_len      sizeof(command)
 * @param reply        recent console output
 * @param reply_len    len(recent console output)
 */

#define NUGGET_PARAM_MODULE_TEST 0xF003
/**
 * Run a module test based on a provided command.
 *
 * A default command is afforded (0x00), which runs each module test that is
 * currently enabled. Specific tests can be specified, but are not enumerated
 * here.
 *
 * The return code of the command (enum app_status) encodes the success state of
 * the tests. A result of `APP_SUCCESS` is, unsurprisingly, a success for all
 * specified tests. A failure of a given test is encoded using the
 * `APP_SPECIFIC_ERROR` values. This allows a given test to not only report that
 * an error has occured, but also to report which test threw the error, and in
 * what point of the test the error was thrown.
 * The encoding is as follows:
 * `rv = (APP_SPECIFIC_ERROR + command + test_step)`
 * where `command` is the 4-byte test value (in steps of 0x10), and where the
 * test_step is a subdivision of the test, valued from 0-15.
 *
 * The return string will describe each test that passes, and each test that
 * fails, and how it failed. Tests should abort after the first failure.
 *
 * @param args         uint32_t command
 * @param arg_len      sizeof(uint32_t)
 * @param reply        null-terminated string (usually)
 * @param reply_len    number of bytes in reply (including trailing '\0')
 */

enum nugget_app_sleep_mode {
	NUGGET_APP_SLEEP_MODE_DEFAULT,
	NUGGET_APP_SLEEP_MODE_WFI,
	NUGGET_APP_SLEEP_MODE_SLEEP
};
#define NUGGET_PARAM_SET_SLEEP_MODE 0xF004
/**
 * Set the Sleep mode of the GSC.
 *
 * In certain tests, we expect the GSC to be in either WFI mode, or in deep
 * sleep mode. The sleep state should be provided by the host to the GSC, to
 * ensure that the test is performed in the correct circumstances.
 *
 * @param args         enum nugget_app_sleep_mode selection
 * @param arg_len      4
 * @param reply        <none>
 * @param reply_len    0
 */

#define NUGGET_PARAM_TRIGGER_PIN 0xF005
/**
 * Get/Set trigger pin level
 *
 * This command asks GSC to set the level (0|1) of an otherwise unused GPIO,
 * to signal external test equipment.
 *
 * @param args         0     OR   1
 * @param arg_len      0     OR   1 byte
 * @param reply        current state (0 or 1)
 * @param reply_len    1 byte
 *
 * @errors             APP_ERROR_BOGUS_ARGS
 */

#ifdef __cplusplus
}
#endif

#endif  /* __CROS_EC_INCLUDE_APP_NUGGET_H */
