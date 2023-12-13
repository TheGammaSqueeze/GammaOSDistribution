package com.android.systemui.statusbar.notification.collection.notifcollection;

import android.os.RemoteException;
import android.service.notification.NotificationListenerService.RankingMap;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.dagger.NotificationLog;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0013\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u0011\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u000e\u0010\t\u001a\u00020\u00062\u0006\u0010\n\u001a\u00020\u000bJ\u000e\u0010\f\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bJ\u0010\u0010\r\u001a\u00020\u00062\b\u0010\u000e\u001a\u0004\u0018\u00010\u000fJ\u0016\u0010\u0010\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u0012\u001a\u00020\u0013J\u001e\u0010\u0014\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0015\u001a\u00020\u000bJ\u000e\u0010\u0016\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u000e\u0010\u0017\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u000e\u0010\u0018\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u000e\u0010\u0019\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u0016\u0010\u001a\u001a\u00020\u00062\u0006\u0010\u001b\u001a\u00020\u000f2\u0006\u0010\u001c\u001a\u00020\u000bJ\u001e\u0010\u001d\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u001e\u001a\u00020\u000f2\u0006\u0010\u001f\u001a\u00020\u000fJ\u001e\u0010 \u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u001e\u001a\u00020\u000f2\u0006\u0010\u001f\u001a\u00020\u000fJ\u000e\u0010!\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u000e\u0010\"\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u0016\u0010#\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010\u001f\u001a\u00020\u000bJ\u000e\u0010$\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000fJ\u0016\u0010%\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010&\u001a\u00020\'J\u000e\u0010(\u001a\u00020\u00062\u0006\u0010)\u001a\u00020*J\u0016\u0010+\u001a\u00020\u00062\u0006\u0010\u0011\u001a\u00020\u000f2\u0006\u0010)\u001a\u00020*R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionLogger;", "", "buffer", "Lcom/android/systemui/log/LogBuffer;", "(Lcom/android/systemui/log/LogBuffer;)V", "logChildDismissed", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "logDismissAll", "userId", "", "logDismissOnAlreadyCanceledEntry", "logIgnoredError", "message", "", "logLifetimeExtended", "key", "extender", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender;", "logLifetimeExtensionEnded", "totalExtenders", "logNoNotificationToRemoveWithKey", "logNotifClearAllDismissalIntercepted", "logNotifDismissed", "logNotifDismissedIntercepted", "logNotifGroupPosted", "groupKey", "batchSize", "logNotifInternalUpdate", "name", "reason", "logNotifInternalUpdateFailed", "logNotifPosted", "logNotifReleased", "logNotifRemoved", "logNotifUpdated", "logRankingMissing", "rankingMap", "Landroid/service/notification/NotificationListenerService$RankingMap;", "logRemoteExceptionOnClearAllNotifications", "e", "Landroid/os/RemoteException;", "logRemoteExceptionOnNotificationClear"})
public final class NotifCollectionLogger {
    private final com.android.systemui.log.LogBuffer buffer = null;
    
    public final void logNotifPosted(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifGroupPosted(@org.jetbrains.annotations.NotNull()
    java.lang.String groupKey, int batchSize) {
    }
    
    public final void logNotifUpdated(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifRemoved(@org.jetbrains.annotations.NotNull()
    java.lang.String key, int reason) {
    }
    
    public final void logNotifReleased(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifDismissed(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logChildDismissed(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public final void logDismissAll(int userId) {
    }
    
    public final void logDismissOnAlreadyCanceledEntry(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public final void logNotifDismissedIntercepted(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifClearAllDismissalIntercepted(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logNotifInternalUpdate(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logNotifInternalUpdateFailed(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    java.lang.String name, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
    }
    
    public final void logNoNotificationToRemoveWithKey(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final void logRankingMissing(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    android.service.notification.NotificationListenerService.RankingMap rankingMap) {
    }
    
    public final void logRemoteExceptionOnNotificationClear(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    android.os.RemoteException e) {
    }
    
    public final void logRemoteExceptionOnClearAllNotifications(@org.jetbrains.annotations.NotNull()
    android.os.RemoteException e) {
    }
    
    public final void logLifetimeExtended(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender extender) {
    }
    
    public final void logLifetimeExtensionEnded(@org.jetbrains.annotations.NotNull()
    java.lang.String key, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender extender, int totalExtenders) {
    }
    
    public final void logIgnoredError(@org.jetbrains.annotations.Nullable()
    java.lang.String message) {
    }
    
    @javax.inject.Inject()
    public NotifCollectionLogger(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.log.dagger.NotificationLog()
    com.android.systemui.log.LogBuffer buffer) {
        super();
    }
}