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

#ifndef ANDROID_DRM_DISPLAY_COMPOSITOR_H_
#define ANDROID_DRM_DISPLAY_COMPOSITOR_H_

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>
#include <pthread.h>

#include <functional>
#include <memory>
#include <sstream>
#include <tuple>

#include "DrmDisplayComposition.h"
#include "Planner.h"
#include "drm/ResourceManager.h"
#include "drm/VSyncWorker.h"
#include "drmhwcomposer.h"

// If a scene is still for this number of vblanks flatten it to reduce power
// consumption.
#define FLATTEN_COUNTDOWN_INIT 60

namespace android {

enum class FlatteningState {
  kNone,
  kNotNeeded,
  kClientRequested,
  kClientDone,
};

std::ostream &operator<<(std::ostream &str, FlatteningState state);

class DrmDisplayCompositor {
 public:
  DrmDisplayCompositor();
  ~DrmDisplayCompositor();

  int Init(ResourceManager *resource_manager, int display);

  hwc2_callback_data_t refresh_callback_data_ = NULL;
  HWC2_PFN_REFRESH refresh_callback_hook_ = NULL;
  std::mutex refresh_callback_lock;

  void SetRefreshCallback(hwc2_callback_data_t data,
                          hwc2_function_pointer_t hook) {
    const std::lock_guard<std::mutex> lock(refresh_callback_lock);
    refresh_callback_data_ = data;
    refresh_callback_hook_ = reinterpret_cast<HWC2_PFN_REFRESH>(hook);
  }

  std::unique_ptr<DrmDisplayComposition> CreateInitializedComposition() const;
  int ApplyComposition(std::unique_ptr<DrmDisplayComposition> composition);
  int TestComposition(DrmDisplayComposition *composition);
  int Composite();
  void Dump(std::ostringstream *out) const;
  void Vsync(int display, int64_t timestamp);
  void ClearDisplay();
  UniqueFd TakeOutFence() {
    if (!active_composition_) {
      return UniqueFd();
    }
    return std::move(active_composition_->out_fence_);
  }

  FlatteningState GetFlatteningState() const;
  uint32_t GetFlattenedFramesCount() const;
  bool ShouldFlattenOnClient() const;

  std::tuple<uint32_t, uint32_t, int> GetActiveModeResolution();

 private:
  struct ModeState {
    bool needs_modeset = false;
    DrmMode mode;
    uint32_t blob_id = 0;
    uint32_t old_blob_id = 0;
  };

  DrmDisplayCompositor(const DrmDisplayCompositor &) = delete;

  // We'll wait for acquire fences to fire for kAcquireWaitTimeoutMs,
  // kAcquireWaitTries times, logging a warning in between.
  static const int kAcquireWaitTries = 5;
  static const int kAcquireWaitTimeoutMs = 100;

  int CommitFrame(DrmDisplayComposition *display_comp, bool test_only);
  int ApplyDpms(DrmDisplayComposition *display_comp);
  int DisablePlanes(DrmDisplayComposition *display_comp);

  void ApplyFrame(std::unique_ptr<DrmDisplayComposition> composition,
                  int status);

  void SetFlattening(FlatteningState new_state);
  bool IsFlatteningNeeded() const;
  int FlattenActiveComposition();
  int FlattenOnClient();

  bool CountdownExpired() const;

  std::tuple<int, uint32_t> CreateModeBlob(const DrmMode &mode);

  ResourceManager *resource_manager_;
  int display_;

  std::unique_ptr<DrmDisplayComposition> active_composition_;

  bool initialized_;
  bool active_;
  bool use_hw_overlays_;

  ModeState mode_;

  // mutable since we need to acquire in Dump()
  mutable pthread_mutex_t lock_{};

  // State tracking progress since our last Dump(). These are mutable since
  // we need to reset them on every Dump() call.
  mutable uint64_t dump_frames_composited_;
  mutable uint64_t dump_last_timestamp_ns_;
  VSyncWorker vsync_worker_;
  int64_t flatten_countdown_;
  std::unique_ptr<Planner> planner_;

  FlatteningState flattening_state_;
  uint32_t frames_flattened_;

  std::function<void(int)> refresh_display_cb_;
};
}  // namespace android

#endif  // ANDROID_DRM_DISPLAY_COMPOSITOR_H_
