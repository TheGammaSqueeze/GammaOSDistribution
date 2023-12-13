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

/**
 * Responsible for building and applying the "shade node spec": the list (tree) of things that
 * currently populate the notification shade.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u000e\u0010\u0013\u001a\u00020\u00142\u0006\u0010\u0015\u001a\u00020\u0016J\u0016\u0010\u0017\u001a\u00020\u00142\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u001a0\u0019H\u0002J\u0016\u0010\u001b\u001a\u00020\u00142\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u001a0\u0019H\u0002R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewManager;", "", "context", "Landroid/content/Context;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "logger", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;", "viewBarn", "Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;", "notificationIconAreaController", "Lcom/android/systemui/statusbar/phone/NotificationIconAreaController;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDifferLogger;Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;Lcom/android/systemui/statusbar/phone/NotificationIconAreaController;)V", "rootController", "Lcom/android/systemui/statusbar/notification/collection/render/RootNodeController;", "specBuilder", "Lcom/android/systemui/statusbar/notification/collection/render/NodeSpecBuilder;", "viewDiffer", "Lcom/android/systemui/statusbar/notification/collection/render/ShadeViewDiffer;", "attach", "", "listBuilder", "Lcom/android/systemui/statusbar/notification/collection/ShadeListBuilder;", "onNewNotifTree", "notifList", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "updateGroupCounts"})
public final class ShadeViewManager {
    private final com.android.systemui.statusbar.notification.collection.render.RootNodeController rootController = null;
    private final com.android.systemui.statusbar.notification.collection.render.NodeSpecBuilder specBuilder = null;
    private final com.android.systemui.statusbar.notification.collection.render.ShadeViewDiffer viewDiffer = null;
    private final com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn = null;
    private final com.android.systemui.statusbar.phone.NotificationIconAreaController notificationIconAreaController = null;
    
    public final void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.ShadeListBuilder listBuilder) {
    }
    
    private final void onNewNotifTree(java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> notifList) {
    }
    
    private final void updateGroupCounts(java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> notifList) {
    }
    
    public ShadeViewManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.NotificationIconAreaController notificationIconAreaController) {
        super();
    }
}