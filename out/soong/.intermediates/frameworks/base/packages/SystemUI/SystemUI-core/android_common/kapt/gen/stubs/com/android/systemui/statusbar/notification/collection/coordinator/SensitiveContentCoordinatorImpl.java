package com.android.systemui.statusbar.notification.collection.coordinator;

import android.os.UserHandle;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.collection.GroupEntry;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.OnBeforeRenderListListener;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.Invalidator;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import dagger.Module;
import dagger.Provides;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\b\u0002\u0018\u00002\u00020\u00012\u00020\u00022\u00020\u00032\u00020\u0004B-\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u00a2\u0006\u0002\u0010\u000fJ\u0010\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0013H\u0016J\u0016\u0010\u0014\u001a\u00020\u00112\f\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00170\u0016H\u0016J\b\u0010\u0018\u001a\u00020\u0011H\u0016R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinatorImpl;", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/Invalidator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinator;", "Lcom/android/systemui/statusbar/notification/DynamicPrivacyController$Listener;", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/OnBeforeRenderListListener;", "dynamicPrivacyController", "Lcom/android/systemui/statusbar/notification/DynamicPrivacyController;", "lockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "keyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "(Lcom/android/systemui/statusbar/notification/DynamicPrivacyController;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/keyguard/KeyguardUpdateMonitor;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/statusbar/policy/KeyguardStateController;)V", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "onBeforeRenderList", "entries", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "onDynamicPrivacyChanged"})
final class SensitiveContentCoordinatorImpl extends com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.Invalidator implements com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinator, com.android.systemui.statusbar.notification.DynamicPrivacyController.Listener, com.android.systemui.statusbar.notification.collection.listbuilder.OnBeforeRenderListListener {
    private final com.android.systemui.statusbar.notification.DynamicPrivacyController dynamicPrivacyController = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager = null;
    private final com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor = null;
    private final com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    @java.lang.Override()
    public void onDynamicPrivacyChanged() {
    }
    
    @java.lang.Override()
    public void onBeforeRenderList(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> entries) {
    }
    
    public SensitiveContentCoordinatorImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.DynamicPrivacyController dynamicPrivacyController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController) {
        super(null);
    }
}