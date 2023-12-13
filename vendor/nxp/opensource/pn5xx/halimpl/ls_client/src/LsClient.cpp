/******************************************************************************
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

#include "LsLib.h"
#include "LsClient.h"
#include <cutils/log.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

/*static char gethex(const char *s, char **endptr);
char *convert(const char *s, int *length);*/
uint8_t datahex(char c);
void updateLsAid(uint8_t intfInfo);
//extern pLsc_Dwnld_Context_t gpLsc_Dwnld_Context;
//static android::sp<ISecureElementHalCallback> cCallback;
/*******************************************************************************
**
** Function:        LSC_Start
**
** Description:     Starts the LSC update over DWP
**
** Returns:         SUCCESS if ok.
**
*******************************************************************************/
tLSC_STATUS LSC_Start(const char* name, const char* dest, uint8_t* pdata,
                      uint16_t len, uint8_t* respSW) {
  static const char fn[] = "LSC_Start";
  tLSC_STATUS status = STATUS_FAILED;
  if (name != NULL) {
    ALOGE("%s: name is %s", fn, name);
    ALOGE("%s: Dest is %s", fn, dest);
    status = Perform_LSC(name, dest, pdata, len, respSW);
  } else {
    ALOGE("Invalid parameter");
  }
  ALOGE("%s: Exit; status=0x0%X", fn, status);
  return status;
}

/*******************************************************************************
**
** Function:        performLSDownload
**
** Description:     Perform LS during hal init
**
** Returns:         SUCCESS of ok
**
*******************************************************************************/
tLSC_STATUS performLSDownload(IChannel_t* data) {
  tLSC_STATUS status = STATUS_FAILED;

  const char* lsUpdateBackupPath =
      "/vendor/etc/loaderservice_updater.txt";
  const char* lsUpdateBackupOutPath[2] =
  {"/data/vendor/nfc/loaderservice_updater_out.txt",
   "/data/vendor/secure_element/loaderservice_updater_out.txt",};
  IChannel_t* mchannel = (IChannel_t*)data;

  /*generated SHA-1 string for secureElementLS
  This will remain constant as handled in secureElement HAL*/
  char sha1[] = "6d583e84f2710e6b0f06beebc1a12a1083591373";
  uint8_t hash[20] = {};

  for (int i = 0; i < 40; i = i + 2) {
    hash[i / 2] =
        (((datahex(sha1[i]) & 0x0F) << 4) | (datahex(sha1[i + 1]) & 0x0F));
  }
  /*Check and update if any new LS AID is available*/
  updateLsAid(mchannel->getInterfaceInfo());

  if(!initialize ((IChannel_t*) data))
    return status;


  uint8_t resSW[4] = {0x4e, 0x02, 0x69, 0x87};
  FILE* fIn, *fOut;
  if ((fIn = fopen(lsUpdateBackupPath, "rb")) == NULL) {
    ALOGE("%s Cannot open file %s\n", __func__, lsUpdateBackupPath);
    ALOGE("%s Error : %s", __func__, strerror(errno));
    return status;
  } else {
    ALOGD("%s File opened %s\n", __func__, lsUpdateBackupPath);
    fseek(fIn, 0, SEEK_END);
    long fsize = ftell(fIn);
    rewind(fIn);

    char* lsUpdateBuf = (char*)malloc(fsize + 1);
    fread(lsUpdateBuf, fsize, 1, fIn);
    fclose(fIn);

    if ((fOut = fopen(lsUpdateBackupOutPath[mchannel->getInterfaceInfo()], "wb")) == NULL) {
      ALOGE("%s Failed to open file %s\n", __func__,
        lsUpdateBackupOutPath[mchannel->getInterfaceInfo()]);
    } else {
      ALOGD("%s File opened %s\n", __func__,
        lsUpdateBackupOutPath[mchannel->getInterfaceInfo()]);

      if ((long)fwrite(lsUpdateBuf, 1, fsize, fOut) != fsize) {
        ALOGE("%s ERROR - Failed to write %ld bytes to file\n", __func__, fsize);
      }

      fclose(fOut);
    }

    status = LSC_Start(lsUpdateBackupPath, lsUpdateBackupOutPath[mchannel->getInterfaceInfo()],
                       (uint8_t*)hash, (uint16_t)sizeof(hash), resSW);
    resSW[0]=0x4e;
    ALOGD("%s LSC_Start completed\n", __func__);
    if (status == STATUS_SUCCESS) {
      if (remove(lsUpdateBackupPath) == 0) {
        ALOGD("%s  : %s file deleted successfully\n", __func__,
              lsUpdateBackupPath);
      } else {
        ALOGD("%s  : %s file deletion failed!!!\n", __func__,
              lsUpdateBackupPath);
      }
    }
    free(lsUpdateBuf);
  }
  ALOGD("%s pthread_exit\n", __func__);

  return status;
}

/*******************************************************************************
**
** Function:        datahex
**
** Description:     Converts char to uint8_t
**
** Returns:         uint8_t variable
**
*******************************************************************************/
uint8_t datahex(char c) {
  uint8_t value = 0;
  if (c >= '0' && c <= '9')
    value = (c - '0');
  else if (c >= 'A' && c <= 'F')
    value = (10 + (c - 'A'));
  else if (c >= 'a' && c <= 'f')
    value = (10 + (c - 'a'));
  return value;
}

/*******************************************************************************
**
** Function:        updateLsAid
**
** Description:     Store AID in LS_SELF_UPDATE_AID_IDX of ArrayOfAIDs if new LS
**                  AID is available after LS Self Update
**
** Returns:         None
**
*******************************************************************************/
void updateLsAid(uint8_t intfInfo) {
  ALOGD_IF( "%s Enter\n", __func__);

  FILE* fAID_MEM = NULL;
  fAID_MEM = fopen(AID_MEM_PATH[intfInfo], "r");

  if (fAID_MEM == NULL) {
    ALOGE("%s: AID data file does not exists", __func__);
    return;
  }

  uint8_t aidLen = 0x00;
  int32_t wStatus = 0;

  while (!(feof(fAID_MEM))) {
    wStatus = FSCANF_BYTE(fAID_MEM, "%2x",
                          &ArrayOfAIDs[LS_SELF_UPDATE_AID_IDX][aidLen++]);
    if (wStatus == 0) {
      ALOGE("%s: exit: Error during read AID data", __func__);
      ArrayOfAIDs[LS_SELF_UPDATE_AID_IDX][0] = 0x00;
      break;
    }
  }
  if ((wStatus > 0x00) && (aidLen > 0x00)) {
    ArrayOfAIDs[LS_SELF_UPDATE_AID_IDX][0] = aidLen - 1;
  }
  fclose(fAID_MEM);
}

void* phLS_memset(void* buff, int val, size_t len) {
  return memset(buff, val, len);
}

void* phLS_memcpy(void* dest, const void* src, size_t len) {
  return memcpy(dest, src, len);
}

void* phLS_memalloc(uint32_t size) { return malloc(size); }

void phLS_free(void* ptr) { return free(ptr); }

void* phLS_calloc(size_t datatype, size_t size) {
  return calloc(datatype, size);
}
