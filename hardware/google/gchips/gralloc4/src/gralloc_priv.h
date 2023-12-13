/*
 * Copyright (C) 2017, 2019-2020 Arm Limited. All rights reserved.
 *
 * Copyright (C) 2008 The Android Open Source Project
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

#ifndef GRALLOC_PRIV_H_
#define GRALLOC_PRIV_H_

#include <stdint.h>
#include <pthread.h>
#include <errno.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cutils/native_handle.h>

/* Allocator = 4.0, Mapper = 4.0 and Common = 1.2 */
#define HIDL_ALLOCATOR_VERSION_SCALED 400
#define HIDL_MAPPER_VERSION_SCALED 400
#define HIDL_COMMON_VERSION_SCALED 120

#include "mali_gralloc_formats.h"
#include "mali_gralloc_usages.h"
#include "gralloc_helper.h"

/*
 * This header file contains the private buffer definition. For gralloc 0.3 it will
 * always be exposed, but for gralloc 1.0 it will be removed at some point in the future.
 *
 * GRALLOC_DISABLE_PRIVATE_BUFFER_DEF is intended for DDKs to test while implementing
 * the new private API.
 */
#include "mali_gralloc_buffer.h"

#endif /* GRALLOC_PRIV_H_ */
