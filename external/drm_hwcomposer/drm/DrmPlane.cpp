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

#define LOG_TAG "hwc-drm-plane"

#include "DrmPlane.h"

#include <algorithm>
#include <cerrno>
#include <cinttypes>
#include <cstdint>

#include "DrmDevice.h"
#include "bufferinfo/BufferInfoGetter.h"
#include "utils/log.h"

namespace android {

DrmPlane::DrmPlane(DrmDevice *drm, drmModePlanePtr p)
    : drm_(drm),
      id_(p->plane_id),
      possible_crtc_mask_(p->possible_crtcs),
      formats_(p->formats, p->formats + p->count_formats) {
}

int DrmPlane::Init() {
  DrmProperty p;

  int ret = drm_->GetPlaneProperty(*this, "type", &p);
  if (ret) {
    ALOGE("Could not get plane type property");
    return ret;
  }

  uint64_t type = 0;
  std::tie(ret, type) = p.value();
  if (ret) {
    ALOGE("Failed to get plane type property value");
    return ret;
  }
  switch (type) {
    case DRM_PLANE_TYPE_OVERLAY:
    case DRM_PLANE_TYPE_PRIMARY:
    case DRM_PLANE_TYPE_CURSOR:
      type_ = (uint32_t)type;
      break;
    default:
      ALOGE("Invalid plane type %" PRIu64, type);
      return -EINVAL;
  }

  ret = drm_->GetPlaneProperty(*this, "CRTC_ID", &crtc_property_);
  if (ret) {
    ALOGE("Could not get CRTC_ID property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "FB_ID", &fb_property_);
  if (ret) {
    ALOGE("Could not get FB_ID property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "CRTC_X", &crtc_x_property_);
  if (ret) {
    ALOGE("Could not get CRTC_X property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "CRTC_Y", &crtc_y_property_);
  if (ret) {
    ALOGE("Could not get CRTC_Y property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "CRTC_W", &crtc_w_property_);
  if (ret) {
    ALOGE("Could not get CRTC_W property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "CRTC_H", &crtc_h_property_);
  if (ret) {
    ALOGE("Could not get CRTC_H property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "SRC_X", &src_x_property_);
  if (ret) {
    ALOGE("Could not get SRC_X property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "SRC_Y", &src_y_property_);
  if (ret) {
    ALOGE("Could not get SRC_Y property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "SRC_W", &src_w_property_);
  if (ret) {
    ALOGE("Could not get SRC_W property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "SRC_H", &src_h_property_);
  if (ret) {
    ALOGE("Could not get SRC_H property");
    return ret;
  }

  ret = drm_->GetPlaneProperty(*this, "zpos", &zpos_property_);
  if (ret)
    ALOGE("Could not get zpos property for plane %u", id());

  ret = drm_->GetPlaneProperty(*this, "rotation", &rotation_property_);
  if (ret)
    ALOGE("Could not get rotation property");

  ret = drm_->GetPlaneProperty(*this, "alpha", &alpha_property_);
  if (ret)
    ALOGI("Could not get alpha property");

  ret = drm_->GetPlaneProperty(*this, "pixel blend mode", &blend_property_);
  if (ret)
    ALOGI("Could not get pixel blend mode property");

  ret = drm_->GetPlaneProperty(*this, "IN_FENCE_FD", &in_fence_fd_property_);
  if (ret)
    ALOGI("Could not get IN_FENCE_FD property");

  if (HasNonRgbFormat()) {
    ret = drm_->GetPlaneProperty(*this, "COLOR_ENCODING",
                                 &color_encoding_propery_);
    if (ret)
      ALOGI("Could not get COLOR_ENCODING property");

    ret = drm_->GetPlaneProperty(*this, "COLOR_RANGE", &color_range_property_);
    if (ret)
      ALOGI("Could not get COLOR_RANGE property");
  }

  return 0;
}

uint32_t DrmPlane::id() const {
  return id_;
}

bool DrmPlane::GetCrtcSupported(const DrmCrtc &crtc) const {
  return ((1 << crtc.pipe()) & possible_crtc_mask_) != 0;
}

bool DrmPlane::IsValidForLayer(DrmHwcLayer *layer) {
  if (rotation_property_.id() == 0) {
    if (layer->transform != DrmHwcTransform::kIdentity) {
      ALOGV("Rotation is not supported on plane %d", id_);
      return false;
    }
  } else {
    // For rotation checks, we assume the hardware reports its capabilities
    // consistently (e.g. a 270 degree rotation is a 90 degree rotation + H
    // flip + V flip; it wouldn't make sense to support all of the latter but
    // not the former).
    int ret = 0;
    const std::pair<enum DrmHwcTransform, std::string> transforms[] =
        {{kFlipH, "reflect-x"},
         {kFlipV, "reflect-y"},
         {kRotate90, "rotate-90"},
         {kRotate180, "rotate-180"},
         {kRotate270, "rotate-270"}};

    for (const auto &[transform, name] : transforms) {
      if (layer->transform & transform) {
        std::tie(std::ignore,
                 ret) = rotation_property_.GetEnumValueWithName(name);
        if (ret) {
          ALOGV("Rotation '%s' is not supported on plane %d", name.c_str(),
                id_);
          return false;
        }
      }
    }
  }

  if (alpha_property_.id() == 0 && layer->alpha != 0xffff) {
    ALOGV("Alpha is not supported on plane %d", id_);
    return false;
  }

  if (blend_property_.id() == 0) {
    if ((layer->blending != DrmHwcBlending::kNone) &&
        (layer->blending != DrmHwcBlending::kPreMult)) {
      ALOGV("Blending is not supported on plane %d", id_);
      return false;
    }
  } else {
    int ret = 0;

    switch (layer->blending) {
      case DrmHwcBlending::kPreMult:
        std::tie(std::ignore,
                 ret) = blend_property_.GetEnumValueWithName("Pre-multiplied");
        break;
      case DrmHwcBlending::kCoverage:
        std::tie(std::ignore,
                 ret) = blend_property_.GetEnumValueWithName("Coverage");
        break;
      case DrmHwcBlending::kNone:
      default:
        std::tie(std::ignore,
                 ret) = blend_property_.GetEnumValueWithName("None");
        break;
    }
    if (ret) {
      ALOGV("Expected a valid blend mode on plane %d", id_);
      return false;
    }
  }

  uint32_t format = layer->buffer_info.format;
  if (!IsFormatSupported(format)) {
    ALOGV("Plane %d does not supports %c%c%c%c format", id_, format,
          format >> 8, format >> 16, format >> 24);
    return false;
  }

  return true;
}

uint32_t DrmPlane::type() const {
  return type_;
}

bool DrmPlane::IsFormatSupported(uint32_t format) const {
  return std::find(std::begin(formats_), std::end(formats_), format) !=
         std::end(formats_);
}

bool DrmPlane::HasNonRgbFormat() const {
  return std::find_if_not(std::begin(formats_), std::end(formats_),
                          [](uint32_t format) {
                            return BufferInfoGetter::IsDrmFormatRgb(format);
                          }) != std::end(formats_);
}

const DrmProperty &DrmPlane::crtc_property() const {
  return crtc_property_;
}

const DrmProperty &DrmPlane::fb_property() const {
  return fb_property_;
}

const DrmProperty &DrmPlane::crtc_x_property() const {
  return crtc_x_property_;
}

const DrmProperty &DrmPlane::crtc_y_property() const {
  return crtc_y_property_;
}

const DrmProperty &DrmPlane::crtc_w_property() const {
  return crtc_w_property_;
}

const DrmProperty &DrmPlane::crtc_h_property() const {
  return crtc_h_property_;
}

const DrmProperty &DrmPlane::src_x_property() const {
  return src_x_property_;
}

const DrmProperty &DrmPlane::src_y_property() const {
  return src_y_property_;
}

const DrmProperty &DrmPlane::src_w_property() const {
  return src_w_property_;
}

const DrmProperty &DrmPlane::src_h_property() const {
  return src_h_property_;
}

const DrmProperty &DrmPlane::zpos_property() const {
  return zpos_property_;
}

const DrmProperty &DrmPlane::rotation_property() const {
  return rotation_property_;
}

const DrmProperty &DrmPlane::alpha_property() const {
  return alpha_property_;
}

const DrmProperty &DrmPlane::blend_property() const {
  return blend_property_;
}

const DrmProperty &DrmPlane::in_fence_fd_property() const {
  return in_fence_fd_property_;
}

const DrmProperty &DrmPlane::color_encoding_propery() const {
  return color_encoding_propery_;
}

const DrmProperty &DrmPlane::color_range_property() const {
  return color_range_property_;
}
}  // namespace android
