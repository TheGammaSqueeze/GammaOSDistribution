/*
 * Copyright (C) 2010-2020 NXP Semiconductors
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
 * DAL I2C port implementation for linux
 *
 * Project: Trusted NFC Linux
 *
 */
#include <errno.h>
#include <fcntl.h>
#include <hardware/nfc.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#include <phNfcStatus.h>
#include <phNxpLog.h>
#include <phTmlNfc_i2c.h>
#include <string.h>
#include "phNxpNciHal_utils.h"
#include "phNxpConfig.h"

#define CRC_LEN 2
#define NORMAL_MODE_HEADER_LEN 3
#define FW_DNLD_HEADER_LEN 2
#define FW_DNLD_LEN_OFFSET 1
#define NORMAL_MODE_LEN_OFFSET 2
#define FRAGMENTSIZE_MAX PHNFC_I2C_FRAGMENT_SIZE
static bool_t bFwDnldFlag = false;
extern phTmlNfc_i2cfragmentation_t fragmentation_enabled;
bool_t notifyFwrequest;
#if(NXP_EXTNS == TRUE)
sem_t txrxSemaphore;
static int phTmlNfc_sem_timed_wait();
static void phTmlNfc_sem_post();
#endif
/*******************************************************************************
**
** Function         phTmlNfc_i2c_close
**
** Description      Closes PN54X device
**
** Parameters       pDevHandle - device handle
**
** Returns          None
**
*******************************************************************************/
void phTmlNfc_i2c_close(void* pDevHandle) {
  if (NULL != pDevHandle) {
    close((intptr_t)pDevHandle);
  }
#if(NXP_EXTNS == TRUE)
  sem_destroy(&txrxSemaphore);
#endif
  return;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_open_and_configure
**
** Description      Open and configure PN54X device
**
** Parameters       pConfig     - hardware information
**                  pLinkHandle - device handle
**
** Returns          NFC status:
**                  NFCSTATUS_SUCCESS - open_and_configure operation success
**                  NFCSTATUS_INVALID_DEVICE - device open operation failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_i2c_open_and_configure(pphTmlNfc_Config_t pConfig,
                                          void** pLinkHandle) {
  int nHandle;
  unsigned long num = 0;

  NXPLOG_TML_D("Opening port=%s\n", pConfig->pDevName);
  /* open port */
  nHandle = open((const char*)pConfig->pDevName, O_RDWR);
  if (nHandle < 0) {
    NXPLOG_TML_E("_i2c_open() Failed: retval %x", nHandle);
    *pLinkHandle = NULL;
    return NFCSTATUS_INVALID_DEVICE;
  }

  *pLinkHandle = (void*)((intptr_t)nHandle);
  phTmlNfc_i2c_reset(*pLinkHandle, MODE_NFC_ENABLED);

#if(NXP_EXTNS == TRUE)
  if (0 != sem_init(&txrxSemaphore, 0, 1)) {
    NXPLOG_TML_E("_i2c_open() Failed: reason sem_init : retval %x", nHandle);
  }
#endif
  /*Reset PN54X*/
  if (GetNxpNumValue(NAME_ENABLE_VEN_TOGGLE, &num, sizeof(num))) {
    NXPLOG_TML_D("ENABLE_VEN_TOGGLE value: %lu", num);
    if (num == 0) {
      NXPLOG_TML_D("Not toggling NFC ENABLE PIN");
    }
    else {
      NXPLOG_TML_D("Toggling NFC ENABLE PIN");
      phTmlNfc_i2c_reset((void*)((intptr_t)nHandle), MODE_POWER_OFF);
      usleep(10 * 1000);
      phTmlNfc_i2c_reset((void*)((intptr_t)nHandle), MODE_POWER_ON);
    }
  }

  return NFCSTATUS_SUCCESS;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_read
**
** Description      Reads requested number of bytes from PN54X device into given
**                  buffer
**
** Parameters       pDevHandle       - valid device handle
**                  pBuffer          - buffer for read data
**                  nNbBytesToRead   - number of bytes requested to be read
**
** Returns          numRead   - number of successfully read bytes
**                  -1        - read operation failure
**
*******************************************************************************/
int phTmlNfc_i2c_read(void* pDevHandle, uint8_t* pBuffer, int nNbBytesToRead) {
  int ret_Read;
  int ret_Select;
  int numRead = 0;
  struct timeval tv;
  fd_set rfds;
  uint16_t totalBtyesToRead = 0;

  UNUSED_PROP(nNbBytesToRead);
  if (NULL == pDevHandle) {
    return -1;
  }

  if (bFwDnldFlag == false) {
    totalBtyesToRead = NORMAL_MODE_HEADER_LEN;
  } else {
    totalBtyesToRead = FW_DNLD_HEADER_LEN;
  }

  /* Read with 2 second timeout, so that the read thread can be aborted
     when the PN54X does not respond and we need to switch to FW download
     mode. This should be done via a control socket instead. */
  FD_ZERO(&rfds);
  FD_SET((intptr_t)pDevHandle, &rfds);
  tv.tv_sec = 2;
  tv.tv_usec = 1;

  ret_Select =
      select((int)((intptr_t)pDevHandle + (int)1), &rfds, NULL, NULL, &tv);
  if (ret_Select < 0) {
    NXPLOG_TML_D("i2c select() errno : %x", errno);
    return -1;
  } else if (ret_Select == 0) {
    NXPLOG_TML_D("i2c select() Timeout");
    return -1;
  } else {
    ret_Read = read((intptr_t)pDevHandle, pBuffer, totalBtyesToRead - numRead);
    if (ret_Read > 0 && !(pBuffer[0] == 0xFF && pBuffer[1] == 0xFF)) {
#if(NXP_EXTNS == TRUE)
      phTmlNfc_sem_timed_wait();
#endif
      numRead += ret_Read;
    } else if (ret_Read == 0) {
      NXPLOG_TML_E("_i2c_read() [hdr]EOF");
      return -1;
    } else {
      NXPLOG_TML_E("_i2c_read() [hdr] errno : %x", errno);
      NXPLOG_TML_E(" _i2c_read: pBuffer[0] = %x pBuffer[1]= %x", pBuffer[0], pBuffer[1]);
      return -1;
    }

    if (bFwDnldFlag == false) {
      totalBtyesToRead = NORMAL_MODE_HEADER_LEN;
    } else {
      totalBtyesToRead = FW_DNLD_HEADER_LEN;
    }

    if (numRead < totalBtyesToRead) {
      ret_Read =
          read((intptr_t)pDevHandle, pBuffer, totalBtyesToRead - numRead);

      if (ret_Read != totalBtyesToRead - numRead) {
#if(NXP_EXTNS == TRUE)
        phTmlNfc_sem_post();
#endif
        NXPLOG_TML_E("_i2c_read() [hdr] errno : %x", errno);
        return -1;
      } else {
        numRead += ret_Read;
      }
    }
    if (bFwDnldFlag == true) {
      totalBtyesToRead =
          pBuffer[FW_DNLD_LEN_OFFSET] + FW_DNLD_HEADER_LEN + CRC_LEN;
    } else {
      totalBtyesToRead =
          pBuffer[NORMAL_MODE_LEN_OFFSET] + NORMAL_MODE_HEADER_LEN;
    }
    if ((totalBtyesToRead - numRead) != 0) {
      ret_Read = read((intptr_t)pDevHandle, (pBuffer + numRead),
                      totalBtyesToRead - numRead);
      if (ret_Read > 0) {
        numRead += ret_Read;
      } else if (ret_Read == 0) {
#if(NXP_EXTNS == TRUE)
        phTmlNfc_sem_post();
#endif
        NXPLOG_TML_E("_i2c_read() [pyld] EOF");
        return -1;
      } else {
        if (bFwDnldFlag == false) {
          NXPLOG_TML_D("_i2c_read() [hdr] received");
          phNxpNciHal_print_packet("RECV", pBuffer, NORMAL_MODE_HEADER_LEN);
        }
#if(NXP_EXTNS == TRUE)
        phTmlNfc_sem_post();
#endif
        NXPLOG_TML_E("_i2c_read() [pyld] errno : %x", errno);
        return -1;
      }
    } else {
      NXPLOG_TML_E("_>>>>> Empty packet recieved !!");
    }
  }
#if(NXP_EXTNS == TRUE)
  phTmlNfc_sem_post();
#endif
  return numRead;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_write
**
** Description      Writes requested number of bytes from given buffer into
**                  PN54X device
**
** Parameters       pDevHandle       - valid device handle
**                  pBuffer          - buffer for read data
**                  nNbBytesToWrite  - number of bytes requested to be written
**
** Returns          numWrote   - number of successfully written bytes
**                  -1         - write operation failure
**
*******************************************************************************/
int phTmlNfc_i2c_write(void* pDevHandle, uint8_t* pBuffer,
                       int nNbBytesToWrite) {
  int ret;
  int numWrote = 0;
  int numBytes = nNbBytesToWrite;
  if (NULL == pDevHandle) {
    return -1;
  }
  if (fragmentation_enabled == I2C_FRAGMENATATION_DISABLED &&
      nNbBytesToWrite > FRAGMENTSIZE_MAX) {
    NXPLOG_TML_D(
        "i2c_write() data larger than maximum I2C  size,enable I2C "
        "fragmentation");
    return -1;
  }
  while (numWrote < nNbBytesToWrite) {
    if (fragmentation_enabled == I2C_FRAGMENTATION_ENABLED &&
        nNbBytesToWrite > FRAGMENTSIZE_MAX) {
      if (nNbBytesToWrite - numWrote > FRAGMENTSIZE_MAX) {
        numBytes = numWrote + FRAGMENTSIZE_MAX;
      } else {
        numBytes = nNbBytesToWrite;
      }
    }
#if(NXP_EXTNS == TRUE)
    phTmlNfc_sem_timed_wait();
#endif
    ret = write((intptr_t)pDevHandle, pBuffer + numWrote, numBytes - numWrote);
#if(NXP_EXTNS == TRUE)
    phTmlNfc_sem_post();
#endif
    if (ret > 0) {
      numWrote += ret;
      if (fragmentation_enabled == I2C_FRAGMENTATION_ENABLED &&
          numWrote < nNbBytesToWrite) {
        usleep(500);
      }
    } else if (ret == 0) {
      NXPLOG_TML_D("_i2c_write() EOF");
      return -1;
    } else {
      NXPLOG_TML_D("_i2c_write() errno : %x", errno);
      if (errno == EINTR || errno == EAGAIN) {
        continue;
      }
      return -1;
    }
  }

  return numWrote;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_reset
**
** Description      Reset PN54X device, using VEN pin
**
** Parameters       pDevHandle     - valid device handle
**                  level          - reset level
**
** Returns           0   - reset operation success
**                  -1   - reset operation failure
**
*******************************************************************************/
int phTmlNfc_i2c_reset(void* pDevHandle, long level) {
  int ret = -1;;
  NXPLOG_TML_D("phTmlNfc_i2c_reset(), VEN level %ld", level);

  if (NULL == pDevHandle) {
    return -1;
  }

  ret = ioctl((intptr_t)pDevHandle, PN544_SET_PWR, level);
  if (ret < 0) {
    NXPLOG_TML_E("%s :failed errno = 0x%x", __func__, errno);
    if ((level == MODE_FW_DWNLD_WITH_VEN || level == MODE_FW_DWND_HIGH || level == MODE_FW_DWND_HDR) && errno == EBUSY) {
         notifyFwrequest = true;
    } else {
         notifyFwrequest = false;
    }
  }
  if ((level != MODE_FW_DWNLD_WITH_VEN && level != MODE_FW_DWND_HIGH && level != MODE_FW_DWND_HDR)
      && ret == 0) {
    bFwDnldFlag = false;
  }

  return ret;
}

/*******************************************************************************
**
** Function         phTmlNfc_ese_reset
**
** Description      Request NFCC to reset the eSE
**
** Parameters       pDevHandle     - valid device handle
**                  level          - reset level
**
** Returns           0   - reset operation success
**                  else - reset operation failure
**
*******************************************************************************/
int phTmlNfc_ese_reset(void* pDevHandle, long level) {
  int ret = -1;;
  NXPLOG_TML_D("phTmlNfc_ese_reset(), level %ld", level);

  if (NULL == pDevHandle) {
    return -1;
  }
  ret = ioctl((intptr_t)pDevHandle, ESE_SET_PWR, level);
  if (ret < 0) {
    NXPLOG_TML_E("%s :failed errno = 0x%x", __func__, errno);
  }
  return ret;
}

/*******************************************************************************
**
** Function         phTmlNfc_get_platform
**
** Description      Get platform interface type (i2c or i3c) for common mw
**
** Parameters       pDevHandle     - valid device handle
**
** Returns           0   - i2c
**                   1   - i3c
**
*******************************************************************************/
int phTmlNfc_get_platform(void* pDevHandle) {
  int ret = -1;
  unsigned char interface = PLATFORM_IF_I2C;

  ret = ioctl((intptr_t)pDevHandle, P544_GET_PLATFORM_INTERFACE);

  /* ret 0 -> I2C, 1 -> I3C interface */
  if (ret < 0) {
      NXPLOG_TML_D("%s: ioctl failed, getting value from config", __func__);

      if (GetNxpNumValue(NAME_NFC_INTERFACE, &interface, sizeof(interface))) {
        NXPLOG_TML_D("NFC_INTERFACE value: %d", interface);
        ret = interface;
      }
  }
  if ((ret == PLATFORM_IF_I2C) || (ret == PLATFORM_IF_I3C)) {
    NXPLOG_TML_D("%s: interface = %d", __func__, ret);
  } else {
    ret = PLATFORM_IF_I2C;
    NXPLOG_TML_E("%s: NFC_INTERFACE not present in config/invalid, setting to I2C", __func__);
  }

  return ret;
}

/*******************************************************************************
**
** Function         phTmlNfc_EnableFwDnldMode
**
** Description      updates the state to Download mode
**
** Parameters       True/False
**
** Returns          None
*******************************************************************************/
void phTmlNfc_EnableFwDnldMode(bool mode) {
  bFwDnldFlag = mode;
}
/*******************************************************************************
**
** Function         getDownloadFlag
**
** Description      Returns the current mode
**
** Parameters       none
**
** Returns           Current mode download/NCI
*******************************************************************************/
bool_t getDownloadFlag(void) { return bFwDnldFlag; }

#if(NXP_EXTNS == TRUE)
/*******************************************************************************
**
** Function         phTmlNfc_sem_post
**
** Description      sem_post 2c_read / write
**
** Parameters       none
**
** Returns          none
*******************************************************************************/
static void phTmlNfc_sem_post() {
  int sem_val = 0;
  sem_getvalue(&txrxSemaphore, &sem_val);
  if(sem_val == 0) {
    sem_post(&txrxSemaphore);
  }
}

/*******************************************************************************
**
** Function         phTmlNfc_sem_wait
**
** Description      Timed sem_wait for avoiding i2c_read & write overlap
**
** Parameters       none
**
** Returns          Sem_wait return status
*******************************************************************************/
static int phTmlNfc_sem_timed_wait() {
  NFCSTATUS status = NFCSTATUS_FAILED;
  long sem_timedout = 500*1000*1000;
  int s = 0;
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  ts.tv_sec += 0;
  ts.tv_nsec += sem_timedout;
  while ((s = sem_timedwait(&txrxSemaphore, &ts)) == -1 &&
         errno == EINTR){
    continue; /* Restart if interrupted by handler */
  }
  if (s != -1) {
    status = NFCSTATUS_SUCCESS;
  } else if(errno == ETIMEDOUT && s == -1) {
    NXPLOG_TML_E("%s :timed out errno = 0x%x", __func__, errno);
  }
  return status;
}
#endif
