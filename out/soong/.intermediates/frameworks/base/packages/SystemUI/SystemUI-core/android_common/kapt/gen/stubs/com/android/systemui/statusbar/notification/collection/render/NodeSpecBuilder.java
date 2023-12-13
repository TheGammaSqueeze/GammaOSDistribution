package com.android.systemui.statusbar.notification.collection.render;

import com.android.systemui.statusbar.notification.collection.GroupEntry;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.listbuilder.NotifSection;

/**
 * Converts a notif list (the output of the ShadeListBuilder) into a NodeSpec, an abstract
 * representation of which views should be present in the shade. This spec will later be consumed
 * by the ViewDiffer, which will add and remove views until the shade matches the spec. Up until
 * this point, the pipeline has dealt with pure data representations of notifications (in the
 * form of NotificationEntries). In this step, NotificationEntries finally become associated with
 * the views that will represent them. In addition, we add in any non-notification views that also
 * need to present in the shade, notably the section headers.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u001c\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\nJ\u0018\u0010\f\u001a\u00020\u00062\u0006\u0010\r\u001a\u00020\u00062\u0006\u0010\u000e\u001a\u00020\u000bH\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/NodeSpecBuilder;", "", "viewBarn", "Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;", "(Lcom/android/systemui/statusbar/notification/collection/render/NotifViewBarn;)V", "buildNodeSpec", "Lcom/android/systemui/statusbar/notification/collection/render/NodeSpec;", "rootController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "notifList", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "buildNotifNode", "parent", "entry"})
public final class NodeSpecBuilder {
    private final com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.render.NodeSpec buildNodeSpec(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController rootController, @org.jetbrains.annotations.NotNull()
    java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> notifList) {
        return null;
    }
    
    private final com.android.systemui.statusbar.notification.collection.render.NodeSpec buildNotifNode(com.android.systemui.statusbar.notification.collection.render.NodeSpec parent, com.android.systemui.statusbar.notification.collection.ListEntry entry) {
        return null;
    }
    
    public NodeSpecBuilder(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NotifViewBarn viewBarn) {
        super();
    }
}