/*
 * Copyright (C) 2010-2018 NXP Semiconductors
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

/*
 *  OSAL header files related to memory, debug, random, semaphore and mutex
 * functions.
 */

#ifndef PHNFCCOMMON_H
#define PHNFCCOMMON_H

/*
************************* Include Files ****************************************
*/

#include <phDal4Nfc_messageQueueLib.h>
#include <phNfcCompId.h>
#include <phNfcStatus.h>
#include <phOsalNfc_Timer.h>
#include <pthread.h>
#include <semaphore.h>

#define FW_DLL_ROOT_DIR "/system/vendor/"
#define FW_DLL_EXTENSION ".so"
#define FW_LIB_ROOT_DIR "/vendor/lib/"
#define FW_BIN_ROOT_DIR "/vendor/firmware/"
#define FW_LIB_EXTENSION ".so"
#define FW_BIN_EXTENSION ".bin"

/* Actual FW library name*/
/* Restore Corrupted PLL Settings/etc */
#define PLATFORM_LIB_PATH \
  FW_DLL_ROOT_DIR "libsn100u_fw_platform" FW_DLL_EXTENSION
/* Upgrade the public Key */
#define PKU_LIB_PATH FW_DLL_ROOT_DIR "libsn100u_fw_pku" FW_DLL_EXTENSION

/* HAL Version number (Updated as per release) */
#define NXP_MW_VERSION_MAJ (0x03)
#define NXP_MW_VERSION_MIN (0x02)

#define GET_EEPROM_DATA (1U)
#define SET_EEPROM_DATA (2U)

#define BITWISE (1U)
#define BYTEWISE (2U)

#define GET_FW_DWNLD_FLAG (1U)
#define RESET_FW_DWNLD_FLAG (2U)

#define FLASH_UPPER_VERSION (1)
#define FLASH_DIFFERENT_VERSION (2)
#define FLASH_ALWAYS (3)
/*
 *****************************************************************
 ***********  System clock source selection configuration ********
 *****************************************************************
 */

#define CLK_SRC_UNDEF 0
#define CLK_SRC_XTAL 1
#define CLK_SRC_PLL 2
#define CLK_SRC_PADDIRECT 3
#define CLK_CFG_XTAL 8

/*Extern crystal clock source*/
/* Use one of CLK_SRC_<value> */
#define NXP_SYS_CLK_SRC_SEL CLK_SRC_PLL
/*Direct clock*/

/*
 *****************************************************************
 ***********  System clock frequency selection configuration ****************
 * If Clk_Src is set to PLL, make sure to set the Clk_Freq also*
 *****************************************************************
 */
#define CLK_FREQ_UNDEF         0
#define CLK_FREQ_13MHZ         1
#define CLK_FREQ_19_2MHZ       2
#define CLK_FREQ_24MHZ         3
#define CLK_FREQ_26MHZ         4
#define CLK_FREQ_32MHZ         5
#define CLK_FREQ_38_4MHZ       6
#define CLK_FREQ_52MHZ         7

/* Set to one of CLK_FREQ_<value> */
#define NXP_SYS_CLK_FREQ_SEL CLK_FREQ_19_2MHZ

#define CLK_TO_CFG_DEF 1
#define CLK_TO_CFG_MAX 6

#define CLK_REQ_DELAY_MIN 1
#define CLK_REQ_DELAY_MAX 31
#define CLK_REQ_DELAY_DEF 22
#define CLK_REQ_DELAY_MASK 0x1F
#define CLK_REQ_DELAY_PLL_OFFSET 13
#define CLK_REQ_DELAY_XTAL_OFFSET 14
/*
 *  information to configure OSAL
 */
typedef struct phOsalNfc_Config {
  uint8_t* pLogFile;            /* Log File Name*/
  uintptr_t dwCallbackThreadId; /* Client ID to which message is posted */
} phOsalNfc_Config_t, *pphOsalNfc_Config_t /* Pointer to #phOsalNfc_Config_t */;

/*
 * Deferred call declaration.
 * This type of API is called from ClientApplication (main thread) to notify
 * specific callback.
 */
typedef void (*pphOsalNfc_DeferFuncPointer_t)(void*);

/*
 * Deferred message specific info declaration.
 */
typedef struct phOsalNfc_DeferedCallInfo {
  pphOsalNfc_DeferFuncPointer_t pDeferedCall; /* pointer to Deferred callback */
  void* pParam; /* contains timer message specific details*/
} phOsalNfc_DeferedCallInfo_t;

/*
 * States in which a OSAL timer exist.
 */
typedef enum {
  eTimerIdle = 0,          /* Indicates Initial state of timer */
  eTimerRunning = 1,       /* Indicate timer state when started */
  eTimerStopped = 2        /* Indicates timer state when stopped */
} phOsalNfc_TimerStates_t; /* Variable representing State of timer */

/*
 **Timer Handle structure containing details of a timer.
 */
typedef struct phOsalNfc_TimerHandle {
  uint32_t TimerId;     /* ID of the timer */
  timer_t hTimerHandle; /* Handle of the timer */
  /* Timer callback function to be invoked */
  pphOsalNfc_TimerCallbck_t Application_callback;
  void* pContext; /* Parameter to be passed to the callback function */
  phOsalNfc_TimerStates_t eState; /* Timer states */
  /* Osal Timer message posted on User Thread */
  phLibNfc_Message_t tOsalMessage;
  /* Deferred Call structure to Invoke Callback function */
  phOsalNfc_DeferedCallInfo_t tDeferedCallInfo;
  /* Variables for Structure Instance and Structure Ptr */
} phOsalNfc_TimerHandle_t, *pphOsalNfc_TimerHandle_t;

#endif /*  PHOSALNFC_H  */
