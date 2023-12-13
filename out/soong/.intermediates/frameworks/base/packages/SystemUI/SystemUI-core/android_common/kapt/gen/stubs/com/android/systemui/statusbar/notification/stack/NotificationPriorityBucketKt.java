package com.android.systemui.statusbar.notification.stack;

import android.annotation.IntDef;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\n\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"BUCKET_ALERTING", "", "BUCKET_FOREGROUND_SERVICE", "BUCKET_HEADS_UP", "BUCKET_MEDIA_CONTROLS", "BUCKET_PEOPLE", "BUCKET_SILENT", "BUCKET_UNKNOWN"})
public final class NotificationPriorityBucketKt {
    public static final int BUCKET_UNKNOWN = 0;
    public static final int BUCKET_MEDIA_CONTROLS = 1;
    public static final int BUCKET_HEADS_UP = 2;
    public static final int BUCKET_FOREGROUND_SERVICE = 3;
    public static final int BUCKET_PEOPLE = 4;
    public static final int BUCKET_ALERTING = 5;
    public static final int BUCKET_SILENT = 6;
}