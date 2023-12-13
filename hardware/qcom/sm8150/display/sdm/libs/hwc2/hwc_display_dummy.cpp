/*
* Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
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

#include "hwc_display_dummy.h"
#include "utils/debug.h"

#define __CLASS__ "HWCDisplayDummy"

namespace sdm {

int HWCDisplayDummy::Create(CoreInterface *core_intf, BufferAllocator *buffer_allocator,
                            HWCCallbacks *callbacks, HWCDisplayEventHandler *event_handler,
                            qService::QService *qservice, hwc2_display_t id, int32_t sdm_id,
                            HWCDisplay **hwc_display) {
  HWCDisplay *hwc_display_dummy = new HWCDisplayDummy(core_intf, buffer_allocator, callbacks,
                                      event_handler, qservice, id, sdm_id);
  *hwc_display = hwc_display_dummy;
  return kErrorNone;
}

void HWCDisplayDummy::Destroy(HWCDisplay *hwc_display) {
  delete hwc_display;
}

HWC2::Error HWCDisplayDummy::Validate(uint32_t *out_num_types, uint32_t *out_num_requests) {
  return HWC2::Error::None;
}

HWC2::Error HWCDisplayDummy::Present(int32_t *out_retire_fence) {
  for (auto hwc_layer : layer_set_) {
    hwc_layer->PushBackReleaseFence(-1);
  }
  return HWC2::Error::None;
}

HWCDisplayDummy::HWCDisplayDummy(CoreInterface *core_intf, BufferAllocator *buffer_allocator,
                                 HWCCallbacks *callbacks, HWCDisplayEventHandler *event_handler,
                                 qService::QService *qservice, hwc2_display_t id,
                                 int32_t sdm_id) :HWCDisplay(core_intf, buffer_allocator,
                                 callbacks, event_handler, qservice, kBuiltIn, id, sdm_id, true,
                                 DISPLAY_CLASS_BUILTIN) {
  DisplayConfigVariableInfo config;
  config.x_pixels = 720;
  config.y_pixels = 1280;
  config.x_dpi = 200.0f;
  config.y_dpi = 200.0f;
  config.fps = 60;
  config.vsync_period_ns = 16600000;
  display_null_.SetFrameBufferConfig(config);
  num_configs_ = 1;
  display_intf_ = &display_null_;
}

HWC2::Error HWCDisplayDummy::GetActiveConfig(hwc2_config_t *out_config) {
  *out_config = 0;
  return HWC2::Error::None;
}

}  // namespace sdm
