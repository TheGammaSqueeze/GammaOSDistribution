package com.android.systemui.statusbar.phone.ongoingcall;

import android.app.ActivityManager;
import android.app.IActivityManager;
import android.app.IUidObserver;
import android.app.Notification;
import android.app.PendingIntent;
import android.util.Log;
import android.view.View;
import androidx.annotation.VisibleForTesting;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.statusbar.policy.CallbackController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.util.time.SystemClock;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.Optional;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * A controller to handle the ongoing call chip in the collapsed status bar.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00b4\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010!\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u000e\n\u0002\u0018\u0002\n\u0000\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001KBm\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\f\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u0015\u0012\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00180\u0015\u0012\u0006\u0010\u0019\u001a\u00020\u001a\u00a2\u0006\u0002\u0010\u001bJ\u0010\u0010+\u001a\u00020,2\u0006\u0010-\u001a\u00020\u0002H\u0016J-\u0010.\u001a\u00020,2\u0006\u0010/\u001a\u0002002\u0006\u00101\u001a\u0002022\u000e\u00103\u001a\n\u0012\u0006\b\u0001\u0012\u00020504H\u0016\u00a2\u0006\u0002\u00106J\u0006\u00107\u001a\u00020!J\u0006\u00108\u001a\u00020,J\u0010\u00109\u001a\u00020!2\u0006\u0010:\u001a\u00020;H\u0002J\u000e\u0010<\u001a\u00020,2\u0006\u0010=\u001a\u00020!J\b\u0010>\u001a\u00020,H\u0002J\u0010\u0010?\u001a\u00020,2\u0006\u0010-\u001a\u00020\u0002H\u0016J\b\u0010@\u001a\u00020,H\u0002J\u000e\u0010A\u001a\u00020,2\u0006\u0010\u001e\u001a\u00020\u001fJ\u0010\u0010B\u001a\u00020,2\u0006\u0010C\u001a\u00020\u001dH\u0002J\u000f\u0010D\u001a\u0004\u0018\u00010,H\u0007\u00a2\u0006\u0002\u0010EJ\b\u0010F\u001a\u00020,H\u0002J\b\u0010G\u001a\u00020,H\u0002J\b\u0010H\u001a\u00020,H\u0002J\u000e\u0010I\u001a\u0004\u0018\u00010J*\u00020\u001fH\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001c\u001a\u0004\u0018\u00010\u001dX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u001e\u001a\u0004\u0018\u00010\u001fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0012\u001a\u00020\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020!X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020!X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010#\u001a\b\u0012\u0004\u0012\u00020\u00020$X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020&X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0019\u001a\u00020\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\'\u001a\u00020(X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00180\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010)\u001a\u0004\u0018\u00010*X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallController;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallListener;", "Lcom/android/systemui/Dumpable;", "notifCollection", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/CommonNotifCollection;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "systemClock", "Lcom/android/systemui/util/time/SystemClock;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "mainExecutor", "Ljava/util/concurrent/Executor;", "iActivityManager", "Landroid/app/IActivityManager;", "logger", "Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallLogger;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "statusBarWindowController", "Ljava/util/Optional;", "Lcom/android/systemui/statusbar/window/StatusBarWindowController;", "swipeStatusBarAwayGestureHandler", "Lcom/android/systemui/statusbar/gesture/SwipeStatusBarAwayGestureHandler;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "(Lcom/android/systemui/statusbar/notification/collection/notifcollection/CommonNotifCollection;Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/util/time/SystemClock;Lcom/android/systemui/plugins/ActivityStarter;Ljava/util/concurrent/Executor;Landroid/app/IActivityManager;Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallLogger;Lcom/android/systemui/dump/DumpManager;Ljava/util/Optional;Ljava/util/Optional;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;)V", "callNotificationInfo", "Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallController$CallNotificationInfo;", "chipView", "Landroid/view/View;", "isCallAppVisible", "", "isFullscreen", "mListeners", "", "notifListener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "statusBarStateListener", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "uidObserver", "Landroid/app/IUidObserver$Stub;", "addCallback", "", "listener", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "hasOngoingCall", "init", "isProcessVisibleToUser", "procState", "", "notifyChipVisibilityChanged", "chipIsVisible", "onSwipeAwayGestureDetected", "removeCallback", "removeChip", "setChipView", "setUpUidObserver", "currentCallNotificationInfo", "tearDownChipView", "()Lkotlin/Unit;", "updateChip", "updateChipClickListener", "updateGestureListening", "getTimeView", "Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallChronometer;", "CallNotificationInfo"})
@com.android.systemui.dagger.SysUISingleton()
public final class OngoingCallController implements com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.statusbar.phone.ongoingcall.OngoingCallListener>, com.android.systemui.Dumpable {
    private boolean isFullscreen = false;
    
    /**
     * Non-null if there's an active call notification.
     */
    private com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController.CallNotificationInfo callNotificationInfo;
    
    /**
     * True if the application managing the call is visible to the user.
     */
    private boolean isCallAppVisible = false;
    private android.view.View chipView;
    private android.app.IUidObserver.Stub uidObserver;
    private final java.util.List<com.android.systemui.statusbar.phone.ongoingcall.OngoingCallListener> mListeners = null;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener notifListener = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener statusBarStateListener = null;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection notifCollection = null;
    private final com.android.systemui.flags.FeatureFlags featureFlags = null;
    private final com.android.systemui.util.time.SystemClock systemClock = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final java.util.concurrent.Executor mainExecutor = null;
    private final android.app.IActivityManager iActivityManager = null;
    private final com.android.systemui.statusbar.phone.ongoingcall.OngoingCallLogger logger = null;
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    private final java.util.Optional<com.android.systemui.statusbar.window.StatusBarWindowController> statusBarWindowController = null;
    private final java.util.Optional<com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler> swipeStatusBarAwayGestureHandler = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    
    public final void init() {
    }
    
    /**
     * Sets the chip view that will contain ongoing call information.
     *
     * Should only be called from [CollapsedStatusBarFragment].
     */
    public final void setChipView(@org.jetbrains.annotations.NotNull()
    android.view.View chipView) {
    }
    
    /**
     * Called when the chip's visibility may have changed.
     *
     * Should only be called from [CollapsedStatusBarFragment].
     */
    public final void notifyChipVisibilityChanged(boolean chipIsVisible) {
    }
    
    /**
     * Returns true if there's an active ongoing call that should be displayed in a status bar chip.
     */
    public final boolean hasOngoingCall() {
        return false;
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ongoingcall.OngoingCallListener listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ongoingcall.OngoingCallListener listener) {
    }
    
    private final void updateChip() {
    }
    
    private final void updateChipClickListener() {
    }
    
    /**
     * Sets up an [IUidObserver] to monitor the status of the application managing the ongoing call.
     */
    private final void setUpUidObserver(com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController.CallNotificationInfo currentCallNotificationInfo) {
    }
    
    /**
     * Returns true if the given [procState] represents a process that's visible to the user.
     */
    private final boolean isProcessVisibleToUser(int procState) {
        return false;
    }
    
    private final void updateGestureListening() {
    }
    
    private final void removeChip() {
    }
    
    /**
     * Tear down anything related to the chip view to prevent leaks.
     */
    @org.jetbrains.annotations.Nullable()
    @androidx.annotation.VisibleForTesting()
    public final kotlin.Unit tearDownChipView() {
        return null;
    }
    
    private final com.android.systemui.statusbar.phone.ongoingcall.OngoingCallChronometer getTimeView(android.view.View $this$getTimeView) {
        return null;
    }
    
    /**
     * If there's an active ongoing call, then we will force the status bar to always show, even if
     * the user is in immersive mode. However, we also want to give users the ability to swipe away
     * the status bar if they need to access the area under the status bar.
     *
     * This method updates the status bar window appropriately when the swipe away gesture is
     * detected.
     */
    private final void onSwipeAwayGestureDetected() {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public OngoingCallController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection notifCollection, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock systemClock, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor, @org.jetbrains.annotations.NotNull()
    android.app.IActivityManager iActivityManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.ongoingcall.OngoingCallLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.statusbar.window.StatusBarWindowController> statusBarWindowController, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler> swipeStatusBarAwayGestureHandler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0018\b\u0082\b\u0018\u00002\u00020\u0001B7\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\rJ\t\u0010\u0018\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0019\u001a\u00020\u0005H\u00c6\u0003J\u000b\u0010\u001a\u001a\u0004\u0018\u00010\u0007H\u00c6\u0003J\t\u0010\u001b\u001a\u00020\tH\u00c6\u0003J\t\u0010\u001c\u001a\u00020\u000bH\u00c6\u0003J\t\u0010\u001d\u001a\u00020\u000bH\u00c6\u0003JG\u0010\u001e\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u00072\b\b\u0002\u0010\b\u001a\u00020\t2\b\b\u0002\u0010\n\u001a\u00020\u000b2\b\b\u0002\u0010\f\u001a\u00020\u000bH\u00c6\u0001J\u0013\u0010\u001f\u001a\u00020\u000b2\b\u0010 \u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\u0006\u0010!\u001a\u00020\u000bJ\t\u0010\"\u001a\u00020\tH\u00d6\u0001J\t\u0010#\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0013\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u0012R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\f\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0012R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallController$CallNotificationInfo;", "", "key", "", "callStartTime", "", "intent", "Landroid/app/PendingIntent;", "uid", "", "isOngoing", "", "statusBarSwipedAway", "(Ljava/lang/String;JLandroid/app/PendingIntent;IZZ)V", "getCallStartTime", "()J", "getIntent", "()Landroid/app/PendingIntent;", "()Z", "getKey", "()Ljava/lang/String;", "getStatusBarSwipedAway", "getUid", "()I", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "equals", "other", "hasValidStartTime", "hashCode", "toString"})
    static final class CallNotificationInfo {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String key = null;
        private final long callStartTime = 0L;
        @org.jetbrains.annotations.Nullable()
        private final android.app.PendingIntent intent = null;
        private final int uid = 0;
        
        /**
         * True if the call is currently ongoing (as opposed to incoming, screening, etc.).
         */
        private final boolean isOngoing = false;
        
        /**
         * True if the user has swiped away the status bar while in this phone call.
         */
        private final boolean statusBarSwipedAway = false;
        
        /**
         * Returns true if the notification information has a valid call start time.
         * See b/192379214.
         */
        public final boolean hasValidStartTime() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getKey() {
            return null;
        }
        
        public final long getCallStartTime() {
            return 0L;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.app.PendingIntent getIntent() {
            return null;
        }
        
        public final int getUid() {
            return 0;
        }
        
        /**
         * True if the call is currently ongoing (as opposed to incoming, screening, etc.).
         */
        public final boolean isOngoing() {
            return false;
        }
        
        /**
         * True if the user has swiped away the status bar while in this phone call.
         */
        public final boolean getStatusBarSwipedAway() {
            return false;
        }
        
        public CallNotificationInfo(@org.jetbrains.annotations.NotNull()
        java.lang.String key, long callStartTime, @org.jetbrains.annotations.Nullable()
        android.app.PendingIntent intent, int uid, boolean isOngoing, boolean statusBarSwipedAway) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        public final long component2() {
            return 0L;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final android.app.PendingIntent component3() {
            return null;
        }
        
        public final int component4() {
            return 0;
        }
        
        /**
         * True if the call is currently ongoing (as opposed to incoming, screening, etc.).
         */
        public final boolean component5() {
            return false;
        }
        
        /**
         * True if the user has swiped away the status bar while in this phone call.
         */
        public final boolean component6() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController.CallNotificationInfo copy(@org.jetbrains.annotations.NotNull()
        java.lang.String key, long callStartTime, @org.jetbrains.annotations.Nullable()
        android.app.PendingIntent intent, int uid, boolean isOngoing, boolean statusBarSwipedAway) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}