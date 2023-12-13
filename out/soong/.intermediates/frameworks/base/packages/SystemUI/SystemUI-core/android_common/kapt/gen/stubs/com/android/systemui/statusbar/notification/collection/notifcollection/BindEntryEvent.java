package com.android.systemui.statusbar.notification.collection.notifcollection;

import android.service.notification.NotificationListenerService.RankingMap;
import android.service.notification.StatusBarNotification;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0013\u0010\u0012\u001a\u00020\u00132\b\u0010\u0014\u001a\u0004\u0018\u00010\u0015H\u00d6\u0003J\t\u0010\u0016\u001a\u00020\u0017H\u00d6\u0001J\t\u0010\u0018\u001a\u00020\u0019H\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/notifcollection/BindEntryEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifEvent;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "sbn", "Landroid/service/notification/StatusBarNotification;", "(Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;Landroid/service/notification/StatusBarNotification;)V", "getEntry", "()Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "getSbn", "()Landroid/service/notification/StatusBarNotification;", "component1", "component2", "copy", "dispatchToListener", "", "listener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "equals", "", "other", "", "hashCode", "", "toString", ""})
public final class BindEntryEvent extends com.android.systemui.statusbar.notification.collection.notifcollection.NotifEvent {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.NotificationEntry entry = null;
    @org.jetbrains.annotations.NotNull()
    private final android.service.notification.StatusBarNotification sbn = null;
    
    @java.lang.Override()
    public void dispatchToListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener listener) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.NotificationEntry getEntry() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.StatusBarNotification getSbn() {
        return null;
    }
    
    public BindEntryEvent(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.NotificationEntry component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.StatusBarNotification component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.notifcollection.BindEntryEvent copy(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn) {
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