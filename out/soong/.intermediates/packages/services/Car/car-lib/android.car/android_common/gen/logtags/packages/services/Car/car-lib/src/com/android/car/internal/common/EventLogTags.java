/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: packages/services/Car/car-lib/src/com/android/car/internal/common/EventLogTags.logtags
 */

package com.android.car.internal.common;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 150000 car_helper_start */
  public static final int CAR_HELPER_START = 150000;

  /** 150001 car_helper_boot_phase (phase|1) */
  public static final int CAR_HELPER_BOOT_PHASE = 150001;

  /** 150002 car_helper_user_starting (user_id|1) */
  public static final int CAR_HELPER_USER_STARTING = 150002;

  /** 150003 car_helper_user_switching (from_user_id|1),(to_user_id|1) */
  public static final int CAR_HELPER_USER_SWITCHING = 150003;

  /** 150004 car_helper_user_unlocking (user_id|1) */
  public static final int CAR_HELPER_USER_UNLOCKING = 150004;

  /** 150005 car_helper_user_unlocked (user_id|1) */
  public static final int CAR_HELPER_USER_UNLOCKED = 150005;

  /** 150006 car_helper_user_stopping (user_id|1) */
  public static final int CAR_HELPER_USER_STOPPING = 150006;

  /** 150007 car_helper_user_stopped (user_id|1) */
  public static final int CAR_HELPER_USER_STOPPED = 150007;

  /** 150008 car_helper_svc_connected (pending_operations|1) */
  public static final int CAR_HELPER_SVC_CONNECTED = 150008;

  /** 150009 car_helper_hal_request (request_type|1) */
  public static final int CAR_HELPER_HAL_REQUEST = 150009;

  /** 150010 car_helper_hal_response (result_code|1) */
  public static final int CAR_HELPER_HAL_RESPONSE = 150010;

  /** 150011 car_helper_hal_default_behavior (fallback|1),(user_locales|3) */
  public static final int CAR_HELPER_HAL_DEFAULT_BEHAVIOR = 150011;

  /** 150012 car_helper_hal_start_user (user_id|1),(user_locales|3) */
  public static final int CAR_HELPER_HAL_START_USER = 150012;

  /** 150013 car_helper_hal_create_user (flags|1),(safe_name|3),(user_locales|3) */
  public static final int CAR_HELPER_HAL_CREATE_USER = 150013;

  /** 150050 car_service_init (number_services|1) */
  public static final int CAR_SERVICE_INIT = 150050;

  /** 150051 car_service_vhal_reconnected (number_services|1) */
  public static final int CAR_SERVICE_VHAL_RECONNECTED = 150051;

  /** 150052 car_service_set_car_service_helper (pid|1) */
  public static final int CAR_SERVICE_SET_CAR_SERVICE_HELPER = 150052;

  /** 150053 car_service_on_user_lifecycle (type|1),(from_user_id|1),(to_user_id|1) */
  public static final int CAR_SERVICE_ON_USER_LIFECYCLE = 150053;

  /** 150055 car_service_create (has_vhal|1) */
  public static final int CAR_SERVICE_CREATE = 150055;

  /** 150056 car_service_connected (interface|3) */
  public static final int CAR_SERVICE_CONNECTED = 150056;

  /** 150057 car_service_destroy (has_vhal|1) */
  public static final int CAR_SERVICE_DESTROY = 150057;

  /** 150058 car_service_vhal_died (cookie|2) */
  public static final int CAR_SERVICE_VHAL_DIED = 150058;

  /** 150059 car_service_init_boot_user */
  public static final int CAR_SERVICE_INIT_BOOT_USER = 150059;

  /** 150060 car_service_on_user_removed (user_id|1) */
  public static final int CAR_SERVICE_ON_USER_REMOVED = 150060;

  /** 150100 car_user_svc_initial_user_info_req (request_type|1),(timeout|1),(current_user_id|1),(current_user_flags|1),(number_existing_users|1) */
  public static final int CAR_USER_SVC_INITIAL_USER_INFO_REQ = 150100;

  /** 150101 car_user_svc_initial_user_info_resp (status|1),(action|1),(user_id|1),(flags|1),(safe_name|3),(user_locales|3) */
  public static final int CAR_USER_SVC_INITIAL_USER_INFO_RESP = 150101;

  /** 150103 car_user_svc_set_initial_user (user_id|1) */
  public static final int CAR_USER_SVC_SET_INITIAL_USER = 150103;

  /** 150104 car_user_svc_set_lifecycle_listener (uid|1),(package_name|3) */
  public static final int CAR_USER_SVC_SET_LIFECYCLE_LISTENER = 150104;

  /** 150105 car_user_svc_reset_lifecycle_listener (uid|1),(package_name|3) */
  public static final int CAR_USER_SVC_RESET_LIFECYCLE_LISTENER = 150105;

  /** 150106 car_user_svc_switch_user_req (user_id|1),(timeout|1) */
  public static final int CAR_USER_SVC_SWITCH_USER_REQ = 150106;

  /** 150107 car_user_svc_switch_user_resp (hal_callback_status|1),(user_switch_status|1),(error_message|3) */
  public static final int CAR_USER_SVC_SWITCH_USER_RESP = 150107;

  /** 150108 car_user_svc_post_switch_user_req (target_user_id|1),(current_user_id|1) */
  public static final int CAR_USER_SVC_POST_SWITCH_USER_REQ = 150108;

  /** 150109 car_user_svc_get_user_auth_req (uid|1),(user_id|1),(number_types|1) */
  public static final int CAR_USER_SVC_GET_USER_AUTH_REQ = 150109;

  /** 150110 car_user_svc_get_user_auth_resp (number_values|1) */
  public static final int CAR_USER_SVC_GET_USER_AUTH_RESP = 150110;

  /** 150111 car_user_svc_switch_user_ui_req (user_id|1) */
  public static final int CAR_USER_SVC_SWITCH_USER_UI_REQ = 150111;

  /** 150112 car_user_svc_switch_user_from_hal_req (request_id|1),(uid|1) */
  public static final int CAR_USER_SVC_SWITCH_USER_FROM_HAL_REQ = 150112;

  /** 150113 car_user_svc_set_user_auth_req (uid|1),(user_id|1),(number_associations|1) */
  public static final int CAR_USER_SVC_SET_USER_AUTH_REQ = 150113;

  /** 150114 car_user_svc_set_user_auth_resp (number_values|1),(error_message|3) */
  public static final int CAR_USER_SVC_SET_USER_AUTH_RESP = 150114;

  /** 150115 car_user_svc_create_user_req (safe_name|3),(user_type|3),(flags|1),(timeout|1) */
  public static final int CAR_USER_SVC_CREATE_USER_REQ = 150115;

  /** 150116 car_user_svc_create_user_resp (status|1),(result|1),(error_message|3) */
  public static final int CAR_USER_SVC_CREATE_USER_RESP = 150116;

  /** 150117 car_user_svc_create_user_user_created (user_id|1),(safe_name|3),(user_type|3),(flags|1) */
  public static final int CAR_USER_SVC_CREATE_USER_USER_CREATED = 150117;

  /** 150118 car_user_svc_create_user_user_removed (user_id|1),(reason|3) */
  public static final int CAR_USER_SVC_CREATE_USER_USER_REMOVED = 150118;

  /** 150119 car_user_svc_remove_user_req (user_id|1),(hasCallerRestrictions|1) */
  public static final int CAR_USER_SVC_REMOVE_USER_REQ = 150119;

  /** 150120 car_user_svc_remove_user_resp (user_id|1),(result|1) */
  public static final int CAR_USER_SVC_REMOVE_USER_RESP = 150120;

  /** 150121 car_user_svc_notify_app_lifecycle_listener (uid|1),(package_name|3),(event_type|1),(from_user_id|1),(to_user_id|1) */
  public static final int CAR_USER_SVC_NOTIFY_APP_LIFECYCLE_LISTENER = 150121;

  /** 150122 car_user_svc_notify_internal_lifecycle_listener (listener_name|3),(event_type|1),(from_user_id|1),(to_user_id|1) */
  public static final int CAR_USER_SVC_NOTIFY_INTERNAL_LIFECYCLE_LISTENER = 150122;

  /** 150123 car_user_svc_pre_creation_requested (number_users|1),(number_guests|1) */
  public static final int CAR_USER_SVC_PRE_CREATION_REQUESTED = 150123;

  /** 150124 car_user_svc_pre_creation_status (number_existing_users|1),(number_users_to_add|1),(number_users_to_remove|1),(number_existing_guests|1),(number_guests_to_add|1),(number_guests_to_remove|1),(number_invalid_users_to_remove|1) */
  public static final int CAR_USER_SVC_PRE_CREATION_STATUS = 150124;

  /** 150125 car_user_svc_start_user_in_background_req (user_id|1) */
  public static final int CAR_USER_SVC_START_USER_IN_BACKGROUND_REQ = 150125;

  /** 150126 car_user_svc_start_user_in_background_resp (user_id|1),(result|1) */
  public static final int CAR_USER_SVC_START_USER_IN_BACKGROUND_RESP = 150126;

  /** 150127 car_user_svc_stop_user_req (user_id|1) */
  public static final int CAR_USER_SVC_STOP_USER_REQ = 150127;

  /** 150128 car_user_svc_stop_user_resp (user_id|1),(result|1) */
  public static final int CAR_USER_SVC_STOP_USER_RESP = 150128;

  /** 150129 car_user_svc_initial_user_info_req_complete (request_type|1) */
  public static final int CAR_USER_SVC_INITIAL_USER_INFO_REQ_COMPLETE = 150129;

  /** 150130 car_user_svc_logout_user_req (user_id|1),(timeout|1) */
  public static final int CAR_USER_SVC_LOGOUT_USER_REQ = 150130;

  /** 150131 car_user_svc_logout_user_resp (hal_callback_status|1),(user_switch_status|1),(error_message|3) */
  public static final int CAR_USER_SVC_LOGOUT_USER_RESP = 150131;

  /** 150140 car_user_hal_initial_user_info_req (request_id|1),(request_type|1),(timeout|1) */
  public static final int CAR_USER_HAL_INITIAL_USER_INFO_REQ = 150140;

  /** 150141 car_user_hal_initial_user_info_resp (request_id|1),(status|1),(action|1),(user_id|1),(flags|1),(safe_name|3),(user_locales|3) */
  public static final int CAR_USER_HAL_INITIAL_USER_INFO_RESP = 150141;

  /** 150142 car_user_hal_switch_user_req (request_id|1),(user_id|1),(user_flags|1),(timeout|1) */
  public static final int CAR_USER_HAL_SWITCH_USER_REQ = 150142;

  /** 150143 car_user_hal_switch_user_resp (request_id|1),(status|1),(result|1),(error_message|3) */
  public static final int CAR_USER_HAL_SWITCH_USER_RESP = 150143;

  /** 150144 car_user_hal_post_switch_user_req (request_id|1),(target_user_id|1),(current_user_id|1) */
  public static final int CAR_USER_HAL_POST_SWITCH_USER_REQ = 150144;

  /** 150145 car_user_hal_get_user_auth_req (int32values|4) */
  public static final int CAR_USER_HAL_GET_USER_AUTH_REQ = 150145;

  /** 150146 car_user_hal_get_user_auth_resp (int32values|4),(error_message|3) */
  public static final int CAR_USER_HAL_GET_USER_AUTH_RESP = 150146;

  /** 150147 car_user_hal_legacy_switch_user_req (request_id|1),(target_user_id|1),(current_user_id|1) */
  public static final int CAR_USER_HAL_LEGACY_SWITCH_USER_REQ = 150147;

  /** 150148 car_user_hal_set_user_auth_req (int32values|4) */
  public static final int CAR_USER_HAL_SET_USER_AUTH_REQ = 150148;

  /** 150149 car_user_hal_set_user_auth_resp (int32values|4),(error_message|3) */
  public static final int CAR_USER_HAL_SET_USER_AUTH_RESP = 150149;

  /** 150150 car_user_hal_oem_switch_user_req (request_id|1),(target_user_id|1) */
  public static final int CAR_USER_HAL_OEM_SWITCH_USER_REQ = 150150;

  /** 150151 car_user_hal_create_user_req (request_id|1),(safe_name|3),(flags|1),(timeout|1) */
  public static final int CAR_USER_HAL_CREATE_USER_REQ = 150151;

  /** 150152 car_user_hal_create_user_resp (request_id|1),(status|1),(result|1),(error_message|3) */
  public static final int CAR_USER_HAL_CREATE_USER_RESP = 150152;

  /** 150153 car_user_hal_remove_user_req (target_user_id|1),(current_user_id|1) */
  public static final int CAR_USER_HAL_REMOVE_USER_REQ = 150153;

  /** 150171 car_user_mgr_add_listener (uid|1),(package_name|3) */
  public static final int CAR_USER_MGR_ADD_LISTENER = 150171;

  /** 150172 car_user_mgr_remove_listener (uid|1),(package_name|3) */
  public static final int CAR_USER_MGR_REMOVE_LISTENER = 150172;

  /** 150173 car_user_mgr_disconnected (uid|1) */
  public static final int CAR_USER_MGR_DISCONNECTED = 150173;

  /** 150174 car_user_mgr_switch_user_req (uid|1),(user_id|1) */
  public static final int CAR_USER_MGR_SWITCH_USER_REQ = 150174;

  /** 150175 car_user_mgr_switch_user_resp (uid|1),(status|1),(error_message|3) */
  public static final int CAR_USER_MGR_SWITCH_USER_RESP = 150175;

  /** 150176 car_user_mgr_get_user_auth_req (types|4) */
  public static final int CAR_USER_MGR_GET_USER_AUTH_REQ = 150176;

  /** 150177 car_user_mgr_get_user_auth_resp (values|4) */
  public static final int CAR_USER_MGR_GET_USER_AUTH_RESP = 150177;

  /** 150178 car_user_mgr_set_user_auth_req (types_and_values_pairs|4) */
  public static final int CAR_USER_MGR_SET_USER_AUTH_REQ = 150178;

  /** 150179 car_user_mgr_set_user_auth_resp (values|4) */
  public static final int CAR_USER_MGR_SET_USER_AUTH_RESP = 150179;

  /** 150180 car_user_mgr_create_user_req (uid|1),(safe_name|3),(user_type|3),(flags|1) */
  public static final int CAR_USER_MGR_CREATE_USER_REQ = 150180;

  /** 150181 car_user_mgr_create_user_resp (uid|1),(status|1),(error_message|3) */
  public static final int CAR_USER_MGR_CREATE_USER_RESP = 150181;

  /** 150182 car_user_mgr_remove_user_req (uid|1),(user_id|1) */
  public static final int CAR_USER_MGR_REMOVE_USER_REQ = 150182;

  /** 150183 car_user_mgr_remove_user_resp (uid|1),(status|1) */
  public static final int CAR_USER_MGR_REMOVE_USER_RESP = 150183;

  /** 150184 car_user_mgr_notify_lifecycle_listener (number_listeners|1),(event_type|1),(from_user_id|1),(to_user_id|1) */
  public static final int CAR_USER_MGR_NOTIFY_LIFECYCLE_LISTENER = 150184;

  /** 150185 car_user_mgr_pre_create_user_req (uid|1) */
  public static final int CAR_USER_MGR_PRE_CREATE_USER_REQ = 150185;

  /** 150186 car_user_mgr_logout_user_req (uid|1) */
  public static final int CAR_USER_MGR_LOGOUT_USER_REQ = 150186;

  /** 150187 car_user_mgr_logout_user_resp (uid|1),(status|1),(error_message|3) */
  public static final int CAR_USER_MGR_LOGOUT_USER_RESP = 150187;

  /** 150200 car_dp_mgr_remove_user_req (uid|1),(user_id|1) */
  public static final int CAR_DP_MGR_REMOVE_USER_REQ = 150200;

  /** 150201 car_dp_mgr_remove_user_resp (uid|1),(status|1) */
  public static final int CAR_DP_MGR_REMOVE_USER_RESP = 150201;

  /** 150202 car_dp_mgr_create_user_req (uid|1),(safe_name|3),(flags|1) */
  public static final int CAR_DP_MGR_CREATE_USER_REQ = 150202;

  /** 150203 car_dp_mgr_create_user_resp (uid|1),(status|1) */
  public static final int CAR_DP_MGR_CREATE_USER_RESP = 150203;

  /** 150204 car_dp_mgr_start_user_in_background_req (uid|1),(user_id|1) */
  public static final int CAR_DP_MGR_START_USER_IN_BACKGROUND_REQ = 150204;

  /** 150205 car_dp_mgr_start_user_in_background_resp (uid|1),(status|1) */
  public static final int CAR_DP_MGR_START_USER_IN_BACKGROUND_RESP = 150205;

  /** 150206 car_dp_mgr_stop_user_req (uid|1),(user_id|1) */
  public static final int CAR_DP_MGR_STOP_USER_REQ = 150206;

  /** 150207 car_dp_mgr_stop_user_resp (uid|1),(status|1) */
  public static final int CAR_DP_MGR_STOP_USER_RESP = 150207;

  public static void writeCarHelperStart() {
    android.util.EventLog.writeEvent(CAR_HELPER_START);
  }

  public static void writeCarHelperBootPhase(int phase) {
    android.util.EventLog.writeEvent(CAR_HELPER_BOOT_PHASE, phase);
  }

  public static void writeCarHelperUserStarting(int userId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_STARTING, userId);
  }

  public static void writeCarHelperUserSwitching(int fromUserId, int toUserId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_SWITCHING, fromUserId, toUserId);
  }

  public static void writeCarHelperUserUnlocking(int userId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_UNLOCKING, userId);
  }

  public static void writeCarHelperUserUnlocked(int userId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_UNLOCKED, userId);
  }

  public static void writeCarHelperUserStopping(int userId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_STOPPING, userId);
  }

  public static void writeCarHelperUserStopped(int userId) {
    android.util.EventLog.writeEvent(CAR_HELPER_USER_STOPPED, userId);
  }

  public static void writeCarHelperSvcConnected(int pendingOperations) {
    android.util.EventLog.writeEvent(CAR_HELPER_SVC_CONNECTED, pendingOperations);
  }

  public static void writeCarHelperHalRequest(int requestType) {
    android.util.EventLog.writeEvent(CAR_HELPER_HAL_REQUEST, requestType);
  }

  public static void writeCarHelperHalResponse(int resultCode) {
    android.util.EventLog.writeEvent(CAR_HELPER_HAL_RESPONSE, resultCode);
  }

  public static void writeCarHelperHalDefaultBehavior(int fallback, String userLocales) {
    android.util.EventLog.writeEvent(CAR_HELPER_HAL_DEFAULT_BEHAVIOR, fallback, userLocales);
  }

  public static void writeCarHelperHalStartUser(int userId, String userLocales) {
    android.util.EventLog.writeEvent(CAR_HELPER_HAL_START_USER, userId, userLocales);
  }

  public static void writeCarHelperHalCreateUser(int flags, String safeName, String userLocales) {
    android.util.EventLog.writeEvent(CAR_HELPER_HAL_CREATE_USER, flags, safeName, userLocales);
  }

  public static void writeCarServiceInit(int numberServices) {
    android.util.EventLog.writeEvent(CAR_SERVICE_INIT, numberServices);
  }

  public static void writeCarServiceVhalReconnected(int numberServices) {
    android.util.EventLog.writeEvent(CAR_SERVICE_VHAL_RECONNECTED, numberServices);
  }

  public static void writeCarServiceSetCarServiceHelper(int pid) {
    android.util.EventLog.writeEvent(CAR_SERVICE_SET_CAR_SERVICE_HELPER, pid);
  }

  public static void writeCarServiceOnUserLifecycle(int type, int fromUserId, int toUserId) {
    android.util.EventLog.writeEvent(CAR_SERVICE_ON_USER_LIFECYCLE, type, fromUserId, toUserId);
  }

  public static void writeCarServiceCreate(int hasVhal) {
    android.util.EventLog.writeEvent(CAR_SERVICE_CREATE, hasVhal);
  }

  public static void writeCarServiceConnected(String interface_) {
    android.util.EventLog.writeEvent(CAR_SERVICE_CONNECTED, interface_);
  }

  public static void writeCarServiceDestroy(int hasVhal) {
    android.util.EventLog.writeEvent(CAR_SERVICE_DESTROY, hasVhal);
  }

  public static void writeCarServiceVhalDied(long cookie) {
    android.util.EventLog.writeEvent(CAR_SERVICE_VHAL_DIED, cookie);
  }

  public static void writeCarServiceInitBootUser() {
    android.util.EventLog.writeEvent(CAR_SERVICE_INIT_BOOT_USER);
  }

  public static void writeCarServiceOnUserRemoved(int userId) {
    android.util.EventLog.writeEvent(CAR_SERVICE_ON_USER_REMOVED, userId);
  }

  public static void writeCarUserSvcInitialUserInfoReq(int requestType, int timeout, int currentUserId, int currentUserFlags, int numberExistingUsers) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_INITIAL_USER_INFO_REQ, requestType, timeout, currentUserId, currentUserFlags, numberExistingUsers);
  }

  public static void writeCarUserSvcInitialUserInfoResp(int status, int action, int userId, int flags, String safeName, String userLocales) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_INITIAL_USER_INFO_RESP, status, action, userId, flags, safeName, userLocales);
  }

  public static void writeCarUserSvcSetInitialUser(int userId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SET_INITIAL_USER, userId);
  }

  public static void writeCarUserSvcSetLifecycleListener(int uid, String packageName) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SET_LIFECYCLE_LISTENER, uid, packageName);
  }

  public static void writeCarUserSvcResetLifecycleListener(int uid, String packageName) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_RESET_LIFECYCLE_LISTENER, uid, packageName);
  }

  public static void writeCarUserSvcSwitchUserReq(int userId, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SWITCH_USER_REQ, userId, timeout);
  }

  public static void writeCarUserSvcSwitchUserResp(int halCallbackStatus, int userSwitchStatus, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SWITCH_USER_RESP, halCallbackStatus, userSwitchStatus, errorMessage);
  }

  public static void writeCarUserSvcPostSwitchUserReq(int targetUserId, int currentUserId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_POST_SWITCH_USER_REQ, targetUserId, currentUserId);
  }

  public static void writeCarUserSvcGetUserAuthReq(int uid, int userId, int numberTypes) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_GET_USER_AUTH_REQ, uid, userId, numberTypes);
  }

  public static void writeCarUserSvcGetUserAuthResp(int numberValues) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_GET_USER_AUTH_RESP, numberValues);
  }

  public static void writeCarUserSvcSwitchUserUiReq(int userId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SWITCH_USER_UI_REQ, userId);
  }

  public static void writeCarUserSvcSwitchUserFromHalReq(int requestId, int uid) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SWITCH_USER_FROM_HAL_REQ, requestId, uid);
  }

  public static void writeCarUserSvcSetUserAuthReq(int uid, int userId, int numberAssociations) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SET_USER_AUTH_REQ, uid, userId, numberAssociations);
  }

  public static void writeCarUserSvcSetUserAuthResp(int numberValues, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_SET_USER_AUTH_RESP, numberValues, errorMessage);
  }

  public static void writeCarUserSvcCreateUserReq(String safeName, String userType, int flags, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_CREATE_USER_REQ, safeName, userType, flags, timeout);
  }

  public static void writeCarUserSvcCreateUserResp(int status, int result, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_CREATE_USER_RESP, status, result, errorMessage);
  }

  public static void writeCarUserSvcCreateUserUserCreated(int userId, String safeName, String userType, int flags) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_CREATE_USER_USER_CREATED, userId, safeName, userType, flags);
  }

  public static void writeCarUserSvcCreateUserUserRemoved(int userId, String reason) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_CREATE_USER_USER_REMOVED, userId, reason);
  }

  public static void writeCarUserSvcRemoveUserReq(int userId, int hascallerrestrictions) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_REMOVE_USER_REQ, userId, hascallerrestrictions);
  }

  public static void writeCarUserSvcRemoveUserResp(int userId, int result) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_REMOVE_USER_RESP, userId, result);
  }

  public static void writeCarUserSvcNotifyAppLifecycleListener(int uid, String packageName, int eventType, int fromUserId, int toUserId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_NOTIFY_APP_LIFECYCLE_LISTENER, uid, packageName, eventType, fromUserId, toUserId);
  }

  public static void writeCarUserSvcNotifyInternalLifecycleListener(String listenerName, int eventType, int fromUserId, int toUserId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_NOTIFY_INTERNAL_LIFECYCLE_LISTENER, listenerName, eventType, fromUserId, toUserId);
  }

  public static void writeCarUserSvcPreCreationRequested(int numberUsers, int numberGuests) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_PRE_CREATION_REQUESTED, numberUsers, numberGuests);
  }

  public static void writeCarUserSvcPreCreationStatus(int numberExistingUsers, int numberUsersToAdd, int numberUsersToRemove, int numberExistingGuests, int numberGuestsToAdd, int numberGuestsToRemove, int numberInvalidUsersToRemove) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_PRE_CREATION_STATUS, numberExistingUsers, numberUsersToAdd, numberUsersToRemove, numberExistingGuests, numberGuestsToAdd, numberGuestsToRemove, numberInvalidUsersToRemove);
  }

  public static void writeCarUserSvcStartUserInBackgroundReq(int userId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_START_USER_IN_BACKGROUND_REQ, userId);
  }

  public static void writeCarUserSvcStartUserInBackgroundResp(int userId, int result) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_START_USER_IN_BACKGROUND_RESP, userId, result);
  }

  public static void writeCarUserSvcStopUserReq(int userId) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_STOP_USER_REQ, userId);
  }

  public static void writeCarUserSvcStopUserResp(int userId, int result) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_STOP_USER_RESP, userId, result);
  }

  public static void writeCarUserSvcInitialUserInfoReqComplete(int requestType) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_INITIAL_USER_INFO_REQ_COMPLETE, requestType);
  }

  public static void writeCarUserSvcLogoutUserReq(int userId, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_LOGOUT_USER_REQ, userId, timeout);
  }

  public static void writeCarUserSvcLogoutUserResp(int halCallbackStatus, int userSwitchStatus, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_SVC_LOGOUT_USER_RESP, halCallbackStatus, userSwitchStatus, errorMessage);
  }

  public static void writeCarUserHalInitialUserInfoReq(int requestId, int requestType, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_INITIAL_USER_INFO_REQ, requestId, requestType, timeout);
  }

  public static void writeCarUserHalInitialUserInfoResp(int requestId, int status, int action, int userId, int flags, String safeName, String userLocales) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_INITIAL_USER_INFO_RESP, requestId, status, action, userId, flags, safeName, userLocales);
  }

  public static void writeCarUserHalSwitchUserReq(int requestId, int userId, int userFlags, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_SWITCH_USER_REQ, requestId, userId, userFlags, timeout);
  }

  public static void writeCarUserHalSwitchUserResp(int requestId, int status, int result, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_SWITCH_USER_RESP, requestId, status, result, errorMessage);
  }

  public static void writeCarUserHalPostSwitchUserReq(int requestId, int targetUserId, int currentUserId) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_POST_SWITCH_USER_REQ, requestId, targetUserId, currentUserId);
  }

  public static void writeCarUserHalGetUserAuthReq(Object[] int32Values) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_GET_USER_AUTH_REQ, int32Values);
  }

  public static void writeCarUserHalGetUserAuthResp(Object[] int32Values, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_GET_USER_AUTH_RESP, int32Values, errorMessage);
  }

  public static void writeCarUserHalLegacySwitchUserReq(int requestId, int targetUserId, int currentUserId) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_LEGACY_SWITCH_USER_REQ, requestId, targetUserId, currentUserId);
  }

  public static void writeCarUserHalSetUserAuthReq(Object[] int32Values) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_SET_USER_AUTH_REQ, int32Values);
  }

  public static void writeCarUserHalSetUserAuthResp(Object[] int32Values, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_SET_USER_AUTH_RESP, int32Values, errorMessage);
  }

  public static void writeCarUserHalOemSwitchUserReq(int requestId, int targetUserId) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_OEM_SWITCH_USER_REQ, requestId, targetUserId);
  }

  public static void writeCarUserHalCreateUserReq(int requestId, String safeName, int flags, int timeout) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_CREATE_USER_REQ, requestId, safeName, flags, timeout);
  }

  public static void writeCarUserHalCreateUserResp(int requestId, int status, int result, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_CREATE_USER_RESP, requestId, status, result, errorMessage);
  }

  public static void writeCarUserHalRemoveUserReq(int targetUserId, int currentUserId) {
    android.util.EventLog.writeEvent(CAR_USER_HAL_REMOVE_USER_REQ, targetUserId, currentUserId);
  }

  public static void writeCarUserMgrAddListener(int uid, String packageName) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_ADD_LISTENER, uid, packageName);
  }

  public static void writeCarUserMgrRemoveListener(int uid, String packageName) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_REMOVE_LISTENER, uid, packageName);
  }

  public static void writeCarUserMgrDisconnected(int uid) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_DISCONNECTED, uid);
  }

  public static void writeCarUserMgrSwitchUserReq(int uid, int userId) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_SWITCH_USER_REQ, uid, userId);
  }

  public static void writeCarUserMgrSwitchUserResp(int uid, int status, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_SWITCH_USER_RESP, uid, status, errorMessage);
  }

  public static void writeCarUserMgrGetUserAuthReq(Object[] types) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_GET_USER_AUTH_REQ, types);
  }

  public static void writeCarUserMgrGetUserAuthResp(Object[] values) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_GET_USER_AUTH_RESP, values);
  }

  public static void writeCarUserMgrSetUserAuthReq(Object[] typesAndValuesPairs) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_SET_USER_AUTH_REQ, typesAndValuesPairs);
  }

  public static void writeCarUserMgrSetUserAuthResp(Object[] values) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_SET_USER_AUTH_RESP, values);
  }

  public static void writeCarUserMgrCreateUserReq(int uid, String safeName, String userType, int flags) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_CREATE_USER_REQ, uid, safeName, userType, flags);
  }

  public static void writeCarUserMgrCreateUserResp(int uid, int status, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_CREATE_USER_RESP, uid, status, errorMessage);
  }

  public static void writeCarUserMgrRemoveUserReq(int uid, int userId) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_REMOVE_USER_REQ, uid, userId);
  }

  public static void writeCarUserMgrRemoveUserResp(int uid, int status) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_REMOVE_USER_RESP, uid, status);
  }

  public static void writeCarUserMgrNotifyLifecycleListener(int numberListeners, int eventType, int fromUserId, int toUserId) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_NOTIFY_LIFECYCLE_LISTENER, numberListeners, eventType, fromUserId, toUserId);
  }

  public static void writeCarUserMgrPreCreateUserReq(int uid) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_PRE_CREATE_USER_REQ, uid);
  }

  public static void writeCarUserMgrLogoutUserReq(int uid) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_LOGOUT_USER_REQ, uid);
  }

  public static void writeCarUserMgrLogoutUserResp(int uid, int status, String errorMessage) {
    android.util.EventLog.writeEvent(CAR_USER_MGR_LOGOUT_USER_RESP, uid, status, errorMessage);
  }

  public static void writeCarDpMgrRemoveUserReq(int uid, int userId) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_REMOVE_USER_REQ, uid, userId);
  }

  public static void writeCarDpMgrRemoveUserResp(int uid, int status) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_REMOVE_USER_RESP, uid, status);
  }

  public static void writeCarDpMgrCreateUserReq(int uid, String safeName, int flags) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_CREATE_USER_REQ, uid, safeName, flags);
  }

  public static void writeCarDpMgrCreateUserResp(int uid, int status) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_CREATE_USER_RESP, uid, status);
  }

  public static void writeCarDpMgrStartUserInBackgroundReq(int uid, int userId) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_START_USER_IN_BACKGROUND_REQ, uid, userId);
  }

  public static void writeCarDpMgrStartUserInBackgroundResp(int uid, int status) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_START_USER_IN_BACKGROUND_RESP, uid, status);
  }

  public static void writeCarDpMgrStopUserReq(int uid, int userId) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_STOP_USER_REQ, uid, userId);
  }

  public static void writeCarDpMgrStopUserResp(int uid, int status) {
    android.util.EventLog.writeEvent(CAR_DP_MGR_STOP_USER_RESP, uid, status);
  }
}
