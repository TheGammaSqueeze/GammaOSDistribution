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

#ifndef CHPP_WIFI_COMMON_H_
#define CHPP_WIFI_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#include "chpp/app.h"
#include "chpp/macros.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************
 *  Public Definitions
 ***********************************************/

#define CHPP_PAL_WIFI_API_VERSION CHRE_PAL_WIFI_API_V1_5

/**
 * Data structures used by the Configure Scan Monitor request.
 */
CHPP_PACKED_START
struct ChppWifiConfigureScanMonitorAsyncRequestParameters {
  bool enable;
  const void *cookie;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

CHPP_PACKED_START
struct ChppWifiConfigureScanMonitorAsyncRequest {
  struct ChppAppHeader header;
  struct ChppWifiConfigureScanMonitorAsyncRequestParameters params;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

/**
 * Data structures used by the Get Capabilities Response.
 */
CHPP_PACKED_START
struct ChppWifiGetCapabilitiesParameters {
  uint32_t capabilities;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

CHPP_PACKED_START
struct ChppWifiGetCapabilitiesResponse {
  struct ChppAppHeader header;
  struct ChppWifiGetCapabilitiesParameters params;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

/**
 * Data structures used by the Configure Scan Monitor Async Response.
 */
CHPP_PACKED_START
struct ChppWifiConfigureScanMonitorAsyncResponseParameters {
  bool enabled;
  uint8_t errorCode;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

CHPP_PACKED_START
struct ChppWifiConfigureScanMonitorAsyncResponse {
  struct ChppAppHeader header;
  struct ChppWifiConfigureScanMonitorAsyncResponseParameters params;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

/**
 * Data structure used by the Request Scan Response.
 */
CHPP_PACKED_START
struct ChppWifiRequestScanResponseParameters {
  bool pending;
  uint8_t errorCode;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

CHPP_PACKED_START
struct ChppWifiRequestScanResponse {
  struct ChppAppHeader header;
  struct ChppWifiRequestScanResponseParameters params;
} CHPP_PACKED_ATTR;
CHPP_PACKED_END

/**
 * Commands used by the WiFi (WLAN) Service.
 */
enum ChppWifiCommands {
  //! Initializes the service.
  CHPP_WIFI_OPEN = 0x0000,

  //! Deinitializes the service.
  CHPP_WIFI_CLOSE = 0x0001,

  //! Retrieves a set of flags indicating supported features.
  CHPP_WIFI_GET_CAPABILITIES = 0x0002,

  //! Configures whether scanEventCallback receives unsolicited scan results.
  CHPP_WIFI_CONFIGURE_SCAN_MONITOR_ASYNC = 0x0003,

  //!  Request that the WiFi chipset perform a scan, or deliver cached results.
  CHPP_WIFI_REQUEST_SCAN_ASYNC = 0x0004,

  //! Request that the WiFi chipset perform RTT ranging.
  CHPP_WIFI_REQUEST_RANGING_ASYNC = 0x0005,
};
#define CHPP_WIFI_CLIENT_REQUEST_MAX CHPP_WIFI_REQUEST_RANGING_ASYNC

#ifdef __cplusplus
}
#endif

#endif  // CHPP_WIFI_COMMON_H_
