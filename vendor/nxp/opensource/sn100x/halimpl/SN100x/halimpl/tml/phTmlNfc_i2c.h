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
 * TML I2C port implementation for linux
 */

/* Basic type definitions */
#include <phNfcTypes.h>
#include <phTmlNfc.h>
#define PN544_MAGIC 0xE9

typedef enum {
  MODE_POWER_OFF = 0x00,
  MODE_POWER_ON,
  MODE_FW_DWNLD_WITH_VEN,
  MODE_ISO_RST,
  MODE_FW_DWND_HIGH,
  MODE_POWER_RESET,
  MODE_FW_GPIO_LOW,
  MODE_NFC_ENABLED,
  MODE_NFC_DISABLED,
  MODE_FW_DWND_HDR,
} MODE_I2C_SET_PWR;

typedef enum {
  MODE_ESE_POWER_ON = 0, /* eSE POWER ON */
  MODE_ESE_POWER_OFF,    /* eSE POWER OFF */
  MODE_ESE_POWER_STATE,  /* eSE POWER STATE */
  MODE_ESE_COLD_RESET    /* eSE COLD RESET */
}MODE_ESE_SET_PWR;

/* Function declarations */
void phTmlNfc_i2c_close(void* pDevHandle);
NFCSTATUS phTmlNfc_i2c_open_and_configure(pphTmlNfc_Config_t pConfig,
                                          void** pLinkHandle);
int phTmlNfc_i2c_read(void* pDevHandle, uint8_t* pBuffer, int nNbBytesToRead);
int phTmlNfc_i2c_write(void* pDevHandle, uint8_t* pBuffer, int nNbBytesToWrite);
int phTmlNfc_i2c_reset(void* pDevHandle, long level);
int phTmlNfc_ese_reset(void* pDevHandle, long level);
bool_t getDownloadFlag(void);
void phTmlNfc_EnableFwDnldMode(bool mode);
extern bool_t notifyFwrequest;
extern phTmlNfc_i2cfragmentation_t fragmentation_enabled;

/*
 * PN544 power control via ioctl
 * PN544_SET_PWR(0): power off
 * PN544_SET_PWR(1): power on
 * PN544_SET_PWR(2): reset and power on with firmware download enabled
 */
#define PN544_SET_PWR _IOW(PN544_MAGIC, 0x01, unsigned int)
NFCSTATUS phTmlNfc_i2c_get_p61_power_state(void* pDevHandle);
NFCSTATUS phTmlNfc_i2c_set_p61_power_state(void* pDevHandle, long arg);
NFCSTATUS phTmlNfc_set_pid(void* pDevHandle, long pid);
NFCSTATUS phTmlNfc_set_power_scheme(void* pDevHandle, long id);
NFCSTATUS phTmlNfc_get_ese_access(void* pDevHandle, long timeout);
NFCSTATUS phTmlNfc_i2c_set_Jcop_dwnld_state(void* pDevHandle, long level);
NFCSTATUS phTmlNfc_i2c_set_spm_state(void* pa_data, void* pDevHandle);
NFCSTATUS phTmlNfc_i2c_reset_spm_state(void* pa_data, void* pDevHandle);
NFCSTATUS phTmlNfc_rel_svdd_wait(void* pDevHandle);
NFCSTATUS phTmlNfc_rel_dwpOnOff_wait(void* pDevHandle);
int phTmlNfc_get_platform(void* pDevHandle);
/*
 * 1. SPI Request NFCC to enable p61 power, only in param
 *   Only for SPI
 *   level 1 = Enable power
 *   level 0 = Disable power
 * 2. NFC Request the eSE cold reset, only with MODE_ESE_COLD_RESET
 */
#define ESE_SET_PWR _IOW(PN544_MAGIC, 0x02, unsigned int)

/* SPI or DWP can call this ioctl to get the current
 * power state of P61
 *
*/
#define ESE_GET_PWR _IOR(PN544_MAGIC, 0x03, unsigned int)

/*
 * get platform interface type(i2c or i3c) for common MW
 * return 0 - i2c, 1 - i3c
 */
#define P544_GET_PLATFORM_INTERFACE _IO(PN544_MAGIC, 0x04)
//#endif
