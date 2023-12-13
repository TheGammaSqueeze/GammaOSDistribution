package com.android.systemui.statusbar.notification.collection.legacy;

import android.service.notification.NotificationListenerService;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010\u000e\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\tH&J.\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\u000b2\b\u0010\f\u001a\u0004\u0018\u00010\u00032\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\t0\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H&R\u0014\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/legacy/LegacyNotificationRanker;", "", "rankingMap", "Landroid/service/notification/NotificationListenerService$RankingMap;", "getRankingMap", "()Landroid/service/notification/NotificationListenerService$RankingMap;", "isNotificationForCurrentProfiles", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "updateRanking", "", "newRankingMap", "entries", "", "reason", ""})
public abstract interface LegacyNotificationRanker {
    
    @org.jetbrains.annotations.Nullable()
    public abstract android.service.notification.NotificationListenerService.RankingMap getRankingMap();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.statusbar.notification.collection.NotificationEntry> updateRanking(@org.jetbrains.annotations.Nullable()
    android.service.notification.NotificationListenerService.RankingMap newRankingMap, @org.jetbrains.annotations.NotNull()
    java.util.Collection<com.android.systemui.statusbar.notification.collection.NotificationEntry> entries, @org.jetbrains.annotations.NotNull()
    java.lang.String reason);
    
    public abstract boolean isNotificationForCurrentProfiles(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry);
}