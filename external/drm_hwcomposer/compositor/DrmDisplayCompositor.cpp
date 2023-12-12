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

#define ATRACE_TAG ATRACE_TAG_GRAPHICS
#define LOG_TAG "hwc-drm-display-compositor"

#include "DrmDisplayCompositor.h"

#include <drm/drm_mode.h>
#include <pthread.h>
#include <sched.h>
#include <sync/sync.h>
#include <utils/Trace.h>

#include <array>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>

#include "drm/DrmCrtc.h"
#include "drm/DrmDevice.h"
#include "drm/DrmPlane.h"
#include "utils/autolock.h"
#include "utils/log.h"

namespace android {

std::ostream &operator<<(std::ostream &str, FlatteningState state) {
  std::array<const char *, 6> flattenting_state_str = {
      "None",   "Not needed", "SF Requested", "Squashed by GPU",
      "Serial", "Concurrent",
  };

  return str << flattenting_state_str[static_cast<int>(state)];
}

class CompositorVsyncCallback : public VsyncCallback {
 public:
  explicit CompositorVsyncCallback(DrmDisplayCompositor *compositor)
      : compositor_(compositor) {
  }

  void Callback(int display, int64_t timestamp) override {
    compositor_->Vsync(display, timestamp);
  }

 private:
  DrmDisplayCompositor *compositor_;
};

DrmDisplayCompositor::DrmDisplayCompositor()
    : resource_manager_(nullptr),
      display_(-1),
      initialized_(false),
      active_(false),
      use_hw_overlays_(true),
      dump_frames_composited_(0),
      dump_last_timestamp_ns_(0),
      flatten_countdown_(FLATTEN_COUNTDOWN_INIT),
      flattening_state_(FlatteningState::kNone),
      frames_flattened_(0) {
  struct timespec ts {};
  if (clock_gettime(CLOCK_MONOTONIC, &ts))
    return;
  dump_last_timestamp_ns_ = ts.tv_sec * 1000 * 1000 * 1000 + ts.tv_nsec;
}

DrmDisplayCompositor::~DrmDisplayCompositor() {
  if (!initialized_)
    return;

  vsync_worker_.Exit();
  int ret = pthread_mutex_lock(&lock_);
  if (ret)
    ALOGE("Failed to acquire compositor lock %d", ret);
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  if (mode_.blob_id)
    drm->DestroyPropertyBlob(mode_.blob_id);
  if (mode_.old_blob_id)
    drm->DestroyPropertyBlob(mode_.old_blob_id);

  active_composition_.reset();

  ret = pthread_mutex_unlock(&lock_);
  if (ret)
    ALOGE("Failed to acquire compositor lock %d", ret);

  pthread_mutex_destroy(&lock_);
}

int DrmDisplayCompositor::Init(ResourceManager *resource_manager, int display) {
  resource_manager_ = resource_manager;
  display_ = display;
  DrmDevice *drm = resource_manager_->GetDrmDevice(display);
  if (!drm) {
    ALOGE("Could not find drmdevice for display");
    return -EINVAL;
  }
  int ret = pthread_mutex_init(&lock_, nullptr);
  if (ret) {
    ALOGE("Failed to initialize drm compositor lock %d\n", ret);
    return ret;
  }
  planner_ = Planner::CreateInstance(drm);

  vsync_worker_.Init(drm, display_);
  auto callback = std::make_shared<CompositorVsyncCallback>(this);
  vsync_worker_.RegisterCallback(callback);

  initialized_ = true;
  return 0;
}

std::unique_ptr<DrmDisplayComposition>
DrmDisplayCompositor::CreateInitializedComposition() const {
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  DrmCrtc *crtc = drm->GetCrtcForDisplay(display_);
  if (!crtc) {
    ALOGE("Failed to find crtc for display = %d", display_);
    return std::unique_ptr<DrmDisplayComposition>();
  }

  return std::make_unique<DrmDisplayComposition>(crtc, planner_.get());
}

FlatteningState DrmDisplayCompositor::GetFlatteningState() const {
  return flattening_state_;
}

uint32_t DrmDisplayCompositor::GetFlattenedFramesCount() const {
  return frames_flattened_;
}

bool DrmDisplayCompositor::ShouldFlattenOnClient() const {
  return flattening_state_ == FlatteningState::kClientRequested ||
         flattening_state_ == FlatteningState::kClientDone;
}

std::tuple<uint32_t, uint32_t, int>
DrmDisplayCompositor::GetActiveModeResolution() {
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  DrmConnector *connector = drm->GetConnectorForDisplay(display_);
  if (connector == nullptr) {
    ALOGE("Failed to determine display mode: no connector for display %d",
          display_);
    return std::make_tuple(0, 0, -ENODEV);
  }

  const DrmMode &mode = connector->active_mode();
  return std::make_tuple(mode.h_display(), mode.v_display(), 0);
}

int DrmDisplayCompositor::DisablePlanes(DrmDisplayComposition *display_comp) {
  drmModeAtomicReqPtr pset = drmModeAtomicAlloc();
  if (!pset) {
    ALOGE("Failed to allocate property set");
    return -ENOMEM;
  }

  int ret = 0;
  std::vector<DrmCompositionPlane> &comp_planes = display_comp
                                                      ->composition_planes();
  for (DrmCompositionPlane &comp_plane : comp_planes) {
    DrmPlane *plane = comp_plane.plane();
    ret = drmModeAtomicAddProperty(pset, plane->id(),
                                   plane->crtc_property().id(), 0) < 0 ||
          drmModeAtomicAddProperty(pset, plane->id(), plane->fb_property().id(),
                                   0) < 0;
    if (ret) {
      ALOGE("Failed to add plane %d disable to pset", plane->id());
      drmModeAtomicFree(pset);
      return ret;
    }
  }
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  ret = drmModeAtomicCommit(drm->fd(), pset, 0, drm);
  if (ret) {
    ALOGE("Failed to commit pset ret=%d\n", ret);
    drmModeAtomicFree(pset);
    return ret;
  }

  drmModeAtomicFree(pset);
  return 0;
}

int DrmDisplayCompositor::CommitFrame(DrmDisplayComposition *display_comp,
                                      bool test_only) {
  ATRACE_CALL();

  int ret = 0;

  std::vector<DrmHwcLayer> &layers = display_comp->layers();
  std::vector<DrmCompositionPlane> &comp_planes = display_comp
                                                      ->composition_planes();
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  uint64_t out_fences[drm->crtcs().size()];

  DrmConnector *connector = drm->GetConnectorForDisplay(display_);
  if (!connector) {
    ALOGE("Could not locate connector for display %d", display_);
    return -ENODEV;
  }
  DrmCrtc *crtc = drm->GetCrtcForDisplay(display_);
  if (!crtc) {
    ALOGE("Could not locate crtc for display %d", display_);
    return -ENODEV;
  }

  drmModeAtomicReqPtr pset = drmModeAtomicAlloc();
  if (!pset) {
    ALOGE("Failed to allocate property set");
    return -ENOMEM;
  }

  if (crtc->out_fence_ptr_property().id() != 0) {
    ret = drmModeAtomicAddProperty(pset, crtc->id(),
                                   crtc->out_fence_ptr_property().id(),
                                   (uint64_t)&out_fences[crtc->pipe()]);
    if (ret < 0) {
      ALOGE("Failed to add OUT_FENCE_PTR property to pset: %d", ret);
      drmModeAtomicFree(pset);
      return ret;
    }
  }

  if (mode_.needs_modeset) {
    ret = drmModeAtomicAddProperty(pset, crtc->id(),
                                   crtc->active_property().id(), 1);
    if (ret < 0) {
      ALOGE("Failed to add crtc active to pset\n");
      drmModeAtomicFree(pset);
      return ret;
    }

    ret = drmModeAtomicAddProperty(pset, crtc->id(), crtc->mode_property().id(),
                                   mode_.blob_id) < 0 ||
          drmModeAtomicAddProperty(pset, connector->id(),
                                   connector->crtc_id_property().id(),
                                   crtc->id()) < 0;
    if (ret) {
      ALOGE("Failed to add blob %d to pset", mode_.blob_id);
      drmModeAtomicFree(pset);
      return ret;
    }
  }

  for (DrmCompositionPlane &comp_plane : comp_planes) {
    DrmPlane *plane = comp_plane.plane();
    std::vector<size_t> &source_layers = comp_plane.source_layers();

    int fb_id = -1;
    int fence_fd = -1;
    hwc_rect_t display_frame;
    hwc_frect_t source_crop;
    uint64_t rotation = 0;
    uint64_t alpha = 0xFFFF;
    uint64_t blend = UINT64_MAX;
    uint64_t color_encoding = UINT64_MAX;
    uint64_t color_range = UINT64_MAX;

    if (comp_plane.type() != DrmCompositionPlane::Type::kDisable) {
      if (source_layers.size() > 1) {
        ALOGE("Can't handle more than one source layer sz=%zu type=%d",
              source_layers.size(), comp_plane.type());
        continue;
      }

      if (source_layers.empty() || source_layers.front() >= layers.size()) {
        ALOGE("Source layer index %zu out of bounds %zu type=%d",
              source_layers.front(), layers.size(), comp_plane.type());
        break;
      }
      DrmHwcLayer &layer = layers[source_layers.front()];
      if (!layer.FbIdHandle) {
        ALOGE("Expected a valid framebuffer for pset");
        break;
      }
      fb_id = layer.FbIdHandle->GetFbId();
      fence_fd = layer.acquire_fence.Get();
      display_frame = layer.display_frame;
      source_crop = layer.source_crop;
      alpha = layer.alpha;

      if (plane->blend_property().id()) {
        switch (layer.blending) {
          case DrmHwcBlending::kPreMult:
            std::tie(blend, ret) = plane->blend_property().GetEnumValueWithName(
                "Pre-multiplied");
            break;
          case DrmHwcBlending::kCoverage:
            std::tie(blend, ret) = plane->blend_property().GetEnumValueWithName(
                "Coverage");
            break;
          case DrmHwcBlending::kNone:
          default:
            std::tie(blend, ret) = plane->blend_property().GetEnumValueWithName(
                "None");
            break;
        }
      }

      if (plane->zpos_property().id() &&
          !plane->zpos_property().is_immutable()) {
        uint64_t min_zpos = 0;

        // Ignore ret and use min_zpos as 0 by default
        std::tie(std::ignore, min_zpos) = plane->zpos_property().range_min();

        ret = drmModeAtomicAddProperty(pset, plane->id(),
                                       plane->zpos_property().id(),
                                       source_layers.front() + min_zpos) < 0;
        if (ret) {
          ALOGE("Failed to add zpos property %d to plane %d",
                plane->zpos_property().id(), plane->id());
          break;
        }
      }

      rotation = 0;
      if (layer.transform & DrmHwcTransform::kFlipH)
        rotation |= DRM_MODE_REFLECT_X;
      if (layer.transform & DrmHwcTransform::kFlipV)
        rotation |= DRM_MODE_REFLECT_Y;
      if (layer.transform & DrmHwcTransform::kRotate90)
        rotation |= DRM_MODE_ROTATE_90;
      else if (layer.transform & DrmHwcTransform::kRotate180)
        rotation |= DRM_MODE_ROTATE_180;
      else if (layer.transform & DrmHwcTransform::kRotate270)
        rotation |= DRM_MODE_ROTATE_270;
      else
        rotation |= DRM_MODE_ROTATE_0;

      if (fence_fd >= 0) {
        int prop_id = plane->in_fence_fd_property().id();
        if (prop_id == 0) {
          ALOGE("Failed to get IN_FENCE_FD property id");
          break;
        }
        ret = drmModeAtomicAddProperty(pset, plane->id(), prop_id, fence_fd);
        if (ret < 0) {
          ALOGE("Failed to add IN_FENCE_FD property to pset: %d", ret);
          break;
        }
      }

      if (plane->color_encoding_propery().id()) {
        switch (layer.dataspace & HAL_DATASPACE_STANDARD_MASK) {
          case HAL_DATASPACE_STANDARD_BT709:
            std::tie(color_encoding,
                     ret) = plane->color_encoding_propery()
                                .GetEnumValueWithName("ITU-R BT.709 YCbCr");
            break;
          case HAL_DATASPACE_STANDARD_BT601_625:
          case HAL_DATASPACE_STANDARD_BT601_625_UNADJUSTED:
          case HAL_DATASPACE_STANDARD_BT601_525:
          case HAL_DATASPACE_STANDARD_BT601_525_UNADJUSTED:
            std::tie(color_encoding,
                     ret) = plane->color_encoding_propery()
                                .GetEnumValueWithName("ITU-R BT.601 YCbCr");
            break;
          case HAL_DATASPACE_STANDARD_BT2020:
          case HAL_DATASPACE_STANDARD_BT2020_CONSTANT_LUMINANCE:
            std::tie(color_encoding,
                     ret) = plane->color_encoding_propery()
                                .GetEnumValueWithName("ITU-R BT.2020 YCbCr");
            break;
        }
      }

      if (plane->color_range_property().id()) {
        switch (layer.dataspace & HAL_DATASPACE_RANGE_MASK) {
          case HAL_DATASPACE_RANGE_FULL:
            std::tie(color_range,
                     ret) = plane->color_range_property()
                                .GetEnumValueWithName("YCbCr full range");
            break;
          case HAL_DATASPACE_RANGE_LIMITED:
            std::tie(color_range,
                     ret) = plane->color_range_property()
                                .GetEnumValueWithName("YCbCr limited range");
            break;
        }
      }
    }

    // Disable the plane if there's no framebuffer
    if (fb_id < 0) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->crtc_property().id(), 0) < 0 ||
            drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->fb_property().id(), 0) < 0;
      if (ret) {
        ALOGE("Failed to add plane %d disable to pset", plane->id());
        break;
      }
      continue;
    }

    ret = drmModeAtomicAddProperty(pset, plane->id(),
                                   plane->crtc_property().id(), crtc->id()) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->fb_property().id(), fb_id) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->crtc_x_property().id(),
                                    display_frame.left) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->crtc_y_property().id(),
                                    display_frame.top) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->crtc_w_property().id(),
                                    display_frame.right - display_frame.left) <
           0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->crtc_h_property().id(),
                                    display_frame.bottom - display_frame.top) <
           0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->src_x_property().id(),
                                    (int)(source_crop.left) << 16) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->src_y_property().id(),
                                    (int)(source_crop.top) << 16) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->src_w_property().id(),
                                    (int)(source_crop.right - source_crop.left)
                                        << 16) < 0;
    ret |= drmModeAtomicAddProperty(pset, plane->id(),
                                    plane->src_h_property().id(),
                                    (int)(source_crop.bottom - source_crop.top)
                                        << 16) < 0;
    if (ret) {
      ALOGE("Failed to add plane %d to set", plane->id());
      break;
    }

    if (plane->rotation_property().id()) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->rotation_property().id(),
                                     rotation) < 0;
      if (ret) {
        ALOGE("Failed to add rotation property %d to plane %d",
              plane->rotation_property().id(), plane->id());
        break;
      }
    }

    if (plane->alpha_property().id()) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->alpha_property().id(), alpha) < 0;
      if (ret) {
        ALOGE("Failed to add alpha property %d to plane %d",
              plane->alpha_property().id(), plane->id());
        break;
      }
    }

    if (plane->blend_property().id() && blend != UINT64_MAX) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->blend_property().id(), blend) < 0;
      if (ret) {
        ALOGE("Failed to add pixel blend mode property %d to plane %d",
              plane->blend_property().id(), plane->id());
        break;
      }
    }

    if (plane->color_encoding_propery().id() && color_encoding != UINT64_MAX) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->color_encoding_propery().id(),
                                     color_encoding) < 0;
      if (ret) {
        ALOGE("Failed to add COLOR_ENCODING property %d to plane %d",
              plane->color_encoding_propery().id(), plane->id());
        break;
      }
    }

    if (plane->color_range_property().id() && color_range != UINT64_MAX) {
      ret = drmModeAtomicAddProperty(pset, plane->id(),
                                     plane->color_range_property().id(),
                                     color_range) < 0;
      if (ret) {
        ALOGE("Failed to add COLOR_RANGE property %d to plane %d",
              plane->color_range_property().id(), plane->id());
        break;
      }
    }
  }

  if (!ret) {
    uint32_t flags = DRM_MODE_ATOMIC_ALLOW_MODESET;
    if (test_only)
      flags |= DRM_MODE_ATOMIC_TEST_ONLY;

    ret = drmModeAtomicCommit(drm->fd(), pset, flags, drm);
    if (ret) {
      if (!test_only)
        ALOGE("Failed to commit pset ret=%d\n", ret);
      drmModeAtomicFree(pset);
      return ret;
    }
  }
  if (pset)
    drmModeAtomicFree(pset);

  if (!test_only && mode_.needs_modeset) {
    ret = drm->DestroyPropertyBlob(mode_.old_blob_id);
    if (ret) {
      ALOGE("Failed to destroy old mode property blob %" PRIu32 "/%d",
            mode_.old_blob_id, ret);
      return ret;
    }

    /* TODO: Add dpms to the pset when the kernel supports it */
    ret = ApplyDpms(display_comp);
    if (ret) {
      ALOGE("Failed to apply DPMS after modeset %d\n", ret);
      return ret;
    }

    connector->set_active_mode(mode_.mode);
    mode_.old_blob_id = mode_.blob_id;
    mode_.blob_id = 0;
    mode_.needs_modeset = false;
  }

  if (crtc->out_fence_ptr_property().id()) {
    display_comp->out_fence_ = UniqueFd((int)out_fences[crtc->pipe()]);
  }

  return ret;
}

int DrmDisplayCompositor::ApplyDpms(DrmDisplayComposition *display_comp) {
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  DrmConnector *conn = drm->GetConnectorForDisplay(display_);
  if (!conn) {
    ALOGE("Failed to get DrmConnector for display %d", display_);
    return -ENODEV;
  }

  const DrmProperty &prop = conn->dpms_property();
  int ret = drmModeConnectorSetProperty(drm->fd(), conn->id(), prop.id(),
                                        display_comp->dpms_mode());
  if (ret) {
    ALOGE("Failed to set DPMS property for connector %d", conn->id());
    return ret;
  }
  return 0;
}

std::tuple<int, uint32_t> DrmDisplayCompositor::CreateModeBlob(
    const DrmMode &mode) {
  struct drm_mode_modeinfo drm_mode {};
  mode.ToDrmModeModeInfo(&drm_mode);

  uint32_t id = 0;
  DrmDevice *drm = resource_manager_->GetDrmDevice(display_);
  int ret = drm->CreatePropertyBlob(&drm_mode, sizeof(struct drm_mode_modeinfo),
                                    &id);
  if (ret) {
    ALOGE("Failed to create mode property blob %d", ret);
    return std::make_tuple(ret, 0);
  }
  ALOGE("Create blob_id %" PRIu32 "\n", id);
  return std::make_tuple(ret, id);
}

void DrmDisplayCompositor::ClearDisplay() {
  if (!active_composition_)
    return;

  if (DisablePlanes(active_composition_.get()))
    return;

  active_composition_.reset(nullptr);
}

void DrmDisplayCompositor::ApplyFrame(
    std::unique_ptr<DrmDisplayComposition> composition, int status) {
  AutoLock lock(&lock_, __func__);
  if (lock.Lock())
    return;
  int ret = status;

  if (!ret) {
    ret = CommitFrame(composition.get(), false);
  }

  if (ret) {
    ALOGE("Composite failed for display %d", display_);
    // Disable the hw used by the last active composition. This allows us to
    // signal the release fences from that composition to avoid hanging.
    ClearDisplay();
    return;
  }
  ++dump_frames_composited_;

  active_composition_.swap(composition);

  flatten_countdown_ = FLATTEN_COUNTDOWN_INIT;
  if (flattening_state_ != FlatteningState::kClientRequested) {
    SetFlattening(FlatteningState::kNone);
  } else {
    SetFlattening(FlatteningState::kClientDone);
  }
  vsync_worker_.VSyncControl(true);
}

int DrmDisplayCompositor::ApplyComposition(
    std::unique_ptr<DrmDisplayComposition> composition) {
  int ret = 0;
  switch (composition->type()) {
    case DRM_COMPOSITION_TYPE_FRAME:
      if (composition->geometry_changed()) {
        // Send the composition to the kernel to ensure we can commit it. This
        // is just a test, it won't actually commit the frame.
        ret = CommitFrame(composition.get(), true);
        if (ret) {
          ALOGE("Commit test failed for display %d, FIXME", display_);
          return ret;
        }
      }

      ApplyFrame(std::move(composition), ret);
      break;
    case DRM_COMPOSITION_TYPE_DPMS:
      active_ = (composition->dpms_mode() == DRM_MODE_DPMS_ON);
      ret = ApplyDpms(composition.get());
      if (ret)
        ALOGE("Failed to apply dpms for display %d", display_);
      return ret;
    case DRM_COMPOSITION_TYPE_MODESET:
      mode_.mode = composition->display_mode();
      if (mode_.blob_id)
        resource_manager_->GetDrmDevice(display_)->DestroyPropertyBlob(
            mode_.blob_id);
      std::tie(ret, mode_.blob_id) = CreateModeBlob(mode_.mode);
      if (ret) {
        ALOGE("Failed to create mode blob for display %d", display_);
        return ret;
      }
      mode_.needs_modeset = true;
      return 0;
    default:
      ALOGE("Unknown composition type %d", composition->type());
      return -EINVAL;
  }

  return ret;
}

int DrmDisplayCompositor::TestComposition(DrmDisplayComposition *composition) {
  return CommitFrame(composition, true);
}

void DrmDisplayCompositor::SetFlattening(FlatteningState new_state) {
  if (flattening_state_ != new_state) {
    switch (flattening_state_) {
      case FlatteningState::kClientDone:
        ++frames_flattened_;
        break;
      case FlatteningState::kClientRequested:
      case FlatteningState::kNone:
      case FlatteningState::kNotNeeded:
        break;
    }
  }
  flattening_state_ = new_state;
}

bool DrmDisplayCompositor::IsFlatteningNeeded() const {
  return CountdownExpired() && active_composition_->layers().size() >= 2;
}

int DrmDisplayCompositor::FlattenOnClient() {
  const std::lock_guard<std::mutex> lock(refresh_callback_lock);

  if (refresh_callback_hook_ && refresh_callback_data_) {
    {
      AutoLock lock(&lock_, __func__);
      if (!IsFlatteningNeeded()) {
        if (flattening_state_ != FlatteningState::kClientDone) {
          ALOGV("Flattening is not needed");
          SetFlattening(FlatteningState::kNotNeeded);
        }
        return -EALREADY;
      }
    }

    ALOGV(
        "No writeback connector available, "
        "falling back to client composition");
    SetFlattening(FlatteningState::kClientRequested);
    refresh_callback_hook_(refresh_callback_data_, display_);
    return 0;
  }

  ALOGV("No writeback connector available");
  return -EINVAL;
}

int DrmDisplayCompositor::FlattenActiveComposition() {
  return FlattenOnClient();
}

bool DrmDisplayCompositor::CountdownExpired() const {
  return flatten_countdown_ <= 0;
}

void DrmDisplayCompositor::Vsync(int display, int64_t timestamp) {
  AutoLock lock(&lock_, __func__);
  if (lock.Lock())
    return;
  flatten_countdown_--;
  if (!CountdownExpired())
    return;
  lock.Unlock();
  int ret = FlattenActiveComposition();
  ALOGV("scene flattening triggered for display %d at timestamp %" PRIu64
        " result = %d \n",
        display, timestamp, ret);
}

void DrmDisplayCompositor::Dump(std::ostringstream *out) const {
  int ret = pthread_mutex_lock(&lock_);
  if (ret)
    return;

  uint64_t num_frames = dump_frames_composited_;
  dump_frames_composited_ = 0;

  struct timespec ts {};
  ret = clock_gettime(CLOCK_MONOTONIC, &ts);
  if (ret) {
    pthread_mutex_unlock(&lock_);
    return;
  }

  uint64_t cur_ts = ts.tv_sec * 1000 * 1000 * 1000 + ts.tv_nsec;
  uint64_t num_ms = (cur_ts - dump_last_timestamp_ns_) / (1000 * 1000);
  float fps = num_ms ? (num_frames * 1000.0F) / (num_ms) : 0.0F;

  *out << "--DrmDisplayCompositor[" << display_
       << "]: num_frames=" << num_frames << " num_ms=" << num_ms
       << " fps=" << fps << "\n";

  dump_last_timestamp_ns_ = cur_ts;

  pthread_mutex_unlock(&lock_);
}
}  // namespace android
