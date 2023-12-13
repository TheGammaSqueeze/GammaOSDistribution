package com.android.systemui.statusbar.notification.collection;

import android.app.Notification;
import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.NotificationListenerService.RankingMap;
import android.service.notification.StatusBarNotification;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.notification.NotificationEntryManager.KeyguardEnvironment;
import com.android.systemui.statusbar.notification.NotificationEntryManagerLogger;
import com.android.systemui.statusbar.notification.NotificationFilter;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.notification.collection.legacy.LegacyNotificationRanker;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
import com.android.systemui.statusbar.notification.stack.PriorityBucket;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import dagger.Lazy;
import java.util.Objects;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0018\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\u001a\f\u0010\u0002\u001a\u00020\u0003*\u00020\u0004H\u0002\u001a\f\u0010\u0005\u001a\u00020\u0003*\u00020\u0004H\u0002\u001a\f\u0010\u0006\u001a\u00020\u0003*\u00020\u0004H\u0002\u001a\f\u0010\u0007\u001a\u00020\u0003*\u00020\bH\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"TAG", "", "isColorizedForegroundService", "", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "isImportantCall", "isSystemMax", "isSystemNotification", "Landroid/service/notification/StatusBarNotification;"})
public final class NotificationRankingManagerKt {
    private static final java.lang.String TAG = "NotifRankingManager";
    
    private static final boolean isSystemMax(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isSystemMax) {
        return false;
    }
    
    private static final boolean isSystemNotification(android.service.notification.StatusBarNotification $this$isSystemNotification) {
        return false;
    }
    
    private static final boolean isImportantCall(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isImportantCall) {
        return false;
    }
    
    private static final boolean isColorizedForegroundService(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isColorizedForegroundService) {
        return false;
    }
}