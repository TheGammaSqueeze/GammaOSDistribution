/*
* Copyright (c) 2017, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*       copyright notice, this list of conditions and the following
*       disclaimer in the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of The Linux Foundation nor the names of its
*       contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __HW_COLOR_MANAGER_DRM_H__
#define __HW_COLOR_MANAGER_DRM_H__

#include <drm_interface.h>
#include <private/color_params.h>
#include <vector>
#include <map>

using sde_drm::DRMPPFeatureID;
using sde_drm::DRMPPFeatureInfo;

using sde_drm::kFeaturePcc;
using sde_drm::kFeatureIgc;
using sde_drm::kFeaturePgc;
using sde_drm::kFeatureMixerGc;
using sde_drm::kFeaturePaV2;
using sde_drm::kFeatureDither;
using sde_drm::kFeatureGamut;
using sde_drm::kFeaturePADither;
using sde_drm::kFeaturePAHsic;
using sde_drm::kFeaturePASixZone;
using sde_drm::kFeaturePAMemColSkin;
using sde_drm::kFeaturePAMemColSky;
using sde_drm::kFeaturePAMemColFoliage;
using sde_drm::kFeaturePAMemColProt;
using sde_drm::kPPFeaturesMax;

namespace sdm {

typedef std::map<uint32_t, std::vector<uint32_t>> DrmPPFeatureMap;

static const DrmPPFeatureMap DrmPPfeatureMap_ = \
  {{kGlobalColorFeaturePcc, {kFeaturePcc}},
    {kGlobalColorFeatureIgc, {kFeatureIgc}},
    {kGlobalColorFeaturePgc, {kFeaturePgc}},
    {kMixerColorFeatureGc, {kMixerColorFeatureGc}},
    {kGlobalColorFeaturePaV2, {kFeaturePAHsic, kFeaturePASixZone,
                               kFeaturePAMemColSkin, kFeaturePAMemColSky,
                               kFeaturePAMemColFoliage, kFeaturePAMemColProt}},
    {kGlobalColorFeatureDither, {kFeatureDither}},
    {kGlobalColorFeatureGamut, {kFeatureGamut}},
    {kGlobalColorFeaturePADither, {kFeaturePADither}},
};

static const uint32_t kMaxPCCChanel = 3;

class HWColorManagerDrm {
 public:
  static DisplayError (*GetDrmFeature[kPPFeaturesMax])(const PPFeatureInfo &in_data,
                                                          DRMPPFeatureInfo *out_data);
  static void FreeDrmFeatureData(DRMPPFeatureInfo *feature);
  static uint32_t GetFeatureVersion(const DRMPPFeatureInfo &feature);
  static DRMPPFeatureID ToDrmFeatureId(uint32_t id);

 protected:
  HWColorManagerDrm() {}

 private:
  static DisplayError GetDrmPCC(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmIGC(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPGC(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmMixerGC(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmDither(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmGamut(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPADither(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPAHsic(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPASixZone(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPAMemColSkin(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPAMemColSky(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPAMemColFoliage(const PPFeatureInfo &in_data,
                                            DRMPPFeatureInfo *out_data);
  static DisplayError GetDrmPAMemColProt(const PPFeatureInfo &in_data, DRMPPFeatureInfo *out_data);
};

}  // namespace sdm

#endif  // __HW_COLOR_MANAGER_DRM_H__
