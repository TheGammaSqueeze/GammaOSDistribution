/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "calibration/sphere_fit/calibration_data.h"

#include <string.h>

#include "common/math/vec.h"

// FUNCTION IMPLEMENTATIONS
//////////////////////////////////////////////////////////////////////////////

// Set calibration data to identity scale factors, zero skew and
// zero bias.
void calDataReset(struct ThreeAxisCalData* calstruct) {
  memset(calstruct, 0, sizeof(struct ThreeAxisCalData));
  calstruct->scale_factor_x = 1.0f;
  calstruct->scale_factor_y = 1.0f;
  calstruct->scale_factor_z = 1.0f;
}

void calDataCorrectData(const struct ThreeAxisCalData* calstruct,
                        const float x_impaired[THREE_AXIS_DIM],
                        float* x_corrected) {
  // x_temp = (x_impaired - bias).
  float x_temp[THREE_AXIS_DIM];
  vecSub(x_temp, x_impaired, calstruct->bias, THREE_AXIS_DIM);

  // x_corrected = scale_skew_mat * x_temp, where:
  // scale_skew_mat = [scale_factor_x    0         0
  //                   skew_yx    scale_factor_y   0
  //                   skew_zx       skew_zy   scale_factor_z].
  x_corrected[0] = calstruct->scale_factor_x * x_temp[0];
  x_corrected[1] =
      calstruct->skew_yx * x_temp[0] + calstruct->scale_factor_y * x_temp[1];
  x_corrected[2] = calstruct->skew_zx * x_temp[0] +
                   calstruct->skew_zy * x_temp[1] +
                   calstruct->scale_factor_z * x_temp[2];
}
