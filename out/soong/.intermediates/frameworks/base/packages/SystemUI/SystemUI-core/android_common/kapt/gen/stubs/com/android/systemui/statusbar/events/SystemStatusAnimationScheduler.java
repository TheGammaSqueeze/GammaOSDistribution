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
 * Dead-simple scheduler for system status events. Obeys the following principles (all values TBD):
 *     - Avoiding log spam by only allowing 12 events per minute (1event/5s)
 *     - Waits 100ms to schedule any event for debouncing/prioritization
 *     - Simple prioritization: Privacy > Battery > connectivity (encoded in StatusEvent)
 *     - Only schedules a single event, and throws away lowest priority events
 *
 * There are 4 basic stages of animation at play here:
 *     1. System chrome animation OUT
 *     2. Chip animation IN
 *     3. Chip animation OUT; potentially into a dot
 *     4. System chrome animation IN
 *
 * Thus we can keep all animations synchronized with two separate ValueAnimators, one for system
 * chrome and the other for the chip. These can animate from 0,1 and listeners can parameterize
 * their respective views based on the progress of the animator. Interpolation differences TBD
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0096\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010#\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u000b\b\u0007\u0018\u0000 E2\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0002DEB9\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\b\b\u0001\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\u0002\u0010\u0010J\u0010\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020\u0002H\u0016J\b\u0010*\u001a\u00020(H\u0002J-\u0010+\u001a\u00020(2\u0006\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020/2\u000e\u00100\u001a\n\u0012\u0006\b\u0001\u0012\u00020201H\u0016\u00a2\u0006\u0002\u00103J\b\u00104\u001a\u00020\u001cH\u0002J\b\u00105\u001a\u00020\u001cH\u0002J\n\u00106\u001a\u0004\u0018\u000107H\u0002J\u0010\u00108\u001a\u00020(2\u0006\u00109\u001a\u00020:H\u0002J\b\u0010;\u001a\u00020(H\u0002J\b\u0010<\u001a\u00020(H\u0002J\n\u0010=\u001a\u0004\u0018\u000107H\u0002J\u000e\u0010>\u001a\u00020(2\u0006\u0010?\u001a\u00020#J\u0010\u0010@\u001a\u00020(2\u0006\u0010)\u001a\u00020\u0002H\u0016J\u0010\u0010A\u001a\u00020(2\u0006\u0010?\u001a\u00020#H\u0002J\u000e\u0010B\u001a\u00020(2\u0006\u0010C\u001a\u00020\u001cR$\u0010\u0013\u001a\u00020\u00122\u0006\u0010\u0011\u001a\u00020\u0012@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0014\u0010\u0015\u001a\u0004\b\u0016\u0010\u0017R\u0010\u0010\u0018\u001a\u0004\u0018\u00010\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u001d\u001a\u00020\u001c2\u0006\u0010\u0011\u001a\u00020\u001c@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001e\u0010\u001fR\u0014\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00020!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\"\u001a\u0004\u0018\u00010#X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010$\u001a\u00020%X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010&\u001a\u00020\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/statusbar/events/SystemStatusAnimationCallback;", "Lcom/android/systemui/Dumpable;", "coordinator", "Lcom/android/systemui/statusbar/events/SystemEventCoordinator;", "chipAnimationController", "Lcom/android/systemui/statusbar/events/SystemEventChipAnimationController;", "statusBarWindowController", "Lcom/android/systemui/statusbar/window/StatusBarWindowController;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "(Lcom/android/systemui/statusbar/events/SystemEventCoordinator;Lcom/android/systemui/statusbar/events/SystemEventChipAnimationController;Lcom/android/systemui/statusbar/window/StatusBarWindowController;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/util/concurrency/DelayableExecutor;)V", "<set-?>", "", "animationState", "getAnimationState$annotations", "()V", "getAnimationState", "()I", "cancelExecutionRunnable", "Ljava/lang/Runnable;", "chipUpdateListener", "Landroid/animation/ValueAnimator$AnimatorUpdateListener;", "", "hasPersistentDot", "getHasPersistentDot", "()Z", "listeners", "", "scheduledEvent", "Lcom/android/systemui/statusbar/events/StatusEvent;", "systemAnimatorAdapter", "Landroid/animation/AnimatorListenerAdapter;", "systemUpdateListener", "addCallback", "", "listener", "clearDotIfVisible", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "isImmersiveIndicatorEnabled", "isTooEarly", "notifyHidePersistentDot", "Landroid/animation/Animator;", "notifySystemAnimationUpdate", "anim", "Landroid/animation/ValueAnimator;", "notifySystemFinish", "notifySystemStart", "notifyTransitionToPersistentDot", "onStatusEvent", "event", "removeCallback", "scheduleEvent", "setShouldShowPersistentPrivacyIndicator", "should", "ChipAnimatorAdapter", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class SystemStatusAnimationScheduler implements com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.statusbar.events.SystemStatusAnimationCallback>, com.android.systemui.Dumpable {
    private int animationState = 0;
    
    /**
     * True if the persistent privacy dot should be active
     */
    private boolean hasPersistentDot = false;
    private com.android.systemui.statusbar.events.StatusEvent scheduledEvent;
    private java.lang.Runnable cancelExecutionRunnable;
    private final java.util.Set<com.android.systemui.statusbar.events.SystemStatusAnimationCallback> listeners = null;
    private final android.animation.ValueAnimator.AnimatorUpdateListener systemUpdateListener = null;
    private final android.animation.AnimatorListenerAdapter systemAnimatorAdapter = null;
    private final android.animation.ValueAnimator.AnimatorUpdateListener chipUpdateListener = null;
    private final com.android.systemui.statusbar.events.SystemEventCoordinator coordinator = null;
    private final com.android.systemui.statusbar.events.SystemEventChipAnimationController chipAnimationController = null;
    private final com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor executor = null;
    private static final java.lang.String PROPERTY_ENABLE_IMMERSIVE_INDICATOR = "enable_immersive_indicator";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.events.SystemStatusAnimationScheduler.Companion Companion = null;
    
    private final boolean isImmersiveIndicatorEnabled() {
        return false;
    }
    
    @SystemAnimationState()
    @java.lang.Deprecated()
    public static void getAnimationState$annotations() {
    }
    
    public final int getAnimationState() {
        return 0;
    }
    
    public final boolean getHasPersistentDot() {
        return false;
    }
    
    public final void onStatusEvent(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.StatusEvent event) {
    }
    
    private final void clearDotIfVisible() {
    }
    
    public final void setShouldShowPersistentPrivacyIndicator(boolean should) {
    }
    
    private final boolean isTooEarly() {
        return false;
    }
    
    /**
     * Clear the scheduled event (if any) and schedule a new one
     */
    private final void scheduleEvent(com.android.systemui.statusbar.events.StatusEvent event) {
    }
    
    private final android.animation.Animator notifyTransitionToPersistentDot() {
        return null;
    }
    
    private final android.animation.Animator notifyHidePersistentDot() {
        return null;
    }
    
    private final void notifySystemStart() {
    }
    
    private final void notifySystemFinish() {
    }
    
    private final void notifySystemAnimationUpdate(android.animation.ValueAnimator anim) {
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemStatusAnimationCallback listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemStatusAnimationCallback listener) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public SystemStatusAnimationScheduler(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemEventCoordinator coordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.events.SystemEventChipAnimationController chipAnimationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.window.StatusBarWindowController statusBarWindowController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor executor) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0086\u0004\u0018\u00002\u00020\u0001B0\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012!\u0010\u0004\u001a\u001d\u0012\u0013\u0012\u00110\u0006\u00a2\u0006\f\b\u0007\u0012\b\b\b\u0012\u0004\b\b(\t\u0012\u0004\u0012\u00020\n0\u0005\u00a2\u0006\u0002\u0010\u000bJ\u0012\u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013H\u0016J\u0012\u0010\u0014\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013H\u0016R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR,\u0010\u0004\u001a\u001d\u0012\u0013\u0012\u00110\u0006\u00a2\u0006\f\b\u0007\u0012\b\b\b\u0012\u0004\b\b(\t\u0012\u0004\u0012\u00020\n0\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler$ChipAnimatorAdapter;", "Landroid/animation/AnimatorListenerAdapter;", "endState", "", "viewCreator", "Lkotlin/Function1;", "Landroid/content/Context;", "Lkotlin/ParameterName;", "name", "context", "Landroid/view/View;", "(Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler;ILkotlin/jvm/functions/Function1;)V", "getEndState", "()I", "getViewCreator", "()Lkotlin/jvm/functions/Function1;", "onAnimationEnd", "", "p0", "Landroid/animation/Animator;", "onAnimationStart"})
    public final class ChipAnimatorAdapter extends android.animation.AnimatorListenerAdapter {
        private final int endState = 0;
        @org.jetbrains.annotations.NotNull()
        private final kotlin.jvm.functions.Function1<android.content.Context, android.view.View> viewCreator = null;
        
        @java.lang.Override()
        public void onAnimationEnd(@org.jetbrains.annotations.Nullable()
        android.animation.Animator p0) {
        }
        
        @java.lang.Override()
        public void onAnimationStart(@org.jetbrains.annotations.Nullable()
        android.animation.Animator p0) {
        }
        
        public final int getEndState() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final kotlin.jvm.functions.Function1<android.content.Context, android.view.View> getViewCreator() {
            return null;
        }
        
        public ChipAnimatorAdapter(@SystemAnimationState()
        int endState, @org.jetbrains.annotations.NotNull()
        kotlin.jvm.functions.Function1<? super android.content.Context, ? extends android.view.View> viewCreator) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/events/SystemStatusAnimationScheduler$Companion;", "", "()V", "PROPERTY_ENABLE_IMMERSIVE_INDICATOR", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}