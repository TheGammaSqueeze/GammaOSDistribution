/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2010-2014 NXP Semiconductors
 * Copyright (C) 2015 The Android Open Source Project
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

/*include files*/
#include <phNciNfcTypes.h>
#include <phNfcStatus.h>
#include <phNfcTypes.h>
#include <time.h>
#include <Mutex.h>

typedef void (*TIMER_FUNC)(union sigval);

typedef struct phFriNfc_MifareStdTimer {
  timer_t mTimerId;   // timer id which will be assigned by create timer
  TIMER_FUNC mCb;     // callback function for timeout
  uint32_t mtimeout;  // timeout value in ms.
  Mutex timerSyncMutex;  // mutext to synchronize timer update
} phFriNfc_MifareStdTimer_t;

NFCSTATUS phFriNfc_MifareStd_StartTimer(phFriNfc_MifareStdTimer_t* timer);

NFCSTATUS phFriNfc_MifareStd_StopTimer(phFriNfc_MifareStdTimer_t* timer);
