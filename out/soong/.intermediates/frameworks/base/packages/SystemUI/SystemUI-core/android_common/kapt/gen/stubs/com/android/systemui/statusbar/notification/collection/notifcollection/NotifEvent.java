package com.android.systemui.statusbar.notification.collection.notifcollection;

import android.service.notification.NotificationListenerService.RankingMap;
import android.service.notification.StatusBarNotification;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;

/**
 * Set of classes that represent the various events that [NotifCollection] can dispatch to
 * [NotifCollectionListener]s.
 *
 * These events build up in a queue and are periodically emitted in chunks by the collection.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b6\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0014\u0010\u0003\u001a\u00020\u00042\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006J\u0010\u0010\b\u001a\u00020\u00042\u0006\u0010\t\u001a\u00020\u0007H&\u0082\u0001\b\n\u000b\f\r\u000e\u000f\u0010\u0011"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifEvent;", "", "()V", "dispatchTo", "", "listeners", "", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "dispatchToListener", "listener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/BindEntryEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/InitEntryEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/EntryAddedEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/EntryUpdatedEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/EntryRemovedEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/CleanUpEntryEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/RankingUpdatedEvent;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/RankingAppliedEvent;"})
public abstract class NotifEvent {
    
    public final void dispatchTo(@org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener> listeners) {
    }
    
    public abstract void dispatchToListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener listener);
    
    private NotifEvent() {
        super();
    }
}