// This file is autogenerated

package com.android.server.scheduling;


import android.util.StatsEvent;
import android.util.StatsLog;


/**
 * Utility class for logging statistics events.
 */
public class SchedulingStatsLog {
    // Constants for atom codes.

    /**
     * UnattendedRebootOccurred unattended_reboot_occurred<br>
     * Usage: StatsLog.write(StatsLog.UNATTENDED_REBOOT_OCCURRED, long time_until_reboot_ready_millis, long time_until_first_unlock_millis, int times_blocked_by_interactivity, int times_blocked_by_subsystems, int times_blocked_by_app_activity, long time_until_next_interaction_ms);<br>
     */
    public static final int UNATTENDED_REBOOT_OCCURRED = 357;

    /**
     * LongRebootBlockingReported long_reboot_blocking_reported<br>
     * Usage: StatsLog.write(StatsLog.LONG_REBOOT_BLOCKING_REPORTED, int reboot_block_reason, java.lang.String component_name, int uid);<br>
     */
    public static final int LONG_REBOOT_BLOCKING_REPORTED = 358;

    // Constants for enum values.

    // Values for LongRebootBlockingReported.reboot_block_reason
    public static final int LONG_REBOOT_BLOCKING_REPORTED__REBOOT_BLOCK_REASON__SYSTEM_COMPONENT = 1;
    public static final int LONG_REBOOT_BLOCKING_REPORTED__REBOOT_BLOCK_REASON__APP_UID = 2;

    // Annotation constants.
    public static final byte ANNOTATION_ID_IS_UID = StatsLog.ANNOTATION_ID_IS_UID;
    public static final byte ANNOTATION_ID_TRUNCATE_TIMESTAMP = StatsLog.ANNOTATION_ID_TRUNCATE_TIMESTAMP;
    public static final byte ANNOTATION_ID_PRIMARY_FIELD = StatsLog.ANNOTATION_ID_PRIMARY_FIELD;
    public static final byte ANNOTATION_ID_EXCLUSIVE_STATE = StatsLog.ANNOTATION_ID_EXCLUSIVE_STATE;
    public static final byte ANNOTATION_ID_PRIMARY_FIELD_FIRST_UID = StatsLog.ANNOTATION_ID_PRIMARY_FIELD_FIRST_UID;
    public static final byte ANNOTATION_ID_TRIGGER_STATE_RESET = StatsLog.ANNOTATION_ID_TRIGGER_STATE_RESET;
    public static final byte ANNOTATION_ID_STATE_NESTED = StatsLog.ANNOTATION_ID_STATE_NESTED;

    // Write methods
    public static void write(int code, int arg1, java.lang.String arg2, int arg3) {
        final StatsEvent.Builder builder = StatsEvent.newBuilder();
        builder.setAtomId(code);
        builder.writeInt(arg1);
        builder.writeString(arg2);
        builder.writeInt(arg3);

        builder.usePooledBuffer();
        StatsLog.write(builder.build());
    }

    public static void write(int code, long arg1, long arg2, int arg3, int arg4, int arg5, long arg6) {
        final StatsEvent.Builder builder = StatsEvent.newBuilder();
        builder.setAtomId(code);
        builder.writeLong(arg1);
        builder.writeLong(arg2);
        builder.writeInt(arg3);
        builder.writeInt(arg4);
        builder.writeInt(arg5);
        builder.writeLong(arg6);

        builder.usePooledBuffer();
        StatsLog.write(builder.build());
    }

}
