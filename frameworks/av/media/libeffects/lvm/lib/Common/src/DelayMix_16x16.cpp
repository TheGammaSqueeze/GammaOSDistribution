/*
 * Copyright (C) 2004-2010 NXP Software
 * Copyright (C) 2010 The Android Open Source Project
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

/**********************************************************************************
   INCLUDE FILES
***********************************************************************************/

#include "VectorArithmetic.h"

void DelayMix_Float(const LVM_FLOAT* src, /* Source 1, to be delayed */
                    LVM_FLOAT* delay,     /* Delay buffer */
                    LVM_INT16 size,       /* Delay size */
                    LVM_FLOAT* dst,       /* Source/destination */
                    LVM_INT16* pOffset,   /* Delay offset */
                    LVM_INT16 n,          /* Number of samples */
                    LVM_INT32 NrChannels) /* Number of channels */
{
    LVM_INT16 i;
    LVM_INT16 Offset = *pOffset;
    LVM_FLOAT temp;

    for (i = 0; i < n; i++) {
        if (NrChannels == FCC_1) {
            temp = (LVM_FLOAT)(*dst + (LVM_FLOAT)delay[Offset]) / 2.0f;
            *dst = temp;
            dst++;

            delay[Offset] = *src;
            Offset++;
            src++;

            /* Make the reverb delay buffer a circular buffer */
            if (Offset >= size) {
                Offset = 0;
            }
        } else {
            /* Left channel */
            temp = (LVM_FLOAT)(*dst + (LVM_FLOAT)delay[Offset]) / 2.0f;
            *dst = temp;
            dst++;

            delay[Offset] = *src;
            Offset++;
            src++;

            /* Right channel */
            temp = (LVM_FLOAT)(*dst - (LVM_FLOAT)delay[Offset]) / 2.0f;
            *dst = temp;
            dst++;

            delay[Offset] = *src;
            Offset++;
            src++;

            /* Make the reverb delay buffer a circular buffer */
            if (Offset >= size) {
                Offset = 0;
            }
        }
    }

    /* Update the offset */
    *pOffset = Offset;

    return;
}
