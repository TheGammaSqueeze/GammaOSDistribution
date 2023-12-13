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

#ifndef ANDROID_EVENT_WORKER_H_
#define ANDROID_EVENT_WORKER_H_

#include <hardware/hardware.h>
#include <hardware/hwcomposer.h>
#include <hardware/hwcomposer2.h>
#include <stdint.h>

#include <atomic>
#include <map>

#include "DrmDevice.h"
#include "utils/Worker.h"

namespace android {

class VsyncCallback {
 public:
  virtual ~VsyncCallback() = default;
  virtual void Callback(int display, int64_t timestamp) = 0;
};

class VSyncWorker : public Worker {
 public:
  VSyncWorker();
  ~VSyncWorker() override = default;

  int Init(DrmDevice *drm, int display);
  void RegisterCallback(std::shared_ptr<VsyncCallback> callback);
  void RegisterClientCallback(hwc2_callback_data_t data,
                              hwc2_function_pointer_t hook);

  void VSyncControl(bool enabled);

 protected:
  void Routine() override;

 private:
  int64_t GetPhasedVSync(int64_t frame_ns, int64_t current) const;
  int SyntheticWaitVBlank(int64_t *timestamp);

  DrmDevice *drm_;

  // shared_ptr since we need to use this outside of the thread lock (to
  // actually call the hook) and we don't want the memory freed until we're
  // done
  std::shared_ptr<VsyncCallback> callback_ = NULL;

  int display_;
  std::atomic_bool enabled_;
  int64_t last_timestamp_;

  hwc2_callback_data_t vsync_callback_data_ = NULL;
  HWC2_PFN_VSYNC vsync_callback_hook_ = NULL;
};
}  // namespace android

#endif
