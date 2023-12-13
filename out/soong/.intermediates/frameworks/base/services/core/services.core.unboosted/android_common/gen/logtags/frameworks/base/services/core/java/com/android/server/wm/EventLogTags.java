/* This file is auto-generated.  DO NOT MODIFY.
 * Source file: frameworks/base/services/core/java/com/android/server/wm/EventLogTags.logtags
 */

package com.android.server.wm;

/**
 * @hide
 */
public class EventLogTags {
  private EventLogTags() { }  // don't instantiate

  /** 30001 wm_finish_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3),(Reason|3) */
  public static final int WM_FINISH_ACTIVITY = 30001;

  /** 30002 wm_task_to_front (User|1|5),(Task|1|5) */
  public static final int WM_TASK_TO_FRONT = 30002;

  /** 30003 wm_new_intent (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3),(Action|3),(MIME Type|3),(URI|3),(Flags|1|5) */
  public static final int WM_NEW_INTENT = 30003;

  /** 30004 wm_create_task (User|1|5),(Task ID|1|5) */
  public static final int WM_CREATE_TASK = 30004;

  /** 30005 wm_create_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3),(Action|3),(MIME Type|3),(URI|3),(Flags|1|5) */
  public static final int WM_CREATE_ACTIVITY = 30005;

  /** 30006 wm_restart_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3) */
  public static final int WM_RESTART_ACTIVITY = 30006;

  /** 30007 wm_resume_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3) */
  public static final int WM_RESUME_ACTIVITY = 30007;

  /** 30009 wm_activity_launch_time (User|1|5),(Token|1|5),(Component Name|3),(time|2|3) */
  public static final int WM_ACTIVITY_LAUNCH_TIME = 30009;

  /** 30012 wm_failed_to_pause (User|1|5),(Token|1|5),(Wanting to pause|3),(Currently pausing|3) */
  public static final int WM_FAILED_TO_PAUSE = 30012;

  /** 30013 wm_pause_activity (User|1|5),(Token|1|5),(Component Name|3),(User Leaving|3),(Reason|3) */
  public static final int WM_PAUSE_ACTIVITY = 30013;

  /** 30018 wm_destroy_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3),(Reason|3) */
  public static final int WM_DESTROY_ACTIVITY = 30018;

  /** 30019 wm_relaunch_resume_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3) */
  public static final int WM_RELAUNCH_RESUME_ACTIVITY = 30019;

  /** 30020 wm_relaunch_activity (User|1|5),(Token|1|5),(Task ID|1|5),(Component Name|3) */
  public static final int WM_RELAUNCH_ACTIVITY = 30020;

  /** 30043 wm_set_resumed_activity (User|1|5),(Component Name|3),(Reason|3) */
  public static final int WM_SET_RESUMED_ACTIVITY = 30043;

  /** 30044 wm_focused_root_task (User|1|5),(Display Id|1|5),(Focused Root Task Id|1|5),(Last Focused Root Task Id|1|5),(Reason|3) */
  public static final int WM_FOCUSED_ROOT_TASK = 30044;

  /** 30048 wm_stop_activity (User|1|5),(Token|1|5),(Component Name|3) */
  public static final int WM_STOP_ACTIVITY = 30048;

  /** 30061 wm_remove_task (Task ID|1|5), (Root Task ID|1|5) */
  public static final int WM_REMOVE_TASK = 30061;

  /** 30066 wm_add_to_stopping (User|1|5),(Token|1|5),(Component Name|3),(Reason|3) */
  public static final int WM_ADD_TO_STOPPING = 30066;

  /** 30067 wm_set_keyguard_shown (keyguardShowing|1),(aodShowing|1),(keyguardGoingAway|1),(Reason|3) */
  public static final int WM_SET_KEYGUARD_SHOWN = 30067;

  /** 31000 wm_no_surface_memory (Window|3),(PID|1|5),(Operation|3) */
  public static final int WM_NO_SURFACE_MEMORY = 31000;

  /** 31001 wm_task_created (TaskId|1|5),(RootTaskId|1|5) */
  public static final int WM_TASK_CREATED = 31001;

  /** 31002 wm_task_moved (TaskId|1|5),(ToTop|1),(Index|1) */
  public static final int WM_TASK_MOVED = 31002;

  /** 31003 wm_task_removed (TaskId|1|5),(Reason|3) */
  public static final int WM_TASK_REMOVED = 31003;

  /** 31007 wm_boot_animation_done (time|2|3) */
  public static final int WM_BOOT_ANIMATION_DONE = 31007;

  public static void writeWmFinishActivity(int user, int token, int taskId, String componentName, String reason) {
    android.util.EventLog.writeEvent(WM_FINISH_ACTIVITY, user, token, taskId, componentName, reason);
  }

  public static void writeWmTaskToFront(int user, int task) {
    android.util.EventLog.writeEvent(WM_TASK_TO_FRONT, user, task);
  }

  public static void writeWmNewIntent(int user, int token, int taskId, String componentName, String action, String mimeType, String uri, int flags) {
    android.util.EventLog.writeEvent(WM_NEW_INTENT, user, token, taskId, componentName, action, mimeType, uri, flags);
  }

  public static void writeWmCreateTask(int user, int taskId) {
    android.util.EventLog.writeEvent(WM_CREATE_TASK, user, taskId);
  }

  public static void writeWmCreateActivity(int user, int token, int taskId, String componentName, String action, String mimeType, String uri, int flags) {
    android.util.EventLog.writeEvent(WM_CREATE_ACTIVITY, user, token, taskId, componentName, action, mimeType, uri, flags);
  }

  public static void writeWmRestartActivity(int user, int token, int taskId, String componentName) {
    android.util.EventLog.writeEvent(WM_RESTART_ACTIVITY, user, token, taskId, componentName);
  }

  public static void writeWmResumeActivity(int user, int token, int taskId, String componentName) {
    android.util.EventLog.writeEvent(WM_RESUME_ACTIVITY, user, token, taskId, componentName);
  }

  public static void writeWmActivityLaunchTime(int user, int token, String componentName, long time) {
    android.util.EventLog.writeEvent(WM_ACTIVITY_LAUNCH_TIME, user, token, componentName, time);
  }

  public static void writeWmFailedToPause(int user, int token, String wantingToPause, String currentlyPausing) {
    android.util.EventLog.writeEvent(WM_FAILED_TO_PAUSE, user, token, wantingToPause, currentlyPausing);
  }

  public static void writeWmPauseActivity(int user, int token, String componentName, String userLeaving, String reason) {
    android.util.EventLog.writeEvent(WM_PAUSE_ACTIVITY, user, token, componentName, userLeaving, reason);
  }

  public static void writeWmDestroyActivity(int user, int token, int taskId, String componentName, String reason) {
    android.util.EventLog.writeEvent(WM_DESTROY_ACTIVITY, user, token, taskId, componentName, reason);
  }

  public static void writeWmRelaunchResumeActivity(int user, int token, int taskId, String componentName) {
    android.util.EventLog.writeEvent(WM_RELAUNCH_RESUME_ACTIVITY, user, token, taskId, componentName);
  }

  public static void writeWmRelaunchActivity(int user, int token, int taskId, String componentName) {
    android.util.EventLog.writeEvent(WM_RELAUNCH_ACTIVITY, user, token, taskId, componentName);
  }

  public static void writeWmSetResumedActivity(int user, String componentName, String reason) {
    android.util.EventLog.writeEvent(WM_SET_RESUMED_ACTIVITY, user, componentName, reason);
  }

  public static void writeWmFocusedRootTask(int user, int displayId, int focusedRootTaskId, int lastFocusedRootTaskId, String reason) {
    android.util.EventLog.writeEvent(WM_FOCUSED_ROOT_TASK, user, displayId, focusedRootTaskId, lastFocusedRootTaskId, reason);
  }

  public static void writeWmStopActivity(int user, int token, String componentName) {
    android.util.EventLog.writeEvent(WM_STOP_ACTIVITY, user, token, componentName);
  }

  public static void writeWmRemoveTask(int taskId, int rootTaskId) {
    android.util.EventLog.writeEvent(WM_REMOVE_TASK, taskId, rootTaskId);
  }

  public static void writeWmAddToStopping(int user, int token, String componentName, String reason) {
    android.util.EventLog.writeEvent(WM_ADD_TO_STOPPING, user, token, componentName, reason);
  }

  public static void writeWmSetKeyguardShown(int keyguardshowing, int aodshowing, int keyguardgoingaway, String reason) {
    android.util.EventLog.writeEvent(WM_SET_KEYGUARD_SHOWN, keyguardshowing, aodshowing, keyguardgoingaway, reason);
  }

  public static void writeWmNoSurfaceMemory(String window, int pid, String operation) {
    android.util.EventLog.writeEvent(WM_NO_SURFACE_MEMORY, window, pid, operation);
  }

  public static void writeWmTaskCreated(int taskid, int roottaskid) {
    android.util.EventLog.writeEvent(WM_TASK_CREATED, taskid, roottaskid);
  }

  public static void writeWmTaskMoved(int taskid, int totop, int index) {
    android.util.EventLog.writeEvent(WM_TASK_MOVED, taskid, totop, index);
  }

  public static void writeWmTaskRemoved(int taskid, String reason) {
    android.util.EventLog.writeEvent(WM_TASK_REMOVED, taskid, reason);
  }

  public static void writeWmBootAnimationDone(long time) {
    android.util.EventLog.writeEvent(WM_BOOT_ANIMATION_DONE, time);
  }
}
