/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: frameworks/ex/common/java/com/android/common/GoogleLogTags.logtags
 */

package com.android.common;

/**
 * @hide
 */
public class GoogleLogTags {
  private GoogleLogTags() { }  // don't instantiate

  /** 201001 system_update (status|1|5),(download_result|1|5),(bytes|2|2),(url|3) */
  public static final int SYSTEM_UPDATE = 201001;

  /** 201002 system_update_user (action|3) */
  public static final int SYSTEM_UPDATE_USER = 201002;

  /** 202001 vending_reconstruct (changes|1) */
  public static final int VENDING_RECONSTRUCT = 202001;

  /** 202901 transaction_event (data|3) */
  public static final int TRANSACTION_EVENT = 202901;

  /** 203001 sync_details (authority|3),(send|1|2),(recv|1|2),(details|3) */
  public static final int SYNC_DETAILS = 203001;

  /** 203002 google_http_request (elapsed|2|3),(status|1),(appname|3),(reused|1) */
  public static final int GOOGLE_HTTP_REQUEST = 203002;

  /** 204001 gtalkservice (eventType|1) */
  public static final int GTALKSERVICE = 204001;

  /** 204002 gtalk_connection (status|1) */
  public static final int GTALK_CONNECTION = 204002;

  /** 204003 gtalk_conn_close (status|1),(duration|1) */
  public static final int GTALK_CONN_CLOSE = 204003;

  /** 204004 gtalk_heartbeat_reset (interval_and_nt|1),(ip|3) */
  public static final int GTALK_HEARTBEAT_RESET = 204004;

  /** 204005 c2dm (packet_type|1),(persistent_id|3),(stream_id|1),(last_stream_id|1) */
  public static final int C2DM = 204005;

  /** 205001 setup_server_timeout */
  public static final int SETUP_SERVER_TIMEOUT = 205001;

  /** 205002 setup_required_captcha (action|3) */
  public static final int SETUP_REQUIRED_CAPTCHA = 205002;

  /** 205003 setup_io_error (status|3) */
  public static final int SETUP_IO_ERROR = 205003;

  /** 205004 setup_server_error */
  public static final int SETUP_SERVER_ERROR = 205004;

  /** 205005 setup_retries_exhausted */
  public static final int SETUP_RETRIES_EXHAUSTED = 205005;

  /** 205006 setup_no_data_network */
  public static final int SETUP_NO_DATA_NETWORK = 205006;

  /** 205007 setup_completed */
  public static final int SETUP_COMPLETED = 205007;

  /** 205008 gls_account_tried (status|1) */
  public static final int GLS_ACCOUNT_TRIED = 205008;

  /** 205009 gls_account_saved (status|1) */
  public static final int GLS_ACCOUNT_SAVED = 205009;

  /** 205010 gls_authenticate (status|1),(service|3) */
  public static final int GLS_AUTHENTICATE = 205010;

  /** 205011 google_mail_switch (direction|1) */
  public static final int GOOGLE_MAIL_SWITCH = 205011;

  /** 206001 snet (payload|3) */
  public static final int SNET = 206001;

  /** 206003 exp_det_snet (payload|3) */
  public static final int EXP_DET_SNET = 206003;

  /** 208000 metrics_heartbeat */
  public static final int METRICS_HEARTBEAT = 208000;

  public static void writeSystemUpdate(int status, int downloadResult, long bytes, String url) {
    android.util.EventLog.writeEvent(SYSTEM_UPDATE, status, downloadResult, bytes, url);
  }

  public static void writeSystemUpdateUser(String action) {
    android.util.EventLog.writeEvent(SYSTEM_UPDATE_USER, action);
  }

  public static void writeVendingReconstruct(int changes) {
    android.util.EventLog.writeEvent(VENDING_RECONSTRUCT, changes);
  }

  public static void writeTransactionEvent(String data) {
    android.util.EventLog.writeEvent(TRANSACTION_EVENT, data);
  }

  public static void writeSyncDetails(String authority, int send, int recv, String details) {
    android.util.EventLog.writeEvent(SYNC_DETAILS, authority, send, recv, details);
  }

  public static void writeGoogleHttpRequest(long elapsed, int status, String appname, int reused) {
    android.util.EventLog.writeEvent(GOOGLE_HTTP_REQUEST, elapsed, status, appname, reused);
  }

  public static void writeGtalkservice(int eventtype) {
    android.util.EventLog.writeEvent(GTALKSERVICE, eventtype);
  }

  public static void writeGtalkConnection(int status) {
    android.util.EventLog.writeEvent(GTALK_CONNECTION, status);
  }

  public static void writeGtalkConnClose(int status, int duration) {
    android.util.EventLog.writeEvent(GTALK_CONN_CLOSE, status, duration);
  }

  public static void writeGtalkHeartbeatReset(int intervalAndNt, String ip) {
    android.util.EventLog.writeEvent(GTALK_HEARTBEAT_RESET, intervalAndNt, ip);
  }

  public static void writeC2Dm(int packetType, String persistentId, int streamId, int lastStreamId) {
    android.util.EventLog.writeEvent(C2DM, packetType, persistentId, streamId, lastStreamId);
  }

  public static void writeSetupServerTimeout() {
    android.util.EventLog.writeEvent(SETUP_SERVER_TIMEOUT);
  }

  public static void writeSetupRequiredCaptcha(String action) {
    android.util.EventLog.writeEvent(SETUP_REQUIRED_CAPTCHA, action);
  }

  public static void writeSetupIoError(String status) {
    android.util.EventLog.writeEvent(SETUP_IO_ERROR, status);
  }

  public static void writeSetupServerError() {
    android.util.EventLog.writeEvent(SETUP_SERVER_ERROR);
  }

  public static void writeSetupRetriesExhausted() {
    android.util.EventLog.writeEvent(SETUP_RETRIES_EXHAUSTED);
  }

  public static void writeSetupNoDataNetwork() {
    android.util.EventLog.writeEvent(SETUP_NO_DATA_NETWORK);
  }

  public static void writeSetupCompleted() {
    android.util.EventLog.writeEvent(SETUP_COMPLETED);
  }

  public static void writeGlsAccountTried(int status) {
    android.util.EventLog.writeEvent(GLS_ACCOUNT_TRIED, status);
  }

  public static void writeGlsAccountSaved(int status) {
    android.util.EventLog.writeEvent(GLS_ACCOUNT_SAVED, status);
  }

  public static void writeGlsAuthenticate(int status, String service) {
    android.util.EventLog.writeEvent(GLS_AUTHENTICATE, status, service);
  }

  public static void writeGoogleMailSwitch(int direction) {
    android.util.EventLog.writeEvent(GOOGLE_MAIL_SWITCH, direction);
  }

  public static void writeSnet(String payload) {
    android.util.EventLog.writeEvent(SNET, payload);
  }

  public static void writeExpDetSnet(String payload) {
    android.util.EventLog.writeEvent(EXP_DET_SNET, payload);
  }

  public static void writeMetricsHeartbeat() {
    android.util.EventLog.writeEvent(METRICS_HEARTBEAT);
  }
}
