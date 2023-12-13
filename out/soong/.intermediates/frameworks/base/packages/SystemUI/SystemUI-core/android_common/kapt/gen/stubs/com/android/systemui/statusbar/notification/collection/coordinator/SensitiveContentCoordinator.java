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

/**
 * Coordinates re-inflation and post-processing of sensitive notification content.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;"})
public abstract interface SensitiveContentCoordinator extends com.android.systemui.statusbar.notification.collection.coordinator.Coordinator {
}