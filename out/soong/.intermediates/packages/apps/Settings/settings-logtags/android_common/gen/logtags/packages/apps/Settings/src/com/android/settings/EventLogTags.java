/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: packages/apps/Settings/src/com/android/settings/EventLogTags.logtags
 */

package com.android.settings;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 90200 lock_screen_type (type|3) */
  public static final int LOCK_SCREEN_TYPE = 90200;

  /** 90201 exp_det_device_admin_activated_by_user (app_signature|3) */
  public static final int EXP_DET_DEVICE_ADMIN_ACTIVATED_BY_USER = 90201;

  /** 90202 exp_det_device_admin_declined_by_user (app_signature|3) */
  public static final int EXP_DET_DEVICE_ADMIN_DECLINED_BY_USER = 90202;

  /** 90203 exp_det_device_admin_uninstalled_by_user (app_signature|3) */
  public static final int EXP_DET_DEVICE_ADMIN_UNINSTALLED_BY_USER = 90203;

  /** 90204 settings_latency (action|1|6),(latency|1|3) */
  public static final int SETTINGS_LATENCY = 90204;

  public static void writeLockScreenType(String type) {
    android.util.EventLog.writeEvent(LOCK_SCREEN_TYPE, type);
  }

  public static void writeExpDetDeviceAdminActivatedByUser(String appSignature) {
    android.util.EventLog.writeEvent(EXP_DET_DEVICE_ADMIN_ACTIVATED_BY_USER, appSignature);
  }

  public static void writeExpDetDeviceAdminDeclinedByUser(String appSignature) {
    android.util.EventLog.writeEvent(EXP_DET_DEVICE_ADMIN_DECLINED_BY_USER, appSignature);
  }

  public static void writeExpDetDeviceAdminUninstalledByUser(String appSignature) {
    android.util.EventLog.writeEvent(EXP_DET_DEVICE_ADMIN_UNINSTALLED_BY_USER, appSignature);
  }

  public static void writeSettingsLatency(int action, int latency) {
    android.util.EventLog.writeEvent(SETTINGS_LATENCY, action, latency);
  }
}
