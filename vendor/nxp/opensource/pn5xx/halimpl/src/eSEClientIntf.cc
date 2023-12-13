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

#include "eSEClientIntf.h"
#include <cutils/log.h>
#include <dirent.h>
#include <stdlib.h>
#include <pthread.h>
#include <IChannel.h>
#include <JcDnld.h>
#include <unistd.h>
#include <sys/stat.h>
#include <phNxpConfig.h>
#include "phNxpConfig.h"
#include <android-base/logging.h>
#include <android-base/stringprintf.h>

#define TERMINAL_LEN  5
bool nfc_debug_enabled;
void* performJCOS_Download_thread(void* data);
IChannel_t Ch;
static const char *path[3] = {"/vendor/etc/JcopOs_Update1.apdu",
                             "/vendor/etc/JcopOs_Update2.apdu",
                             "/vendor/etc/JcopOs_Update3.apdu"};

static const char *uai_path[2] = {"/vendor/etc/cci.jcsh",
                                  "/vendor/etc/jci.jcsh"};
static const char *isSystemImgInfo[2] = {"/data/vendor/nfc/jcop_info.txt",
                                         "/data/vendor/secure_element/jcop_info.txt"};
static const char *lsUpdateBackupPath =
"/vendor/etc/loaderservice_updater.txt";
static const char *isFirstTimeLsUpdate[2] =
{"/data/vendor/nfc/LS_Status.txt",
 "/data/vendor/secure_element/LS_Status.txt"};
se_extns_entry seExtn;

static bool scriptUpdateRequired(ESE_CLIENT_INTF intf);
static bool jcopOsUpdateRequired(ESE_CLIENT_INTF intf);
/*******************************************************************************
**
** Function:        checkeSEClientUpdateRequired
**
** Description:     HAL service entry criteria is verified
**                  Read the interface and condition for ese Update(JCOP download/LS download)
**                  from the config file and file path and validate.
**
** Returns:         SUCCESS of ok
**
*******************************************************************************/
uint8_t checkeSEClientRequired(ESE_CLIENT_INTF intf ) {
  uint8_t status = SESTATUS_FAILED;
  unsigned long int num;
  bool isApduPresent = true;
  bool isSystemImgUpdated = false;
  bool isLsScriptPresent = true;
  bool isFirstLsUpdate = false;
  struct stat st;

  LOG(ERROR) <<"Check_HalStart_Entry: enter:  ";
  /*Check APDU files are present*/
  for (int num = 0; num < 2; num++)
  {
    if (stat(uai_path[num], &st))
    {
      isApduPresent = false;
    }
  }
  /*If UAI specific files are present*/
  if(isApduPresent == true)
  {
    for (int num = 0; num < 1; num++)
    {
      if (stat(path[num], &st))
      {
        isApduPresent = false;
      }
    }
  }
  /*Check if OS udpate required*/
  isSystemImgUpdated = jcopOsUpdateRequired(intf);

  /*Check if LS script present*/
  if(stat(lsUpdateBackupPath, &st))
  {
    isLsScriptPresent = false;
  }
  /*Check if LS update required*/
  isFirstLsUpdate = scriptUpdateRequired(intf);

  if(GetNxpNumValue(NAME_NXP_P61_JCOP_DEFAULT_INTERFACE, &num, sizeof(num))) {
    seExtn.sJcopUpdateIntferface = num;
  }
  if(GetNxpNumValue(NAME_NXP_P61_LS_DEFAULT_INTERFACE, &num, sizeof(num))) {
    seExtn.sLsUpdateIntferface = num;
  }
  if(GetNxpNumValue(NAME_NXP_LS_FORCE_UPDATE_REQUIRED, &num, sizeof(num))) {
    seExtn.isLSUpdateRequired = num;
  }
  if(GetNxpNumValue(NAME_NXP_JCOP_FORCE_UPDATE_REQUIRED, &num, sizeof(num))) {
    seExtn.isJcopUpdateRequired = num;
  }
  if(isApduPresent && seExtn.sJcopUpdateIntferface &&
    ((isSystemImgUpdated && (intf == seExtn.sJcopUpdateIntferface))
      || seExtn.isJcopUpdateRequired))
  {
    LOG(ERROR) <<" Jcop update required  ";
    seExtn.isJcopUpdateRequired = true;
  }
  else
  {
    LOG(ERROR) <<"Jcop update not required  ";
    seExtn.isJcopUpdateRequired = false;
  }

  if(isLsScriptPresent && seExtn.sLsUpdateIntferface &&
    (seExtn.isLSUpdateRequired || (isFirstLsUpdate &&
    (intf == seExtn.sLsUpdateIntferface))))
  {
    LOG(ERROR) <<" LS update required  ";
    seExtn.isLSUpdateRequired = true;
  }
  else
  {
    LOG(ERROR) <<" LS update not required  ";
    seExtn.isLSUpdateRequired = false;
  }
  return status;
}

/*******************************************************************************
**
** Function:        scriptUpdateRequired
**
** Description:     Get SEMS script update required
**
** Returns:         TRUE/FALSE
**
*******************************************************************************/
bool scriptUpdateRequired(ESE_CLIENT_INTF intf)
{
  bool mScriptUpdateRequired = false;
  uint32_t status[2] = {SEMS_STATUS_FAILED_SW1, SEMS_STATUS_FAILED_SW2};
  FILE* fLS_STATUS = fopen(isFirstTimeLsUpdate[intf-1], "r");

  if (fLS_STATUS == NULL) {
    LOG(ERROR) <<"Error opening status file";
    mScriptUpdateRequired = true;
  }
  else {
    if ((fscanf(fLS_STATUS, "%2x %2x", &status[0], &status[1])) == 0) {
      LOG(ERROR) <<"Error reading status file:";
      status[0] = SEMS_STATUS_FAILED_SW1;
      status[1] = SEMS_STATUS_FAILED_SW2;
    }
    if(status[0] == SEMS_STATUS_SUCCESS_SW1 &&
                  status[1] == SEMS_STATUS_SUCCESS_SW2) {
      mScriptUpdateRequired = false;
      LOG(ERROR) <<"Last script execution success";
    }
    else {
      mScriptUpdateRequired = true;
      LOG(ERROR) <<"Last script execution failed ";
    }
    fclose(fLS_STATUS);
  }
  return mScriptUpdateRequired;
}
/*******************************************************************************
**
** Function:        jcopOsUpdateRequired
**
** Description:     Get JCOP update required
**
** Returns:         TRUE/FALSE
**
*******************************************************************************/
bool jcopOsUpdateRequired(ESE_CLIENT_INTF intf)
{
  bool isUpdateRequired = false;
  uint32_t status = 0;
  FILE* fp = fopen(isSystemImgInfo[intf-1], "r");

  if (fp == NULL) {
    LOG(ERROR) <<"jcopOsUpdateRequired : file not exits for reading";
    isUpdateRequired = true;
  }
  else {
    if (fscanf(fp, "%u", &status) == 0) {
      LOG(ERROR) <<"jcop status read fail";
      isUpdateRequired = true;
    }
    else {
      LOG(ERROR) << "JcopOsState: "<< status;
      if (status == JCOP_UPDATE_3STEP_DONE) {
        isUpdateRequired = false;
        LOG(ERROR) <<"jcopOsUpdateRequired : Jcop update completed";
      }
      else {
        LOG(ERROR) << "jcopOsUpdateRequired : Jcop update required";
        isUpdateRequired = true;
      }
    }
    fclose(fp);
  }
  return isUpdateRequired;
}

uint8_t getJcopUpdateRequired()
{
  return seExtn.isJcopUpdateRequired;
}
uint8_t getLsUpdateRequired()
{
  return seExtn.isLSUpdateRequired;
}
uint8_t getJcopUpdateIntf()
{
  return seExtn.sJcopUpdateIntferface;
}
uint8_t getLsUpdateIntf()
{
  return seExtn.sLsUpdateIntferface;
}

void setJcopUpdateRequired(uint8_t state)
{
  seExtn.isJcopUpdateRequired = state;
}

void setLsUpdateRequired(uint8_t  state)
{
  seExtn.isLSUpdateRequired = state;
}

bool geteSETerminalId(char* val)
{
  bool ret = false;

  if(GetNxpStrValue(NAME_NXP_SPI_SE_TERMINAL_NUM, val, TERMINAL_LEN))
  {
    LOG(ERROR) <<"eSETerminalId found";
    ALOGE("eSETerminalId found val = %s ", val);

    ret = true;
  }
  return ret;
}

bool geteUICCTerminalId(char* val)
{
  bool ret = false;

  if(GetNxpStrValue(NAME_NXP_VISO_SE_TERMINAL_NUM, val, TERMINAL_LEN))
  {
    ALOGE("eUICCTerminalId found val = %s ", val);
    ret = true;
  }
  return ret;
}

bool getNfcSeTerminalId(char* val)
{
  bool ret = false;

  if(GetNxpStrValue(NAME_NXP_NFC_SE_TERMINAL_NUM, val, TERMINAL_LEN))
  {
    ALOGE("NfcSeTerminalId found val = %s ", val);
    ret = true;
  }
  return ret;
}
