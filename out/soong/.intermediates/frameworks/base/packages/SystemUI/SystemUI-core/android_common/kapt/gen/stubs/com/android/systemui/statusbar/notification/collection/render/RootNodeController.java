package com.android.systemui.statusbar.notification.collection.render;

import android.view.View;
import com.android.systemui.statusbar.notification.row.ExpandableView;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;

/**
 * Temporary wrapper around [NotificationListContainer], for use by [ShadeViewDiffer]. Long term,
 * we should just modify NLC to implement the NodeController interface.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u000b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0018\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00012\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0012\u0010\u0012\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\b\u0010\u0013\u001a\u00020\u0011H\u0016J\u0018\u0010\u0014\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00012\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0018\u0010\u0015\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00012\u0006\u0010\u0016\u001a\u00020\u0017H\u0016R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0007\u001a\u00020\bX\u0096D\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0014\u0010\u0004\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/render/RootNodeController;", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "listContainer", "Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;", "view", "Landroid/view/View;", "(Lcom/android/systemui/statusbar/notification/stack/NotificationListContainer;Landroid/view/View;)V", "nodeLabel", "", "getNodeLabel", "()Ljava/lang/String;", "getView", "()Landroid/view/View;", "addChildAt", "", "child", "index", "", "getChildAt", "getChildCount", "moveChildTo", "removeChild", "isTransfer", ""})
public final class RootNodeController implements com.android.systemui.statusbar.notification.collection.render.NodeController {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String nodeLabel = "<root>";
    private final com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer = null;
    @org.jetbrains.annotations.NotNull()
    private final android.view.View view = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getNodeLabel() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.view.View getChildAt(int index) {
        return null;
    }
    
    @java.lang.Override()
    public int getChildCount() {
        return 0;
    }
    
    @java.lang.Override()
    public void addChildAt(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
    }
    
    @java.lang.Override()
    public void moveChildTo(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, int index) {
    }
    
    @java.lang.Override()
    public void removeChild(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NodeController child, boolean isTransfer) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.view.View getView() {
        return null;
    }
    
    public RootNodeController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.stack.NotificationListContainer listContainer, @org.jetbrains.annotations.NotNull()
    android.view.View view) {
        super();
    }
}