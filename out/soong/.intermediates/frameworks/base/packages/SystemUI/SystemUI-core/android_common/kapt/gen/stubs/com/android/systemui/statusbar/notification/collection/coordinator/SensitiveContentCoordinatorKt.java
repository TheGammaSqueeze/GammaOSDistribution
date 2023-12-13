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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0016\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \u001a\u0016\u0010\u0000\u001a\b\u0012\u0004\u0012\u00020\u00020\u00012\u0006\u0010\u0003\u001a\u00020\u0004H\u0002\u001a\u001c\u0010\u0000\u001a\b\u0012\u0004\u0012\u00020\u00020\u00012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00040\u0006H\u0002"}, d2 = {"extractAllRepresentativeEntries", "Lkotlin/sequences/Sequence;", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "listEntry", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "entries", ""})
public final class SensitiveContentCoordinatorKt {
    
    private static final kotlin.sequences.Sequence<com.android.systemui.statusbar.notification.collection.NotificationEntry> extractAllRepresentativeEntries(java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> entries) {
        return null;
    }
    
    private static final kotlin.sequences.Sequence<com.android.systemui.statusbar.notification.collection.NotificationEntry> extractAllRepresentativeEntries(com.android.systemui.statusbar.notification.collection.ListEntry listEntry) {
        return null;
    }
}