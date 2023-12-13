/*
 * Copyright (C) 2018 The Android Open Source Project
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

#define LOG_TAG "hwc-resource-manager"

#include "ResourceManager.h"

#include <fcntl.h>
#include <sys/stat.h>

#include <sstream>

#include "bufferinfo/BufferInfoGetter.h"
#include "utils/log.h"
#include "utils/properties.h"

namespace android {

ResourceManager::ResourceManager() : num_displays_(0), gralloc_(nullptr) {
}

int ResourceManager::Init() {
  char path_pattern[PROPERTY_VALUE_MAX];
  // Could be a valid path or it can have at the end of it the wildcard %
  // which means that it will try open all devices until an error is met.
  int path_len = property_get("vendor.hwc.drm.device", path_pattern,
                              "/dev/dri/card%");
  int ret = 0;
  if (path_pattern[path_len - 1] != '%') {
    ret = AddDrmDevice(std::string(path_pattern));
  } else {
    path_pattern[path_len - 1] = '\0';
    for (int idx = 0; !ret; ++idx) {
      std::ostringstream path;
      path << path_pattern << idx;

      struct stat buf {};
      if (stat(path.str().c_str(), &buf))
        break;

      if (IsKMSDev(path.str().c_str()))
        ret = AddDrmDevice(path.str());
    }
  }

  if (!num_displays_) {
    ALOGE("Failed to initialize any displays");
    return ret ? -EINVAL : ret;
  }

  char scale_with_gpu[PROPERTY_VALUE_MAX];
  property_get("vendor.hwc.drm.scale_with_gpu", scale_with_gpu, "0");
  scale_with_gpu_ = bool(strncmp(scale_with_gpu, "0", 1));

  if (!BufferInfoGetter::GetInstance()) {
    ALOGE("Failed to initialize BufferInfoGetter");
    return -EINVAL;
  }

  return hw_get_module(GRALLOC_HARDWARE_MODULE_ID,
                       (const hw_module_t **)&gralloc_);
}

int ResourceManager::AddDrmDevice(const std::string &path) {
  auto drm = std::make_unique<DrmDevice>();
  int displays_added = 0;
  int ret = 0;
  std::tie(ret, displays_added) = drm->Init(path.c_str(), num_displays_);
  drms_.push_back(std::move(drm));
  num_displays_ += displays_added;
  return ret;
}

DrmConnector *ResourceManager::AvailableWritebackConnector(int display) {
  DrmDevice *drm_device = GetDrmDevice(display);
  DrmConnector *writeback_conn = nullptr;
  if (drm_device) {
    writeback_conn = drm_device->AvailableWritebackConnector(display);
    if (writeback_conn)
      return writeback_conn;
  }
  for (auto &drm : drms_) {
    if (drm.get() == drm_device)
      continue;
    writeback_conn = drm->AvailableWritebackConnector(display);
    if (writeback_conn)
      return writeback_conn;
  }
  return writeback_conn;
}

bool ResourceManager::IsKMSDev(const char *path) {
  int fd = open(path, O_RDWR | O_CLOEXEC);
  if (fd < 0)
    return false;

  auto *res = drmModeGetResources(fd);
  if (!res) {
    close(fd);
    return false;
  }

  bool is_kms = res->count_crtcs > 0 && res->count_connectors > 0 &&
                res->count_encoders > 0;

  drmModeFreeResources(res);
  close(fd);

  return is_kms;
}

DrmDevice *ResourceManager::GetDrmDevice(int display) {
  for (auto &drm : drms_) {
    if (drm->HandlesDisplay(display))
      return drm.get();
  }
  return nullptr;
}

const gralloc_module_t *ResourceManager::gralloc() {
  return gralloc_;
}
}  // namespace android
