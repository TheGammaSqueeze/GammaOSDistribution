/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include "Backend.h"

#include <climits>

#include "BackendManager.h"
#include "bufferinfo/BufferInfoGetter.h"

namespace android {

HWC2::Error Backend::ValidateDisplay(DrmHwcTwo::HwcDisplay *display,
                                     uint32_t *num_types,
                                     uint32_t *num_requests) {
  *num_types = 0;
  *num_requests = 0;

  auto layers = display->GetOrderLayersByZPos();

  int client_start = -1;
  size_t client_size = 0;

  if (display->compositor().ShouldFlattenOnClient()) {
    client_start = 0;
    client_size = layers.size();
    MarkValidated(layers, client_start, client_size);
  } else {
    std::tie(client_start, client_size) = GetClientLayers(display, layers);

    MarkValidated(layers, client_start, client_size);

    bool testing_needed = !(client_start == 0 && client_size == layers.size());

    if (testing_needed &&
        display->CreateComposition(true) != HWC2::Error::None) {
      ++display->total_stats().failed_kms_validate_;
      client_start = 0;
      client_size = layers.size();
      MarkValidated(layers, 0, client_size);
    }
  }

  *num_types = client_size;

  display->total_stats().frames_flattened_ = display->compositor()
                                                 .GetFlattenedFramesCount();
  display->total_stats().gpu_pixops_ += CalcPixOps(layers, client_start,
                                                   client_size);
  display->total_stats().total_pixops_ += CalcPixOps(layers, 0, layers.size());

  return *num_types ? HWC2::Error::HasChanges : HWC2::Error::None;
}

std::tuple<int, size_t> Backend::GetClientLayers(
    DrmHwcTwo::HwcDisplay *display,
    const std::vector<DrmHwcTwo::HwcLayer *> &layers) {
  int client_start = -1;
  size_t client_size = 0;

  for (int z_order = 0; z_order < layers.size(); ++z_order) {
    if (IsClientLayer(display, layers[z_order])) {
      if (client_start < 0)
        client_start = (int)z_order;
      client_size = (z_order - client_start) + 1;
    }
  }

  return GetExtraClientRange(display, layers, client_start, client_size);
}

bool Backend::IsClientLayer(DrmHwcTwo::HwcDisplay *display,
                            DrmHwcTwo::HwcLayer *layer) {
  return !HardwareSupportsLayerType(layer->sf_type()) ||
         !BufferInfoGetter::GetInstance()->IsHandleUsable(layer->buffer()) ||
         display->color_transform_hint() != HAL_COLOR_TRANSFORM_IDENTITY ||
         (layer->RequireScalingOrPhasing() &&
          display->resource_manager()->ForcedScalingWithGpu());
}

bool Backend::HardwareSupportsLayerType(HWC2::Composition comp_type) {
  return comp_type == HWC2::Composition::Device ||
         comp_type == HWC2::Composition::Cursor;
}

uint32_t Backend::CalcPixOps(const std::vector<DrmHwcTwo::HwcLayer *> &layers,
                             size_t first_z, size_t size) {
  uint32_t pixops = 0;
  for (int z_order = 0; z_order < layers.size(); ++z_order) {
    if (z_order >= first_z && z_order < first_z + size) {
      hwc_rect_t df = layers[z_order]->display_frame();
      pixops += (df.right - df.left) * (df.bottom - df.top);
    }
  }
  return pixops;
}

void Backend::MarkValidated(std::vector<DrmHwcTwo::HwcLayer *> &layers,
                            size_t client_first_z, size_t client_size) {
  for (int z_order = 0; z_order < layers.size(); ++z_order) {
    if (z_order >= client_first_z && z_order < client_first_z + client_size)
      layers[z_order]->set_validated_type(HWC2::Composition::Client);
    else
      layers[z_order]->set_validated_type(HWC2::Composition::Device);
  }
}

std::tuple<int, int> Backend::GetExtraClientRange(
    DrmHwcTwo::HwcDisplay *display,
    const std::vector<DrmHwcTwo::HwcLayer *> &layers, int client_start,
    size_t client_size) {
  size_t avail_planes = display->primary_planes().size() +
                        display->overlay_planes().size();

  /*
   * If more layers then planes, save one plane
   * for client composited layers
   */
  if (avail_planes < display->layers().size())
    avail_planes--;

  int extra_client = int(layers.size() - client_size) - int(avail_planes);

  if (extra_client > 0) {
    int start = 0;
    size_t steps = 0;
    if (client_size != 0) {
      int prepend = std::min(client_start, extra_client);
      int append = std::min(int(layers.size()) -
                                int(client_start + client_size),
                            extra_client);
      start = client_start - (int)prepend;
      client_size += extra_client;
      steps = 1 + std::min(std::min(append, prepend),
                           int(layers.size()) - int(start + client_size));
    } else {
      client_size = extra_client;
      steps = 1 + layers.size() - extra_client;
    }

    uint32_t gpu_pixops = INT_MAX;
    for (int i = 0; i < steps; i++) {
      uint32_t po = CalcPixOps(layers, start + i, client_size);
      if (po < gpu_pixops) {
        gpu_pixops = po;
        client_start = start + i;
      }
    }
  }

  return std::make_tuple(client_start, client_size);
}

// clang-format off
// NOLINTNEXTLINE(cppcoreguidelines-avoid-non-const-global-variables, cert-err58-cpp)
REGISTER_BACKEND("generic", Backend);
// clang-format on

}  // namespace android
