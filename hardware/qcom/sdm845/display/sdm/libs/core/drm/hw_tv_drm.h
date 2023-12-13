/*
* Copyright (c) 2017-2018, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright notice, this list of
*      conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright notice, this list of
*      conditions and the following disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its contributors may be used to
*      endorse or promote products derived from this software without specific prior written
*      permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __HW_TV_DRM_H__
#define __HW_TV_DRM_H__

#include <map>
#include <vector>

#include "hw_device_drm.h"

namespace sdm {

using std::vector;

class HWTVDRM : public HWDeviceDRM {
 public:
  explicit HWTVDRM(BufferSyncHandler *buffer_sync_handler, BufferAllocator *buffer_allocator,
                     HWInfoInterface *hw_info_intf);

 protected:
  virtual DisplayError SetDisplayAttributes(uint32_t index);
  virtual DisplayError GetConfigIndex(char *mode, uint32_t *index);
  virtual DisplayError PowerOff();
  virtual DisplayError Doze(int *release_fence);
  virtual DisplayError DozeSuspend(int *release_fence);
  virtual DisplayError Standby();
  virtual DisplayError Commit(HWLayers *hw_layers);
  virtual void PopulateHWPanelInfo();
  virtual DisplayError OnMinHdcpEncryptionLevelChange(uint32_t min_enc_level);
  virtual DisplayError PowerOn(int *release_fence);

 private:
  DisplayError UpdateHDRMetaData(HWLayers *hw_layers);
  void DumpHDRMetaData(HWHDRLayerInfo::HDROperation operation);

  static const int kBitRGB  = 20;
  static const int kBitYUV  = 21;
  drm_msm_ext_hdr_metadata hdr_metadata_ = {};
};

}  // namespace sdm

#endif  // __HW_TV_DRM_H__

