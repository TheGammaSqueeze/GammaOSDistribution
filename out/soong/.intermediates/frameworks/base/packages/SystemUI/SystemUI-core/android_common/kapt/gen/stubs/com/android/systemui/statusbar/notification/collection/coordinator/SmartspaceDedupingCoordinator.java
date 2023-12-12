package com.android.systemui.statusbar.notification.collection.coordinator;

import android.app.smartspace.SmartspaceTarget;
import android.os.Parcelable;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import javax.inject.Inject;

/**
 * Hides notifications on the lockscreen if the content of those notifications is also visible
 * in smartspace. This ONLY hides the notifications on the lockscreen: if the user pulls the shade
 * down or unlocks the device, then the notifications are unhidden.
 *
 * In addition, notifications that have recently alerted aren't filtered. Tracking this in a way
 * that involves the fewest pipeline invalidations requires some unfortunately complex logic.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0080\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u0001BA\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\b\b\u0001\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\u0002\u0010\u0010J\u0010\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u000bH\u0016J\u0010\u0010 \u001a\u00020\u001e2\u0006\u0010!\u001a\u00020\u001cH\u0002J\u0010\u0010\"\u001a\u00020\u00162\u0006\u0010#\u001a\u00020$H\u0002J\u0010\u0010%\u001a\u00020\u00162\u0006\u0010#\u001a\u00020$H\u0002J\u0016\u0010&\u001a\u00020\u001e2\f\u0010\'\u001a\b\u0012\u0004\u0012\u00020)0(H\u0002J\u0010\u0010*\u001a\u00020\u001e2\u0006\u0010+\u001a\u00020,H\u0002J\u0018\u0010-\u001a\u00020\u001e2\u0006\u0010!\u001a\u00020\u001c2\u0006\u0010#\u001a\u00020$H\u0002J\u0010\u0010.\u001a\u00020\u00162\u0006\u0010!\u001a\u00020\u001cH\u0002R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0019\u001a\u000e\u0012\u0004\u0012\u00020\u001b\u0012\u0004\u0012\u00020\u001c0\u001aX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/SmartspaceDedupingCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "statusBarStateController", "Lcom/android/systemui/statusbar/SysuiStatusBarStateController;", "smartspaceController", "Lcom/android/systemui/statusbar/lockscreen/LockscreenSmartspaceController;", "notificationEntryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "notificationLockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "notifPipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "clock", "Lcom/android/systemui/util/time/SystemClock;", "(Lcom/android/systemui/statusbar/SysuiStatusBarStateController;Lcom/android/systemui/statusbar/lockscreen/LockscreenSmartspaceController;Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/time/SystemClock;)V", "collectionListener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "filter", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifFilter;", "isOnLockscreen", "", "statusBarStateListener", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController$StateListener;", "trackedSmartspaceTargets", "", "", "Lcom/android/systemui/statusbar/notification/collection/coordinator/TrackedSmartspaceTarget;", "attach", "", "pipeline", "cancelExceptionTimeout", "target", "hasRecentlyAlerted", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "isDupedWithSmartspaceContent", "onNewSmartspaceTargets", "targets", "", "Landroid/os/Parcelable;", "recordStatusBarState", "newState", "", "updateAlertException", "updateFilterStatus"})
@com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
public final class SmartspaceDedupingCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator {
    private boolean isOnLockscreen = false;
    private java.util.Map<java.lang.String, com.android.systemui.statusbar.notification.collection.coordinator.TrackedSmartspaceTarget> trackedSmartspaceTargets;
    private final com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter filter = null;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener collectionListener = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController.StateListener statusBarStateListener = null;
    private final com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController smartspaceController = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager notificationLockscreenUserManager = null;
    private final com.android.systemui.statusbar.notification.collection.NotifPipeline notifPipeline = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor executor = null;
    private final com.android.systemui.util.time.SystemClock clock = null;
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    private final boolean isDupedWithSmartspaceContent(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    private final void onNewSmartspaceTargets(java.util.List<? extends android.os.Parcelable> targets) {
    }
    
    /**
     * Returns true if the target's alert exception status has changed
     */
    private final boolean updateFilterStatus(com.android.systemui.statusbar.notification.collection.coordinator.TrackedSmartspaceTarget target) {
        return false;
    }
    
    private final void updateAlertException(com.android.systemui.statusbar.notification.collection.coordinator.TrackedSmartspaceTarget target, com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    private final void cancelExceptionTimeout(com.android.systemui.statusbar.notification.collection.coordinator.TrackedSmartspaceTarget target) {
    }
    
    private final void recordStatusBarState(int newState) {
    }
    
    private final boolean hasRecentlyAlerted(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    @javax.inject.Inject()
    public SmartspaceDedupingCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SysuiStatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController smartspaceController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager notificationLockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline notifPipeline, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.time.SystemClock clock) {
        super();
    }
}