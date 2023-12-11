/*******************************************************************************
 *
 *  Copyright 2018 NXP
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
 ******************************************************************************/

#include <cutils/log.h>
#include <LsLib.h>
#include <LsClient.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

pLsc_Dwnld_Context_t gpLsc_Dwnld_Context = NULL;
static int32_t gTransceiveTimeout = 120000;
#ifdef JCOP3_WR
uint8_t Cmd_Buffer[64 * 1024];
static int32_t cmd_count = 0;
bool islastcmdLoad;
bool SendBack_cmds = false;
uint8_t* pBuffer;
#endif
bool mIsInit;
uint8_t Select_Rsp[1024];
uint8_t Jsbl_RefKey[256];
uint8_t Jsbl_keylen;
uint8_t StoreData[22];
int Select_Rsp_Len;
uint8_t lsVersionArr[2];
uint8_t tag42Arr[17];
uint8_t tag45Arr[9];
uint8_t lsExecuteResp[4];
uint8_t AID_ARRAY[22];
int32_t resp_len = 0;
FILE* fAID_MEM = NULL;
FILE* fLS_STATUS = NULL;
uint8_t lsGetStatusArr[2];
phNxpLs_data cmdApdu;
phNxpLs_data rspApdu;
static tLSC_STATUS LSC_Transceive(phNxpLs_data* pCmd, phNxpLs_data* pRsp);
tLSC_STATUS (*Applet_load_seqhandler[])(Lsc_ImageInfo_t* pContext,
                                        tLSC_STATUS status,
                                        Lsc_TranscieveInfo_t* pInfo) = {
    LSC_OpenChannel, LSC_SelectLsc, LSC_StoreData, LSC_loadapplet, NULL};

/*******************************************************************************
**
** Function:        initialize
**
** Description:     Initialize all member variables.
**                  native: Native data.
**
** Returns:         True if ok.
**
*******************************************************************************/
bool initialize (IChannel_t* channel)
{
    static const char fn [] = "Ala_initialize";

    ALOGD ("%s: enter", fn);

    gpLsc_Dwnld_Context = (pLsc_Dwnld_Context_t)malloc(sizeof(Lsc_Dwnld_Context_t));
    if(gpLsc_Dwnld_Context != NULL)
    {
        memset((void *)gpLsc_Dwnld_Context, 0, (uint32_t)sizeof(Lsc_Dwnld_Context_t));
    }
    else
    {
        ALOGD("%s: Memory allocation failed", fn);
        return (false);
    }
    gpLsc_Dwnld_Context->mchannel = channel;
    if((channel != NULL) &&
       (channel->open) != NULL)
    {
      if(channel->open() == STATUS_FAILED)
      {
        ALOGD ("%s: exit : channle open failed", fn);
        return false;
      }
    }
    else
    {
      ALOGD ("%s: exit : channel null", fn);
      return false;
    }
    mIsInit = true;
    ALOGD ("%s: exit : success", fn);
    return (true);
}

/*******************************************************************************
**
** Function:        finalize
**
** Description:     Release all resources.
**
** Returns:         None
**
*******************************************************************************/
void finalize() {
  static const char fn[] = "Lsc_finalize";
  ALOGD("%s: enter", fn);
  mIsInit = false;
  if (gpLsc_Dwnld_Context != NULL) {
    free(gpLsc_Dwnld_Context);
    gpLsc_Dwnld_Context = NULL;
  }
  ALOGD("%s: exit", fn);
}

/*******************************************************************************
**
** Function:        Perform_LSC
**
** Description:     Performs the LSC download sequence
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS Perform_LSC(const char* name, const char* dest,
                        const uint8_t* pdata, uint16_t len, uint8_t* respSW) {
  static const char fn[] = "Perform_LSC";
  tLSC_STATUS status = STATUS_FAILED;
  ALOGD("%s: enter; sha-len=%d", fn, len);
  //mIsInit = true; Changed here HARI
  if (mIsInit == false) {
    ALOGD("%s: LSC lib is not initialized", fn);
    status = STATUS_FAILED;
  } else if ((pdata == NULL) || (len == 0x00)) {
    ALOGD("%s: Invalid SHA-data", fn);
  } else {
    StoreData[0] = STORE_DATA_TAG;
    StoreData[1] = len;
    memcpy(&StoreData[2], pdata, len);
    status = LSC_update_seq_handler(Applet_load_seqhandler, name, dest);
    if ((status != STATUS_OK) && (lsExecuteResp[2] == 0x90) &&
        (lsExecuteResp[3] == 0x00)) {
      lsExecuteResp[2] = LS_ABORT_SW1;
      lsExecuteResp[3] = LS_ABORT_SW2;
    }
    memcpy(&respSW[0], &lsExecuteResp[0], 4);
    ALOGD("%s: lsExecuteScript Response SW=%2x%2x", fn, lsExecuteResp[2],
          lsExecuteResp[3]);
  }

  ALOGD("%s: exit; status=0x0%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_update_seq_handler
**
** Description:     Performs the LSC update sequence handler sequence
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_update_seq_handler(
    tLSC_STATUS (*seq_handler[])(Lsc_ImageInfo_t* pContext, tLSC_STATUS status,
                                 Lsc_TranscieveInfo_t* pInfo),
    const char* name, const char* dest) {
  static const char fn[] = "LSC_update_seq_handler";
  uint16_t seq_counter = 0;
  Lsc_ImageInfo_t update_info =
      (Lsc_ImageInfo_t)gpLsc_Dwnld_Context->Image_info;
  Lsc_TranscieveInfo_t trans_info =
      (Lsc_TranscieveInfo_t)gpLsc_Dwnld_Context->Transcv_Info;
  tLSC_STATUS status = STATUS_FAILED;
  ALOGD("%s: enter", fn);

  if (dest != NULL) {
    strcat(update_info.fls_RespPath, dest);
    ALOGD("Loader Service response data path/destination: %s", dest);
    update_info.bytes_wrote = 0xAA;
  } else {
    update_info.bytes_wrote = 0x55;
  }
  if ((LSC_UpdateExeStatus(LS_DEFAULT_STATUS)) != true) {
    return false;
  }
  // memcpy(update_info.fls_path, (char*)Lsc_path, sizeof(Lsc_path));
  strcat(update_info.fls_path, name);
  ALOGD("Selected applet to install is: %s", update_info.fls_path);

  while ((seq_handler[seq_counter]) != NULL) {
    status = STATUS_FAILED;
    status = (*(seq_handler[seq_counter]))(&update_info, status, &trans_info);
    if (STATUS_SUCCESS != status) {
      ALOGE("%s: exiting; status=0x0%X", fn, status);
      break;
    }
    seq_counter++;
  }

  LSC_CloseChannel(&update_info, STATUS_FAILED, &trans_info);
  ALOGE("%s: exit; status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_OpenChannel
**
** Description:     Creates the logical channel with lsc
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_OpenChannel(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                            Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_OpenChannel";
  tLSC_STATUS transStat = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  Os_info->channel_cnt = 0x00;
  ALOGD("%s: enter", fn);
  if (Os_info == NULL || pTranscv_Info == NULL) {
    ALOGD("%s: Invalid parameter", fn);
  } else {
    phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
    phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));

    cmdApdu.len = (int32_t)sizeof(OpenChannel);
    cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
    memcpy(cmdApdu.p_data, OpenChannel, cmdApdu.len);

    ALOGD("%s: Calling Secure Element Transceive", fn);
    transStat = LSC_Transceive(&cmdApdu, &rspApdu);

    if (transStat != STATUS_SUCCESS && (rspApdu.len < 0x03)) {
      if (rspApdu.len == 0x02)
        memcpy(&lsExecuteResp[2], &rspApdu.p_data[rspApdu.len - 2], 2);
      status = STATUS_FAILED;
      ALOGE("%s: SE transceive failed status = 0x%X", fn, status);
    } else if (((rspApdu.p_data[rspApdu.len - 2] != 0x90) &&
                (rspApdu.p_data[rspApdu.len - 1] != 0x00))) {
      memcpy(&lsExecuteResp[2], &rspApdu.p_data[rspApdu.len - 2], 2);
      status = STATUS_FAILED;
      ALOGE("%s: invalid response = 0x%X", fn, status);
    } else {
      uint8_t cnt = Os_info->channel_cnt;
      Os_info->Channel_Info[cnt].channel_id = rspApdu.p_data[rspApdu.len - 3];
      Os_info->Channel_Info[cnt].isOpend = true;
      Os_info->channel_cnt++;
      status = STATUS_OK;
    }
    phLS_free(cmdApdu.p_data);
  }

  ALOGE("%s: exit; status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_SelectLsc
**
** Description:     Creates the logical channel with lsc
**                  Channel_id will be used for any communication with Lsc
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_SelectLsc(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                          Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_SelectLsc";
  tLSC_STATUS transStat = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  unsigned long semsPresent = 1;

  if (Os_info == NULL || pTranscv_Info == NULL) {
    ALOGD("%s: Invalid parameter", fn);
  } else {
    phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
    phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));

  GetNxpNumValue(NAME_NXP_SEMS_SUPPORTED, &semsPresent, sizeof(semsPresent));

  if(semsPresent)
  {
    cmdApdu.len = (int32_t)(sizeof(SelectSEMS) + 1);
    cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
    cmdApdu.p_data[0] = Os_info->Channel_Info[0].channel_id;
    memcpy(&(cmdApdu.p_data[1]), SelectSEMS, sizeof(SelectSEMS));
  }
  else
  {
    /*p_data will have channel_id (1 byte) + SelectLsc APDU*/
    cmdApdu.len = (int32_t)(sizeof(SelectLsc) + 1);
    cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
    cmdApdu.p_data[0] = Os_info->Channel_Info[0].channel_id;
    memcpy(&(cmdApdu.p_data[1]), SelectLsc, sizeof(SelectLsc));
  }
  ALOGD("%s: Calling Secure Element Transceive with Loader service AID", fn);

  transStat = LSC_Transceive(&cmdApdu, &rspApdu);

  if (transStat != STATUS_SUCCESS && (rspApdu.len == 0x00)) {
    status = STATUS_FAILED;
    ALOGE("%s: SE transceive failed status = 0x%X", fn, status);
  } else if (((rspApdu.p_data[rspApdu.len - 2] == 0x90) &&
                  (rspApdu.p_data[rspApdu.len - 1] == 0x00))) {
    status = Process_SelectRsp(rspApdu.p_data, (rspApdu.len - 2));
    if (status != STATUS_OK) {
      ALOGE("%s: Select Lsc Rsp doesnt have a valid key; status = 0x%X", fn,
        status);
    }
    } else if (((rspApdu.p_data[rspApdu.len - 2] != 0x90))) {
    /*Copy the response SW in failure case*/
    memcpy(&lsExecuteResp[2], &(rspApdu.p_data[rspApdu.len - 2]), 2);
    }
    else {
    status = STATUS_FAILED;
    }
    if(status == STATUS_FAILED && semsPresent)
    {
      phLS_free(cmdApdu.p_data);
      cmdApdu.len = (int32_t)(sizeof(SelectSEMSUpdater) + 1);
      cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
      cmdApdu.p_data[0] = Os_info->Channel_Info[0].channel_id;
      memcpy(&(cmdApdu.p_data[1]), SelectSEMSUpdater, sizeof(SelectSEMSUpdater));
      transStat = LSC_Transceive(&cmdApdu, &rspApdu);

      if (transStat != STATUS_SUCCESS && (rspApdu.len == 0x00)) {
        status = STATUS_FAILED;
        ALOGE("%s: SE transceive failed status = 0x%X", fn, status);
      } else if (((rspApdu.p_data[rspApdu.len - 2] == 0x90) &&
                      (rspApdu.p_data[rspApdu.len - 1] == 0x00))) {
        status = Process_SelectRsp(rspApdu.p_data, (rspApdu.len - 2));
        if (status != STATUS_OK) {
          ALOGE("%s: Select Lsc Rsp doesnt have a valid key; status = 0x%X", fn,
            status);
          }
        } else if (((rspApdu.p_data[rspApdu.len - 2] != 0x90))) {
          /*Copy the response SW in failure case*/
          memcpy(&lsExecuteResp[2], &(rspApdu.p_data[rspApdu.len - 2]), 2);
        }
        else {
        status = STATUS_FAILED;
      }
    }
    phLS_free(cmdApdu.p_data);
  }
  ALOGE("%s: exit; status=0x%x", fn, status);
  return status;
}

/*******************************************************************************
**
** Function:        LSC_StoreData
**
** Description:     It is used to provide the LSC with an Unique
**                  Identifier of the Application that has triggered the LSC
*script.
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_StoreData(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                          Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_StoreData";
  tLSC_STATUS transStat = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  int32_t xx = 0, len = 0;
  ALOGD("%s: enter", fn);
  if (Os_info == NULL || pTranscv_Info == NULL) {
    ALOGD("%s: Invalid parameter", fn);
  } else {
    phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
    phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));
    cmdApdu.len = (int32_t)(5 + sizeof(StoreData));
    cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));

    len = StoreData[1] + 2;  //+2 offset is for tag value and length byte
    cmdApdu.p_data[xx++] =
        STORE_DATA_CLA | (Os_info->Channel_Info[0].channel_id);
    cmdApdu.p_data[xx++] = STORE_DATA_INS;
    cmdApdu.p_data[xx++] = 0x00;  // P1
    cmdApdu.p_data[xx++] = 0x00;  // P2
    cmdApdu.p_data[xx++] = len;
    memcpy(&(cmdApdu.p_data[xx]), StoreData, len);

    ALOGD("%s: Calling Secure Element Transceive", fn);
    transStat = LSC_Transceive(&cmdApdu, &rspApdu);

    if ((transStat != STATUS_SUCCESS) && (rspApdu.len == 0x00)) {
      status = STATUS_FAILED;
      ALOGE("%s: SE transceive failed status = 0x%X", fn, status);
    } else if ((rspApdu.p_data[rspApdu.len - 2] == 0x90) &&
               (rspApdu.p_data[rspApdu.len - 1] == 0x00)) {
      ALOGE("STORE CMD is successful");
      status = STATUS_SUCCESS;
    } else {
      /*Copy the response SW in failure case*/
      memcpy(&lsExecuteResp[2], &(rspApdu.p_data[rspApdu.len - 2]), 2);
      status = STATUS_FAILED;
    }
  }
  phLS_free(cmdApdu.p_data);
  ALOGE("%s: exit; status=0x%x", fn, status);
  return status;
}

/*******************************************************************************
**
** Function:        LSC_loadapplet
**
** Description:     Reads the script from the file and sent to Lsc
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_loadapplet(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                           Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_loadapplet";
  int wResult;
  int32_t wLen = 0;
  uint8_t temp_buf[1024];
  uint8_t len_byte = 0, offset = 0;
  Os_info->bytes_read = 0;
  bool reachEOFCheck = false;
  tLSC_STATUS tag40_found = STATUS_FAILED;
  if (Os_info->bytes_wrote == 0xAA) {
    Os_info->fResp = fopen(Os_info->fls_RespPath, "a+");
    if (Os_info->fResp == NULL) {
      ALOGE("Error opening response recording file <%s> for reading: %s",
            Os_info->fls_RespPath, strerror(errno));
      return status;
    }
    ALOGD("%s: Response OUT FILE path is successfully created", fn);
  } else {
    ALOGD("%s: Response Out file is optional as per input", fn);
  }
  ALOGD("%s: enter", fn);
  if (Os_info == NULL || pTranscv_Info == NULL) {
    ALOGE("%s: invalid parameter", fn);
    return status;
  }
  Os_info->fp = fopen(Os_info->fls_path, "r");

  if (Os_info->fp == NULL) {
    ALOGE("Error opening OS image file <%s> for reading: %s", Os_info->fls_path,
          strerror(errno));
    return status;
  }
  wResult = fseek(Os_info->fp, 0L, SEEK_END);
  if (wResult) {
    ALOGE("Error seeking end OS image file %s", strerror(errno));
    goto exit;
  }
  Os_info->fls_size = ftell(Os_info->fp);
  ALOGE("fls_size=%d", Os_info->fls_size);
  if (Os_info->fls_size < 0) {
    ALOGE("Error ftelling file %s", strerror(errno));
    goto exit;
  }
  wResult = fseek(Os_info->fp, 0L, SEEK_SET);
  if (wResult) {
    ALOGE("Error seeking start image file %s", strerror(errno));
    goto exit;
  }
  status = LSC_Check_KeyIdentifier(Os_info, status, pTranscv_Info, NULL,
                                   STATUS_FAILED, 0);
  if (status != STATUS_OK) {
    goto exit;
  }
  while (!feof(Os_info->fp) && (Os_info->bytes_read < Os_info->fls_size)) {
    len_byte = 0x00;
    offset = 0;
    /*Check if the certificate/ is verified or not*/
    if (status != STATUS_OK) {
      goto exit;
    }
    memset(temp_buf, 0, sizeof(temp_buf));
    ALOGE("%s; Start of line processing", fn);
    status = LSC_ReadScript(Os_info, temp_buf);
    if (status != STATUS_OK) {
      goto exit;
    } else if (status == STATUS_OK) {
      /*Reset the flag in case further commands exists*/
      reachEOFCheck = false;
    }
    if (temp_buf[offset] == TAG_LSC_CMD_ID) {
      /*
       * start sending the packet to Lsc
       * */
      offset = offset + 1;
      len_byte = Numof_lengthbytes(&temp_buf[offset], &wLen);
      /*If the len data not present or
       * len is less than or equal to 32*/
      if ((len_byte == 0) || (wLen <= 32))

      {
        ALOGE("Invalid length zero");
        goto exit;
      } else {
        tag40_found = STATUS_OK;
        offset = offset + len_byte;
        pTranscv_Info->sSendlength = wLen;
        memcpy(pTranscv_Info->sSendData, &temp_buf[offset], wLen);
      }
      status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Comm);
      if (status != STATUS_OK) {
        /*When the switching of LS 6320 case*/
        if (status == STATUS_FILE_NOT_FOUND) {
          /*When 6320 occurs close the existing channels*/
          LSC_CloseChannel(Os_info, status, pTranscv_Info);

          status = STATUS_FAILED;
          status = LSC_OpenChannel(Os_info, status, pTranscv_Info);
          if (status == STATUS_OK) {
            ALOGD("SUCCESS:Post Switching LS open channel");
            status = STATUS_FAILED;
            status = LSC_SelectLsc(Os_info, status, pTranscv_Info);
            if (status == STATUS_OK) {
              ALOGD("SUCCESS:Post Switching LS select");
              status = STATUS_FAILED;
              status = LSC_StoreData(Os_info, status, pTranscv_Info);
              if (status == STATUS_OK) {
                /*Enable certificate and signature verification*/
                tag40_found = STATUS_OK;
                lsExecuteResp[2] = 0x90;
                lsExecuteResp[3] = 0x00;
                reachEOFCheck = true;
                continue;
              }
              ALOGE("Post Switching LS store data failure");
            }
            ALOGE("Post Switching LS select failure");
          }
          ALOGE("Post Switching LS failure");
        }
        ALOGE("Sending packet to lsc failed");
        goto exit;
      }
    } else if ((temp_buf[offset] == (0x7F)) &&
               (temp_buf[offset + 1] == (0x21))) {
      ALOGD("TAGID: Encountered again certificate tag 7F21");
      if (tag40_found == STATUS_OK) {
        ALOGD("2nd Script processing starts with reselect");
        status = STATUS_FAILED;
        status = LSC_SelectLsc(Os_info, status, pTranscv_Info);
        if (status == STATUS_OK) {
          ALOGD("2nd Script select success next store data command");
          status = STATUS_FAILED;
          status = LSC_StoreData(Os_info, status, pTranscv_Info);
          if (status == STATUS_OK) {
            ALOGD(
                "2nd Script store data success next certificate verification");
            offset = offset + 2;
            len_byte = Numof_lengthbytes(&temp_buf[offset], &wLen);
            status = LSC_Check_KeyIdentifier(Os_info, status, pTranscv_Info,
                                             temp_buf, STATUS_OK,
                                             wLen + len_byte + 2);
          }
        }
        /*If the certificate and signature is verified*/
        if (status == STATUS_OK) {
          /*If the certificate is verified for 6320 then new
           * script starts*/
          tag40_found = STATUS_FAILED;
        }
        /*If the certificate or signature verification failed*/
        else {
          goto exit;
        }
      }
      /*Already certificate&Sginature verified previously skip 7f21& tag 60*/
      else {
        memset(temp_buf, 0, sizeof(temp_buf));
        status = LSC_ReadScript(Os_info, temp_buf);
        if (status != STATUS_OK) {
          ALOGE("%s; Next Tag has to TAG 60 not found", fn);
          goto exit;
        }
        if (temp_buf[offset] == TAG_JSBL_HDR_ID)
          continue;
        else
          goto exit;
      }
    } else {
      /*
       * Invalid packet received in between stop processing packet
       * return failed status
       * */
      status = STATUS_FAILED;
      break;
    }
  }
  if (Os_info->bytes_wrote == 0xAA) {
    fclose(Os_info->fResp);
  }
  LSC_UpdateExeStatus(LS_SUCCESS_STATUS);
  wResult = fclose(Os_info->fp);
  ALOGE("%s exit;End of Load Applet; status=0x%x", fn, status);
  return status;
exit:
  wResult = fclose(Os_info->fp);
  if (Os_info->bytes_wrote == 0xAA) {
    fclose(Os_info->fResp);
  }
  /*Script ends with SW 6320 and reached END OF FILE*/
  if (reachEOFCheck == true) {
    status = STATUS_OK;
    LSC_UpdateExeStatus(LS_SUCCESS_STATUS);
  }
  ALOGE("%s close fp and exit; status= 0x%X", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_Check_KeyIdentifier
**
** Description:     Checks and validates certificate
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_Check_KeyIdentifier(Lsc_ImageInfo_t* Os_info,
                                    tLSC_STATUS status,
                                    Lsc_TranscieveInfo_t* pTranscv_Info,
                                    uint8_t* temp_buf, tLSC_STATUS flag,
                                    int32_t wNewLen) {
  static const char fn[] = "LSC_Check_KeyIdentifier";
  uint16_t offset = 0x00, len_byte = 0;
  status = STATUS_FAILED;
  uint8_t read_buf[1024];
  int32_t wLen;
  uint8_t certf_found = STATUS_FAILED;
  uint8_t sign_found = STATUS_FAILED;
  ALOGD("%s: enter", fn);

  while (!feof(Os_info->fp) && (Os_info->bytes_read < Os_info->fls_size)) {
    offset = 0x00;
    wLen = 0;
    if (flag == STATUS_OK) {
      /*If the 7F21 TAG is already read: After TAG 40*/
      memcpy(read_buf, temp_buf, wNewLen);
      status = STATUS_OK;
      flag = STATUS_FAILED;
    } else {
      /*If the 7F21 TAG is not read: Before TAG 40*/
      status = LSC_ReadScript(Os_info, read_buf);
    }
    if (status != STATUS_OK) return status;
    if (STATUS_OK ==
        Check_Complete_7F21_Tag(Os_info, pTranscv_Info, read_buf, &offset)) {
      ALOGD("%s: Certificate is verified", fn);
      certf_found = STATUS_OK;
      break;
    }
    /*The Loader Service Client ignores all subsequent commands starting by tag
     * �7F21� or tag �60� until the first command starting by tag �40� is
     * found*/
    else if (((read_buf[offset] == TAG_LSC_CMD_ID) &&
              (certf_found != STATUS_OK))) {
      ALOGE("%s: NOT FOUND Root entity identifier's certificate", fn);
      status = STATUS_FAILED;
      return status;
    }
  }
  memset(read_buf, 0, sizeof(read_buf));
  if (certf_found == STATUS_OK) {
    offset = 0x00;
    wLen = 0;
    status = LSC_ReadScript(Os_info, read_buf);
    if (status != STATUS_OK)
      return status;
    else
      status = STATUS_FAILED;

    if ((read_buf[offset] == TAG_JSBL_HDR_ID) &&
        (certf_found != STATUS_FAILED) && (sign_found != STATUS_OK))

    {
      // TODO check the SElect cmd response and return status accordingly
      ALOGD("TAGID: TAG_JSBL_HDR_ID");
      offset = offset + 1;
      len_byte = Numof_lengthbytes(&read_buf[offset], &wLen);
      offset = offset + len_byte;
      if (read_buf[offset] == TAG_SIGNATURE_ID) {
        offset = offset + 1;
        len_byte = Numof_lengthbytes(&read_buf[offset], &wLen);
        offset = offset + len_byte;
        ALOGE("TAGID: TAG_SIGNATURE_ID");

        pTranscv_Info->sSendlength = wLen + 5;

        pTranscv_Info->sSendData[0] = 0x00;
        pTranscv_Info->sSendData[1] = 0xA0;
        pTranscv_Info->sSendData[2] = 0x00;
        pTranscv_Info->sSendData[3] = 0x00;
        pTranscv_Info->sSendData[4] = wLen;

        memcpy(&(pTranscv_Info->sSendData[5]), &read_buf[offset], wLen);
        ALOGE("%s: start transceive for length %ld", fn,
              (long)pTranscv_Info->sSendlength);
        status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Sign);
        if (status != STATUS_OK) {
          return status;
        } else {
          sign_found = STATUS_OK;
        }
      }
    } else if (read_buf[offset] != TAG_JSBL_HDR_ID) {
      status = STATUS_FAILED;
    }
  } else {
    ALOGE("%s : Exit certificate verification failed", fn);
  }

  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_ReadScript
**
** Description:     Reads the current line if the script
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_ReadScript(Lsc_ImageInfo_t* Os_info, uint8_t* read_buf) {
  static const char fn[] = "LSC_ReadScript";
  int32_t wCount, wLen, wIndex = 0;
  uint8_t len_byte = 0;
  int wResult = 0;
  tLSC_STATUS status = STATUS_FAILED;
  int32_t lenOff = 1;
  bool isMetaDatapresent = false;

  ALOGD("%s: enter", fn);

  for (wCount = 0; (wCount < 2 && !feof(Os_info->fp)); wCount++, wIndex++) {
    wResult = FSCANF_BYTE(Os_info->fp, "%2X", (unsigned int*)&read_buf[wIndex]);

    if(wResult == 0)
    {
      char metaString[MAX_META_STRING_SIZE];
      char *ptr = fgets(metaString, sizeof(metaString), Os_info->fp);
      if(ptr != NULL)
      {
        isMetaDatapresent = true;
        ALOGD("MetaData = %s",ptr);
        wCount = 0;
        wIndex = 0;
      }
      else
      {
         break;
      }
    }
    else
    {
      if(isMetaDatapresent)
      {
        isMetaDatapresent = false;
        wCount = 0;
        wIndex = 0;
        read_buf[0] = read_buf[1];
        ALOGD("End of MetaData");
      }
    }
  }
  if (wResult == 0) return STATUS_FAILED;

  Os_info->bytes_read = Os_info->bytes_read + (wCount * 2);

  if ((read_buf[0] == 0x7f) && (read_buf[1] == 0x21)) {
    for (wCount = 0; (wCount < 1 && !feof(Os_info->fp)); wCount++, wIndex++) {
      wResult =
          FSCANF_BYTE(Os_info->fp, "%2X", (unsigned int*)&read_buf[wIndex]);
    }
    if (wResult == 0) {
      ALOGE("%s: Exit Read Script failed in 7F21 ", fn);
      return STATUS_FAILED;
    }
    /*Read_Script from wCount*2 to wCount*1 */
    Os_info->bytes_read = Os_info->bytes_read + (wCount * 2);
    lenOff = 2;
  } else if ((read_buf[0] == 0x40) || (read_buf[0] == 0x60)) {
    lenOff = 1;
  }
  /*If TAG is neither 7F21 nor 60 nor 40 then ABORT execution*/
  else {
    ALOGE("Invalid TAG 0x%X found in the script", read_buf[0]);
    return STATUS_FAILED;
  }

  if (read_buf[lenOff] == 0x00) {
    ALOGE("Invalid length zero");
    len_byte = 0x00;
    return STATUS_FAILED;
  } else if ((read_buf[lenOff] & 0x80) == 0x80) {
    len_byte = read_buf[lenOff] & 0x0F;
    len_byte = len_byte + 1;  // 1 byte added for byte 0x81

    ALOGD("%s: Length byte Read from 0x80 is 0x%x ", fn, len_byte);

    if (len_byte == 0x02) {
      for (wCount = 0; (wCount < 1 && !feof(Os_info->fp)); wCount++, wIndex++) {
        wResult =
            FSCANF_BYTE(Os_info->fp, "%2X", (unsigned int*)&read_buf[wIndex]);
      }
      if (wResult == 0) {
        ALOGE("%s: Exit Read Script failed in length 0x02 ", fn);
        return STATUS_FAILED;
      }

      wLen = read_buf[lenOff + 1];
      Os_info->bytes_read = Os_info->bytes_read + (wCount * 2);
      ALOGD("%s: Length of Read Script in len_byte= 0x02 is 0x%x ", fn, wLen);
    } else if (len_byte == 0x03) {
      for (wCount = 0; (wCount < 2 && !feof(Os_info->fp)); wCount++, wIndex++) {
        wResult =
            FSCANF_BYTE(Os_info->fp, "%2X", (unsigned int*)&read_buf[wIndex]);
      }
      if (wResult == 0) {
        ALOGE("%s: Exit Read Script failed in length 0x03 ", fn);
        return STATUS_FAILED;
      }

      Os_info->bytes_read = Os_info->bytes_read + (wCount * 2);
      wLen = read_buf[lenOff + 1];  // Length of the packet send to LSC
      wLen = ((wLen << 8) | (read_buf[lenOff + 2]));
      ALOGD("%s: Length of Read Script in len_byte= 0x03 is 0x%x ", fn, wLen);
    } else {
      /*Need to provide the support if length is more than 2 bytes*/
      ALOGE("Length recived is greater than 3");
      return STATUS_FAILED;
    }
  } else {
    len_byte = 0x01;
    wLen = read_buf[lenOff];
    ALOGE("%s: Length of Read Script in len_byte= 0x01 is 0x%x ", fn, wLen);
  }

  for (wCount = 0; (wCount < wLen && !feof(Os_info->fp)); wCount++, wIndex++) {
    wResult = FSCANF_BYTE(Os_info->fp, "%2X", (unsigned int*)&read_buf[wIndex]);
  }

  if (wResult == 0) {
    ALOGE("%s: Exit Read Script failed in fscanf function ", fn);
    return status;
  } else {
    Os_info->bytes_read =
        Os_info->bytes_read + (wCount * 2) + 1;  // not sure why 2 added
    status = STATUS_OK;
  }

  ALOGD("%s: exit: status=0x%x; Num of bytes read=%d and index=%d", fn, status,
        Os_info->bytes_read, wIndex);

  return status;
}

/*******************************************************************************
**
** Function:        LSC_SendtoEse
**
** Description:     It is used to send the packet to p61
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_SendtoEse(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                          Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_SendtoEse";
  bool chanl_open_cmd = false;
  tLSC_STATUS transStat = STATUS_FAILED;
  status = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  int32_t recvBufferActualSize = 0;
  ALOGD("%s: enter", fn);
#ifdef JCOP3_WR
  /*
   * Bufferize_load_cmds function is implemented in JCOP
   * */
  status = Bufferize_load_cmds(Os_info, status, pTranscv_Info);
  if (status != STATUS_FAILED) {
#endif
    if (pTranscv_Info->sSendData[1] == 0x70) {
      if (pTranscv_Info->sSendData[2] == 0x00) {
        ALOGE("Channel open");
        chanl_open_cmd = true;
      } else {
        ALOGE("Channel close");
        for (uint8_t cnt = 0; cnt < Os_info->channel_cnt; cnt++) {
          if (Os_info->Channel_Info[cnt].channel_id ==
              pTranscv_Info->sSendData[3]) {
            ALOGE("Closed channel id = 0x0%x",
                  Os_info->Channel_Info[cnt].channel_id);
            Os_info->Channel_Info[cnt].isOpend = false;
          }
        }
      }
    }
    phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
    phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));

    cmdApdu.len = (int32_t)(pTranscv_Info->sSendlength);
    cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
    memcpy(cmdApdu.p_data, pTranscv_Info->sSendData, cmdApdu.len);

    transStat = LSC_Transceive(&cmdApdu, &rspApdu);

    if (transStat != STATUS_SUCCESS) {
      ALOGE("%s: Transceive failed; status=0x%X", fn, transStat);
    } else {
      if (chanl_open_cmd == true) {
        if ((rspApdu.len == 0x03) &&
            ((rspApdu.p_data[rspApdu.len - 2] == 0x90) &&
             (rspApdu.p_data[rspApdu.len - 1] == 0x00))) {
          ALOGE("open channel success");
          uint8_t cnt = Os_info->channel_cnt;
          Os_info->Channel_Info[cnt].channel_id =
              rspApdu.p_data[rspApdu.len - 3];
          Os_info->Channel_Info[cnt].isOpend = true;
          Os_info->channel_cnt++;
        } else {
          ALOGE("channel open faield");
        }
      }
      memcpy(pTranscv_Info->sRecvData, rspApdu.p_data, rspApdu.len);
      status = Process_EseResponse(pTranscv_Info, rspApdu.len, Os_info);
    }
#ifdef JCOP3_WR
  } else if (SendBack_cmds == false) {
    /*
     * Workaround for issue in JCOP
     * Send the fake response back
     * */
    recvBufferActualSize = 0x03;
    pTranscv_Info->sRecvData[0] = 0x00;
    pTranscv_Info->sRecvData[1] = 0x90;
    pTranscv_Info->sRecvData[2] = 0x00;
    status = Process_EseResponse(pTranscv_Info, recvBufferActualSize, Os_info);
  } else {
    if (islastcmdLoad == true) {
      status = Send_Backall_Loadcmds(Os_info, status, pTranscv_Info);
      SendBack_cmds = false;
    } else {
      memset(Cmd_Buffer, 0, sizeof(Cmd_Buffer));
      SendBack_cmds = false;
      status = STATUS_FAILED;
    }
  }
#endif
  phLS_free(cmdApdu.p_data);
  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}

/*******************************************************************************
**
** Function:        LSC_SendtoLsc
**
** Description:     It is used to forward the packet to Lsc
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_SendtoLsc(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                          Lsc_TranscieveInfo_t* pTranscv_Info,
                          Ls_TagType tType) {
  static const char fn[] = "LSC_SendtoLsc";
  tLSC_STATUS transStat = STATUS_FAILED;
  status = STATUS_FAILED;

  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  ALOGD("%s: enter", fn);
  pTranscv_Info->sSendData[0] = (0x80 | Os_info->Channel_Info[0].channel_id);
  pTranscv_Info->timeout = gTransceiveTimeout;
  pTranscv_Info->sRecvlength = 1024;

  phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
  phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));
  cmdApdu.len = pTranscv_Info->sSendlength;
  cmdApdu.p_data = (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
  memcpy(cmdApdu.p_data, pTranscv_Info->sSendData, cmdApdu.len);

  transStat = LSC_Transceive(&cmdApdu, &rspApdu);

  if (transStat != STATUS_SUCCESS) {
    ALOGE("%s: Transceive failed; status=0x%X", fn, transStat);
  } else {
    memcpy(pTranscv_Info->sRecvData, rspApdu.p_data, rspApdu.len);

    status = LSC_ProcessResp(Os_info, rspApdu.len, pTranscv_Info, tType);
  }
  phLS_free(cmdApdu.p_data);
  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_CloseChannel
**
** Description:     Closes the previously opened logical channel
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_CloseChannel(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                             Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "LSC_CloseChannel";
  status = STATUS_FAILED;
  tLSC_STATUS transStat = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  uint8_t xx = 0;
  uint8_t cnt = 0;
  ALOGD("%s: enter", fn);

  if (Os_info == NULL || pTranscv_Info == NULL) {
    ALOGE("Invalid parameter");
  } else {
    for (cnt = 0; (cnt < Os_info->channel_cnt); cnt++) {
      phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
      phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));

      cmdApdu.len = 5;
      cmdApdu.p_data =
          (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
      if (Os_info->Channel_Info[cnt].isOpend == false) continue;
      xx = 0;
      cmdApdu.p_data[xx++] = Os_info->Channel_Info[cnt].channel_id;
      cmdApdu.p_data[xx++] = 0x70;
      cmdApdu.p_data[xx++] = 0x80;
      cmdApdu.p_data[xx++] = Os_info->Channel_Info[cnt].channel_id;
      cmdApdu.p_data[xx++] = 0x00;

      transStat = LSC_Transceive(&cmdApdu, &rspApdu);

      if (transStat != STATUS_SUCCESS && rspApdu.len < 2) {
        ALOGE("%s: Transceive failed; status=0x%X", fn, transStat);
      } else if ((rspApdu.p_data[rspApdu.len - 2] == 0x90) &&
                 (rspApdu.p_data[rspApdu.len - 1] == 0x00)) {
        ALOGE("Close channel id = 0x0%x is success",
              Os_info->Channel_Info[cnt].channel_id);
        status = STATUS_OK;
      } else {
        ALOGE("Close channel id = 0x0%x is failed",
              Os_info->Channel_Info[cnt].channel_id);
      }
    }
  }
  phLS_free(cmdApdu.p_data);
  ALOGD("%s: exit; status=0x0%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        LSC_ProcessResp
**
** Description:     Process the response packet received from Lsc
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_ProcessResp(Lsc_ImageInfo_t* image_info, int32_t recvlen,
                            Lsc_TranscieveInfo_t* trans_info,
                            Ls_TagType tType) {
  static const char fn[] = "LSC_ProcessResp";
  tLSC_STATUS status = STATUS_FAILED;
  static int32_t temp_len = 0;
  uint8_t* RecvData = trans_info->sRecvData;
  char sw[2];

  ALOGD("%s: enter", fn);

  if (RecvData == NULL && recvlen == 0x00) {
    ALOGE("%s: Invalid parameter: status=0x%x", fn, status);
    return status;
  } else if (recvlen >= 2) {
    sw[0] = RecvData[recvlen - 2];
    sw[1] = RecvData[recvlen - 1];
  } else {
    ALOGE("%s: Invalid response; status=0x%x", fn, status);
    return status;
  }
  /*Update the Global variable for storing response length*/
  resp_len = recvlen;
  if ((sw[0] != 0x63)) {
    lsExecuteResp[2] = sw[0];
    lsExecuteResp[3] = sw[1];
    ALOGD("%s: Process Response SW; status = 0x%x", fn, sw[0]);
    ALOGD("%s: Process Response SW; status = 0x%x", fn, sw[1]);
  }
  if ((recvlen == 0x02) && (sw[0] == 0x90) && (sw[1] == 0x00)) {
    tLSC_STATUS wStatus = STATUS_FAILED;
    ALOGE("%s: Before Write Response", fn);
    wStatus = Write_Response_To_OutFile(image_info, RecvData, recvlen, tType);
    if (wStatus != STATUS_FAILED) status = STATUS_OK;
  } else if ((recvlen > 0x02) && (sw[0] == 0x90) && (sw[1] == 0x00)) {
    tLSC_STATUS wStatus = STATUS_FAILED;
    ALOGE("%s: Before Write Response", fn);
    wStatus = Write_Response_To_OutFile(image_info, RecvData, recvlen, tType);
    if (wStatus != STATUS_FAILED) status = STATUS_OK;
  }

  else if ((recvlen > 0x02) && (sw[0] == 0x63) && (sw[1] == 0x10)) {
    if (temp_len != 0) {
      memcpy((trans_info->sTemp_recvbuf + temp_len), RecvData, (recvlen - 2));
      trans_info->sSendlength = temp_len + (recvlen - 2);
      memcpy(trans_info->sSendData, trans_info->sTemp_recvbuf,
             trans_info->sSendlength);
      temp_len = 0;
    } else {
      memcpy(trans_info->sSendData, RecvData, (recvlen - 2));
      trans_info->sSendlength = recvlen - 2;
    }
    status = LSC_SendtoEse(image_info, status, trans_info);
  } else if ((recvlen > 0x02) && (sw[0] == 0x63) && (sw[1] == 0x20)) {
    uint8_t respLen = 0;
    int32_t wStatus = 0;

    AID_ARRAY[0] = recvlen + 3;
    AID_ARRAY[1] = 00;
    AID_ARRAY[2] = 0xA4;
    AID_ARRAY[3] = 0x04;
    AID_ARRAY[4] = 0x00;
    AID_ARRAY[5] = recvlen - 2;
    memcpy(&AID_ARRAY[6], &RecvData[0], recvlen - 2);
    //memcpy(&ArrayOfAIDs[2][0], &AID_ARRAY[0], recvlen + 4);
    memcpy(&ArrayOfAIDs[LS_SELF_UPDATE_AID_IDX][0], &AID_ARRAY[0], recvlen + 4);

    fAID_MEM = fopen(AID_MEM_PATH[gpLsc_Dwnld_Context->
      mchannel->getInterfaceInfo()], "w");

    if (fAID_MEM == NULL) {
      ALOGE("Error opening AID data for writing: %s", strerror(errno));
      return status;
    }

    /*Updating the AID_MEM with new value into AID file*/
    while (respLen <= (recvlen + 4)) {
      wStatus = fprintf(fAID_MEM, "%2x", AID_ARRAY[respLen++]);
      if (wStatus != 2) {
        ALOGE("%s: Invalid Response during fprintf; status=0x%x", fn, status);
        fclose(fAID_MEM);
        break;
      }
    }
    if (wStatus == 2) {
      status = STATUS_FILE_NOT_FOUND;
    } else {
      status = STATUS_FAILED;
    }
  } else if ((recvlen >= 0x02) &&
             ((sw[0] != 0x90) && (sw[0] != 0x63) && (sw[0] != 0x61))) {
    tLSC_STATUS wStatus = STATUS_FAILED;
    wStatus = Write_Response_To_OutFile(image_info, RecvData, recvlen, tType);
  }
  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        Process_EseResponse
**
** Description:     It is used to process the received response packet from ESE
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS Process_EseResponse(Lsc_TranscieveInfo_t* pTranscv_Info,
                                int32_t recv_len, Lsc_ImageInfo_t* Os_info) {
  static const char fn[] = "Process_EseResponse";
  tLSC_STATUS status = STATUS_OK;
  uint8_t xx = 0;
  ALOGD("%s: enter", fn);

  pTranscv_Info->sSendData[xx++] =
      (CLA_BYTE | Os_info->Channel_Info[0].channel_id);
  pTranscv_Info->sSendData[xx++] = 0xA2;

  if (recv_len <= 0xFF) {
    pTranscv_Info->sSendData[xx++] = 0x80;
    pTranscv_Info->sSendData[xx++] = 0x00;
    pTranscv_Info->sSendData[xx++] = (uint8_t)recv_len;
    memcpy(&(pTranscv_Info->sSendData[xx]), pTranscv_Info->sRecvData, recv_len);
    pTranscv_Info->sSendlength = xx + recv_len;
    status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Comm);
  } else {
    while (recv_len > MAX_SIZE) {
      xx = PARAM_P1_OFFSET;
      pTranscv_Info->sSendData[xx++] = 0x00;
      pTranscv_Info->sSendData[xx++] = 0x00;
      pTranscv_Info->sSendData[xx++] = MAX_SIZE;
      recv_len = recv_len - MAX_SIZE;
      memcpy(&(pTranscv_Info->sSendData[xx]), pTranscv_Info->sRecvData,
             MAX_SIZE);
      pTranscv_Info->sSendlength = xx + MAX_SIZE;
      /*Need not store Process eSE response's response in the out file so
       * LS_Comm = 0*/
      status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Comm);
      if (status != STATUS_OK) {
        ALOGE("Sending packet to Lsc failed: status=0x%x", status);
        return status;
      }
    }
    xx = PARAM_P1_OFFSET;
    pTranscv_Info->sSendData[xx++] = LAST_BLOCK;
    pTranscv_Info->sSendData[xx++] = 0x01;
    pTranscv_Info->sSendData[xx++] = recv_len;
    memcpy(&(pTranscv_Info->sSendData[xx]), pTranscv_Info->sRecvData, recv_len);
    pTranscv_Info->sSendlength = xx + recv_len;
    status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Comm);
  }
  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}
/*******************************************************************************
**
** Function:        Process_SelectRsp
**
** Description:     It is used to process the received response for SELECT LSC
*cmd
**
** Returns:         Success if ok.
**
*******************************************************************************/
tLSC_STATUS Process_SelectRsp(uint8_t* Recv_data, int32_t Recv_len) {
  (void)Recv_len;
  static const char fn[] = "Process_SelectRsp";
  tLSC_STATUS status = STATUS_FAILED;
  int i = 0, len = 0;
  ALOGE("%s: enter", fn);

  if (Recv_data[i] == TAG_SELECT_ID) {
    ALOGD("TAG: TAG_SELECT_ID");
    i = i + 1;
    len = Recv_data[i];
    i = i + 1;
    if (Recv_data[i] == TAG_LSC_ID) {
      ALOGD("TAG: TAG_LSC_ID");
      i = i + 1;
      len = Recv_data[i];
      i = i + 1 + len;  // points to next tag name A5
      // points to TAG 9F08 for LS application version
      if ((Recv_data[i] == TAG_LS_VER1) && (Recv_data[i + 1] == TAG_LS_VER2)) {
        uint8_t lsaVersionLen = 0;
        ALOGD("TAG: TAG_LS_APPLICATION_VER");

        i = i + 2;
        lsaVersionLen = Recv_data[i];
        // points to TAG 9F08 LS application version
        i = i + 1;
        memcpy(lsVersionArr, &Recv_data[i], lsaVersionLen);

        // points to Identifier of the Root Entity key set identifier
        i = i + lsaVersionLen;

        if (Recv_data[i] == TAG_RE_KEYID) {
          uint8_t rootEntityLen = 0;
          i = i + 1;
          rootEntityLen = Recv_data[i];

          i = i + 1;
          if (Recv_data[i] == TAG_LSRE_ID) {
            uint8_t tag42Len = 0;
            i = i + 1;
            tag42Len = Recv_data[i];
            // copy the data including length
            memcpy(tag42Arr, &Recv_data[i], tag42Len + 1);
            i = i + tag42Len + 1;
            ALOGD("tag42Arr %s", tag42Arr);
            if (Recv_data[i] == TAG_LSRE_SIGNID) {
              uint8_t tag45Len = Recv_data[i + 1];
              memcpy(tag45Arr, &Recv_data[i + 1], tag45Len + 1);
              status = STATUS_OK;
            } else {
              ALOGE(
                  "Invalid Root entity for TAG 45 = 0x%x; "
                  "status=0x%x",
                  Recv_data[i], status);
              return status;
            }
          } else {
            ALOGE(
                "Invalid Root entity for TAG 42 = 0x%x; "
                "status=0x%x",
                Recv_data[i], status);
            return status;
          }
        } else {
          ALOGE(
              "Invalid Root entity key set TAG ID = 0x%x; "
              "status=0x%x",
              Recv_data[i], status);
          return status;
        }
      }
    } else {
      ALOGE("Invalid Loader Service AID TAG ID = 0x%x; status=0x%x",
            Recv_data[i], status);
      return status;
    }
  } else {
    ALOGE("Invalid FCI TAG = 0x%x; status=0x%x", Recv_data[i], status);
    return status;
  }
  ALOGE("%s: Exiting status = 0x%x", fn, status);
  return status;
}

#ifdef JCOP3_WR
tLSC_STATUS Bufferize_load_cmds(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                                Lsc_TranscieveInfo_t* pTranscv_Info) {
  (void)Os_info;
  static const char fn[] = "Bufferize_load_cmds";
  uint8_t Param_P2;
  status = STATUS_FAILED;

  if (cmd_count == 0x00) {
    if ((pTranscv_Info->sSendData[1] == INSTAL_LOAD_ID) &&
        (pTranscv_Info->sSendData[2] == PARAM_P1_OFFSET) &&
        (pTranscv_Info->sSendData[3] == 0x00)) {
      ALOGE("BUffer: install for load");
      pBuffer[0] = pTranscv_Info->sSendlength;
      memcpy(&pBuffer[1], &(pTranscv_Info->sSendData[0]),
             pTranscv_Info->sSendlength);
      pBuffer = pBuffer + pTranscv_Info->sSendlength + 1;
      cmd_count++;
    } else {
      /*
       * Do not buffer this cmd
       * Send this command to eSE
       * */
      status = STATUS_OK;
    }

  } else {
    Param_P2 = cmd_count - 1;
    if ((pTranscv_Info->sSendData[1] == LOAD_CMD_ID) &&
        (pTranscv_Info->sSendData[2] == LOAD_MORE_BLOCKS) &&
        (pTranscv_Info->sSendData[3] == Param_P2)) {
      ALOGE("BUffer: load");
      pBuffer[0] = pTranscv_Info->sSendlength;
      memcpy(&pBuffer[1], &(pTranscv_Info->sSendData[0]),
             pTranscv_Info->sSendlength);
      pBuffer = pBuffer + pTranscv_Info->sSendlength + 1;
      cmd_count++;
    } else if ((pTranscv_Info->sSendData[1] == LOAD_CMD_ID) &&
               (pTranscv_Info->sSendData[2] == LOAD_LAST_BLOCK) &&
               (pTranscv_Info->sSendData[3] == Param_P2)) {
      ALOGE("BUffer: last load");
      SendBack_cmds = true;
      pBuffer[0] = pTranscv_Info->sSendlength;
      memcpy(&pBuffer[1], &(pTranscv_Info->sSendData[0]),
             pTranscv_Info->sSendlength);
      pBuffer = pBuffer + pTranscv_Info->sSendlength + 1;
      cmd_count++;
      islastcmdLoad = true;
    } else {
      ALOGE("BUffer: Not a load cmd");
      SendBack_cmds = true;
      pBuffer[0] = pTranscv_Info->sSendlength;
      memcpy(&pBuffer[1], &(pTranscv_Info->sSendData[0]),
             pTranscv_Info->sSendlength);
      pBuffer = pBuffer + pTranscv_Info->sSendlength + 1;
      islastcmdLoad = false;
      cmd_count++;
    }
  }
  ALOGE("%s: exit; status=0x%x", fn, status);
  return status;
}

tLSC_STATUS Send_Backall_Loadcmds(Lsc_ImageInfo_t* Os_info, tLSC_STATUS status,
                                  Lsc_TranscieveInfo_t* pTranscv_Info) {
  static const char fn[] = "Send_Backall_Loadcmds";
  tLSC_STATUS transStat = STATUS_FAILED;
  status = STATUS_FAILED;
  phNxpLs_data cmdApdu;
  phNxpLs_data rspApdu;
  int32_t recvBufferActualSize = 0;
  ALOGD("%s: enter", fn);
  pBuffer = Cmd_Buffer;  // Points to start of first cmd to send
  if (cmd_count == 0x00) {
    ALOGE("No cmds stored to send to eSE");
  } else {
    while (cmd_count-- > 0) {
      phLS_memset(&cmdApdu, 0x00, sizeof(phNxpLs_data));
      phLS_memset(&rspApdu, 0x00, sizeof(phNxpLs_data));

      cmdApdu.len = (int32_t)(pBuffer[0]);
      cmdApdu.p_data =
          (uint8_t*)phLS_memalloc(cmdApdu.len * sizeof(uint8_t));
      pBuffer = pBuffer + 1 + cmdApdu.len;

      memcpy(cmdApdu.p_data, &pBuffer[1], cmdApdu.len);

      transStat = LSC_Transceive(&cmdApdu, &rspApdu);

      memcpy(pTranscv_Info->sRecvData, rspApdu.p_data, rspApdu.len);
      recvBufferActualSize = rspApdu.len;

      if (transStat != STATUS_SUCCESS || (recvBufferActualSize < 2)) {
        ALOGE("%s: Transceive failed; status=0x%X", fn, transStat);
      } else if (cmd_count == 0x00)  // Last command in the buffer
      {
        if (islastcmdLoad == false) {
          status =
              Process_EseResponse(pTranscv_Info, recvBufferActualSize, Os_info);
        } else if ((recvBufferActualSize == 0x02) &&
                   (pTranscv_Info->sRecvData[recvBufferActualSize - 2] ==
                    0x90) &&
                   (pTranscv_Info->sRecvData[recvBufferActualSize - 1] ==
                    0x00)) {
          recvBufferActualSize = 0x03;
          pTranscv_Info->sRecvData[0] = 0x00;
          pTranscv_Info->sRecvData[1] = 0x90;
          pTranscv_Info->sRecvData[2] = 0x00;
          status =
              Process_EseResponse(pTranscv_Info, recvBufferActualSize, Os_info);
        } else {
          status =
              Process_EseResponse(pTranscv_Info, recvBufferActualSize, Os_info);
        }
      } else if ((recvBufferActualSize == 0x02) &&
                 (pTranscv_Info->sRecvData[0] == 0x90) &&
                 (pTranscv_Info->sRecvData[1] == 0x00)) {
        /*Do not do anything
         * send next command in the buffer*/
      } else if ((recvBufferActualSize == 0x03) &&
                 (pTranscv_Info->sRecvData[0] == 0x00) &&
                 (pTranscv_Info->sRecvData[1] == 0x90) &&
                 (pTranscv_Info->sRecvData[2] == 0x00)) {
        /*Do not do anything
         * Send next cmd in the buffer*/
      } else if ((pTranscv_Info->sRecvData[recvBufferActualSize - 2] != 0x90) &&
                 (pTranscv_Info->sRecvData[recvBufferActualSize - 1] != 0x00)) {
        /*Error condition hence exiting the loop*/
        status =
            Process_EseResponse(pTranscv_Info, recvBufferActualSize, Os_info);
        /*If the sending of Load fails reset the count*/
        cmd_count = 0;
        break;
      }
    }
  }
  memset(Cmd_Buffer, 0, sizeof(Cmd_Buffer));
  pBuffer = Cmd_Buffer;  // point back to start of line
  cmd_count = 0x00;
  phLS_free(cmdApdu.p_data);
  ALOGD("%s: exit: status=0x%x", fn, status);
  return status;
}
#endif
/*******************************************************************************
**
** Function:        Numof_lengthbytes
**
** Description:     Checks the number of length bytes and assigns
**                  length value to wLen.
**
** Returns:         Number of Length bytes
**
*******************************************************************************/
uint8_t Numof_lengthbytes(uint8_t* read_buf, int32_t* pLen) {
  static const char fn[] = "Numof_lengthbytes";
  uint8_t len_byte = 0, i = 0;
  int32_t wLen = 0;
  ALOGE("%s:enter", fn);

  if (read_buf[i] == 0x00) {
    ALOGE("Invalid length zero");
    len_byte = 0x00;
  } else if ((read_buf[i] & 0x80) == 0x80) {
    len_byte = read_buf[i] & 0x0F;
    len_byte = len_byte + 1;  // 1 byte added for byte 0x81
  } else {
    len_byte = 0x01;
  }
  /*
   * To get the length of the value field
   * */
  switch (len_byte) {
    case 0:
      wLen = read_buf[0];
      break;
    case 1:
      /*1st byte is the length*/
      wLen = read_buf[0];
      break;
    case 2:
      /*2nd byte is the length*/
      wLen = read_buf[1];
      break;
    case 3:
      /*1st and 2nd bytes are length*/
      wLen = read_buf[1];
      wLen = ((wLen << 8) | (read_buf[2]));
      break;
    case 4:
      /*3bytes are the length*/
      wLen = read_buf[1];
      wLen = ((wLen << 16) | (read_buf[2] << 8));
      wLen = (wLen | (read_buf[3]));
      break;
    default:
      ALOGE("default case");
      break;
  }

  *pLen = wLen;
  ALOGE("%s:exit; len_bytes=0x0%x, Length=%d", fn, len_byte, *pLen);
  return len_byte;
}
/*******************************************************************************
**
** Function:        Write_Response_To_OutFile
**
** Description:     Write the response to Out file
**                  with length recvlen from buffer RecvData.
**
** Returns:         Success if OK
**
*******************************************************************************/
tLSC_STATUS Write_Response_To_OutFile(Lsc_ImageInfo_t* image_info,
                                      uint8_t* RecvData, int32_t recvlen,
                                      Ls_TagType tType) {
  int32_t respLen = 0;
  tLSC_STATUS wStatus = STATUS_FAILED;
  static const char fn[] = "Write_Response_to_OutFile";
  int32_t status = 0;
  uint8_t tagBuffer[12] = {0x61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int32_t tag44Len = 0;
  int32_t tag61Len = 0;
  uint8_t tag43Len = 1;
  uint8_t tag43off = 0;
  uint8_t tag44off = 0;
  uint8_t ucTag44[3] = {0x00, 0x00, 0x00};
  uint8_t tagLen = 0;
  uint8_t tempLen = 0;
  /*If the Response out file is NULL or Other than LS commands*/
  if ((image_info->bytes_wrote == 0x55) || (tType == LS_Default)) {
    return STATUS_OK;
  }
  /*Certificate TAG occupies 2 bytes*/
  if (tType == LS_Cert) {
    tag43Len = 2;
  }
  ALOGE("%s: Enter", fn);

  /* |TAG | LEN(BERTLV)|                                VAL |
   * | 61 |      XX    |  TAG | LEN |     VAL    | TAG | LEN(BERTLV) |      VAL
   *|
   *                   |  43  | 1/2 | 7F21/60/40 | 44  | apduRespLen |
   *apduResponse |
   **/
  if (recvlen < 0x80) {
    tag44Len = 1;
    ucTag44[0] = recvlen;
    tag61Len = recvlen + 4 + tag43Len;

    if (tag61Len & 0x80) {
      tagBuffer[1] = 0x81;
      tagBuffer[2] = tag61Len;
      tag43off = 3;
      tag44off = 5 + tag43Len;
      tagLen = tag44off + 2;
    } else {
      tagBuffer[1] = tag61Len;
      tag43off = 2;
      tag44off = 4 + tag43Len;
      tagLen = tag44off + 2;
    }
  } else if ((recvlen >= 0x80) && (recvlen <= 0xFF)) {
    ucTag44[0] = 0x81;
    ucTag44[1] = recvlen;
    tag61Len = recvlen + 5 + tag43Len;
    tag44Len = 2;

    if ((tag61Len & 0xFF00) != 0) {
      tagBuffer[1] = 0x82;
      tagBuffer[2] = (tag61Len & 0xFF00) >> 8;
      tagBuffer[3] = (tag61Len & 0xFF);
      tag43off = 4;
      tag44off = 6 + tag43Len;
      tagLen = tag44off + 3;
    } else {
      tagBuffer[1] = 0x81;
      tagBuffer[2] = (tag61Len & 0xFF);
      tag43off = 3;
      tag44off = 5 + tag43Len;
      tagLen = tag44off + 3;
    }
  } else if ((recvlen > 0xFF) && (recvlen <= 0xFFFF)) {
    ucTag44[0] = 0x82;
    ucTag44[1] = (recvlen & 0xFF00) >> 8;
    ucTag44[2] = (recvlen & 0xFF);
    tag44Len = 3;

    tag61Len = recvlen + 6 + tag43Len;

    if ((tag61Len & 0xFF00) != 0) {
      tagBuffer[1] = 0x82;
      tagBuffer[2] = (tag61Len & 0xFF00) >> 8;
      tagBuffer[3] = (tag61Len & 0xFF);
      tag43off = 4;
      tag44off = 6 + tag43Len;
      tagLen = tag44off + 4;
    }
  }
  tagBuffer[tag43off] = 0x43;
  tagBuffer[tag43off + 1] = tag43Len;
  tagBuffer[tag44off] = 0x44;
  memcpy(&tagBuffer[tag44off + 1], &ucTag44[0], tag44Len);

  if (tType == LS_Cert) {
    tagBuffer[tag43off + 2] = 0x7F;
    tagBuffer[tag43off + 3] = 0x21;
  } else if (tType == LS_Sign) {
    tagBuffer[tag43off + 2] = 0x60;
  } else if (tType == LS_Comm) {
    tagBuffer[tag43off + 2] = 0x40;
  } else {
    /*Do nothing*/
  }
  while (tempLen < tagLen) {
    status = fprintf(image_info->fResp, "%02X", tagBuffer[tempLen++]);
    if (status != 2) {
      ALOGE("%s: Invalid Response during fprintf; status=0x%x", fn, (status));
      wStatus = STATUS_FAILED;
      break;
    }
  }
  /*Updating the response data into out script*/
  while (respLen < recvlen) {
    status = fprintf(image_info->fResp, "%02X", RecvData[respLen++]);
    if (status != 2) {
      ALOGE("%s: Invalid Response during fprintf; status=0x%x", fn, (status));
      wStatus = STATUS_FAILED;
      break;
    }
  }
  if (status == 2) {
    fprintf(image_info->fResp, "%s\n", "");
    ALOGE("%s: SUCCESS Response written to script out file; status=0x%x", fn,
          (status));
    wStatus = STATUS_OK;
  }
  fflush(image_info->fResp);
  return wStatus;
}

/*******************************************************************************
**
** Function:        Check_Certificate_Tag
**
** Description:     Check certificate Tag presence in script
**                  by 7F21 .
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_Certificate_Tag(uint8_t* read_buf, uint16_t* offset1) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t len_byte = 0;
  int32_t wLen /*, recvBufferActualSize=0*/;
  uint16_t offset = *offset1;

  if (((read_buf[offset] << 8 | read_buf[offset + 1]) == TAG_CERTIFICATE)) {
    ALOGD("TAGID: TAG_CERTIFICATE");
    offset = offset + 2;
    len_byte = Numof_lengthbytes(&read_buf[offset], &wLen);
    offset = offset + len_byte;
    *offset1 = offset;
    if (wLen <= MAX_CERT_LEN) status = STATUS_OK;
  }
  return status;
}

/*******************************************************************************
**
** Function:        Check_SerialNo_Tag
**
** Description:     Check Serial number Tag presence in script
**                  by 0x93 .
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_SerialNo_Tag(uint8_t* read_buf, uint16_t* offset1) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t offset = *offset1;
  static const char fn[] = "Check_SerialNo_Tag";

  if (read_buf[offset] == TAG_SERIAL_NO) {
    ALOGD("TAGID: TAG_SERIAL_NO");
    uint8_t serNoLen = read_buf[offset + 1];
    offset = offset + serNoLen + 2;
    *offset1 = offset;
    ALOGD("%s: TAG_LSROOT_ENTITY is %x", fn, read_buf[offset]);
    status = STATUS_OK;
  }
  return status;
}

/*******************************************************************************
**
** Function:        Check_LSRootID_Tag
**
** Description:     Check LS root ID tag presence in script and compare with
**                  select response root ID value.
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_LSRootID_Tag(uint8_t* read_buf, uint16_t* offset1) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t offset = *offset1;

  if (read_buf[offset] == TAG_LSRE_ID) {
    ALOGD("TAGID: TAG_LSROOT_ENTITY");
    if (tag42Arr[0] == read_buf[offset + 1]) {
      uint8_t tag42Len = read_buf[offset + 1];
      offset = offset + 2;
      status = memcmp(&read_buf[offset], &tag42Arr[1], tag42Arr[0]);
      ALOGD("LSC_Check_KeyIdentifier : TAG 42 verified");

      if (status == STATUS_OK) {
        ALOGD(
            "LSC_Check_KeyIdentifier : Loader service root entity "
            "ID is matched");
        offset = offset + tag42Len;
        *offset1 = offset;
      }
    }
  }
  return status;
}

/*******************************************************************************
**
** Function:        Check_CertHoldID_Tag
**
** Description:     Check certificate holder ID tag presence in script.
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_CertHoldID_Tag(uint8_t* read_buf, uint16_t* offset1) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t offset = *offset1;

  if ((read_buf[offset] << 8 | read_buf[offset + 1]) == TAG_CERTFHOLD_ID) {
    uint8_t certfHoldIDLen = 0;
    ALOGD("TAGID: TAG_CERTFHOLD_ID");
    certfHoldIDLen = read_buf[offset + 2];
    offset = offset + certfHoldIDLen + 3;
    if (read_buf[offset] == TAG_KEY_USAGE) {
      uint8_t keyusgLen = 0;
      ALOGD("TAGID: TAG_KEY_USAGE");
      keyusgLen = read_buf[offset + 1];
      offset = offset + keyusgLen + 2;
      *offset1 = offset;
      status = STATUS_OK;
    }
  }
  return status;
}

/*******************************************************************************
**
** Function:        Check_Date_Tag
**
** Description:     Check date tags presence in script.
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_Date_Tag(uint8_t* read_buf, uint16_t* offset1) {
  tLSC_STATUS status = STATUS_OK;
  uint16_t offset = *offset1;

  if ((read_buf[offset] << 8 | read_buf[offset + 1]) == TAG_EFF_DATE) {
    uint8_t effDateLen = read_buf[offset + 2];
    offset = offset + 3 + effDateLen;
    ALOGD("TAGID: TAG_EFF_DATE");
    if ((read_buf[offset] << 8 | read_buf[offset + 1]) == TAG_EXP_DATE) {
      uint8_t effExpLen = read_buf[offset + 2];
      offset = offset + 3 + effExpLen;
      ALOGD("TAGID: TAG_EXP_DATE");
      status = STATUS_OK;
    } else if (read_buf[offset] == TAG_LSRE_SIGNID) {
      status = STATUS_OK;
    }
  } else if ((read_buf[offset] << 8 | read_buf[offset + 1]) == TAG_EXP_DATE) {
    uint8_t effExpLen = read_buf[offset + 2];
    offset = offset + 3 + effExpLen;
    ALOGD("TAGID: TAG_EXP_DATE");
    status = STATUS_OK;
  } else if (read_buf[offset] == TAG_LSRE_SIGNID) {
    status = STATUS_OK;
  } else {
    /*STATUS_FAILED*/
  }
  *offset1 = offset;
  return status;
}

/*******************************************************************************
**
** Function:        Check_45_Tag
**
** Description:     Check 45 tags presence in script and compare the value
**                  with select response tag 45 value
**
** Returns:         Success if Tag found
**
*******************************************************************************/
tLSC_STATUS Check_45_Tag(uint8_t* read_buf, uint16_t* offset1,
                         uint8_t* tag45Len) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t offset = *offset1;
  if (read_buf[offset] == TAG_LSRE_SIGNID) {
    *tag45Len = read_buf[offset + 1];
    offset = offset + 2;
    if (tag45Arr[0] == *tag45Len) {
      status = memcmp(&read_buf[offset], &tag45Arr[1], tag45Arr[0]);
      if (status == STATUS_OK) {
        ALOGD("LSC_Check_KeyIdentifier : TAG 45 verified");
        *offset1 = offset;
      }
    }
  }
  return status;
}

/*******************************************************************************
**
** Function:        Certificate_Verification
**
** Description:     Perform the certificate verification by forwarding it to
**                  LS applet.
**
** Returns:         Success if certificate is verified
**
*******************************************************************************/
tLSC_STATUS Certificate_Verification(Lsc_ImageInfo_t* Os_info,
                                     Lsc_TranscieveInfo_t* pTranscv_Info,
                                     uint8_t* read_buf, uint16_t* offset1,
                                     uint8_t* tag45Len) {
  tLSC_STATUS status = STATUS_FAILED;
  uint16_t offset = *offset1;
  int32_t wCertfLen = (read_buf[2] << 8 | read_buf[3]);
  tLSC_STATUS certf_found = STATUS_FAILED;
  static const char fn[] = "Certificate_Verification";
  uint8_t tag_len_byte = Numof_lengthbytes(&read_buf[2], &wCertfLen);

  pTranscv_Info->sSendData[0] = 0x80;
  pTranscv_Info->sSendData[1] = 0xA0;
  pTranscv_Info->sSendData[2] = 0x01;
  pTranscv_Info->sSendData[3] = 0x00;
  /*If the certificate is less than 255 bytes*/
  if (wCertfLen <= 251) {
    uint8_t tag7f49Off = 0;
    uint8_t u7f49Len = 0;
    uint8_t tag5f37Len = 0;
    ALOGD("Certificate is greater than 255");
    offset = offset + *tag45Len;
    ALOGD("%s: Before TAG_CCM_PERMISSION = %x", fn, read_buf[offset]);
    if (read_buf[offset] == TAG_CCM_PERMISSION) {
      int32_t tag53Len = 0;
      uint8_t len_byte = 0;
      offset = offset + 1;
      len_byte = Numof_lengthbytes(&read_buf[offset], &tag53Len);
      offset = offset + tag53Len + len_byte;
      ALOGD("%s: Verified TAG TAG_CCM_PERMISSION = 0x53", fn);
      if ((uint16_t)(read_buf[offset] << 8 | read_buf[offset + 1]) ==
          TAG_SIG_RNS_COMP) {
        tag7f49Off = offset;
        u7f49Len = read_buf[offset + 2];
        offset = offset + 3 + u7f49Len;
        if (u7f49Len != 64) {
          return STATUS_FAILED;
        }
        if ((uint16_t)(read_buf[offset] << 8 | read_buf[offset + 1]) ==
            0x7f49) {
          tag5f37Len = read_buf[offset + 2];
          if (read_buf[offset + 3] != 0x86 || (read_buf[offset + 4] != 65)) {
            return STATUS_FAILED;
          }
        } else {
          return STATUS_FAILED;
        }
      } else {
        return STATUS_FAILED;
      }
    } else {
      return STATUS_FAILED;
    }
    pTranscv_Info->sSendData[4] = wCertfLen + 2 + tag_len_byte;
    pTranscv_Info->sSendlength = wCertfLen + 7 + tag_len_byte;
    memcpy(&(pTranscv_Info->sSendData[5]), &read_buf[0],
           wCertfLen + 2 + tag_len_byte);

    ALOGD("%s: start transceive for length %d", fn, pTranscv_Info->sSendlength);
    status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Cert);
    if (status != STATUS_OK) {
      return status;
    } else {
      certf_found = STATUS_OK;
      ALOGD("Certificate is verified");
      return status;
    }
  }
  /*If the certificate is more than 255 bytes*/
  else {
    uint8_t tag7f49Off = 0;
    uint8_t u7f49Len = 0;
    uint8_t tag5f37Len = 0;
    ALOGD("Certificate is greater than 255");
    offset = offset + *tag45Len;
    ALOGD("%s: Before TAG_CCM_PERMISSION = %x", fn, read_buf[offset]);
    if (read_buf[offset] == TAG_CCM_PERMISSION) {
      int32_t tag53Len = 0;
      uint8_t len_byte = 0;
      offset = offset + 1;
      len_byte = Numof_lengthbytes(&read_buf[offset], &tag53Len);
      offset = offset + tag53Len + len_byte;
      ALOGD("%s: Verified TAG TAG_CCM_PERMISSION = 0x53", fn);
      if ((uint16_t)(read_buf[offset] << 8 | read_buf[offset + 1]) ==
          TAG_SIG_RNS_COMP) {
        tag7f49Off = offset;
        u7f49Len = read_buf[offset + 2];
        offset = offset + 3 + u7f49Len;
        if (u7f49Len != 64) {
          return STATUS_FAILED;
        }
        if ((uint16_t)(read_buf[offset] << 8 | read_buf[offset + 1]) ==
            0x7f49) {
          tag5f37Len = read_buf[offset + 2];
          if (read_buf[offset + 3] != 0x86 || (read_buf[offset + 4] != 65)) {
            return STATUS_FAILED;
          }
        } else {
          return STATUS_FAILED;
        }
        pTranscv_Info->sSendData[4] = tag7f49Off;
        memcpy(&(pTranscv_Info->sSendData[5]), &read_buf[0], tag7f49Off);
        pTranscv_Info->sSendlength = tag7f49Off + 5;
        ALOGD("%s: start transceive for length %d", fn,
              pTranscv_Info->sSendlength);

        status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Default);
        if (status != STATUS_OK) {
          uint8_t* RecvData = pTranscv_Info->sRecvData;
          Write_Response_To_OutFile(Os_info, RecvData, resp_len, LS_Cert);
          return status;
        }

        pTranscv_Info->sSendData[2] = 0x00;
        pTranscv_Info->sSendData[4] = u7f49Len + tag5f37Len + 6;
        memcpy(&(pTranscv_Info->sSendData[5]), &read_buf[tag7f49Off],
               u7f49Len + tag5f37Len + 6);
        pTranscv_Info->sSendlength = u7f49Len + tag5f37Len + 11;
        ALOGD("%s: start transceive for length %d", fn,
              pTranscv_Info->sSendlength);

        status = LSC_SendtoLsc(Os_info, status, pTranscv_Info, LS_Cert);
        if (status != STATUS_OK) {
          return status;
        } else {
          ALOGD("Certificate is verified");
          certf_found = STATUS_OK;
          return status;
        }
      } else {
        return STATUS_FAILED;
      }
    } else {
      return STATUS_FAILED;
    }
  }
  return status;
}

/*******************************************************************************
**
** Function:        Check_Complete_7F21_Tag
**
** Description:     Traverses the 7F21 tag for verification of each sub tag with
**                  in the 7F21 tag.
**
** Returns:         Success if all tags are verified
**
*******************************************************************************/
tLSC_STATUS Check_Complete_7F21_Tag(Lsc_ImageInfo_t* Os_info,
                                    Lsc_TranscieveInfo_t* pTranscv_Info,
                                    uint8_t* read_buf, uint16_t* offset) {
  static const char fn[] = "Check_Complete_7F21_Tag";

  if (STATUS_OK == Check_Certificate_Tag(read_buf, offset)) {
    if (STATUS_OK == Check_SerialNo_Tag(read_buf, offset)) {
      if (STATUS_OK == Check_LSRootID_Tag(read_buf, offset)) {
        if (STATUS_OK == Check_CertHoldID_Tag(read_buf, offset)) {
          if (STATUS_OK == Check_Date_Tag(read_buf, offset)) {
            uint8_t tag45Len = 0;
            if (STATUS_OK == Check_45_Tag(read_buf, offset, &tag45Len)) {
              if (STATUS_OK == Certificate_Verification(Os_info, pTranscv_Info,
                                                        read_buf, offset,
                                                        &tag45Len)) {
                return STATUS_OK;
              }
            } else {
              ALOGE("%s: FAILED in Check_45_Tag", fn);
            }
          } else {
            ALOGE("%s: FAILED in Check_Date_Tag", fn);
          }
        } else {
          ALOGE("%s: FAILED in Check_CertHoldID_Tag", fn);
        }
      } else {
        ALOGE("%s: FAILED in Check_LSRootID_Tag", fn);
      }
    } else {
      ALOGE("%s: FAILED in Check_SerialNo_Tag", fn);
    }
  } else {
    ALOGE("%s: FAILED in Check_Certificate_Tag", fn);
  }
  return STATUS_FAILED;
}

/*******************************************************************************
**
** Function:        LSC_UpdateExeStatus
**
** Description:     Updates LSC status to a file
**
** Returns:         true if success else false
**
*******************************************************************************/
bool LSC_UpdateExeStatus(uint16_t status) {
  fLS_STATUS = fopen(LS_STATUS_PATH[gpLsc_Dwnld_Context->mchannel
  ->getInterfaceInfo()], "w+");
  ALOGD("enter: LSC_UpdateExeStatus");
  if (fLS_STATUS == NULL) {
    ALOGE("Error opening LS Status file for backup: %s", strerror(errno));
    return false;
  }
  if ((fprintf(fLS_STATUS, "%04x", status)) != 4) {
    ALOGE("Error updating LS Status backup: %s", strerror(errno));
    fclose(fLS_STATUS);
    return false;
  }
  ALOGD("exit: LSC_UpdateExeStatus");
  fclose(fLS_STATUS);
  return true;
}

/*******************************************************************************
**
** Function:        Get_LsStatus
**
** Description:     Interface to fetch Loader service client status to JNI,
*Services
**
** Returns:         SUCCESS/FAILURE
**
*******************************************************************************/
tLSC_STATUS Get_LsStatus(uint8_t* pStatus) {
  tLSC_STATUS status = STATUS_FAILED;
  uint8_t lsStatus[2] = {0x63, 0x40};
  uint8_t loopcnt = 0;
  fLS_STATUS = fopen(LS_STATUS_PATH[gpLsc_Dwnld_Context
    ->mchannel->getInterfaceInfo()], "r");

  if (fLS_STATUS == NULL) {
    ALOGE("Error opening LS Status file for backup: %s", strerror(errno));
    return status;
  }
  for (loopcnt = 0; loopcnt < 2; loopcnt++) {
    if ((FSCANF_BYTE(fLS_STATUS, "%2x", &lsStatus[loopcnt])) == 0) {
      ALOGE("Error updating LS Status backup: %s", strerror(errno));
      fclose(fLS_STATUS);
      return status;
    }
  }
  ALOGD("enter: LSC_getLsStatus 0x%X 0x%X", lsStatus[0], lsStatus[1]);
  memcpy(pStatus, lsStatus, 2);
  fclose(fLS_STATUS);
  return STATUS_OK;
}

static tLSC_STATUS LSC_Transceive(phNxpLs_data* pCmd, phNxpLs_data* pRsp)
{
  bool stat = false;
  tLSC_STATUS status = STATUS_FAILED;
  int32_t recvBufferActualSize = 0;
  IChannel_t *mchannel = gpLsc_Dwnld_Context->mchannel;
  Lsc_TranscieveInfo_t* pTranscv_Info = &gpLsc_Dwnld_Context->Transcv_Info;

  pTranscv_Info->timeout = gTransceiveTimeout;
  pTranscv_Info->sSendlength = pCmd->len;
  pTranscv_Info->sRecvlength = 1024;//(int32_t)sizeof(int32_t);
  
  memcpy(pTranscv_Info->sSendData, pCmd->p_data, pTranscv_Info->sSendlength);
  stat = mchannel->transceive (pTranscv_Info->sSendData,
          pTranscv_Info->sSendlength,
          pTranscv_Info->sRecvData,
          pTranscv_Info->sRecvlength,
          recvBufferActualSize,
          pTranscv_Info->timeout);
  if(stat == true)
  {
    pRsp->len = recvBufferActualSize;
    //memcpy(pRsp->p_data, pTranscv_Info->sRecvData, recvBufferActualSize);
    pRsp->p_data = pTranscv_Info->sRecvData;
    status = STATUS_OK;
  }
  return status;

}
