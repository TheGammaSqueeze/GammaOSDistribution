package com.android.systemui.statusbar;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import javax.inject.Inject;

/**
 * Class to track user interaction with notifications. It's a glorified map of key : bool that can
 * merge multiple "user interacted with notification" signals into a single place.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002B\u0017\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000e\u0010\f\u001a\u00020\u000b2\u0006\u0010\r\u001a\u00020\nJ\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0010\u0010\u0012\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0010\u0010\u0013\u001a\u00020\u000f2\u0006\u0010\r\u001a\u00020\nH\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\b\u001a\u000e\u0012\u0004\u0012\u00020\n\u0012\u0004\u0012\u00020\u000b0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/NotificationInteractionTracker;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "Lcom/android/systemui/statusbar/NotificationInteractionListener;", "clicker", "Lcom/android/systemui/statusbar/NotificationClickNotifier;", "entryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "(Lcom/android/systemui/statusbar/NotificationClickNotifier;Lcom/android/systemui/statusbar/notification/NotificationEntryManager;)V", "interactions", "", "", "", "hasUserInteractedWith", "key", "onEntryAdded", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "onEntryCleanUp", "onNotificationInteraction"})
@com.android.systemui.dagger.SysUISingleton()
public final class NotificationInteractionTracker implements com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener, com.android.systemui.statusbar.NotificationInteractionListener {
    private final java.util.Map<java.lang.String, java.lang.Boolean> interactions = null;
    private final com.android.systemui.statusbar.NotificationClickNotifier clicker = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager entryManager = null;
    
    public final boolean hasUserInteractedWith(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    @java.lang.Override()
    public void onEntryAdded(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @java.lang.Override()
    public void onEntryCleanUp(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @java.lang.Override()
    public void onNotificationInteraction(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    @javax.inject.Inject()
    public NotificationInteractionTracker(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationClickNotifier clicker, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager entryManager) {
        super();
    }
}