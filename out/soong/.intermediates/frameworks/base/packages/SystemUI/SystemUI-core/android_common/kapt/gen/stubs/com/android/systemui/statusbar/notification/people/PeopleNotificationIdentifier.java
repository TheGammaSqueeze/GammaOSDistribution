package com.android.systemui.statusbar.notification.people;

import android.annotation.IntDef;
import android.service.notification.NotificationListenerService.Ranking;
import android.service.notification.StatusBarNotification;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\bf\u0018\u0000 \t2\u00020\u0001:\u0001\tJ\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00032\u0006\u0010\u0005\u001a\u00020\u0003H&J\u0010\u0010\u0006\u001a\u00020\u00032\u0006\u0010\u0007\u001a\u00020\bH&"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "", "compareTo", "", "a", "b", "getPeopleNotificationType", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "Companion"})
public abstract interface PeopleNotificationIdentifier {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion Companion = null;
    public static final int TYPE_NON_PERSON = 0;
    public static final int TYPE_PERSON = 1;
    public static final int TYPE_FULL_PERSON = 2;
    public static final int TYPE_IMPORTANT_PERSON = 3;
    
    /**
     * Identifies if the given notification can be classified as a "People" notification.
     *
     * @return [TYPE_NON_PERSON] if not a people notification, [TYPE_PERSON] if it is a people
     * notification that doesn't use shortcuts, [TYPE_FULL_PERSON] if it is a person notification
     * that users shortcuts, and [TYPE_IMPORTANT_PERSON] if an "important" people notification
     * that users shortcuts.
     */
    @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    public abstract int getPeopleNotificationType(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry);
    
    public abstract int compareTo(@com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int a, @com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier.Companion.PeopleNotificationType()
    int b);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\b\u0086\u0003\u0018\u00002\u00020\u0001:\u0001\bB\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier$Companion;", "", "()V", "TYPE_FULL_PERSON", "", "TYPE_IMPORTANT_PERSON", "TYPE_NON_PERSON", "TYPE_PERSON", "PeopleNotificationType"})
    public static final class Companion {
        public static final int TYPE_NON_PERSON = 0;
        public static final int TYPE_PERSON = 1;
        public static final int TYPE_FULL_PERSON = 2;
        public static final int TYPE_IMPORTANT_PERSON = 3;
        
        private Companion() {
            super();
        }
        
        @android.annotation.IntDef(prefix = {"TYPE_"}, value = {0, 1, 2, 3})
        @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0087\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier$Companion$PeopleNotificationType;", ""})
        @java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.SOURCE)
        @kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.SOURCE)
        public static abstract @interface PeopleNotificationType {
        }
    }
}