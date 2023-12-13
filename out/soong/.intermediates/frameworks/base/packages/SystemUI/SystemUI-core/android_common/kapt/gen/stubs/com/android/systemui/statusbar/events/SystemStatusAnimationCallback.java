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

/**
 * The general idea here is that this scheduler will run two value animators, and provide
 * animator-like callbacks for each kind of animation. The SystemChrome animation is expected to
 * create space for the chip animation to display. This means hiding the system elements in the
 * status bar and keyguard.
 *
 * TODO: the chip animation really only has one client, we can probably remove it from this
 * interface
 *
 * The value animators themselves are simple animators from 0.0 to 1.0. Listeners can apply any
 * interpolation they choose but realistically these are most likely to be simple alpha transitions
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\bf\u0018\u00002\u00020\u0001J\n\u0010\u0002\u001a\u0004\u0018\u00010\u0003H\u0017J\b\u0010\u0004\u001a\u00020\u0005H\u0017J\b\u0010\u0006\u001a\u00020\u0005H\u0017J\u0010\u0010\u0007\u001a\u00020\u00052\u0006\u0010\b\u001a\u00020\tH\u0017J\u0014\u0010\n\u001a\u0004\u0018\u00010\u00032\b\u0010\u000b\u001a\u0004\u0018\u00010\fH\u0017\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemStatusAnimationCallback;", "", "onHidePersistentDot", "Landroid/animation/Animator;", "onSystemChromeAnimationEnd", "", "onSystemChromeAnimationStart", "onSystemChromeAnimationUpdate", "animator", "Landroid/animation/ValueAnimator;", "onSystemStatusAnimationTransitionToPersistentDot", "contentDescription", ""})
public abstract interface SystemStatusAnimationCallback {
    
    public default void onSystemChromeAnimationUpdate(@org.jetbrains.annotations.NotNull()
    android.animation.ValueAnimator animator) {
    }
    
    public default void onSystemChromeAnimationStart() {
    }
    
    public default void onSystemChromeAnimationEnd() {
    }
    
    @org.jetbrains.annotations.Nullable()
    public default android.animation.Animator onSystemStatusAnimationTransitionToPersistentDot(@org.jetbrains.annotations.Nullable()
    java.lang.String contentDescription) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public default android.animation.Animator onHidePersistentDot() {
        return null;
    }
}