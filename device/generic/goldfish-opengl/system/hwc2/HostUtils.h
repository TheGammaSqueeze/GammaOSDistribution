/*
 * Copyright (C) 2021 The Android Open Source Project
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

#ifndef ANDROID_HWC_HOSTUTILS_H
#define ANDROID_HWC_HOSTUTILS_H

#include "Common.h"
#include "HostConnection.h"

namespace android {

HostConnection* createOrGetHostConnection();

#define DEFINE_AND_VALIDATE_HOST_CONNECTION                                   \
  HostConnection* hostCon = createOrGetHostConnection();                      \
  if (!hostCon) {                                                             \
    ALOGE("%s: Failed to get host connection\n", __FUNCTION__);               \
    return HWC2::Error::NoResources;                                          \
  }                                                                           \
  ExtendedRCEncoderContext* rcEnc = hostCon->rcEncoder();                     \
  if (!rcEnc) {                                                               \
    ALOGE("%s: Failed to get renderControl encoder context\n", __FUNCTION__); \
    return HWC2::Error::NoResources;                                          \
  }

}  // namespace android

#endif