/*
 * Copyright (C) 2017, 2019-2022 Arm Limited. All rights reserved.
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

#pragma once

#include <stdint.h>
#include <pthread.h>
#include <errno.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cutils/native_handle.h>

#ifndef GRALLOC_VERSION_MAJOR
#error "GRALLOC_VERSION_MAJOR must be defined."
#endif

#if GRALLOC_VERSION_MAJOR == 4
    /* Allocator = 4.0, Mapper = 4.0 and Common = 1.2 */
    #define HIDL_ALLOCATOR_VERSION_SCALED 400
    #define HIDL_MAPPER_VERSION_SCALED 400
    #define HIDL_COMMON_VERSION_SCALED 120
#else
    #error "Gralloc version $(GRALLOC_VERSION_MAJOR) is not supported"
#endif

#include "gralloc/formats.h"
#include "usages.h"
#include "helper_functions.h"
