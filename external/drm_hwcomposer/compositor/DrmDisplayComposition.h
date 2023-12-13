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

#ifndef ANDROID_DRM_DISPLAY_COMPOSITION_H_
#define ANDROID_DRM_DISPLAY_COMPOSITION_H_

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>

#include <sstream>
#include <vector>

#include "drm/DrmCrtc.h"
#include "drm/DrmPlane.h"
#include "drmhwcomposer.h"

namespace android {

class Importer;
class Planner;

enum DrmCompositionType {
  DRM_COMPOSITION_TYPE_EMPTY,
  DRM_COMPOSITION_TYPE_FRAME,
  DRM_COMPOSITION_TYPE_DPMS,
  DRM_COMPOSITION_TYPE_MODESET,
};

class DrmCompositionPlane {
 public:
  enum class Type : int32_t {
    kDisable,
    kLayer,
  };

  DrmCompositionPlane() = default;
  DrmCompositionPlane(DrmCompositionPlane &&rhs) = default;
  DrmCompositionPlane &operator=(DrmCompositionPlane &&other) = default;
  DrmCompositionPlane(Type type, DrmPlane *plane) : type_(type), plane_(plane) {
  }
  DrmCompositionPlane(Type type, DrmPlane *plane, size_t source_layer)
      : type_(type), plane_(plane), source_layers_(1, source_layer) {
  }

  Type type() const {
    return type_;
  }

  DrmPlane *plane() const {
    return plane_;
  }
  void set_plane(DrmPlane *plane) {
    plane_ = plane;
  }

  std::vector<size_t> &source_layers() {
    return source_layers_;
  }

  const std::vector<size_t> &source_layers() const {
    return source_layers_;
  }

 private:
  Type type_ = Type::kDisable;
  DrmPlane *plane_ = NULL;
  std::vector<size_t> source_layers_;
};

class DrmDisplayComposition {
 public:
  DrmDisplayComposition(const DrmDisplayComposition &) = delete;
  DrmDisplayComposition(DrmCrtc *crtc, Planner *planner);
  ~DrmDisplayComposition() = default;

  int SetLayers(DrmHwcLayer *layers, size_t num_layers, bool geometry_changed);
  int AddPlaneComposition(DrmCompositionPlane plane);
  int AddPlaneDisable(DrmPlane *plane);
  int SetDpmsMode(uint32_t dpms_mode);
  int SetDisplayMode(const DrmMode &display_mode);

  int Plan(std::vector<DrmPlane *> *primary_planes,
           std::vector<DrmPlane *> *overlay_planes);

  std::vector<DrmHwcLayer> &layers() {
    return layers_;
  }

  std::vector<DrmCompositionPlane> &composition_planes() {
    return composition_planes_;
  }

  bool geometry_changed() const {
    return geometry_changed_;
  }

  DrmCompositionType type() const {
    return type_;
  }

  uint32_t dpms_mode() const {
    return dpms_mode_;
  }

  const DrmMode &display_mode() const {
    return display_mode_;
  }

  DrmCrtc *crtc() const {
    return crtc_;
  }

  Planner *planner() const {
    return planner_;
  }

  void Dump(std::ostringstream *out) const;

  UniqueFd out_fence_;

 private:
  bool validate_composition_type(DrmCompositionType desired);

  DrmCrtc *crtc_ = NULL;
  Planner *planner_ = NULL;

  DrmCompositionType type_ = DRM_COMPOSITION_TYPE_EMPTY;
  uint32_t dpms_mode_ = DRM_MODE_DPMS_ON;
  DrmMode display_mode_;

  bool geometry_changed_ = true;
  std::vector<DrmHwcLayer> layers_;
  std::vector<DrmCompositionPlane> composition_planes_;
};
}  // namespace android

#endif  // ANDROID_DRM_DISPLAY_COMPOSITION_H_
