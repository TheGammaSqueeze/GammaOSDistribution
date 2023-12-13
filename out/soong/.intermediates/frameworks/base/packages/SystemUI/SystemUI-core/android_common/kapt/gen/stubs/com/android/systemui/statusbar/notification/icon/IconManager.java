package com.android.systemui.statusbar.notification.icon;

import android.app.Notification;
import android.app.Person;
import android.content.pm.LauncherApps;
import android.graphics.drawable.Icon;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import com.android.internal.statusbar.StatusBarIcon;
import com.android.systemui.R;
import com.android.systemui.statusbar.StatusBarIconView;
import com.android.systemui.statusbar.notification.InflationException;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import javax.inject.Inject;

/**
 * Inflates and updates icons associated with notifications
 *
 * Notifications are represented by icons in a few different places -- in the status bar, in the
 * notification shelf, in AOD, etc. This class is in charge of inflating the views that hold these
 * icons and keeping the icon assets themselves up to date as notifications change.
 *
 * TODO: Much of this code was copied whole-sale in order to get it out of NotificationEntry.
 * Long-term, it should probably live somewhere in the content inflation pipeline.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u001f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0006\u0010\r\u001a\u00020\u000eJ\u000e\u0010\u000f\u001a\u00020\u000e2\u0006\u0010\u0010\u001a\u00020\u0011J\u0012\u0010\u0012\u001a\u0004\u0018\u00010\u00132\u0006\u0010\u0010\u001a\u00020\u0011H\u0002J\u0018\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0016\u001a\u00020\u0017H\u0002J\u001c\u0010\u0018\u001a\u000e\u0012\u0004\u0012\u00020\u0015\u0012\u0004\u0012\u00020\u00150\u00192\u0006\u0010\u0010\u001a\u00020\u0011H\u0002J\u0010\u0010\u001a\u001a\u00020\u00172\u0006\u0010\u0010\u001a\u00020\u0011H\u0002J \u0010\u001b\u001a\u00020\u000e2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u001c\u001a\u00020\u00152\u0006\u0010\u001d\u001a\u00020\u001eH\u0002J \u0010\u001f\u001a\u00020\u00172\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001c\u001a\u00020\u0015H\u0002J\u000e\u0010 \u001a\u00020\u000e2\u0006\u0010\u0010\u001a\u00020\u0011J\u0010\u0010!\u001a\u00020\u000e2\u0006\u0010\u0010\u001a\u00020\u0011H\u0002R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/icon/IconManager;", "", "notifCollection", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/CommonNotifCollection;", "launcherApps", "Landroid/content/pm/LauncherApps;", "iconBuilder", "Lcom/android/systemui/statusbar/notification/icon/IconBuilder;", "(Lcom/android/systemui/statusbar/notification/collection/notifcollection/CommonNotifCollection;Landroid/content/pm/LauncherApps;Lcom/android/systemui/statusbar/notification/icon/IconBuilder;)V", "entryListener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "sensitivityListener", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry$OnSensitivityChangedListener;", "attach", "", "createIcons", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "createPeopleAvatar", "Landroid/graphics/drawable/Icon;", "getIconDescriptor", "Lcom/android/internal/statusbar/StatusBarIcon;", "redact", "", "getIconDescriptors", "Lkotlin/Pair;", "isImportantConversation", "setIcon", "iconDescriptor", "iconView", "Lcom/android/systemui/statusbar/StatusBarIconView;", "showsConversation", "updateIcons", "updateIconsSafe"})
public final class IconManager {
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener entryListener = null;
    private final com.android.systemui.statusbar.notification.collection.NotificationEntry.OnSensitivityChangedListener sensitivityListener = null;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection notifCollection = null;
    private final android.content.pm.LauncherApps launcherApps = null;
    private final com.android.systemui.statusbar.notification.icon.IconBuilder iconBuilder = null;
    
    public final void attach() {
    }
    
    /**
     * Inflate icon views for each icon variant and assign appropriate icons to them. Stores the
     * result in [NotificationEntry.getIcons].
     *
     * @throws InflationException Exception if required icons are not valid or specified
     */
    public final void createIcons(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) throws com.android.systemui.statusbar.notification.InflationException {
    }
    
    /**
     * Update the notification icons.
     *
     * @param entry the notification to read the icon from.
     * @throws InflationException Exception if required icons are not valid or specified
     */
    public final void updateIcons(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) throws com.android.systemui.statusbar.notification.InflationException {
    }
    
    private final void updateIconsSafe(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    private final kotlin.Pair<com.android.internal.statusbar.StatusBarIcon, com.android.internal.statusbar.StatusBarIcon> getIconDescriptors(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return null;
    }
    
    private final com.android.internal.statusbar.StatusBarIcon getIconDescriptor(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, boolean redact) throws com.android.systemui.statusbar.notification.InflationException {
        return null;
    }
    
    private final void setIcon(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, com.android.internal.statusbar.StatusBarIcon iconDescriptor, com.android.systemui.statusbar.StatusBarIconView iconView) throws com.android.systemui.statusbar.notification.InflationException {
    }
    
    private final android.graphics.drawable.Icon createPeopleAvatar(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) throws com.android.systemui.statusbar.notification.InflationException {
        return null;
    }
    
    /**
     * Determines if this icon shows a conversation based on the sensitivity of the icon, its
     * context and the user's indicated sensitivity preference. If we're using a fall back icon
     * of the small icon, we don't consider this to be showing a conversation
     *
     * @param iconView The icon that shows the conversation.
     */
    private final boolean showsConversation(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, com.android.systemui.statusbar.StatusBarIconView iconView, com.android.internal.statusbar.StatusBarIcon iconDescriptor) {
        return false;
    }
    
    private final boolean isImportantConversation(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    @javax.inject.Inject()
    public IconManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection notifCollection, @org.jetbrains.annotations.NotNull()
    android.content.pm.LauncherApps launcherApps, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.icon.IconBuilder iconBuilder) {
        super();
    }
}