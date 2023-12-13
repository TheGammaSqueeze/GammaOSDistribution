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

#define LOG_TAG "bt_stack_config"

#include "stack_config.h"

#include <base/logging.h>

#include "osi/include/future.h"
#include "osi/include/log.h"

const char* TRACE_CONFIG_ENABLED_KEY = "TraceConf";
const char* PTS_SECURE_ONLY_MODE = "PTS_SecurePairOnly";
const char* PTS_LE_CONN_UPDATED_DISABLED = "PTS_DisableConnUpdates";
const char* PTS_DISABLE_SDP_LE_PAIR = "PTS_DisableSDPOnLEPair";
const char* PTS_SMP_PAIRING_OPTIONS_KEY = "PTS_SmpOptions";
const char* PTS_SMP_FAILURE_CASE_KEY = "PTS_SmpFailureCase";
const char *PTS_LE_NONCONN_ADV_MODE = "PTS_EnableNonConnAdvMode";
const char *PTS_LE_CONN_NONDISC_ADV_MODE = "PTS_EnableConnNonDiscAdvMode";
const char* PTS_LE_SEC_REQUEST_DISABLED = "PTS_DisableSecRequest";
const char* PTS_LE_FRESH_PAIRING_ENABLED = "PTS_EnableFreshPairing";
const char* PTS_L2CAP_LE_INSUFF_ENCRYP = "PTS_L2capLeInsuffEnc";
const char* PTS_SMP_GENERATE_INVALID_PUBLIC_KEY = "PTS_GenerateInvalidPublicKey";
const char* PTS_BREDR_AUTH_REQ = "PTS_BredrAuthReq";
const char* PTS_BREDR_SECURECONNECTION_HOSTSUPPORT_DISABLE = "PTS_BredrSecConnHostSupportDisable";
const char* PTS_BREDR_INVALID_ENCRYPTION_KEYSIZE = "PTS_BredrInvalidEncryKeysize";
const char* PTS_LE_DISABLE_ENCRYP = "PTS_LeDisableEncryp";
const char* PTS_SMP_DISABLE_H7_SUPPORT = "PTS_DisableH7Support";

static config_t* config;

// Module lifecycle functions

static future_t* init() {
// TODO(armansito): Find a better way than searching by a hardcoded path.
#if defined(OS_GENERIC)
  const char* path = "bt_stack_qti.conf";
#else  // !defined(OS_GENERIC)
  const char* path = "/etc/bluetooth/bt_stack_qti.conf";
#endif  // defined(OS_GENERIC)
  CHECK(path != NULL);

  LOG_INFO(LOG_TAG, "%s attempt to load stack conf from %s", __func__, path);

  config = config_new(path);
  if (!config) {
    LOG_INFO(LOG_TAG, "%s file >%s< not found", __func__, path);
    config = config_new_empty();
  }

  return future_new_immediate(FUTURE_SUCCESS);
}

static future_t* clean_up() {
  config_free(config);
  config = NULL;
  return future_new_immediate(FUTURE_SUCCESS);
}

EXPORT_SYMBOL extern const module_t stack_config_module = {
    .name = STACK_CONFIG_MODULE,
    .init = init,
    .start_up = NULL,
    .shut_down = NULL,
    .clean_up = clean_up,
    .dependencies = {NULL}};

// Interface functions
static bool get_trace_config_enabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         TRACE_CONFIG_ENABLED_KEY, false);
}

static bool get_pts_secure_only_mode(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION, PTS_SECURE_ONLY_MODE,
                         false);
}

static bool get_pts_conn_updates_disabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         PTS_LE_CONN_UPDATED_DISABLED, false);
}

static bool get_pts_crosskey_sdp_disable(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         PTS_DISABLE_SDP_LE_PAIR, false);
}

static const char* get_pts_smp_options(void) {
  return config_get_string(config, CONFIG_DEFAULT_SECTION,
                           PTS_SMP_PAIRING_OPTIONS_KEY, NULL);
}

static int get_pts_smp_failure_case(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_SMP_FAILURE_CASE_KEY, 0);
}

static bool get_pts_le_nonconn_adv_enabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION, PTS_LE_NONCONN_ADV_MODE, false);
}

static bool get_pts_le_conn_nondisc_adv_enabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION, PTS_LE_CONN_NONDISC_ADV_MODE, false);
}

static bool get_pts_le_sec_request_disabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         PTS_LE_SEC_REQUEST_DISABLED, false);
}

static bool get_pts_le_fresh_pairing_enabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         PTS_LE_FRESH_PAIRING_ENABLED, false);
}

static int get_pts_l2cap_le_insuff_enc_result(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_L2CAP_LE_INSUFF_ENCRYP, 0);
}

static int get_pts_le_enc_disable(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_LE_DISABLE_ENCRYP, 0);
}

static int get_pts_smp_disable_h7_support(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_SMP_DISABLE_H7_SUPPORT, 0);
}

static int get_pts_smp_generate_invalid_public_key(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                           PTS_SMP_GENERATE_INVALID_PUBLIC_KEY, 0);
}

static int get_pts_bredr_auth_req(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_BREDR_AUTH_REQ, -1);
}

static bool get_pts_bredr_secureconnection_host_support_disabled(void) {
  return config_get_bool(config, CONFIG_DEFAULT_SECTION,
                         PTS_BREDR_SECURECONNECTION_HOSTSUPPORT_DISABLE, false);
}

static int get_pts_bredr_invalid_encryption_keysize(void) {
  return config_get_int(config, CONFIG_DEFAULT_SECTION,
                        PTS_BREDR_INVALID_ENCRYPTION_KEYSIZE, 0);
}

static config_t* get_all(void) { return config; }

const stack_config_t interface = {get_trace_config_enabled,
                                  get_pts_secure_only_mode,
                                  get_pts_conn_updates_disabled,
                                  get_pts_crosskey_sdp_disable,
                                  get_pts_smp_options,
                                  get_pts_smp_failure_case,
                                  get_pts_le_nonconn_adv_enabled,
                                  get_pts_le_conn_nondisc_adv_enabled,
                                  get_pts_le_sec_request_disabled,
                                  get_pts_le_fresh_pairing_enabled,
                                  get_pts_l2cap_le_insuff_enc_result,
                                  get_pts_smp_generate_invalid_public_key,
                                  get_pts_bredr_auth_req,
                                  get_pts_bredr_secureconnection_host_support_disabled,
                                  get_pts_bredr_invalid_encryption_keysize,
                                  get_pts_le_enc_disable,
                                  get_pts_smp_disable_h7_support,
                                  get_all};

const stack_config_t* stack_config_get_interface(void) { return &interface; }
