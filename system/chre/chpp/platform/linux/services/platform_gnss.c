/**
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

#include <stdbool.h>
#include <stdint.h>

#include "chpp/common/gnss.h"
#include "chpp/macros.h"
#include "chre/pal/gnss.h"

static const struct chrePalSystemApi *gSystemApi;
static const struct chrePalGnssCallbacks *gCallbacks;

static bool gnssPalOpen(const struct chrePalSystemApi *systemApi,
                        const struct chrePalGnssCallbacks *callbacks) {
  gSystemApi = systemApi;
  gCallbacks = callbacks;

  return true;
}

static void gnssPalClose(void) {}

static uint32_t gnssPalGetCapabilities(void) {
  return CHRE_GNSS_CAPABILITIES_LOCATION | CHRE_GNSS_CAPABILITIES_MEASUREMENTS |
         CHRE_GNSS_CAPABILITIES_GNSS_ENGINE_BASED_PASSIVE_LISTENER;
}

static bool gnssPalControlLocationSession(bool enable, uint32_t minIntervalMs,
                                          uint32_t minTimeToNextFixMs) {
  // TODO
  UNUSED_VAR(enable);
  UNUSED_VAR(minIntervalMs);
  UNUSED_VAR(minTimeToNextFixMs);

  return true;  // If successful
}

static void gnssPalReleaseLocationEvent(struct chreGnssLocationEvent *event) {
  gSystemApi->memoryFree(event);
}

static bool gnssPalControlMeasurementSessiont(bool enable,
                                              uint32_t minIntervalMs) {
  // TODO
  UNUSED_VAR(enable);
  UNUSED_VAR(minIntervalMs);

  return true;  // If successful
}

static void gnssPalReleaseMeasurementDataEvent(
    struct chreGnssDataEvent *event) {
  gSystemApi->memoryFree(CHPP_CONST_CAST_POINTER(event->measurements));
  gSystemApi->memoryFree(event);
}

static bool gnssPalConfigurePassiveLocationListener(bool enable) {
  // TODO
  UNUSED_VAR(enable);

  return true;  // If successful
}

#ifdef CHPP_SERVICE_ENABLED_GNSS
const struct chrePalGnssApi *chrePalGnssGetApi(uint32_t requestedApiVersion) {
  static const struct chrePalGnssApi api = {
      .moduleVersion = CHPP_PAL_GNSS_API_VERSION,
      .open = gnssPalOpen,
      .close = gnssPalClose,
      .getCapabilities = gnssPalGetCapabilities,
      .controlLocationSession = gnssPalControlLocationSession,
      .releaseLocationEvent = gnssPalReleaseLocationEvent,
      .controlMeasurementSession = gnssPalControlMeasurementSessiont,
      .releaseMeasurementDataEvent = gnssPalReleaseMeasurementDataEvent,
      .configurePassiveLocationListener =
          gnssPalConfigurePassiveLocationListener,
  };

  CHPP_STATIC_ASSERT(
      CHRE_PAL_GNSS_API_CURRENT_VERSION == CHPP_PAL_GNSS_API_VERSION,
      "A newer CHRE PAL API version is available. Please update.");

  if (!CHRE_PAL_VERSIONS_ARE_COMPATIBLE(api.moduleVersion,
                                        requestedApiVersion)) {
    return NULL;
  } else {
    return &api;
  }
}
#endif
