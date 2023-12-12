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

/**
 * NotificationRankingManager is responsible for holding on to the most recent [RankingMap], and
 * updating SystemUI's set of [NotificationEntry]s with their own ranking. It also sorts and filters
 * a set of entries (but retains none of them). We also set buckets on the entries here since
 * bucketing is tied closely to sorting.
 *
 * For the curious: this class is one iteration closer to null of what used to be called
 * NotificationData.java.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008a\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010 \n\u0000\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0002\u0010\u001c\n\u0002\b\u0004\b\u0016\u0018\u00002\u00020\u0001BU\b\u0007\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u00a2\u0006\u0002\u0010\u0015J\u0010\u0010+\u001a\u00020(2\u0006\u0010,\u001a\u00020\u001eH\u0002J$\u0010-\u001a\b\u0012\u0004\u0012\u00020\u001e0.2\f\u0010/\u001a\b\u0012\u0004\u0012\u00020\u001e002\u0006\u00101\u001a\u000202H\u0002J\u0010\u00103\u001a\u0002042\u0006\u0010,\u001a\u00020\u001eH\u0002J\u0010\u00105\u001a\u00020(2\u0006\u0010,\u001a\u00020\u001eH\u0016J.\u00106\u001a\b\u0012\u0004\u0012\u00020\u001e0.2\b\u00107\u001a\u0004\u0018\u00010!2\f\u0010/\u001a\b\u0012\u0004\u0012\u00020\u001e002\u0006\u00101\u001a\u000202H\u0016J\u0016\u00108\u001a\u0002092\f\u0010/\u001a\b\u0012\u0004\u0012\u00020\u001e0:H\u0002J\f\u0010;\u001a\u000204*\u00020\u001eH\u0002J\f\u0010<\u001a\u00020(*\u00020\u001eH\u0002J\f\u0010=\u001a\u00020(*\u00020\u001eH\u0002J\f\u0010>\u001a\u00020(*\u00020\u001eH\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R#\u0010\u0016\u001a\n \u0017*\u0004\u0018\u00010\u00040\u00048BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u001a\u0010\u001b\u001a\u0004\b\u0018\u0010\u0019R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u001c\u001a\u0012\u0012\u0004\u0012\u00020\u001e0\u001dj\b\u0012\u0004\u0012\u00020\u001e`\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R(\u0010\"\u001a\u0004\u0018\u00010!2\b\u0010 \u001a\u0004\u0018\u00010!@TX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010$\"\u0004\b%\u0010&R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\'\u001a\u00020(8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b)\u0010*"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/NotificationRankingManager;", "Lcom/android/systemui/statusbar/notification/collection/legacy/LegacyNotificationRanker;", "mediaManagerLazy", "Ldagger/Lazy;", "Lcom/android/systemui/statusbar/NotificationMediaManager;", "groupManager", "Lcom/android/systemui/statusbar/notification/collection/legacy/NotificationGroupManagerLegacy;", "headsUpManager", "Lcom/android/systemui/statusbar/policy/HeadsUpManager;", "notifFilter", "Lcom/android/systemui/statusbar/notification/NotificationFilter;", "logger", "Lcom/android/systemui/statusbar/notification/NotificationEntryManagerLogger;", "sectionsFeatureManager", "Lcom/android/systemui/statusbar/notification/NotificationSectionsFeatureManager;", "peopleNotificationIdentifier", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "highPriorityProvider", "Lcom/android/systemui/statusbar/notification/collection/provider/HighPriorityProvider;", "keyguardEnvironment", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager$KeyguardEnvironment;", "(Ldagger/Lazy;Lcom/android/systemui/statusbar/notification/collection/legacy/NotificationGroupManagerLegacy;Lcom/android/systemui/statusbar/policy/HeadsUpManager;Lcom/android/systemui/statusbar/notification/NotificationFilter;Lcom/android/systemui/statusbar/notification/NotificationEntryManagerLogger;Lcom/android/systemui/statusbar/notification/NotificationSectionsFeatureManager;Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;Lcom/android/systemui/statusbar/notification/collection/provider/HighPriorityProvider;Lcom/android/systemui/statusbar/notification/NotificationEntryManager$KeyguardEnvironment;)V", "mediaManager", "kotlin.jvm.PlatformType", "getMediaManager", "()Lcom/android/systemui/statusbar/NotificationMediaManager;", "mediaManager$delegate", "Lkotlin/Lazy;", "rankingComparator", "Ljava/util/Comparator;", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "Lkotlin/Comparator;", "<set-?>", "Landroid/service/notification/NotificationListenerService$RankingMap;", "rankingMap", "getRankingMap", "()Landroid/service/notification/NotificationListenerService$RankingMap;", "setRankingMap", "(Landroid/service/notification/NotificationListenerService$RankingMap;)V", "usePeopleFiltering", "", "getUsePeopleFiltering", "()Z", "filter", "entry", "filterAndSortLocked", "", "entries", "", "reason", "", "getBucketForEntry", "", "isNotificationForCurrentProfiles", "updateRanking", "newRankingMap", "updateRankingForEntries", "", "", "getPeopleNotificationType", "isConversation", "isHighPriority", "isImportantMedia"})
public class NotificationRankingManager implements com.android.systemui.statusbar.notification.collection.legacy.LegacyNotificationRanker {
    @org.jetbrains.annotations.Nullable()
    private android.service.notification.NotificationListenerService.RankingMap rankingMap;
    private final kotlin.Lazy mediaManager$delegate = null;
    private final java.util.Comparator<com.android.systemui.statusbar.notification.collection.NotificationEntry> rankingComparator = null;
    private final dagger.Lazy<com.android.systemui.statusbar.NotificationMediaManager> mediaManagerLazy = null;
    private final com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy groupManager = null;
    private final com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager = null;
    private final com.android.systemui.statusbar.notification.NotificationFilter notifFilter = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManagerLogger logger = null;
    private final com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager sectionsFeatureManager = null;
    private final com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier = null;
    private final com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider highPriorityProvider = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager.KeyguardEnvironment keyguardEnvironment = null;
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.service.notification.NotificationListenerService.RankingMap getRankingMap() {
        return null;
    }
    
    protected void setRankingMap(@org.jetbrains.annotations.Nullable()
    android.service.notification.NotificationListenerService.RankingMap p0) {
    }
    
    private final com.android.systemui.statusbar.NotificationMediaManager getMediaManager() {
        return null;
    }
    
    private final boolean getUsePeopleFiltering() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.statusbar.notification.collection.NotificationEntry> updateRanking(@org.jetbrains.annotations.Nullable()
    android.service.notification.NotificationListenerService.RankingMap newRankingMap, @org.jetbrains.annotations.NotNull()
    java.util.Collection<com.android.systemui.statusbar.notification.collection.NotificationEntry> entries, @org.jetbrains.annotations.NotNull()
    java.lang.String reason) {
        return null;
    }
    
    @java.lang.Override()
    public boolean isNotificationForCurrentProfiles(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    /**
     * Uses the [rankingComparator] to sort notifications which aren't filtered
     */
    private final java.util.List<com.android.systemui.statusbar.notification.collection.NotificationEntry> filterAndSortLocked(java.util.Collection<com.android.systemui.statusbar.notification.collection.NotificationEntry> entries, java.lang.String reason) {
        return null;
    }
    
    private final boolean filter(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    @com.android.systemui.statusbar.notification.stack.PriorityBucket()
    private final int getBucketForEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return 0;
    }
    
    private final void updateRankingForEntries(java.lang.Iterable<com.android.systemui.statusbar.notification.collection.NotificationEntry> entries) {
    }
    
    private final boolean isImportantMedia(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isImportantMedia) {
        return false;
    }
    
    private final boolean isConversation(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isConversation) {
        return false;
    }
    
    private final int getPeopleNotificationType(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$getPeopleNotificationType) {
        return 0;
    }
    
    private final boolean isHighPriority(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$isHighPriority) {
        return false;
    }
    
    @javax.inject.Inject()
    public NotificationRankingManager(@org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.statusbar.NotificationMediaManager> mediaManagerLazy, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy groupManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.HeadsUpManager headsUpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationFilter notifFilter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManagerLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager sectionsFeatureManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider highPriorityProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager.KeyguardEnvironment keyguardEnvironment) {
        super();
    }
}