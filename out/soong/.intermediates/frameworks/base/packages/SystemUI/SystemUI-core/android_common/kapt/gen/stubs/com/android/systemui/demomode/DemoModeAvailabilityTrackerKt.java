package com.android.systemui.demomode;

import android.content.Context;
import android.database.ContentObserver;
import android.os.Handler;
import android.os.Looper;
import android.provider.Settings;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0010\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "DEMO_MODE_ALLOWED", "", "DEMO_MODE_ON", "TAG"})
public final class DemoModeAvailabilityTrackerKt {
    private static final java.lang.String TAG = "DemoModeAvailabilityTracker";
    private static final java.lang.String DEMO_MODE_ALLOWED = "sysui_demo_allowed";
    private static final java.lang.String DEMO_MODE_ON = "sysui_tuner_demo_on";
    private static final boolean DEBUG = false;
}