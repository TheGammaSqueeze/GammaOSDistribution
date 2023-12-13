/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: packages/services/Telephony/src/com/android/phone/EventLogTags.logtags
 */

package com.android.phone;;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 70301 phone_ui_enter */
  public static final int PHONE_UI_ENTER = 70301;

  /** 70302 phone_ui_exit */
  public static final int PHONE_UI_EXIT = 70302;

  /** 70303 phone_ui_button_click (text|3) */
  public static final int PHONE_UI_BUTTON_CLICK = 70303;

  /** 70304 phone_ui_ringer_query_elapsed */
  public static final int PHONE_UI_RINGER_QUERY_ELAPSED = 70304;

  /** 70305 phone_ui_multiple_query */
  public static final int PHONE_UI_MULTIPLE_QUERY = 70305;

  public static void writePhoneUiEnter() {
    android.util.EventLog.writeEvent(PHONE_UI_ENTER);
  }

  public static void writePhoneUiExit() {
    android.util.EventLog.writeEvent(PHONE_UI_EXIT);
  }

  public static void writePhoneUiButtonClick(String text) {
    android.util.EventLog.writeEvent(PHONE_UI_BUTTON_CLICK, text);
  }

  public static void writePhoneUiRingerQueryElapsed() {
    android.util.EventLog.writeEvent(PHONE_UI_RINGER_QUERY_ELAPSED);
  }

  public static void writePhoneUiMultipleQuery() {
    android.util.EventLog.writeEvent(PHONE_UI_MULTIPLE_QUERY);
  }
}
