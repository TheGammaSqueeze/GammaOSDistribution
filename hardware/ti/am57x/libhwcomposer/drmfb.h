/*
 * Copyright (C) Texas Instruments Incorporated - http://www.ti.com/
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

#pragma once

#include <cstdint>

class DRMFramebuffer
{
   public:
    DRMFramebuffer(int drm_fd, buffer_handle_t handle, bool is_overlay);
    ~DRMFramebuffer();

    uint32_t width;
    uint32_t height;
    uint32_t format;
    uint32_t bo[4];
    uint32_t pitches[4];
    uint32_t offsets[4];
    uint32_t fb_id;
    int drm_fd;
};
