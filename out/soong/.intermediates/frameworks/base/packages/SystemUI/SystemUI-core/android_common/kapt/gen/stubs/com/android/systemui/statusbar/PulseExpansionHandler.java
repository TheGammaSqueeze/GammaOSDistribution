package com.android.systemui.statusbar;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ObjectAnimator;
import android.content.Context;
import android.content.res.Configuration;
import android.os.PowerManager;
import android.os.SystemClock;
import android.util.IndentingPrintWriter;
import android.view.MotionEvent;
import android.view.VelocityTracker;
import android.view.ViewConfiguration;
import com.android.systemui.Dumpable;
import com.android.systemui.Gefingerpoken;
import com.android.systemui.R;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.ExpandableView;
import com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * A utility class to enable the downward swipe on when pulsing.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00bc\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\r\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\r\b\u0007\u0018\u0000 c2\u00020\u00012\u00020\u0002:\u0001cB_\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u0012\u0006\u0010\u0017\u001a\u00020\u0018\u00a2\u0006\u0002\u0010\u0019J\b\u0010B\u001a\u00020\u001bH\u0002J\b\u0010C\u001a\u00020DH\u0002J\u0018\u0010E\u001a\u00020D2\u0006\u0010F\u001a\u00020)2\u0006\u0010G\u001a\u00020)H\u0002J-\u0010H\u001a\u00020D2\u0006\u0010I\u001a\u00020J2\u0006\u0010K\u001a\u00020L2\u000e\u0010M\u001a\n\u0012\u0006\b\u0001\u0012\u00020O0NH\u0016\u00a2\u0006\u0002\u0010PJ\u001a\u0010Q\u001a\u0004\u0018\u00010/2\u0006\u0010F\u001a\u00020)2\u0006\u0010G\u001a\u00020)H\u0002J\b\u0010R\u001a\u00020DH\u0002J\u0010\u0010S\u001a\u00020D2\u0006\u0010\u0003\u001a\u00020\u0004H\u0002J\u0010\u0010T\u001a\u00020\u001b2\u0006\u0010U\u001a\u00020VH\u0016J\u0010\u0010W\u001a\u00020\u001b2\u0006\u0010U\u001a\u00020VH\u0016J\b\u0010X\u001a\u00020DH\u0002J\u0010\u0010Y\u001a\u00020D2\u0006\u0010Z\u001a\u00020/H\u0002J\u000e\u0010[\u001a\u00020D2\u0006\u0010\\\u001a\u00020\u001bJ\u000e\u0010]\u001a\u00020D2\u0006\u0010=\u001a\u00020>J\u0018\u0010^\u001a\u00020D2\u0006\u0010Z\u001a\u00020/2\u0006\u0010_\u001a\u00020\u001bH\u0002J\u0010\u0010`\u001a\u00020\u001b2\u0006\u0010U\u001a\u00020VH\u0002J\u0010\u0010a\u001a\u00020D2\u0006\u0010b\u001a\u00020)H\u0002R\u001a\u0010\u001a\u001a\u00020\u001bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R$\u0010!\u001a\u00020\u001b2\u0006\u0010 \u001a\u00020\u001b@BX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\u001d\"\u0004\b\"\u0010\u001fR\u0014\u0010#\u001a\u00020\u001b8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b#\u0010\u001dR\u001e\u0010%\u001a\u00020\u001b2\u0006\u0010$\u001a\u00020\u001b@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u001dR\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010+\u001a\u0004\u0018\u00010,X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010-\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010.\u001a\u0004\u0018\u00010/X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u00100\u001a\u000201X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00102\u001a\u000203X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u00104\u001a\u0004\u0018\u000105X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b6\u00107\"\u0004\b8\u00109R\u001a\u0010:\u001a\u00020\u001bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b;\u0010\u001d\"\u0004\b<\u0010\u001fR\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010=\u001a\u00020>X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010?\u001a\u00020)X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010@\u001a\u0004\u0018\u00010AX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/PulseExpansionHandler;", "Lcom/android/systemui/Gefingerpoken;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "wakeUpCoordinator", "Lcom/android/systemui/statusbar/notification/NotificationWakeUpCoordinator;", "bypassController", "Lcom/android/systemui/statusbar/phone/KeyguardBypassController;", "headsUpManager", "Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;", "roundnessManager", "Lcom/android/systemui/statusbar/notification/stack/NotificationRoundnessManager;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "lockscreenShadeTransitionController", "Lcom/android/systemui/statusbar/LockscreenShadeTransitionController;", "falsingCollector", "Lcom/android/systemui/classifier/FalsingCollector;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/notification/NotificationWakeUpCoordinator;Lcom/android/systemui/statusbar/phone/KeyguardBypassController;Lcom/android/systemui/statusbar/phone/HeadsUpManagerPhone;Lcom/android/systemui/statusbar/notification/stack/NotificationRoundnessManager;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/statusbar/LockscreenShadeTransitionController;Lcom/android/systemui/classifier/FalsingCollector;Lcom/android/systemui/dump/DumpManager;)V", "bouncerShowing", "", "getBouncerShowing", "()Z", "setBouncerShowing", "(Z)V", "value", "isExpanding", "setExpanding", "isFalseTouch", "<set-?>", "leavingLockscreen", "getLeavingLockscreen", "mDraggedFarEnough", "mInitialTouchX", "", "mInitialTouchY", "mPowerManager", "Landroid/os/PowerManager;", "mPulsing", "mStartingChild", "Lcom/android/systemui/statusbar/notification/row/ExpandableView;", "mTemp2", "", "minDragDistance", "", "pulseExpandAbortListener", "Ljava/lang/Runnable;", "getPulseExpandAbortListener", "()Ljava/lang/Runnable;", "setPulseExpandAbortListener", "(Ljava/lang/Runnable;)V", "qsExpanded", "getQsExpanded", "setQsExpanded", "stackScrollerController", "Lcom/android/systemui/statusbar/notification/stack/NotificationStackScrollLayoutController;", "touchSlop", "velocityTracker", "Landroid/view/VelocityTracker;", "canHandleMotionEvent", "cancelExpansion", "", "captureStartingChild", "x", "y", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "findView", "finishExpansion", "initResources", "onInterceptTouchEvent", "event", "Landroid/view/MotionEvent;", "onTouchEvent", "recycleVelocityTracker", "reset", "child", "setPulsing", "pulsing", "setUp", "setUserLocked", "userLocked", "startExpansion", "updateExpansionHeight", "height", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class PulseExpansionHandler implements com.android.systemui.Gefingerpoken, com.android.systemui.Dumpable {
    private final android.os.PowerManager mPowerManager = null;
    private float mInitialTouchX = 0.0F;
    private float mInitialTouchY = 0.0F;
    private boolean isExpanding = false;
    private boolean leavingLockscreen = false;
    private float touchSlop = 0.0F;
    private int minDragDistance = 0;
    private com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController stackScrollerController;
    private final int[] mTemp2 = null;
    private boolean mDraggedFarEnough = false;
    private com.android.systemui.statusbar.notification.row.ExpandableView mStartingChild;
    private boolean mPulsing = false;
    private android.view.VelocityTracker velocityTracker;
    private boolean qsExpanded = false;
    @org.jetbrains.annotations.Nullable()
    private java.lang.Runnable pulseExpandAbortListener;
    private boolean bouncerShowing = false;
    private final com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator wakeUpCoordinator = null;
    private final com.android.systemui.statusbar.phone.KeyguardBypassController bypassController = null;
    private final com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager = null;
    private final com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager roundnessManager = null;
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.systemui.statusbar.LockscreenShadeTransitionController lockscreenShadeTransitionController = null;
    private final com.android.systemui.classifier.FalsingCollector falsingCollector = null;
    private static final int SPRING_BACK_ANIMATION_LENGTH_MS = 375;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.PulseExpansionHandler.Companion Companion = null;
    
    public final boolean isExpanding() {
        return false;
    }
    
    private final void setExpanding(boolean value) {
    }
    
    public final boolean getLeavingLockscreen() {
        return false;
    }
    
    private final boolean isFalseTouch() {
        return false;
    }
    
    public final boolean getQsExpanded() {
        return false;
    }
    
    public final void setQsExpanded(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Runnable getPulseExpandAbortListener() {
        return null;
    }
    
    public final void setPulseExpandAbortListener(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable p0) {
    }
    
    public final boolean getBouncerShowing() {
        return false;
    }
    
    public final void setBouncerShowing(boolean p0) {
    }
    
    private final void initResources(android.content.Context context) {
    }
    
    @java.lang.Override()
    public boolean onInterceptTouchEvent(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent event) {
        return false;
    }
    
    private final boolean canHandleMotionEvent() {
        return false;
    }
    
    private final boolean startExpansion(android.view.MotionEvent event) {
        return false;
    }
    
    private final void recycleVelocityTracker() {
    }
    
    @java.lang.Override()
    public boolean onTouchEvent(@org.jetbrains.annotations.NotNull()
    android.view.MotionEvent event) {
        return false;
    }
    
    private final void finishExpansion() {
    }
    
    private final void updateExpansionHeight(float height) {
    }
    
    private final void captureStartingChild(float x, float y) {
    }
    
    private final void reset(com.android.systemui.statusbar.notification.row.ExpandableView child) {
    }
    
    private final void setUserLocked(com.android.systemui.statusbar.notification.row.ExpandableView child, boolean userLocked) {
    }
    
    private final void cancelExpansion() {
    }
    
    private final com.android.systemui.statusbar.notification.row.ExpandableView findView(float x, float y) {
        return null;
    }
    
    public final void setUp(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController stackScrollerController) {
    }
    
    public final void setPulsing(boolean pulsing) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public PulseExpansionHandler(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator wakeUpCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.KeyguardBypassController bypassController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.HeadsUpManagerPhone headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager roundnessManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.LockscreenShadeTransitionController lockscreenShadeTransitionController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.classifier.FalsingCollector falsingCollector, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/PulseExpansionHandler$Companion;", "", "()V", "SPRING_BACK_ANIMATION_LENGTH_MS", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}