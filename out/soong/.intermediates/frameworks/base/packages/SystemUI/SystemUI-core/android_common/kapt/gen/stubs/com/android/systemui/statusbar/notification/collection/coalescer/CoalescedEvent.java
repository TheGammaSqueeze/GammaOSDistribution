package com.android.systemui.statusbar.notification.collection.coalescer;

import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.StatusBarNotification;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u001a\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0086\b\u0018\u00002\u00020\u0001B/\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\u0010\n\u001a\u0004\u0018\u00010\u000b\u00a2\u0006\u0002\u0010\fJ\t\u0010\u001f\u001a\u00020\u0003H\u00c6\u0003J\t\u0010 \u001a\u00020\u0005H\u00c6\u0003J\t\u0010!\u001a\u00020\u0007H\u00c6\u0003J\t\u0010\"\u001a\u00020\tH\u00c6\u0003J\u000b\u0010#\u001a\u0004\u0018\u00010\u000bH\u00c6\u0003J=\u0010$\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\t2\n\b\u0002\u0010\n\u001a\u0004\u0018\u00010\u000bH\u00c6\u0001J\u0013\u0010%\u001a\u00020&2\b\u0010\'\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010(\u001a\u00020\u0005H\u00d6\u0001J\b\u0010)\u001a\u00020\u0003H\u0016R\u001c\u0010\n\u001a\u0004\u0018\u00010\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0004\u001a\u00020\u0005X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016R\u001a\u0010\b\u001a\u00020\tX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u001a\u0010\u0006\u001a\u00020\u0007X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001e"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coalescer/CoalescedEvent;", "", "key", "", "position", "", "sbn", "Landroid/service/notification/StatusBarNotification;", "ranking", "Landroid/service/notification/NotificationListenerService$Ranking;", "batch", "Lcom/android/systemui/statusbar/notification/collection/coalescer/EventBatch;", "(Ljava/lang/String;ILandroid/service/notification/StatusBarNotification;Landroid/service/notification/NotificationListenerService$Ranking;Lcom/android/systemui/statusbar/notification/collection/coalescer/EventBatch;)V", "getBatch", "()Lcom/android/systemui/statusbar/notification/collection/coalescer/EventBatch;", "setBatch", "(Lcom/android/systemui/statusbar/notification/collection/coalescer/EventBatch;)V", "getKey", "()Ljava/lang/String;", "getPosition", "()I", "setPosition", "(I)V", "getRanking", "()Landroid/service/notification/NotificationListenerService$Ranking;", "setRanking", "(Landroid/service/notification/NotificationListenerService$Ranking;)V", "getSbn", "()Landroid/service/notification/StatusBarNotification;", "setSbn", "(Landroid/service/notification/StatusBarNotification;)V", "component1", "component2", "component3", "component4", "component5", "copy", "equals", "", "other", "hashCode", "toString"})
public final class CoalescedEvent {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String key = null;
    private int position;
    @org.jetbrains.annotations.NotNull()
    private android.service.notification.StatusBarNotification sbn;
    @org.jetbrains.annotations.NotNull()
    private android.service.notification.NotificationListenerService.Ranking ranking;
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.statusbar.notification.collection.coalescer.EventBatch batch;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getKey() {
        return null;
    }
    
    public final int getPosition() {
        return 0;
    }
    
    public final void setPosition(int p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.StatusBarNotification getSbn() {
        return null;
    }
    
    public final void setSbn(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.NotificationListenerService.Ranking getRanking() {
        return null;
    }
    
    public final void setRanking(@org.jetbrains.annotations.NotNull()
    android.service.notification.NotificationListenerService.Ranking p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.coalescer.EventBatch getBatch() {
        return null;
    }
    
    public final void setBatch(@org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.coalescer.EventBatch p0) {
    }
    
    public CoalescedEvent(@org.jetbrains.annotations.NotNull()
    java.lang.String key, int position, @org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn, @org.jetbrains.annotations.NotNull()
    android.service.notification.NotificationListenerService.Ranking ranking, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.coalescer.EventBatch batch) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    public final int component2() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.StatusBarNotification component3() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.notification.NotificationListenerService.Ranking component4() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.statusbar.notification.collection.coalescer.EventBatch component5() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.coalescer.CoalescedEvent copy(@org.jetbrains.annotations.NotNull()
    java.lang.String key, int position, @org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn, @org.jetbrains.annotations.NotNull()
    android.service.notification.NotificationListenerService.Ranking ranking, @org.jetbrains.annotations.Nullable()
    com.android.systemui.statusbar.notification.collection.coalescer.EventBatch batch) {
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