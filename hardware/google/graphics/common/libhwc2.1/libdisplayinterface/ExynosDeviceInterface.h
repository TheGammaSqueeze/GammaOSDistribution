/*
 * Copyright (C) 2019 The Android Open Source Project
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

#ifndef _EXYNOSDEVICEINTERFACE_H
#define _EXYNOSDEVICEINTERFACE_H

#include "ExynosHWCHelper.h"
#include "ExynosDisplayInterface.h"

struct hwc_dpp_size_range {
  uint32_t min;
  uint32_t max;
  uint32_t align;
};

struct hwc_dpp_restriction {
  struct hwc_dpp_size_range src_f_w;
  struct hwc_dpp_size_range src_f_h;
  struct hwc_dpp_size_range src_w;
  struct hwc_dpp_size_range src_h;
  uint32_t src_x_align;
  uint32_t src_y_align;
  struct hwc_dpp_size_range dst_f_w;
  struct hwc_dpp_size_range dst_f_h;
  struct hwc_dpp_size_range dst_w;
  struct hwc_dpp_size_range dst_h;
  uint32_t dst_x_align;
  uint32_t dst_y_align;
  struct hwc_dpp_size_range blk_w;
  struct hwc_dpp_size_range blk_h;
  uint32_t blk_x_align;
  uint32_t blk_y_align;
  uint32_t src_h_rot_max;
  std::vector<uint32_t> formats;
  uint32_t scale_down;
  uint32_t scale_up;
};

struct hwc_dpp_ch_restriction {
  int id;
  unsigned long attr;
  struct hwc_dpp_restriction restriction;
};

struct hwc_dpp_restrictions_info {
  uint32_t ver;
  std::vector<hwc_dpp_ch_restriction> dpp_chs;
  uint32_t ppc = 0;
  uint32_t max_disp_freq = 0;
};

/* for restriction query */
typedef struct dpu_dpp_info {
    struct hwc_dpp_restrictions_info dpuInfo;
    bool overlap[16] = {false, };
} dpu_dpp_info_t;

class ExynosDevice;
class ExynosDeviceInterface {
    protected:
        ExynosDevice *mExynosDevice = NULL;
        bool mUseQuery = false;
        // Gathered DPU resctrictions
        dpu_dpp_info_t mDPUInfo;
    public:
        virtual ~ExynosDeviceInterface(){};
        virtual void init(ExynosDevice *exynosDevice) = 0;
        virtual int32_t initDisplayInterface(
                std::unique_ptr<ExynosDisplayInterface> &dispInterface)
        { return 0;};
        /* Fill mDPUInfo according to interface type */
        virtual void updateRestrictions() = 0;
        virtual bool getUseQuery() { return mUseQuery; };
        ExynosDevice* getExynosDevice() {return mExynosDevice;};
    protected:
        /* Make dpu restrictions using mDPUInfo */
        int32_t makeDPURestrictions();
        /* Update feature table using mDPUInfo */
        int32_t updateFeatureTable();
        /* Print restriction */
        void printDppRestriction(struct hwc_dpp_ch_restriction res);
    public:
        uint32_t mType = INTERFACE_TYPE_NONE;
};
#endif //_EXYNOSDEVICEINTERFACE_H
