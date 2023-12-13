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

#define LOG_TAG "hwc-bufferinfo-imagination"

#include "BufferInfoImagination.h"

#include <xf86drm.h>

#include "img_gralloc1_public.h"
#include "utils/log.h"

namespace android {

LEGACY_BUFFER_INFO_GETTER(BufferInfoImagination);

int BufferInfoImagination::ConvertBoInfo(buffer_handle_t handle,
                                         hwc_drm_bo_t *bo) {
  auto *hnd = (IMG_native_handle_t *)handle;
  if (!hnd)
    return -EINVAL;

  /* Extra bits are responsible for buffer compression and memory layout */
  if (hnd->iFormat & ~0x10f) {
    ALOGV("Special buffer formats are not supported");
    return -EINVAL;
  }

  bo->width = hnd->iWidth;
  bo->height = hnd->iHeight;
  bo->usage = hnd->usage;
  bo->prime_fds[0] = hnd->fd[0];
  bo->pitches[0] = ALIGN(hnd->iWidth, HW_ALIGN) * hnd->uiBpp >> 3;
  bo->hal_format = hnd->iFormat;

  switch (hnd->iFormat) {
#ifdef HAL_PIXEL_FORMAT_BGRX_8888
    case HAL_PIXEL_FORMAT_BGRX_8888:
      bo->format = DRM_FORMAT_XRGB8888;
      break;
#endif
    default:
      bo->format = ConvertHalFormatToDrm(hnd->iFormat & 0xf);
      if (bo->format == DRM_FORMAT_INVALID) {
        ALOGV("Cannot convert hal format to drm format %u", hnd->iFormat);
        return -EINVAL;
      }
  }

  return 0;
}

}  // namespace android
