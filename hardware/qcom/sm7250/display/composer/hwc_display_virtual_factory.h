/*
 * Copyright (c) 2019, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

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
#ifndef __HWC_DISPLAY_VIRTUAL_FACTORY_H__
#define __HWC_DISPLAY_VIRTUAL_FACTORY_H__

#include <core/core_interface.h>

#include "hwc_callbacks.h"
#include "hwc_debugger.h"
#include "hwc_display.h"
#include "hwc_buffer_allocator.h"

namespace sdm {

class HWCVirtualDisplayFactory {
 public:
  int Create(CoreInterface *core_intf, HWCBufferAllocator *buffer_allocator,
             HWCCallbacks *callbacks, hwc2_display_t id, int32_t sdm_id, uint32_t width,
             uint32_t height, int32_t *format, float min_lum, float max_lum,
             HWCDisplay **hwc_display);
  void Destroy(HWCDisplay *hwc_display);
  bool IsGPUColorConvertSupported();
};

}  // namespace sdm

#endif  // __HWC_DISPLAY_VIRTUAL_FACTORY_H__
