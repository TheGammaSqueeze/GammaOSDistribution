package com.android.systemui.statusbar.notification.people;

import android.annotation.IntDef;
import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.StatusBarNotification;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0007\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0018\u0010\f\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\b2\u0006\u0010\u000e\u001a\u00020\bH\u0016J\u0010\u0010\u000f\u001a\u00020\b2\u0006\u0010\u0010\u001a\u00020\u0011H\u0002J\u0010\u0010\u0012\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u0014H\u0016J\u0010\u0010\u0015\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u0014H\u0002J\u0018\u0010\u0016\u001a\u00020\b2\u0006\u0010\u0017\u001a\u00020\b2\u0006\u0010\u0018\u001a\u00020\bH\u0002R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0018\u0010\u0007\u001a\u00020\b*\u00020\t8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifierImpl;", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "personExtractor", "Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;", "groupManager", "Lcom/android/systemui/statusbar/notification/collection/render/GroupMembershipManager;", "(Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;Lcom/android/systemui/statusbar/notification/collection/render/GroupMembershipManager;)V", "personTypeInfo", "", "Landroid/service/notification/NotificationListenerService$Ranking;", "getPersonTypeInfo", "(Landroid/service/notification/NotificationListenerService$Ranking;)I", "compareTo", "a", "b", "extractPersonTypeInfo", "sbn", "Landroid/service/notification/StatusBarNotification;", "getPeopleNotificationType", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "getPeopleTypeOfSummary", "upperBound", "type", "other"})
@com.android.systemui.dagger.SysUISingleton()
public final class PeopleNotificationIdentifierImpl implements com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier {
    private final com.android.systemui.statusbar.notification.people.NotificationPersonExtractor personExtractor = null;
    private final com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager groupManager = null;
    
    @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    @java.lang.Override()
    public int getPeopleNotificationType(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return 0;
    }
    
    @java.lang.Override()
    public int compareTo(@com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int a, @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int b) {
        return 0;
    }
    
    /**
     * Given two [PeopleNotificationType]s, determine the upper bound. Used to constrain a
     * notification to a type given multiple signals, i.e. notification groups, where each child
     * has a [PeopleNotificationType] that is used to constrain the summary.
     */
    @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    private final int upperBound(@com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int type, @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int other) {
        return 0;
    }
    
    private final int getPersonTypeInfo(android.service.notification.NotificationListenerService.Ranking $this$personTypeInfo) {
        return 0;
    }
    
    private final int extractPersonTypeInfo(android.service.notification.StatusBarNotification sbn) {
        return 0;
    }
    
    private final int getPeopleTypeOfSummary(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return 0;
    }
    
    @javax.inject.Inject()
    public PeopleNotificationIdentifierImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.NotificationPersonExtractor personExtractor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager groupManager) {
        super();
    }
}