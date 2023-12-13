package com.android.systemui.statusbar.events;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ValueAnimator;
import android.annotation.IntDef;
import android.content.Context;
import android.os.Process;
import android.provider.DeviceConfig;
import android.util.Log;
import android.view.View;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.CallbackController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.util.Assert;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001c\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\t\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\n\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\f\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\r\u001a\u00020\u0001X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u000e\u001a\u00020\u000fX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"ANIMATING_IN", "", "ANIMATING_OUT", "CHIP_ANIM_LENGTH", "", "DEBUG", "", "DELAY", "DISPLAY_LENGTH", "ENTRANCE_ANIM_LENGTH", "IDLE", "MIN_UPTIME", "RUNNING_CHIP_ANIM", "SHOWING_PERSISTENT_DOT", "TAG", ""})
public final class SystemStatusAnimationSchedulerKt {
    
    /**
     * No animation is in progress
     */
    public static final int IDLE = 0;
    
    /**
     * System is animating out, and chip is animating in
     */
    public static final int ANIMATING_IN = 1;
    
    /**
     * Chip has animated in and is awaiting exit animation, and optionally playing its own animation
     */
    public static final int RUNNING_CHIP_ANIM = 2;
    
    /**
     * Chip is animating away and system is animating back
     */
    public static final int ANIMATING_OUT = 3;
    
    /**
     * Chip has animated away, and the persistent dot is showing
     */
    public static final int SHOWING_PERSISTENT_DOT = 4;
    private static final java.lang.String TAG = "SystemStatusAnimationScheduler";
    private static final long DELAY = 0L;
    
    /**
     * The total time spent animation should be 1500ms. The entrance animation is how much time
     * we give to the system to animate system elements out of the way. Total chip animation length
     * will be equivalent to 2*chip_anim_length + display_length
     */
    private static final long ENTRANCE_ANIM_LENGTH = 250L;
    private static final long CHIP_ANIM_LENGTH = 250L;
    private static final long DISPLAY_LENGTH = 1500L;
    private static final long MIN_UPTIME = 5000L;
    private static final boolean DEBUG = false;
}