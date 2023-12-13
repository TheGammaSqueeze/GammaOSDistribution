package com.android.systemui.statusbar.notification.collection.render;

import android.content.Context;
import android.view.View;
import com.android.systemui.statusbar.notification.collection.GroupEntry;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.ShadeListBuilder;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u0018\u00002\u00020\u0001B\'\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u000e\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewManagerFactory;", "", "context", "Landroid/content/Context;", "logger", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;", "viewBarn", "Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;", "notificationIconAreaController", "Lcom/android/systemui/statusbar/phone/NotificationIconAreaController;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;Lcom/android/systemui/statusbar/phone/NotificationIconAreaController;)V", "create", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewManager;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;"})
public final class ShadeViewManagerFactory {
    private final android.content.Context context = null;
    private final com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger logger = null;
    private final com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn = null;
    private final com.android.systemui.statusbar.phone.NotificationIconAreaController notificationIconAreaController = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.render.ShadeViewManager create(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer) {
        return null;
    }
    
    @javax.inject.Inject()
    public ShadeViewManagerFactory(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationIconAreaController notificationIconAreaController) {
        super();
    }
}