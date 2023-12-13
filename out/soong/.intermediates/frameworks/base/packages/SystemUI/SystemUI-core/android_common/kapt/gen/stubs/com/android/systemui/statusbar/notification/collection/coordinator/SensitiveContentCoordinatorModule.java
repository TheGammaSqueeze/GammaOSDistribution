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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c7\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J0\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinatorModule;", "", "()V", "provideCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinator;", "dynamicPrivacyController", "Lcom/android/systemui/statusbar/notification/DynamicPrivacyController;", "lockscreenUserManager", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "keyguardUpdateMonitor", "Lcom/android/keyguard/KeyguardUpdateMonitor;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;"})
@dagger.Module()
public final class SensitiveContentCoordinatorModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinatorModule INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinator provideCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.DynamicPrivacyController dynamicPrivacyController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager lockscreenUserManager, @org.jetbrains.annotations.NotNull()
    com.android.keyguard.KeyguardUpdateMonitor keyguardUpdateMonitor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController) {
        return null;
    }
    
    private SensitiveContentCoordinatorModule() {
        super();
    }
}