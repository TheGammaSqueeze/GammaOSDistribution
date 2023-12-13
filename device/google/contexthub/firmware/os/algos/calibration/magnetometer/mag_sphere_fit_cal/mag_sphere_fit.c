/*
 * Copyright (C) 2017 The Android Open Source Project
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

#include "calibration/magnetometer/mag_sphere_fit_cal/mag_sphere_fit.h"

#include <errno.h>
#include <string.h>

#define MAX_ITERATIONS 30
#define INITIAL_U_SCALE 1.0e-4f
#define GRADIENT_THRESHOLD 1.0e-16f
#define RELATIVE_STEP_THRESHOLD 1.0e-7f
#define FROM_MICRO_SEC_TO_SEC 1.0e-6f

void magCalSphereReset(struct MagCalSphere *mocs) {
  mocs->number_of_data_samples = 0;
  mocs->sample_counter = 0;
  memset(&mocs->sphere_data, 0, sizeof(mocs->sphere_data));
}

void initMagCalSphere(
    struct MagCalSphere *mocs,
    const struct MagCalParameters *mag_cal_parameters,
    const struct DiversityCheckerParameters *diverse_parameters,
    float default_odr_in_hz) {
  initMagCal(&mocs->moc, mag_cal_parameters, diverse_parameters);
  mocs->inv_data_size = 1.0f / (float)NUM_SPHERE_FIT_DATA;
  mocs->batch_time_in_sec =
      (float)(mag_cal_parameters->min_batch_window_in_micros) *
      FROM_MICRO_SEC_TO_SEC;
  // Initialize to take every sample, default setting.
  mocs->sample_drop = 0;
  magCalSphereReset(mocs);

  // Setting lm params.
  mocs->sphere_fit.params.max_iterations = MAX_ITERATIONS;
  mocs->sphere_fit.params.initial_u_scale = INITIAL_U_SCALE;
  mocs->sphere_fit.params.gradient_threshold = GRADIENT_THRESHOLD;
  mocs->sphere_fit.params.relative_step_threshold = RELATIVE_STEP_THRESHOLD;
  sphereFitInit(&mocs->sphere_fit.sphere_cal, &mocs->sphere_fit.params,
                MIN_NUM_SPHERE_FIT_POINTS);
  sphereFitSetSolverData(&mocs->sphere_fit.sphere_cal,
                         &mocs->sphere_fit.lm_data);
  calDataReset(&mocs->sphere_fit.sphere_param);

  // Initializes the starting output data rate estimate.
  magCalSphereOdrUpdate(mocs, default_odr_in_hz);
}

void magCalSphereOdrUpdate(struct MagCalSphere *mocs, float odr_in_hz) {
  // Calculate the numbers of samples to be dropped, in order to fill up
  // the data set.
  float sample_drop = odr_in_hz * mocs->batch_time_in_sec * mocs->inv_data_size;
  mocs->sample_drop = (uint32_t)floorf(sample_drop);
}

// Updates the sphere fit data set, by calculating the numbers
// of samples to be dropped, based on odr_in_hz, to fill up the available memory
// in the given batch size window.
void magCalSphereDataUpdate(struct MagCalSphere *mocs, float x, float y,
                            float z) {
  // build a vector.
  const float vec[3] = {x, y, z};

  // sample_counter for the down sampling.
  mocs->sample_counter++;

  // checking if sample_count >= sample_drop, if yes we store the mag sample in
  // the data set.
  if (mocs->sample_counter >= mocs->sample_drop) {
    if (mocs->number_of_data_samples < NUM_SPHERE_FIT_DATA) {
      memcpy(&mocs->sphere_data[mocs->number_of_data_samples *
                                THREE_AXIS_DATA_DIM],
             vec, sizeof(float) * THREE_AXIS_DATA_DIM);
      // counting the numbers of samples in the data set.
      mocs->number_of_data_samples++;
    }
    // resetting the sample_counter.
    mocs->sample_counter = 0;
  }
}

// Runs the Sphere Fit.
enum MagUpdate magCalSphereFit(struct MagCalSphere *mocs,
                               uint64_t sample_time_us) {
  // Setting up sphere fit data.
  struct SphereFitData data = {&mocs->sphere_data[0], NULL,
                               mocs->number_of_data_samples, mocs->moc.radius};
  float initial_bias[3] = {mocs->moc.x_bias, mocs->moc.y_bias,
                           mocs->moc.z_bias};

  // Setting initial bias values based on the KASA fit.
  sphereFitSetInitialBias(&mocs->sphere_fit.sphere_cal, initial_bias);

  // Running the sphere fit and checking if successful.
  if (sphereFitRunCal(&mocs->sphere_fit.sphere_cal, &data, sample_time_us)) {
    // Updating sphere parameters.
    sphereFitGetLatestCal(&mocs->sphere_fit.sphere_cal,
                          &mocs->sphere_fit.sphere_param);

    // Updating that a full sphere fit is available.
    return UPDATE_SPHERE_FIT;
  }
  return NO_UPDATE;
}

enum MagUpdate magCalSphereUpdate(struct MagCalSphere *mocs,
                                  uint64_t sample_time_us, float x, float y,
                                  float z) {
  enum MagUpdate new_cal = NO_UPDATE;

  // Saving data for sphere fit.
  magCalSphereDataUpdate(mocs, x, y, z);

  // Checking if KASA found a bias, if yes can run the sphere fit.
  if (UPDATE_BIAS == magCalUpdate(&mocs->moc, sample_time_us, x, y, z)) {
    // Running the sphere fit algo.
    new_cal = magCalSphereFit(mocs, sample_time_us);

    // Resetting.
    sphereFitReset(&mocs->sphere_fit.sphere_cal);
    magCalSphereReset(mocs);

    // If moc.kasa_batching is false, ran into a time out, hence the sphere
    // algo has to be reset as well.
  } else if (!mocs->moc.kasa_batching) {
    magCalSphereReset(mocs);
  }

  // Return which update has happened.
  return new_cal;
}
