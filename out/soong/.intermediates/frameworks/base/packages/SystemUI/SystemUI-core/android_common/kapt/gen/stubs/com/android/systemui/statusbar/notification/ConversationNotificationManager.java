package com.android.systemui.statusbar.notification;

import android.app.Notification;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.graphics.drawable.AnimatedImageDrawable;
import android.os.Handler;
import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.NotificationListenerService.RankingMap;
import com.android.internal.statusbar.NotificationVisibility;
import com.android.internal.widget.ConversationLayout;
import com.android.internal.widget.MessagingImageMessage;
import com.android.internal.widget.MessagingLayout;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.NotificationContentView;
import com.android.systemui.statusbar.notification.stack.StackStateAnimator;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.statusbar.policy.OnHeadsUpChangedListener;
import java.util.concurrent.ConcurrentHashMap;
import javax.inject.Inject;

/**
 * Tracks state related to conversation notifications, and updates the UI of existing notifications
 * when necessary.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0006\b\u0007\u0018\u0000 \"2\u00020\u0001:\u0002\"#B)\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0001\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0016\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J\u000e\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\fJ\u0010\u0010\u001a\u001a\u00020\u00182\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\u0010\u0010\u001b\u001a\u00020\u00182\u0006\u0010\u001c\u001a\u00020\u001dH\u0002J\u0010\u0010\u001e\u001a\u00020\u00182\u0006\u0010\u001f\u001a\u00020\u000fH\u0002J\u0014\u0010 \u001a\u00020\f*\u00020\u00102\u0006\u0010!\u001a\u00020\u0016H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\r\u001a\u000e\u0012\u0004\u0012\u00020\u000f\u0012\u0004\u0012\u00020\u00100\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/ConversationNotificationManager;", "", "notificationEntryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "notificationGroupManager", "Lcom/android/systemui/statusbar/notification/collection/legacy/NotificationGroupManagerLegacy;", "context", "Landroid/content/Context;", "mainHandler", "Landroid/os/Handler;", "(Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/notification/collection/legacy/NotificationGroupManagerLegacy;Landroid/content/Context;Landroid/os/Handler;)V", "notifPanelCollapsed", "", "states", "Ljava/util/concurrent/ConcurrentHashMap;", "", "Lcom/android/systemui/statusbar/notification/ConversationNotificationManager$ConversationState;", "getUnreadCount", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "recoveredBuilder", "Landroid/app/Notification$Builder;", "onNotificationPanelExpandStateChanged", "", "isCollapsed", "removeTrackedEntry", "resetBadgeUi", "row", "Lcom/android/systemui/statusbar/notification/row/ExpandableNotificationRow;", "resetCount", "key", "shouldIncrementUnread", "newBuilder", "Companion", "ConversationState"})
@com.android.systemui.dagger.SysUISingleton()
public final class ConversationNotificationManager {
    private final java.util.concurrent.ConcurrentHashMap<java.lang.String, com.android.systemui.statusbar.notification.ConversationNotificationManager.ConversationState> states = null;
    private boolean notifPanelCollapsed = true;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager = null;
    private final com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy notificationGroupManager = null;
    private final android.content.Context context = null;
    private final android.os.Handler mainHandler = null;
    private static final int IMPORTANCE_ANIMATION_DELAY = 960;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.ConversationNotificationManager.Companion Companion = null;
    
    private final boolean shouldIncrementUnread(com.android.systemui.statusbar.notification.ConversationNotificationManager.ConversationState $this$shouldIncrementUnread, android.app.Notification.Builder newBuilder) {
        return false;
    }
    
    public final int getUnreadCount(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry, @org.jetbrains.annotations.NotNull()
    android.app.Notification.Builder recoveredBuilder) {
        return 0;
    }
    
    public final void onNotificationPanelExpandStateChanged(boolean isCollapsed) {
    }
    
    private final void resetCount(java.lang.String key) {
    }
    
    private final void removeTrackedEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    private final void resetBadgeUi(com.android.systemui.statusbar.notification.row.ExpandableNotificationRow row) {
    }
    
    @javax.inject.Inject()
    public ConversationNotificationManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy notificationGroupManager, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler mainHandler) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\b\u0082\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0011\u001a\u00020\u0003H\u00d6\u0001J\t\u0010\u0012\u001a\u00020\u0013H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/statusbar/notification/ConversationNotificationManager$ConversationState;", "", "unreadCount", "", "notification", "Landroid/app/Notification;", "(ILandroid/app/Notification;)V", "getNotification", "()Landroid/app/Notification;", "getUnreadCount", "()I", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString", ""})
    static final class ConversationState {
        private final int unreadCount = 0;
        @org.jetbrains.annotations.NotNull()
        private final android.app.Notification notification = null;
        
        public final int getUnreadCount() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.app.Notification getNotification() {
            return null;
        }
        
        public ConversationState(int unreadCount, @org.jetbrains.annotations.NotNull()
        android.app.Notification notification) {
            super();
        }
        
        public final int component1() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.app.Notification component2() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.notification.ConversationNotificationManager.ConversationState copy(int unreadCount, @org.jetbrains.annotations.NotNull()
        android.app.Notification notification) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/ConversationNotificationManager$Companion;", "", "()V", "IMPORTANCE_ANIMATION_DELAY", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}