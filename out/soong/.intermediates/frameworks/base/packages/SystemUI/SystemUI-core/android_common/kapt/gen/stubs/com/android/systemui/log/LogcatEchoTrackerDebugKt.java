package com.android.systemui.log;

import android.content.ContentResolver;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"BUFFER_PATH", "", "DEFAULT_LEVEL", "Lcom/android/systemui/log/LogLevel;", "TAG_PATH"})
public final class LogcatEchoTrackerDebugKt {
    private static final com.android.systemui.log.LogLevel DEFAULT_LEVEL = com.android.systemui.log.LogLevel.WARNING;
    private static final java.lang.String BUFFER_PATH = "systemui/buffer";
    private static final java.lang.String TAG_PATH = "systemui/tag";
}