/******************************************************************************
 *
 *  Copyright (C) 2014 Google, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#pragma once

#include <stdint.h>

#define SOC_ADD_ON_FEATURES_MAX_SIZE 245
#define HOST_ADD_ON_FEATURES_MAX_SIZE 255

#define HOST_ADD_ON_ADV_AUDIO_UNICAST_FEAT_MASK(x) ((x)[0] & 0x01)
#define HOST_ADD_ON_ADV_AUDIO_BCA_FEAT_MASK(x)     ((x)[0] & 0x02)
#define HOST_ADD_ON_ADV_AUDIO_BCS_FEAT_MASK(x)     ((x)[0] & 0x04)
#define HOST_ADD_ON_ADV_AUDIO_STEREO_RECORDING(x)  ((x)[0] & 0x08)
#define HOST_ADD_ON_ADV_AUDIO_LC3Q_FEAT_MASK(x)    ((x)[0] & 0x10)
#define HOST_ADD_ON_QHS_FEAT_MASK(x)               ((x)[0] & 0x20)

// Represents a page of device feature enabled/disabled bits returned
// by the local controller. See the bluetooth spec for bit indexes.
typedef struct { uint8_t as_array[8]; } bt_device_features_t;

typedef struct {
  uint8_t as_array[SOC_ADD_ON_FEATURES_MAX_SIZE];
} bt_device_soc_add_on_features_t;

typedef struct {
  uint8_t as_array[HOST_ADD_ON_FEATURES_MAX_SIZE];
} bt_device_host_add_on_features_t;

