/*
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

#ifndef ANDROID_DRM_PLATFORM_H_
#define ANDROID_DRM_PLATFORM_H_

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

#include <map>
#include <memory>
#include <vector>

#include "compositor/DrmDisplayComposition.h"
#include "drmhwcomposer.h"

namespace android {

class DrmDevice;

class Planner {
 public:
  class PlanStage {
   public:
    virtual ~PlanStage() {
    }

    virtual int ProvisionPlanes(std::vector<DrmCompositionPlane> *composition,
                                std::map<size_t, DrmHwcLayer *> &layers,
                                std::vector<DrmPlane *> *planes) = 0;

   protected:
    // Removes and returns the next available plane from planes
    static DrmPlane *PopPlane(std::vector<DrmPlane *> *planes) {
      if (planes->empty())
        return NULL;
      DrmPlane *plane = planes->front();
      planes->erase(planes->begin());
      return plane;
    }

    // Inserts the given layer:plane in the composition at the back
    static int Emplace(std::vector<DrmCompositionPlane> *composition,
                       std::vector<DrmPlane *> *planes,
                       DrmCompositionPlane::Type type,
                       std::pair<size_t, DrmHwcLayer *> layer) {
      DrmPlane *plane = PopPlane(planes);
      std::vector<DrmPlane *> unused_planes;
      int ret = -ENOENT;
      while (plane) {
        ret = plane->IsValidForLayer(layer.second) ? 0 : -EINVAL;
        if (!ret)
          break;
        if (!plane->zpos_property().is_immutable())
          unused_planes.push_back(plane);
        plane = PopPlane(planes);
      }

      if (!ret) {
        composition->emplace_back(type, plane, layer.first);
        planes->insert(planes->begin(), unused_planes.begin(),
                       unused_planes.end());
      }

      return ret;
    }
  };

  // Creates a planner instance with platform-specific planning stages
  static std::unique_ptr<Planner> CreateInstance(DrmDevice *drm);

  // Takes a stack of layers and provisions hardware planes for them. If the
  // entire stack can't fit in hardware, FIXME
  //
  // @layers: a map of index:layer of layers to composite
  // @primary_planes: a vector of primary planes available for this frame
  // @overlay_planes: a vector of overlay planes available for this frame
  //
  // Returns: A tuple with the status of the operation (0 for success) and
  //          a vector of the resulting plan (ie: layer->plane mapping).
  std::tuple<int, std::vector<DrmCompositionPlane>> ProvisionPlanes(
      std::map<size_t, DrmHwcLayer *> &layers, DrmCrtc *crtc,
      std::vector<DrmPlane *> *primary_planes,
      std::vector<DrmPlane *> *overlay_planes);

  template <typename T, typename... A>
  void AddStage(A &&...args) {
    stages_.emplace_back(
        std::unique_ptr<PlanStage>(new T(std::forward(args)...)));
  }

 private:
  std::vector<DrmPlane *> GetUsablePlanes(
      DrmCrtc *crtc, std::vector<DrmPlane *> *primary_planes,
      std::vector<DrmPlane *> *overlay_planes);

  std::vector<std::unique_ptr<PlanStage>> stages_;
};

// This plan stage extracts all protected layers and places them on dedicated
// planes.
class PlanStageProtected : public Planner::PlanStage {
 public:
  int ProvisionPlanes(std::vector<DrmCompositionPlane> *composition,
                      std::map<size_t, DrmHwcLayer *> &layers,
                      std::vector<DrmPlane *> *planes);
};

// This plan stage places as many layers on dedicated planes as possible (first
// come first serve), and then sticks the rest in a precomposition plane (if
// needed).
class PlanStageGreedy : public Planner::PlanStage {
 public:
  int ProvisionPlanes(std::vector<DrmCompositionPlane> *composition,
                      std::map<size_t, DrmHwcLayer *> &layers,
                      std::vector<DrmPlane *> *planes);
};
}  // namespace android
#endif
