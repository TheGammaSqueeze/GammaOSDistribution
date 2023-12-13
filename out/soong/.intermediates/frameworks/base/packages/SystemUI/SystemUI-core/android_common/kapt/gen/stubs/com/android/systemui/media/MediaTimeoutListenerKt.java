package com.android.systemui.media;

import android.media.session.MediaController;
import android.media.session.PlaybackState;
import android.os.SystemProperties;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.util.concurrent.TimeUnit;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0002\b\b\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u001c\u0010\u0002\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0004\u0010\u0005\u001a\u0004\b\u0006\u0010\u0007\"\u001c\u0010\b\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\t\u0010\u0005\u001a\u0004\b\n\u0010\u0007\"\u000e\u0010\u000b\u001a\u00020\fX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "PAUSED_MEDIA_TIMEOUT", "", "getPAUSED_MEDIA_TIMEOUT$annotations", "()V", "getPAUSED_MEDIA_TIMEOUT", "()J", "RESUME_MEDIA_TIMEOUT", "getRESUME_MEDIA_TIMEOUT$annotations", "getRESUME_MEDIA_TIMEOUT", "TAG", ""})
public final class MediaTimeoutListenerKt {
    private static final boolean DEBUG = true;
    private static final java.lang.String TAG = "MediaTimeout";
    private static final long PAUSED_MEDIA_TIMEOUT = 0L;
    private static final long RESUME_MEDIA_TIMEOUT = 0L;
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getPAUSED_MEDIA_TIMEOUT$annotations() {
    }
    
    public static final long getPAUSED_MEDIA_TIMEOUT() {
        return 0L;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getRESUME_MEDIA_TIMEOUT$annotations() {
    }
    
    public static final long getRESUME_MEDIA_TIMEOUT() {
        return 0L;
    }
}