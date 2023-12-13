/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: packages/providers/CalendarProvider/src/com/android/providers/calendar/EventLogTags.logtags
 */

package com.android.providers.calendar;;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 4000 calendar_upgrade_receiver (time|2|3) */
  public static final int CALENDAR_UPGRADE_RECEIVER = 4000;

  public static void writeCalendarUpgradeReceiver(long time) {
    android.util.EventLog.writeEvent(CALENDAR_UPGRADE_RECEIVER, time);
  }
}
