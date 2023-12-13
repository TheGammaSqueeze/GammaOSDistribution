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

#ifndef CLIENT_INTF_H_
#define CLIENT_INTF_H_
#include <pthread.h>
#include <string>

#define SEMS_STATUS_FAILED_SW1 0x63
#define SEMS_STATUS_FAILED_SW2 0x40

#define SEMS_STATUS_SUCCESS_SW1 0x90
#define SEMS_STATUS_SUCCESS_SW2 0x00

#define JCOP_UPDATE_3STEP_DONE 3

typedef struct se_extns_entry{
  uint8_t isJcopUpdateRequired;
  uint8_t isLSUpdateRequired;
  unsigned long int sJcopUpdateIntferface;
  unsigned long int sLsUpdateIntferface;
} se_extns_entry;

typedef enum {
  ESE_INTF_INVALID = 0,
  ESE_INTF_NFC = 1,
  ESE_INTF_SPI = 2
}ESE_CLIENT_INTF;

typedef enum {
  SESTATUS_SUCCESS = (0x0000),
  SESTATUS_FAILED = (0x0003),
  SESTATUS_FILE_NOT_FOUND = (0x0005)
} SESTATUS;

typedef enum {
  ESE_UPDATE_COMPLETED = 0,
  ESE_UPDATE_STARTED,
  ESE_JCOP_UPDATE_REQUIRED,
  ESE_JCOP_UPDATE_COMPLETED,
  ESE_LS_UPDATE_REQUIRED,
  ESE_LS_UPDATE_COMPLETED
}ese_update_state_t;

extern bool nfc_debug_enabled;
/*******************************************************************************
**
** Function:        checkeSEClientRequired
**
** Description:     Read the interface and condition for ese Update(JCOP download/LS download)
**
** Returns:         SUCCESS of ok
**
*******************************************************************************/
uint8_t checkeSEClientRequired(ESE_CLIENT_INTF intf );

uint8_t getJcopUpdateRequired();
uint8_t getLsUpdateRequired();
uint8_t getJcopUpdateIntf();
uint8_t getLsUpdateIntf();
bool geteSETerminalId(char*);
bool geteUICCTerminalId(char*);
bool getNfcSeTerminalId(char*);
void setJcopUpdateRequired(uint8_t state);
void setLsUpdateRequired(uint8_t  state);
#endif /* CLIENT_INTF_H_ */
