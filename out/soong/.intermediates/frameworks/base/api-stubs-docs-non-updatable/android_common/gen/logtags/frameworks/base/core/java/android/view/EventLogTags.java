/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: frameworks/base/core/java/android/view/EventLogTags.logtags
 */

package android.view;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 62002 view_enqueue_input_event (eventType|3),(action|3) */
  public static final int VIEW_ENQUEUE_INPUT_EVENT = 62002;

  public static void writeViewEnqueueInputEvent(String eventtype, String action) {
    android.util.EventLog.writeEvent(VIEW_ENQUEUE_INPUT_EVENT, eventtype, action);
  }
}
