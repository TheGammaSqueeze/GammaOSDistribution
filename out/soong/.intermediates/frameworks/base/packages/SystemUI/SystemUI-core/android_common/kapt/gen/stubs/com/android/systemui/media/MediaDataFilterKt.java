package com.android.systemui.media;

import android.content.Context;
import android.os.SystemProperties;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.settings.CurrentUserTracker;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.util.time.SystemClock;
import java.util.SortedMap;
import java.util.concurrent.Executor;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;
import kotlin.collections.LinkedHashMap;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0018\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0005\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u001c\u0010\u0005\u001a\u00020\u00068\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0007\u0010\b\u001a\u0004\b\t\u0010\n\"\u000e\u0010\u000b\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "EXPORTED_SMARTSPACE_TRAMPOLINE_ACTIVITY_NAME", "", "RESUMABLE_MEDIA_MAX_AGE_SECONDS_KEY", "SMARTSPACE_MAX_AGE", "", "getSMARTSPACE_MAX_AGE$annotations", "()V", "getSMARTSPACE_MAX_AGE", "()J", "TAG"})
public final class MediaDataFilterKt {
    private static final java.lang.String TAG = "MediaDataFilter";
    private static final boolean DEBUG = true;
    private static final java.lang.String EXPORTED_SMARTSPACE_TRAMPOLINE_ACTIVITY_NAME = "com.google.android.apps.gsa.staticplugins.opa.smartspace.ExportedSmartspaceTrampolineActivity";
    private static final java.lang.String RESUMABLE_MEDIA_MAX_AGE_SECONDS_KEY = "resumable_media_max_age_seconds";
    
    /**
     * Maximum age of a media control to re-activate on smartspace signal. If there is no media control
     * available within this time window, smartspace recommendations will be shown instead.
     */
    private static final long SMARTSPACE_MAX_AGE = 0L;
    
    /**
     * Maximum age of a media control to re-activate on smartspace signal. If there is no media control
     * available within this time window, smartspace recommendations will be shown instead.
     */
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSMARTSPACE_MAX_AGE$annotations() {
    }
    
    public static final long getSMARTSPACE_MAX_AGE() {
        return 0L;
    }
}