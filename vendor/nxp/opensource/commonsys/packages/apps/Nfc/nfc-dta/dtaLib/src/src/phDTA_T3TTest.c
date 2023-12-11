/*
* Copyright (C) 2015-2020 NXP Semiconductors
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

/*!
 * \file phDTA_T3TTest.c
 *
 * Project: NFC DTA
 *
 */

/* Preprocessor includes for different platform */
#ifdef WIN32
#include <windows.h>
#else
#include <utils/Log.h>
#include "data_types.h"
#endif

#include "phDTAOSAL.h"
#include "phMwIf.h"
#include "phDTALib.h"
#include "phDTATst.h"

#ifdef __cplusplus
extern "C" {
#endif

#define T3T_CHECK_CMD                 0x06
#define T3T_RESPONSE_DATA_OFFSET      0x0D /* In T3T CHECK command response, Data offset starts from 13th byte */
#define T3T_UPDATE_CMD                0x08

typedef struct phDtaLibi_sT3Tcmd
{
    uint8_t  bCmd;
    uint8_t* pbBuf;
    uint32_t dwBufLen;
    uint8_t  abResultBuffer[400];
    uint32_t dwResultBufLen;
}phDtaLibi_sT3Tcmd_t;

static const uint8_t gs_abCheckNDEFCmd[]={
    0x01,         /**<Number of Services*/
    0x0B,0x00,    /**<NDEF Service 0x000B*/
    0x01,         /**<Number of Blocks*/
    0x80,0x00     /**<First Block with 2-byte Block bit set*/
};
static const uint8_t gs_abCheckReadCmd[1+1*2+1+15*2] = {
    0x01,       /**< services */
                /**< service list */
    0x09, 0x00,
    0x0F,       /**< blocks */
                /**< block list */
    0x80, 0x01,  0x80, 0x02,  0x80, 0x03,  0x80, 0x04,  0x80, 0x05,  0x80, 0x06,
    0x80, 0x07,  0x80, 0x08,  0x80, 0x09,  0x80, 0x0A,  0x80, 0x0B,  0x80, 0x0C,
    0x80, 0x0D,  0x80, 0x0E,  0x80, 0x0F
};
static const uint8_t gs_abCheckMinBlkReadCmd[]={
        0x01,     /**<Number of Services*/
        0x09,0x00,/**<Service 0x0009*/
        0x01,     /**<Number of Blocks*/
        0x80,0x01 /**<Block 1 with 2-byte Block bit set*/
};
static const uint8_t gs_abMinBlkWriteCmd[]={
        0x01,                    /**<Number of Services*/
        0x09,0x00,               /**<Service 0x0009*/
        0x01,                    /**<Number of Blocks*/
        0x80,0x01,               /**<Block 1 with 2-byte Block bit set*/
        0xFF, 0xFF, 0xFF, 0xFF,  /**<16 Bytes of Data*/
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF
};
static const uint8_t  gs_abMinBlkEndOfTransaction[]={
    0x20, 0x08,0x02, 0xFE, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x01,                     /**<Number of Services*/
    0x09,0x00,                /**<Service 0x0009*/
    0x01,                     /**<Number of Blocks*/
    0x80,0x01,                /**<Block 1 with 2-byte Block bit set*/
    0x0F, 0x00, 0x00, 0x00,   /**<16 Bytes of Data*/
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

static const uint8_t gs_abMaxSvcChkWriteCmd[1+12*2+1+12*2+192] = {
    0x0C, /* services */
    /* service list */
    0x09, 0x00,  0x49, 0x11,  0x89, 0x22,  0xC9, 0x33,  0x09, 0x44,  0x49, 0x55,
    0x89, 0x66,  0xC9, 0x77,  0x09, 0x88,  0x49, 0x99,  0x89, 0xAA,  0xC9, 0xBB,
    0x0C, /* blocks */
    /* block list */
    0x80, 0x00,  0x81, 0x00,  0x82, 0x00,  0x83, 0x00,  0x84, 0x00,  0x85, 0x00,
    0x86, 0x00,  0x87, 0x00,  0x88, 0x00,  0x89, 0x00,  0x8A, 0x00,  0x8B, 0x00,
    /* Data 192 Bytes*/
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 1 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 2 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 3 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 4 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 5 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 6 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 7 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 8 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 9 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 10 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 11 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 12 */
},
gs_MaxSvcChkReadCmd[1+15*2+1+15*2/*+240*/] = {/*@For Error in Total Size*/
  0x0F, /* # services */
  /* service list */
  0x0B, 0x00,  0x4B, 0x11,  0x8B, 0x22,  0xCB, 0x33,  0x0B, 0x44,  0x4B, 0x55,
  0x8B, 0x66,  0xCB, 0x77,  0x0B, 0x88,  0x4B, 0x99,  0x8B, 0xAA,  0xCB, 0xBB,
  0x0B, 0xCC,  0x4B, 0xDD,  0x8B, 0xEE,
  0x0F, /* # blocks */
  /* block list */
  0x80, 0x00,  0x81, 0x00,  0x82, 0x00,  0x83, 0x00,  0x84, 0x00,  0x85, 0x00,
  0x86, 0x00,  0x87, 0x00,  0x88, 0x00,  0x89, 0x00,  0x8A, 0x00,  0x8B, 0x00,
  0x8C, 0x00,  0x8D, 0x00,  0x8E, 0x00
},
gs_abMaxSvcChkEndOFtransactionCmd[]={
    0x20, 0x08,0x02, 0xFE, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x01,/* Number of Services */
    0x09,0x00,/*Service 0x0009 */
    0x01,/* Number of Blocks */
    0x80,0x01, /* Block 1 with 2-byte Block bit set */
    0x0F, 0x00, 0x00, 0x00, /* 16 Bytes of Data */
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

const uint8_t gs_abMaxBlkChkWriteCmd1[1+4*2+1+13*2+208] = {
    0x04, /* # services */
    0x09, 0x00,  0x49, 0x11,  0x89, 0x22,  0xC9, 0x33, /* service list */
    0x0D, /* # blocks */
    /* block list */
    0x80, 0x00,  0x80, 0x01,  0x80, 0x02,  0x81, 0x00,  0x81, 0x01,  0x81, 0x02,
    0x82, 0x00,  0x82, 0x01,  0x82, 0x02,  0x83, 0x00,  0x83, 0x01,  0x83, 0x02,
    0x83, 0x03,
    /* Data 208 Bytes*/
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 1 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 2 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 3 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 4 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 5 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 6 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 7 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 8 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 9 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 10 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 11 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 12 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 13 */
},
gs_abMaxBlkChkRead1[1+5*2+1+15*2/*+240*/] = {/* @For Error in Total Size */
    0x05, /* # services */
    0x0B, 0x00,  0x4B, 0x11,  0x8B, 0x22,  0xCB, 0x33,  0x0B, 0x44, /* services */
    0x0F, /* # blocks */
    /* block list */
    0x80, 0x00,  0x80, 0x01,  0x80, 0x02,  0x81, 0x00,  0x81, 0x01,  0x81, 0x02,
    0x82, 0x00,  0x82, 0x01,  0x82, 0x02,  0x83, 0x00,  0x83, 0x01,  0x83, 0x02,
    0x84, 0x00,  0x84, 0x01,  0x84, 0x02
},
gs_abMaxBlkChkWriteCmd2[1+7*2+1+12*3+192] = {/* @For Error in Total Size added 1 */
    0x07, /* # services */
    0x09, 0x00,  0x49, 0x11,  0x89, 0x22,  0xC9, 0x33,
    0x09, 0x44,  0x49, 0x55,  0x89, 0x66, /* service list */
    0x0C, /* # blocks */
    0x00, 0x00, 0x00,  0x00, 0x01, 0x00,  0x01, 0x00, 0x00,  0x01, 0x01, 0x00,
    0x02, 0x00, 0x00,  0x02, 0x01, 0x00,  0x03, 0x00, 0x00,  0x03, 0x01, 0x00,
    0x04, 0x00, 0x00,  0x04, 0x01, 0x00,  0x05, 0x00, 0x00,  0x06, 0x00, 0x00,
    /* Data 192 Bytes */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 1 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 2 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 3 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 4 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 5 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 6 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 7 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 8 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 9 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 10 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 11 */
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,    /* 12 */
},
gs_abMaxBlkChkRead2[1+5*2+1+15*3/*+240*/] = {/* @For Error in Total Size */
    0x05, /* # services */
    0x0B, 0x00,  0x4B, 0x11,  0x8B, 0x22,  0xCB, 0x33,  0x0B, 0x44, /* services */
    0x0F, /* # blocks */
    /* block list */
    0x00, 0x00, 0x00,  0x00, 0x01, 0x00,  0x00, 0x02, 0x00,  0x01, 0x00, 0x00,
    0x01, 0x01, 0x00,  0x01, 0x02, 0x00,  0x02, 0x00, 0x00,  0x02, 0x01, 0x00,
    0x02, 0x02, 0x00,  0x03, 0x00, 0x00,  0x03, 0x01, 0x00,  0x03, 0x02, 0x00,
    0x04, 0x00, 0x00,  0x04, 0x01, 0x00,  0x04, 0x02, 0x00
},
gs_abMaxBlkChkEndOfTransaction[]={
    0x20, 0x08,0x02, 0xFE, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x01,/* Number of Services */
    0x09,0x00,/* Service 0x0009 */
    0x01,/* Number of Blocks */
    0x80,0x01, /* Block 1 with 2-byte Block bit set */
    0x0F, 0x00, 0x00, 0x00, /* 16 Bytes of Data */
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

static const uint8_t gs_abUpdateCmdData[]={
    0x10,0x0F,0x0C,0x00,0x93,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0xF0,0x01,0xAF
},
gs_abUpdateWriteFlagCmdON[]={
    0x01,0x09,0x00,0x01,0x80,0x00,0x10,0x0F,0x0C,0x00,0x93,0x00,0x00,0x00,0x00,
    0x0F,0x01,0x00,0x00,0xF0,0x01,0xBE
},
gs_abUpdateWriteCmdData[]={
    0x01,0x09,0x00,0x0C,0x80,0x01,0x80,0x02,0x80,0x03,0x80,0x04,0x80,
    0x05,0x80,0x06,0x80,0x07,0x80,0x08,0x80,0x09,0x80,0x0A,0x80,0x0B,0x80,0x0C,
    0x03,0xBE,0xD1,0x01,0xBF,0x54,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D,0x46,0x6F,0x72,
    0x75,0x6D,0x2D,0x4E,0x58,0x50,0x4E,0x46,0x43,0x2D
},
gs_abUpdateWriteAttrData[]={
    0x01,0x09,0x00,0x01,0x80,0x00,0x10,0x0F,0x0C,0x00,0x93,0x00,0x00,
    0x00,0x00,0x00,0x01,0x00,0x00,0xC0,0x01,0x7F
};

extern phDtaLib_sHandle_t g_DtaLibHdl;

static DTASTATUS phDtaLibi_T3TNDEFRead(void);
static DTASTATUS phDtaLibi_T3TNDEFWrite(void);
static DTASTATUS phDtaLibi_T3TPoll(uint16_t wSysCode,uint8_t bReqSysCode,uint8_t bTsn);
static DTASTATUS phDtaLibi_T3TCmd(phDtaLibi_sT3Tcmd_t *psT3TcmdPrms);
static DTASTATUS phDtaLibi_T3TMinBlockCheck(void);
static DTASTATUS phDtaLibi_T3TMaxServiceCheck(void);
static DTASTATUS phDtaLibi_T3TMaxBlockCheck(void);

#define PATTERN_NUM_ANALOG_TEST 0x1000

/**
*T3T Tag read/write operations based on pattern number
*/
DTASTATUS phDtaLibi_T3TOperations(phDtaLib_sTestProfile_t sTestProfile,
                                         phMWIf_sActivatedEvtInfo_t* psT3TActivationParams,BOOLEAN* bStartDiscReqd,
                                         BOOLEAN* bStopDiscReqd)
{
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    LOG_FUNCTION_ENTRY;
    dtaLibHdl->sT3TActivationParams = *psT3TActivationParams;
    switch(sTestProfile.Pattern_Number)
    {
      case 0x0001:
        phOsal_LogDebug ((const uint8_t*)"DTALib>T3T: Perform NDEF Check \n");
        phDtaLibi_T3TNDEFRead();
      break;
      case 0x0002:
        phOsal_LogDebug ((const uint8_t*)"DTALib>T3T: Perform NDEF Check \n");
        phDtaLibi_T3TNDEFWrite();
      break;
      case 0x0006:
      case 0x0003:
        if(phDtaLibi_T3TPoll(0x12FC,00,00) == DTASTATUS_SUCCESS)
        {
          phOsal_LogDebug ((const uint8_t*)"DTALib>T3T: Perform x_NFC_FelicaMinBlockCheck \n");
          phDtaLibi_T3TMinBlockCheck();
        }else{
            phDtaLibi_T3TPoll(0x12FC,00,00);
        }
      break;
      case 0x0004:
       if(phDtaLibi_T3TPoll(0x12FC,00,00) == DTASTATUS_SUCCESS)
       {
           phDtaLibi_T3TMaxServiceCheck();
       }
      break;
      case 0x0005:
        if(phDtaLibi_T3TPoll(0x12FC,00,00) == DTASTATUS_SUCCESS)
        {
            phDtaLibi_T3TMaxBlockCheck();
        }
      break;
      case 0x0007:
      case 0x0008:
      case PHDTALIB_PATTERN_NUM_ANALOG_TEST:
      {

          if(phDtaLibi_T3TPoll(0xFFFF,01,0x0F) == DTASTATUS_SUCCESS)
          {
              if(phDtaLibi_T3TMinBlockCheck()==DTASTATUS_SUCCESS)
              {
                   phMwIf_NfcDeactivate(dtaLibHdl->mwIfHdl,PHMWIF_DEACTIVATE_TYPE_DISCOVERY);
                   *bStartDiscReqd = FALSE;
                   *bStopDiscReqd  = FALSE;
              }
            }
      }
      break;

      case 0x000E:
      case 0x000F:
      {
        phDtaLibi_T3TPoll(0x12FC,00,0x00);
      }
      break;

      default:
        phOsal_LogError((const uint8_t*)"DTALib>T3T: Error Pattern Number not valid for T3T !! \n");
        break;
    }
    LOG_FUNCTION_EXIT;
  return gx_status;
}

/**
 * \brief This function performs the ndef read for Felica
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TNDEFRead(void)
{

    phDtaLibi_sT3Tcmd_t sT3Tcmd;
    phDtaLibi_sT3Tcmd_t *psT3TcmdPrms = &sT3Tcmd;
    LOG_FUNCTION_ENTRY;

    gx_status = phDtaLibi_T3TPoll(0x12FC,00,00);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status,(const uint8_t*)"DTALib>T3T: Error in Felica Custom Read at Poll !! \n");
    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abCheckNDEFCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abCheckNDEFCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Read at Check NDEF !! \n");

    if(psT3TcmdPrms->abResultBuffer[1+8+1+1+1]>0x20)/**<Invalid Version*/
    {
        phOsal_LogError((const uint8_t*)"DTALib>T3T: Error Invalid T3T version !! \n");
        return DTASTATUS_FAILED;
    }

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abCheckReadCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abCheckReadCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Read at Check Read NDEF !! \n");

    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function performs ndef write for Felica tag
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TNDEFWrite(void)
{
    phDtaLibi_sT3Tcmd_t sT3Tcmd;
    phDtaLibi_sT3Tcmd_t *psT3TcmdPrms = &sT3Tcmd;
    LOG_FUNCTION_ENTRY;

    gx_status = phDtaLibi_T3TPoll(0x12FC,00,00);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Write at Poll !! \n");

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abCheckNDEFCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abCheckNDEFCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Write at Check NDEF !! \n");
    if(!(memcmp(psT3TcmdPrms->abResultBuffer+T3T_RESPONSE_DATA_OFFSET,gs_abUpdateCmdData,sizeof(gs_abUpdateCmdData))))
    {
        psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
        psT3TcmdPrms->pbBuf = (uint8_t *)gs_abUpdateWriteFlagCmdON;
        psT3TcmdPrms->dwBufLen = sizeof(gs_abUpdateWriteFlagCmdON);
        gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
        PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Write at Check NDEF !! \n");
        psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
        psT3TcmdPrms->pbBuf = (uint8_t *)gs_abUpdateWriteCmdData;
        psT3TcmdPrms->dwBufLen = sizeof(gs_abUpdateWriteCmdData);
        gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
        PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Write at Check NDEF !! \n");
        psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
        psT3TcmdPrms->pbBuf = (uint8_t *)gs_abUpdateWriteAttrData;
        psT3TcmdPrms->dwBufLen = sizeof(gs_abUpdateWriteAttrData);
        gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
        PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in Felica Custom Write at Check NDEF !! \n");
    }
    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function performs block check for Felica tag
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TMinBlockCheck(void)
{
    phDtaLibi_sT3Tcmd_t sT3Tcmd;
    phDtaLibi_sT3Tcmd_t *psT3TcmdPrms = &sT3Tcmd;
    uint8_t bMiscBuffer[400];             /**< Misc buffer used for compare */
    uint32_t dwMiscBufferLength;          /**< Length for Misc array  */
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    LOG_FUNCTION_ENTRY;

    psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMinBlkWriteCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMinBlkWriteCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MinBlockCheck at first Write !! \n");

    /*Save the Buffer*/
    memcpy(&bMiscBuffer,&psT3TcmdPrms->abResultBuffer,psT3TcmdPrms->dwResultBufLen);
    dwMiscBufferLength = psT3TcmdPrms->dwResultBufLen;

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abCheckMinBlkReadCmd;
    psT3TcmdPrms->dwBufLen = (uint32_t)sizeof(gs_abCheckMinBlkReadCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MinBlockCheck at Second Read !! \n");

    /* Compare Read and write data*/
    if(memcmp(bMiscBuffer+1,psT3TcmdPrms->abResultBuffer+1,psT3TcmdPrms->dwResultBufLen)!=0)
    {
        phOsal_LogError((const uint8_t*)"DTALib>T3T: Data Write & Read don't match in MinBlockCheck !! \n");
    }

    phMwIf_SendRawFrame(dtaLibHdl->mwIfHdl,(uint8_t *)gs_abMinBlkEndOfTransaction,sizeof(gs_abMinBlkEndOfTransaction));

    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MinBlockCheck at EOT Write !! \n");
    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function performs service check for Felica tag
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */

DTASTATUS phDtaLibi_T3TMaxServiceCheck(void)
{
    phDtaLibi_sT3Tcmd_t sT3Tcmd;
    phDtaLibi_sT3Tcmd_t *psT3TcmdPrms = &sT3Tcmd;
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    LOG_FUNCTION_ENTRY;

    psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMaxSvcChkWriteCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMaxSvcChkWriteCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxServiceCheck at First Write !! \n");

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_MaxSvcChkReadCmd;
    psT3TcmdPrms->dwBufLen = sizeof(gs_MaxSvcChkReadCmd);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxServiceCheck at Second Read !! \n");

    phMwIf_SendRawFrame(dtaLibHdl->mwIfHdl,(uint8_t *)gs_abMaxSvcChkEndOFtransactionCmd,sizeof(gs_abMaxSvcChkEndOFtransactionCmd));
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxServiceCheck at EOT Write !! \n");

    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function performs max block check for Felica tag
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TMaxBlockCheck(void)
{
    phDtaLibi_sT3Tcmd_t sT3Tcmd;
    phDtaLibi_sT3Tcmd_t *psT3TcmdPrms = &sT3Tcmd;
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    LOG_FUNCTION_ENTRY;

    psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMaxBlkChkWriteCmd1;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMaxBlkChkWriteCmd1);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxBlockCheck at First Write !! \n");

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMaxBlkChkRead1;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMaxBlkChkRead1);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxBlockCheck at Second Read !! \n");

    psT3TcmdPrms->bCmd = T3T_UPDATE_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMaxBlkChkWriteCmd2;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMaxBlkChkWriteCmd2);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxBlockCheck at Third Write !! \n");

    psT3TcmdPrms->bCmd = T3T_CHECK_CMD;
    psT3TcmdPrms->pbBuf = (uint8_t *)gs_abMaxBlkChkRead2;
    psT3TcmdPrms->dwBufLen = sizeof(gs_abMaxBlkChkRead2);
    gx_status = phDtaLibi_T3TCmd(psT3TcmdPrms);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxBlockCheck at Fourth Read !! \n");

    phMwIf_SendRawFrame(dtaLibHdl->mwIfHdl,(uint8_t *)gs_abMaxBlkChkEndOfTransaction,sizeof(gs_abMaxBlkChkEndOfTransaction));
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, gx_status, (const uint8_t*)"DTALib>T3T: Error in MaxBlockCheck at EOT Write !! \n");

    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function sends the custom poll config command to NFCC
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TPoll(uint16_t wSysCode,uint8_t bReqSysCode,uint8_t bTsn)
{
    uint8_t ucmd[7];
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    uint8_t resultBuffer[400];
    uint32_t dwSizeOfResultBuff=0;
    MWIFSTATUS dwMwIfStatus = 0;
    ucmd[0] = 6; /*Size*/
    ucmd[1] = 0x00; /* SENSEF*/
    ucmd[2] = (uint8_t)((wSysCode >> 8) & 0x0FF);
    ucmd[3] = (uint8_t)(wSysCode & 0x0FF);
    ucmd[4] = bReqSysCode; /* RC: request system code*/
    ucmd[5] = bTsn; /* TSN: time slot no*/
    LOG_FUNCTION_ENTRY;

    dwMwIfStatus = phMwIf_Transceive(dtaLibHdl->mwIfHdl,
                                       (uint8_t *)ucmd,
                                        6,
                                         resultBuffer,
                                         &dwSizeOfResultBuff);
    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS, dwMwIfStatus, (const uint8_t*)"DTALib>T3T: Error Could not send Felica Poll !! \n");

    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

/**
 * \brief This function sends the Felica response to LTU
 * /return NFA_STATUS_OK - if the initialization was successful
 *         NFA_STATUS_FAILED - in case of errors with Semaphore post
 */
DTASTATUS phDtaLibi_T3TCmd(phDtaLibi_sT3Tcmd_t *psT3TcmdPrms)
{
    uint8_t baParamBuffer[400];    /**< Buffer for passing Data during operations */
    uint32_t dwsizeParamBuffer;
    uint8_t resultBuffer[400];     /**< for transceive function */
    uint32_t dwSizeOfResultBuff=0; /**< for transceive function */
    phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
    LOG_FUNCTION_ENTRY;
    if(psT3TcmdPrms->dwBufLen > 390)
    {
        phOsal_LogErrorU32h((const uint8_t*)"DTALib>T3T: Error Buffer length  > 390 !! \n",psT3TcmdPrms->dwBufLen);
        return DTASTATUS_INVALID_PARAM;/*NFA_STATUS_BAD_LENGTH;*/
    }
    /* Temporary Store */
    memcpy(psT3TcmdPrms->abResultBuffer,psT3TcmdPrms->pbBuf,psT3TcmdPrms->dwBufLen);
    psT3TcmdPrms->dwResultBufLen = psT3TcmdPrms->dwBufLen;

    baParamBuffer[0] = 0x00;/* Size */
    baParamBuffer[1] = psT3TcmdPrms->bCmd;/* Command */
    /* Copy IDm */
    memcpy(baParamBuffer+2, dtaLibHdl->sT3TActivationParams.uRfTechParams.sPollFPrms.abNfcId2, 8);
    /* Copy Buffer */
    memcpy(baParamBuffer+10,psT3TcmdPrms->abResultBuffer,psT3TcmdPrms->dwResultBufLen);
    /* Size Set */
    baParamBuffer[0] = (uint8_t)(10 + psT3TcmdPrms->dwBufLen);
    dwsizeParamBuffer = 10 + psT3TcmdPrms->dwBufLen;

    gx_status = phMwIf_Transceive(dtaLibHdl->mwIfHdl,
                                        (uint8_t *)baParamBuffer,
                                         dwsizeParamBuffer,
                                         resultBuffer,
                                         &dwSizeOfResultBuff);
    memcpy(psT3TcmdPrms->abResultBuffer,resultBuffer,dwSizeOfResultBuff);

    PH_ON_ERROR_RETURN(DTASTATUS_SUCCESS,gx_status,(const uint8_t*)"DTALib>T3T: Error in Felica Check !! \n");
    LOG_FUNCTION_EXIT;
    return DTASTATUS_SUCCESS;
}

DTASTATUS phDtaLibi_T3TOperations_DynamicExecution(phDtaLib_sTestProfile_t sTestProfile,
                                                    phMWIf_sActivatedEvtInfo_t* psT3TActivationParams)
{
  DTASTATUS  dwDtaStatus = DTASTATUS_FAILED;
  phDtaLib_sHandle_t *dtaLibHdl = &g_DtaLibHdl;
  phMwIf_uTagOpsParams_t sTagOpsParams;
  phMwIf_sNdefDetectParams_t* psNdefDetectParams;
  dtaLibHdl->sT3TActivationParams = *psT3TActivationParams;

  LOG_FUNCTION_ENTRY;

  phOsal_LogDebugString((const uint8_t*)"DTALib> :", (const uint8_t*)__FUNCTION__);
  phOsal_LogDebugU32h((const uint8_t*)"DTALib>T3T:pattern number = ", sTestProfile.Pattern_Number);
  sTagOpsParams.sBuffParams.pbBuff = gs_ndefReadWriteBuff;
  switch(sTestProfile.Pattern_Number)
  {
    case 0x0001:
    {
      /* Pattern Numbers to test READ functionality */
      phOsal_LogDebug ((const uint8_t*)"DTALib>T3T:Perform NDEF Check \n");
      dwDtaStatus = phDtaLibi_CheckNDEF(&sTagOpsParams);
      if (dwDtaStatus != DTASTATUS_SUCCESS)
      {
        phOsal_LogError((const uint8_t*)"DTALib>T3T:Device is not NDEF Compliant\n");
        break;
      }
      psNdefDetectParams = &sTagOpsParams.sNdefDetectParams;
      if(!psNdefDetectParams->dwStatus)
      {
        phOsal_LogDebug((const uint8_t*)"DTALib> T3T:Tag is NDEF compliant \n");
        phOsal_LogDebug((const uint8_t*)"DTALib> T3T:Read NDEF \n");
        dwDtaStatus = phDtaLibi_ReadNDEF(&sTagOpsParams);
        if (dwDtaStatus != DTASTATUS_SUCCESS)
        {
          phOsal_LogError((const uint8_t*)"DTALib> T3T:Error Could not read data !!\n");
          break;
        }
        memset(gs_ndefReadWriteBuff, 0, sizeof(gs_ndefReadWriteBuff));
        memcpy(gs_ndefReadWriteBuff,sTagOpsParams.sBuffParams.pbBuff, sTagOpsParams.sBuffParams.dwBuffLength);
        gs_sizeNdefRWBuff = sTagOpsParams.sBuffParams.dwBuffLength;
        phOsal_LogDebugU32d((const uint8_t*)"DTALib>:T3T:NDEF READ Length: ", gs_sizeNdefRWBuff);
      }
    }
    break;

    /* Pattern Numbers to test WRITE functionality */
    case 0x0002:
    {
      phOsal_LogDebug ((const uint8_t*)"DTALib>T3T:Perform NDEF Check \n");
      dwDtaStatus = phDtaLibi_CheckNDEF(&sTagOpsParams);
      if (dwDtaStatus != DTASTATUS_SUCCESS)
      {
        phOsal_LogError((const uint8_t*)"DTALib>T3T:Device is not NDEF Compliant\n");
        break;
      }

      psNdefDetectParams = &sTagOpsParams.sNdefDetectParams;
      if(!psNdefDetectParams->dwStatus)
      {
        phOsal_LogDebug((const uint8_t*)"DTALib> T3T:Tag is NDEF compliant \n");
        phOsal_LogDebug((const uint8_t*)"DTALib>T3T:Write NDEF Message \n");
        sTagOpsParams.sBuffParams.dwBuffLength = gs_sizeNdefRWBuff;
        phOsal_LogDebugU32d((const uint8_t*)"DTALib>:T3T:NDEF WRITE Length: ", sTagOpsParams.sBuffParams.dwBuffLength);
        dwDtaStatus = phDtaLibi_WriteNDEF(&sTagOpsParams);
        if(dwDtaStatus != DTASTATUS_SUCCESS)
        {
          phOsal_LogError((const uint8_t*)"DTALib>T3T:Device is not NDEF Complaint\n");
          break;
        }
      }
    }
    break;

    case 0x0003:
    {
      // TC_T3T_NDA_BV_1 test case
      phOsal_LogDebug((const uint8_t*)"DTALib> : Type 3 Tag Operation READ / WRITE to READ-ONLY Test Functionality");
      phOsal_LogDebug ((const uint8_t*)"DTALib>T3T:Perform NDEF Check \n");
      dwDtaStatus = phDtaLibi_CheckNDEF(&sTagOpsParams);
      if (dwDtaStatus != DTASTATUS_SUCCESS)
      {
        phOsal_LogError((const uint8_t*)"DTALib>T3T:Device is not NDEF Compliant\n");
        break;
      }
      dwDtaStatus = phDtaLibi_SetTagReadOnly(&sTagOpsParams);
      if (dwDtaStatus != DTASTATUS_SUCCESS)
      {
        phOsal_LogError((const uint8_t*)"DTALib> T3T:Error Could not set tag readonly !!\n");
        break;
      }
    }
    break;

    case 0x0000:
    case 0x0004:
    case 0x0005:
    case 0x0006:
    case 0x0007:
    case 0x0008:
    case 0x000A:
    case 0x000B:
    case PHDTALIB_PATTERN_NUM_ANALOG_TEST:
    {
      phOsal_LogDebug ((const uint8_t*)"DTALib>T3T:Perform NDEF Check for other PN \n");
      dwDtaStatus = phDtaLibi_CheckNDEF(&sTagOpsParams);
      if (dwDtaStatus != DTASTATUS_SUCCESS)
      {
        phOsal_LogError((const uint8_t*)"DTALib>T3T:Device is not NDEF Compliant\n");
        break;
      }
    }
    break;

    default:
      phOsal_LogError((const uint8_t*)"DTALib>T3T: Error Pattern Number not valid for T3T !! \n");
    break;
  }
  usleep(4000000);
  LOG_FUNCTION_EXIT;
  return dwDtaStatus;
}

#ifdef __cplusplus
}
#endif
