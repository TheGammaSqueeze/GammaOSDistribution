/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: frameworks/base/packages/SettingsProvider/src/com/android/providers/settings/EventLogTags.logtags
 */

package com.android.providers.settings;;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 52100 unsupported_settings_query (uri|3),(selection|3),(whereArgs|3) */
  public static final int UNSUPPORTED_SETTINGS_QUERY = 52100;

  /** 52101 persist_setting_error (message|3) */
  public static final int PERSIST_SETTING_ERROR = 52101;

  public static void writeUnsupportedSettingsQuery(String uri, String selection, String whereargs) {
    android.util.EventLog.writeEvent(UNSUPPORTED_SETTINGS_QUERY, uri, selection, whereargs);
  }

  public static void writePersistSettingError(String message) {
    android.util.EventLog.writeEvent(PERSIST_SETTING_ERROR, message);
  }
}
