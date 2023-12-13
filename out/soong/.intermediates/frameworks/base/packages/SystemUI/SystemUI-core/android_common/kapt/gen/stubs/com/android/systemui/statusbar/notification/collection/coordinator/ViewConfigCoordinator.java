package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.internal.widget.MessagingGroup;
import com.android.internal.widget.MessagingMessage;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.NotificationLockscreenUserManager.UserChangedListener;
import com.android.systemui.statusbar.NotificationLockscreenUserManagerImpl;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.policy.ConfigurationController;
import javax.inject.Inject;

/**
 * A coordinator which ensures that notifications within the new pipeline are correctly inflated
 * for the current uiMode and screen properties; additionally deferring those changes when a user
 * change is in progress until that process has completed.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000P\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u00012\u00020\u00022\u00020\u0003B/\b\u0001\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0012H\u0016J\b\u0010\u0017\u001a\u00020\u0015H\u0016J\b\u0010\u0018\u001a\u00020\u0015H\u0016J\b\u0010\u0019\u001a\u00020\u0015H\u0016J\u0010\u0010\u001a\u001a\u00020\u00152\u0006\u0010\u001b\u001a\u00020\u001cH\u0016J\b\u0010\u001d\u001a\u00020\u0015H\u0002J\b\u0010\u001e\u001a\u00020\u0015H\u0002R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0010X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/ViewConfigCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager$UserChangedListener;", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "lockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManagerImpl;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "mGutsManager", "Lcom/android/systemui/statusbar/notification/row/NotificationGutsManager;", "mKeyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "(Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManagerImpl;Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/statusbar/notification/row/NotificationGutsManager;Lcom/android/keyguard/KeyguardUpdateMonitor;)V", "mDispatchUiModeChangeOnUserSwitched", "", "mPipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "mReinflateNotificationsOnUserSwitched", "attach", "", "pipeline", "onDensityOrFontScaleChanged", "onThemeChanged", "onUiModeChanged", "onUserChanged", "userId", "", "updateNotificationsOnDensityOrFontScaleChanged", "updateNotificationsOnUiModeChanged"})
@com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
public final class ViewConfigCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator, com.android.systemui.statusbar.NotificationLockscreenUserManager.UserChangedListener, com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener {
    private boolean mReinflateNotificationsOnUserSwitched = false;
    private boolean mDispatchUiModeChangeOnUserSwitched = false;
    private com.android.systemui.statusbar.notification.collection.NotifPipeline mPipeline;
    private final com.android.systemui.statusbar.notification.row.NotificationGutsManager mGutsManager = null;
    private final com.android.keyguard.KeyguardUpdateMonitor mKeyguardUpdateMonitor = null;
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    @java.lang.Override()
    public void onDensityOrFontScaleChanged() {
    }
    
    @java.lang.Override()
    public void onUiModeChanged() {
    }
    
    @java.lang.Override()
    public void onThemeChanged() {
    }
    
    @java.lang.Override()
    public void onUserChanged(int userId) {
    }
    
    private final void updateNotificationsOnUiModeChanged() {
    }
    
    private final void updateNotificationsOnDensityOrFontScaleChanged() {
    }
    
    @javax.inject.Inject()
    public ViewConfigCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManagerImpl lockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.NotificationGutsManager mGutsManager, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor mKeyguardUpdateMonitor) {
        super();
    }
}