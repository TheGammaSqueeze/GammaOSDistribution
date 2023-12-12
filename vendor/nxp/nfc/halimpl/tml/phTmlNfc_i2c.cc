/*
 * Copyright 2015-2020 NXP
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
#include <hardware/nfc.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <errno.h>

#include <phNxpLog.h>
#include <phTmlNfc_i2c.h>
#include <phNfcStatus.h>
#include <string.h>
#include <phNxpNciHal_utils.h>

#define CRC_LEN 2
#define NORMAL_MODE_HEADER_LEN 3
#define FW_DNLD_HEADER_LEN 2
#define FW_DNLD_LEN_OFFSET 1
#define NORMAL_MODE_LEN_OFFSET 2
#define FRAGMENTSIZE_MAX PHNFC_I2C_FRAGMENT_SIZE
static bool_t bFwDnldFlag = false;
bool_t notifyFwrequest;

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

  NXPLOG_TML_D("Opening port=%s\n", pConfig->pDevName);
  /* open port */
  nHandle = open((const char*)pConfig->pDevName, O_RDWR);
  if (nHandle < 0) {
    NXPLOG_TML_E("_i2c_open() Failed: retval %x", nHandle);
    *pLinkHandle = NULL;
    return NFCSTATUS_INVALID_DEVICE;
  }

  *pLinkHandle = (void*)((intptr_t)nHandle);

  /*Reset PN54X*/
  phTmlNfc_i2c_reset((void*)((intptr_t)nHandle), 0);
  usleep(10 * 1000);
  phTmlNfc_i2c_reset((void*)((intptr_t)nHandle), 1);

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

  UNUSED(nNbBytesToRead);
  if (NULL == pDevHandle) {
    return -1;
  }

  if (false == bFwDnldFlag) {
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
    if (ret_Read > 0) {
      numRead += ret_Read;
    } else if (ret_Read == 0) {
      NXPLOG_TML_E("_i2c_read() [hdr]EOF");
      return -1;
    } else {
      NXPLOG_TML_E("_i2c_read() [hdr] errno : %x", errno);
      return -1;
    }

    if (false == bFwDnldFlag) {
      totalBtyesToRead = NORMAL_MODE_HEADER_LEN;
    } else {
      totalBtyesToRead = FW_DNLD_HEADER_LEN;
    }

    if (numRead < totalBtyesToRead) {
      ret_Read =
          read((intptr_t)pDevHandle, pBuffer + numRead, totalBtyesToRead - numRead);
      if (ret_Read != totalBtyesToRead - numRead) {
        NXPLOG_TML_E("_i2c_read() [hdr] errno : %x", errno);
        return -1;
      } else {
        numRead += ret_Read;
      }
    }
    if (true == bFwDnldFlag) {
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
        NXPLOG_TML_E("_i2c_read() [pyld] EOF");
        return -1;
      } else {
        if (false == bFwDnldFlag) {
          NXPLOG_TML_D("_i2c_read() [hdr] received");
          phNxpNciHal_print_packet("RECV", pBuffer, NORMAL_MODE_HEADER_LEN);
        }
        NXPLOG_TML_E("_i2c_read() [pyld] errno : %x", errno);
        return -1;
      }
    } else {
      NXPLOG_TML_E("_>>>>> Empty packet recieved !!");
    }
  }
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
    ret = write((intptr_t)pDevHandle, pBuffer + numWrote, numBytes - numWrote);
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
  int ret = -1;

  NXPLOG_TML_D("phTmlNfc_i2c_reset(), VEN level %ld", level);

  if (NULL == pDevHandle) {
    return -1;
  }
  ret = ioctl((intptr_t)pDevHandle, PN544_SET_PWR, level);
  if (ret < 0) {
    NXPLOG_TML_E("%s :failed errno = 0x%x", __func__, errno);
    if (level == 2 && errno == EBUSY) {
      notifyFwrequest = true;
    } else {
      notifyFwrequest = false;
    }
  }
  if (level == 2 && ret == 0) {
    bFwDnldFlag = true;
  } else {
    bFwDnldFlag = false;
  }
  return ret;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_set_Jcop_dwnld_state
**
** Description      This function set jcop download state.
**
** Parameters       pDevHandle     - valid device handle
**
** Returns          NFCSTATUS
**
**
*******************************************************************************/
NFCSTATUS phTmlNfc_i2c_set_Jcop_dwnld_state(void* pDevHandle, long level) {
    NXPLOG_TML_D("phTmlNfc_i2c_set_Jcop_dwnld_state()");
    if(!nfcFL.nfcNxpEse) {
        NXPLOG_TML_D("NxpEse not available. Returning");
        return NFCSTATUS_FAILED;
    }
  int32_t ret = -1;
  NFCSTATUS wStatus = NFCSTATUS_SUCCESS;

  NXPLOG_TML_D("phTmlNfc_i2c_set_Jcop_dwnld_state(), level %ld", level);

  if (NULL == pDevHandle) return NFCSTATUS_FAILED;

  ret =
      ioctl((intptr_t)pDevHandle, PN544_SET_DWNLD_STATUS, (unsigned long)level);
  if (ret < 0) {
    NXPLOG_TML_E("%s : failed errno = 0x%x", __func__, errno);
    if (errno == -EBUSY) {
      wStatus = NFCSTATUS_BUSY;
    } else if (errno == -EBADRQC) {
      wStatus = NFCSTATUS_INVALID_FORMAT;
    } else if (errno == -EINVAL) {
      wStatus = NFCSTATUS_INVALID_PARAMETER;
    } else {
      wStatus = NFCSTATUS_FAILED;
    }
  }
  return wStatus;
}

/*******************************************************************************
**
** Function         phTmlNfc_set_pid
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**                        pid - nfc service pid
**
** Returns          p61_access_state_t  - get_p61_power operation success
**                  P61_STATE_INVALID   - get_p61_power operation failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_set_pid(void* pDevHandle, long pid) {
    NXPLOG_TML_D("phTmlNfc_set_pid()");
        if(!nfcFL.nfcNxpEse) {
            NXPLOG_TML_D("NxpEse not available. Returning");
            return NFCSTATUS_FAILED;
        }
  NFCSTATUS wStatus = NFCSTATUS_FAILED;
  uint32_t ret = -1;
  NXPLOG_TML_D("phTmlNfc_set_pid(), pid  %ld", pid);

  if (NULL == pDevHandle) {
    return NFCSTATUS_FAILED;
  }

  ret = (uint32_t)ioctl((intptr_t)pDevHandle, P544_SET_NFC_SERVICE_PID, pid);
  if (!ret) wStatus = NFCSTATUS_SUCCESS;

  return wStatus;
}

/*******************************************************************************
**
** Function         phTmlNfc_set_power_scheme
**
** Description      This function sets the eSE power scheme in pn544 driver
**
** Parameters       pDevHandle     - valid device handle
**                        pid - nfc service pid
**
** Returns          p61_access_state_t  - get_p61_power operation success
**                  P61_STATE_INVALID   - get_p61_power operation failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_set_power_scheme(void* pDevHandle, long id) {
    NXPLOG_TML_D("phTmlNfc_set_power_scheme()");
    if(!nfcFL.nfcNxpEse) {
        NXPLOG_TML_D("NxpEse not available. Returning");
        return NFCSTATUS_FAILED;
    }
  int ret;
  NXPLOG_TML_D("phTmlNfc_set_power_scheme(), id  %ld", id);

  if (NULL == pDevHandle) {
    return NFCSTATUS_FAILED;
  }

  ret = ioctl((intptr_t)pDevHandle, P544_SET_POWER_SCHEME, id);
  return ret;
}
/*******************************************************************************
**
** Function         phTmlNfc_i2c_set_p61_power_state
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**
** Returns          p61_access_state_t  - get_p61_power operation success
**                  P61_STATE_INVALID   - get_p61_power operation failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_i2c_set_p61_power_state(void* pDevHandle, long level) {
    NXPLOG_TML_D("phTmlNfc_i2c_set_p61_power_state()");
    if(!nfcFL.nfcNxpEse) {
        NXPLOG_TML_D("NxpEse not available. Returning");
        return NFCSTATUS_FAILED;
    }
  int ret = -1;
  NFCSTATUS wStatus = NFCSTATUS_FAILED;

  NXPLOG_TML_D("phTmlNfc_i2c_set_p61_power_state(), level %ld", level);

  if (NULL == pDevHandle) {
    return -1;
  }
  ret = ioctl((intptr_t)pDevHandle, P61_SET_WIRED_ACCESS, (unsigned long)level);
  if (ret < 0) {
    NXPLOG_TML_E("%s : failed errno = 0x%x", __func__, errno);
    if (errno == -EBUSY) {
      wStatus = NFCSTATUS_BUSY;
    } else if (errno == -EPERM) {
      wStatus = NFCSTATUS_NOT_ALLOWED;
    } else if (errno == -EBADRQC) {
      wStatus = NFCSTATUS_INVALID_PARAMETER;
    } else {
      wStatus = NFCSTATUS_FAILED;
    }
  } else {
    wStatus = NFCSTATUS_SUCCESS;
  }

  return wStatus;
}

/*******************************************************************************
**
** Function         phTmlNfc_i2c_get_p61_power_state
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**
** Returns          get_p61_power operation success
**                  NFCSTATUS_FAILED   - get_p61_power operation failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_i2c_get_p61_power_state(void* pDevHandle) {
    NXPLOG_TML_D("phTmlNfc_i2c_get_p61_power_state()");
    if(!nfcFL.nfcNxpEse) {
        NXPLOG_TML_D("NxpEse not available. Returning");
        return NFCSTATUS_FAILED;
    }
  int ret;
  NFCSTATUS wStatus = NFCSTATUS_FAILED;
  p61_access_state_t p61_current_state = P61_STATE_INVALID;
  NXPLOG_TML_D("phTmlNfc_i2c_get_p61_power_mode()");

  if (NULL == pDevHandle) {
    return -1;
  }
  ret = ioctl((intptr_t)pDevHandle, P61_GET_PWR_STATUS,
              (unsigned long)&p61_current_state);
  if (ret < 0) {
    NXPLOG_TML_E("%s : failed errno = 0x%x", __func__, errno);
    p61_current_state = P61_STATE_INVALID;
  }
  wStatus = p61_current_state;
  return wStatus;
}
/*******************************************************************************
**
** Function         phTmlNfc_get_ese_access
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**                  timeout - timeout to wait for ese access
**
** Returns          success or failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_get_ese_access(void* pDevHandle, long timeout) {
    NXPLOG_TML_D("phTmlNfc_get_ese_access()");
    if(!nfcFL.nfcNxpEse) {
        NXPLOG_TML_D("NxpEse not available. Returning");
        return NFCSTATUS_FAILED;
    }
  int ret = -1;
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  NXPLOG_TML_D("phTmlNfc_get_ese_access(), enter timeout  %ld", timeout);

  if (NULL == pDevHandle) {
    return NFCSTATUS_FAILED;
  }

  ret = ioctl((intptr_t)pDevHandle, P544_GET_ESE_ACCESS, timeout);
  if (ret < 0) {
    if (ret == -EBUSY)
      status = NFCSTATUS_BUSY;
    else
      status = NFCSTATUS_FAILED;
  }
  NXPLOG_TML_D("phTmlNfc_get_ese_access(), exit ret %d, status %d", ret,
               status);
  return status;
}

/*******************************************************************************
**
** Function         phTmlNfc_rel_svdd_wait
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**
** Returns          success or failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_rel_svdd_wait(void *pDevHandle, long svddWaitStatus) {
  NXPLOG_TML_D("phTmlNfc_rel_svdd_wait()");
  if (!nfcFL.nfcNxpEse && !nfcFL.eseFL._ESE_SVDD_SYNC) {
    NXPLOG_TML_D("NxpEse and ESE_SVDD_SYNC not available. Returning");
    return NFCSTATUS_FAILED;
  }
  int ret = -1;
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  NXPLOG_TML_D("phTmlNfc_rel_svdd_wait(), enter ");

  if (NULL == pDevHandle) {
    return NFCSTATUS_FAILED;
  }

  ret = ioctl((intptr_t)pDevHandle, P544_REL_SVDD_WAIT, svddWaitStatus);
  if (ret < 0) {
    if (ret == -EBUSY)
      status = NFCSTATUS_BUSY;
    else
      status = NFCSTATUS_FAILED;
  }
  NXPLOG_TML_D("phTmlNfc_rel_svdd_wait(), exit  ret %d, status %d", ret,
               status);
  return status;
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

/*******************************************************************************
**
** Function         phTmlNfc_rel_dwpOnOff_wait
**
** Description
**
** Parameters       pDevHandle     - valid device handle
**
** Returns          success or failure
**
*******************************************************************************/
NFCSTATUS phTmlNfc_rel_dwpOnOff_wait(void *pDevHandle, long dwplinkActvStatus) {
  int ret = -1;
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  NXPLOG_TML_D("phTmlNfc_rel_dwpOnOff_wait(), enter ");

  if (NULL == pDevHandle) {
    return NFCSTATUS_FAILED;
  }

  ret = ioctl((intptr_t)pDevHandle, P544_REL_DWPONOFF_WAIT, dwplinkActvStatus);
  if (ret < 0) {
    if (ret == -EBUSY)
      status = NFCSTATUS_BUSY;
    else
      status = NFCSTATUS_FAILED;
  }
  NXPLOG_TML_D("phTmlNfc_rel_dwpOnOff_wait(), exit  ret %d, status %d", ret,
               status);
  return status;

}
